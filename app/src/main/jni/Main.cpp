#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <thread>
#include <pthread.h>
#include <dirent.h> 
#include <libgen.h>
#include <cstdint>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <jni.h>
#include <android/log.h>
#include <elf.h>
#include <dlfcn.h>
#include <sys/system_properties.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <codecvt>
#include <android/native_window.h>

#define IMGUI_DEFINE_MATH_OPERATORS

#include "imgui.h"
#include "imgui_additional.h"
#include "imgui_themes.h"

#include "backends/imgui_impl_android.h"
#include "backends/imgui_impl_opengl3.h"

#include "fonts/GoogleSans.h"
#include "fonts/MyFont.hpp"

#include "Tools/Il2Cpp.h"
#include "Tools/Tools.h"

#include "struct/Vector3.hpp"
#include "struct/Vector2.h"

#include "config/setup.h"
#include "config/JNIStuff.h"

#include "TouchSystem.h"

#include "login/Login.h"

#include "feature/class.h"
#include "feature/esp.h"

#include "utils.h"
#include "Menu.h"
#include "Display.h"

// ========== TOUCH CACHE THREAD ==========
void* TouchCacheThread(void*) {
	__android_log_print(ANDROID_LOG_INFO, "TOUCH", "Touch cache thread started");
	
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 60fps
		UpdateTouchCacheFromMainThread();
	}
	return nullptr;
}

void Render_Display(void *address, DobbyRegisterContext *ctx) 
{

    if (!Display::m_pWindow()->getViewPort()) return;

    glWidth = Display::m_pWindow()->getWidth();
    glHeight = Display::m_pWindow()->getHeight();

    if (!g_Initialized) {
        #define HI(v)   ImVec4(0.502f, 0.075f, 0.256f, v)
        #define MED(v)  ImVec4(0.455f, 0.198f, 0.301f, v)
        #define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
        #define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
        #define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)

        ImGui::CreateContext();
		void SetDarkRedTheme();
        
        ImGuiStyle *style = &ImGui::GetStyle();
        style->FrameRounding     = 6;
        style->FrameBorderSize   = 1;
        style->WindowRounding    = 5.3f;
        style->ScrollbarRounding = 0;
        style->FramePadding      = ImVec2(8, 6);
        style->ScaleAllSizes(2.0f);
        style->ScrollbarSize    /= 1;
        style->WindowTitleAlign  = ImVec2(0.5, 0.5);

        ImGuiIO* io = &ImGui::GetIO();
        io->IniFilename = nullptr;
        io->DisplaySize = ImVec2((float)glWidth, (float)glHeight);

        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImFontConfig font_cfg;
        io->Fonts->AddFontFromMemoryCompressedTTF(GoogleSans_compressed_data, GoogleSans_compressed_size, 30.5f, 
            &font_cfg, 
            io->Fonts->GetGlyphRangesChineseFull()
        );

        setRes(glWidth, glHeight);
        g_Initialized = true;
        
        // Set screen height para sa touch cache
        SetTouchScreenHeight(glHeight);
        
        // Start touch cache thread
        pthread_t touch_thread;
        pthread_create(&touch_thread, nullptr, TouchCacheThread, nullptr);
        pthread_detach(touch_thread);
    }

    ImGuiIO* io = &ImGui::GetIO();

    ImGui_ImplOpenGL3_NewFrame();
    ImplAndroid_NewFrame();
    ImGui::NewFrame();

    if (screenWidth < glWidth && screenHeight < glHeight) {
        setRes(glWidth, glHeight);
    }

    // set the unity screen resolution to fix touch issue
    if (screenWidth != Screen::get_width() || screenHeight != Screen::get_height()) {
        Screen::SetResolution(screenWidth, screenHeight, true);
    }

    // FIXED: Now only reads cached data - NO Unity calls!
    OnTouchEvent();

    auto hideShowMin = ImVec2(0, screenHeight - 80);
    auto hideShowMax = ImVec2(80, screenHeight);
    auto mousePos    = io->MousePos;

    std::string strCool = "TAP TO SHOW MENU"; 
    auto textSize = ImGui::CalcTextSize(strCool.c_str(), 0, 100);

    if (mousePos.x >= hideShowMin.x && mousePos.x <= hideShowMax.x && 
        mousePos.y >= hideShowMin.y && mousePos.y <= hideShowMax.y) {
        bShowMenu = true;
    }
	
    if (bShowMenu) {
        ShowMenu();
    }

    if (bFullChecked) {
        DrawESP(ImGui::GetBackgroundDrawList(), screenWidth, screenHeight);
    }
    
    ImGui::EndFrame();
    ImGui::Render();

    glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    
    if (clearMousePos) {
        io->MousePos = ImVec2(-1, -1);
        clearMousePos = false;
    }
}

void SwapBuffers_handler(void *address, DobbyRegisterContext *ctx) 
{
        Render_Display(address, ctx);
}

void *main_thread(void *) 
{
    // Wait for liblogic first
    while (!m_IL2CPP) {
        m_IL2CPP = Tools::GetBaseAddress("liblogic.so");
        sleep(2);
    }

    // Hook SwapBuffers agad para sa menu UI
    if (auto addr = DobbySymbolResolver(0, OBFUSCATE("eglSwapBuffers"))) {
        DobbyInstrument(addr, SwapBuffers_handler);
    }

    Il2CppAttach("liblogic.so");
	
    return nullptr;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* ) 
{
    g_vm = vm;
    JNIEnv* env = nullptr;

    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    // Main Menu/Cheat Thr
    pthread_t thread{};
    if (pthread_create(&thread, nullptr, main_thread, nullptr) != 0) {
        return JNI_ERR;
    }
    pthread_detach(thread);

    return JNI_VERSION_1_6;
}