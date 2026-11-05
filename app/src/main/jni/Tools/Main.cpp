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
#include "KittyMemory/MemoryPatch.h"
#include "Tools/xDL/xdl.h"
#include "Tools/fake_dlfcn.h"
#include "Tools/Il2Cpp.h"
#include "Tools/Tools.h"

#include "struct/Vector3.hpp"
#include "struct/Vector2.h"
#include "struct/Rect.h"
#include "struct/Quaternion.h"

#include "config/setup.h"
#include "config/JNIStuff.h"

#include "TouchSystem.h"

//#include "OnTouchEvents.h"



#include "icon/DrawIcon.h"

#include "login/Login.h"

#include "feature/minimap.h"
#include "feature/init.h"
#include "feature/class.h"
#include "feature/listcountry.h"
#include "feature/room.h"
#include "feature/esp.h"
//#include "Dungs/Call_Dungs.h"
#include "utils.h"
#include "feature/UnlockSkin.h"
#include "feature/classaim.h"
#include "feature/aim.h"
#include "feature/retri.h"
#include "Menu.h"
#include "feature/FullSight.h"


#include "feature/DevBypassV2.h"
#include "feature/DevBypassV3.h"
//#include "feature/Maphack.h"
//#include "feature/protection.h"

#include "feature/BypassPatch.h"
#include "feature/BypassString.h"
#include "feature/BypassWafe.h"
#include "feature/Bypass.h"


#include "feature/Bypass.h"
bool KEN1 = true;
bool BanFix = true;

struct My_Patches {
	MemoryPatch
	IsMd5Log,
	OnErrorLog,
	InitPlugInTesting,
	PlugInTesting,
	SetAntiCheatReport,
	HasSeasonReportRes,
	SendUdpReport,
	ipDeviceIdNotMatchReport,
	OnRoleBan,
	OnHelpBan,
	NotifyRemoveActData,
	on_Notify_Activity_Incr_Reload,
	RefreshMsgCacheActivity,
	SendMtrReportData,
	SendLargeGameReportData,
	IsLogicRvoSummon,
	SendPackageReportData,
   UpdateMainThreadLogic,
   IsBanPickNotSendGrey;
   
   
   
       MemoryPatch Bypazz, Bypazz2, Bypazz3, Bypazz4, Bypazz5, Bypazz6, Bypazz7, Bypazz8, Bypazz9, Bypazz10, Bypazz11, Bypazz12, Bypazz13, Bypazz14, Bypazz15, Bypazz16, Bypazz17, Bypazz18, Bypazz19, Bypazz20;                                             
       
                                                       
                                                                                                                                                       

} kenPatches;
	




	
	
//#include "Bypass.h"
//#include "feature/konoha.h"
EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
	eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);

    if (!g_Initialized) {
    
        #define HI(v)   ImVec4(0.502f, 0.075f, 0.256f, v)
    #define MED(v)  ImVec4(0.455f, 0.198f, 0.301f, v)
    #define LOW(v)  ImVec4(0.232f, 0.201f, 0.271f, v)
    // backgrounds (@todo: complete with BG_MED, BG_LOW)
    #define BG(v)   ImVec4(0.200f, 0.220f, 0.270f, v)
    // text
    #define TEXT(v) ImVec4(0.860f, 0.930f, 0.890f, v)
    
        ImGui::CreateContext();
        ImGuiStyle * style = &ImGui::GetStyle();
    ImVec4* colors = style->Colors;

    colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg]               = ImColor(22,25,36,240);
    colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border]                 = ImColor(238,238,238,60);
    colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_TitleBg]                = ImColor(53,28,117,220);
    colors[ImGuiCol_TitleBgActive]          = ImColor(53,28,117,240);
    colors[ImGuiCol_TitleBgCollapsed]       = ImColor(53,28,117,100);
    colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark]              = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Button]                 = ImColor(53,28,117,100);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
    colors[ImGuiCol_HeaderHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator]              = colors[ImGuiCol_Border];
    colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    colors[ImGuiCol_Tab]                    = ImLerp(colors[ImGuiCol_Header],       colors[ImGuiCol_TitleBgActive], 0.80f);
    colors[ImGuiCol_TabHovered]             = colors[ImGuiCol_HeaderHovered];
    colors[ImGuiCol_TabActive]              = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
    colors[ImGuiCol_TabUnfocused]           = ImLerp(colors[ImGuiCol_Tab],          colors[ImGuiCol_TitleBg], 0.80f);
    colors[ImGuiCol_TabUnfocusedActive]     = ImLerp(colors[ImGuiCol_TabActive],    colors[ImGuiCol_TitleBg], 0.40f);
    colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
    colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);   // Prefer using Alpha=1.0 here
    colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);   // Prefer using Alpha=1.0 here
    colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
    colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
 
style->FrameRounding        = 6;
	style->FrameBorderSize      = 1;
	style->WindowRounding       = 5.3f;
	style->ScrollbarRounding    = 0;
	style->FramePadding         = ImVec2(8, 6);
	style->ScaleAllSizes(1.0f);
	style->ScrollbarSize /= 1;
	

	
	
       style->WindowTitleAlign = ImVec2(0.5, 0.5);
        ImGuiIO* io = &ImGui::GetIO();
        io->IniFilename = nullptr;
		
		io->DisplaySize = ImVec2((float)glWidth, (float)glHeight);
		
        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImFontConfig font_cfg;
        io->Fonts->AddFontFromMemoryCompressedTTF(GoogleSans_compressed_data, GoogleSans_compressed_size, 28.5f, &font_cfg, io->Fonts->GetGlyphRangesChineseFull());
		
		setRes(glWidth, glHeight);
		
        g_Initialized = true;
        
        
    }

    ImGuiIO* io = &ImGui::GetIO();
	
    ImGui_ImplOpenGL3_NewFrame();
	ImplAndroid_NewFrame();
    ImGui::NewFrame();
	
	if (screenWidth < glWidth && screenHeight < glHeight) setRes(glWidth, glHeight);
	
	// set the unity screen resolution to fix touch issue
    if (screenWidth != Screen::get_width() || screenHeight != Screen::get_height()) {
        Screen::SetResolution(screenWidth, screenHeight, true);
    }
	
	ImGui_GetTouch(io, screenHeight);
	
    auto hideShowMin = ImVec2(0, screenHeight - 80);
    auto hideShowMax = ImVec2(80, screenHeight);
    auto mousePos = io->MousePos;

    if  (mousePos.x >= hideShowMin.x && mousePos.x <= hideShowMax.x && mousePos.y >= hideShowMin.y && mousePos.y <= hideShowMax.y) {
        bShowMenu = true;
    }
    
    //BOTTOM
//    DrawBottomNavigationMenu(screenWidth, screenHeight);
    
    //ShowWindow
    if (bShowMenu) {
        ShowMenu();
    }
	
	if (bFullChecked) drawESP(ImGui::GetBackgroundDrawList(), screenWidth, screenHeight);
	//UnlockSkin();
    if (!AttachIconDone) {
        AttachIcon();
        AttachIconDone = true;
    }

    if (!AttachSpellDone) {
        AttachSpell();
        AttachSpellDone = true;
    }
    
    if (!AttachCountryDone) {
        AttachCountry();   
        AttachCountryDone = true;
    }
    
            if (!AttachRankDone) {
        AttachRank();
        AttachRankDone = true;
	}
    
        
    if (!AttachMonsterAlertDone) {
    AttachMonsterAlert();
    AttachMonsterAlertDone = true;
    }
    

		    if (!AttachMonsterDone) {
    AttachMonster();
    AttachMonsterDone = true;
    }
	
        	if (Retri2) {
		
		ImGui::SetNextWindowSize(ImVec2(), ImGuiCond_Once);
		
		
       	if (ImGui::Begin(OBFUSCATE("Retri"), 0 , ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize| ImGuiWindowFlags_NoBringToFrontOnFocus)) {
       // ImGui::RadioButton("Accurate Retri", &RetriPhase, 2);
       ImGui::BeginGroupPanel(OBFUSCATE("Retribution :"), ImVec2(0.0f, 0.0f));

        ImGui::Checkbox("Retri Buff", &AutoRetriBuff);                  
		ImGui::Checkbox("Retri Lord", &AutoRetriLord);
		ImGui::Checkbox("Retri Turtle", &AutoRetriTurtle);
		ImGui::Checkbox("Retri Litho", &AutoRetriLitho);
	//	ImGui::Checkbox("Retri Crab", &AutoRetriCrab);
		ImGui::EndGroupPanel();
}}


    /*
    
    	if (Retri2) {
		
		ImGui::SetNextWindowSize(ImVec2(), ImGuiCond_Once);
		
		
       	if (ImGui::Begin(OBFUSCATE("Retri"), 0 , ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize| ImGuiWindowFlags_NoBringToFrontOnFocus)) {
       // ImGui::RadioButton("Accurate Retri", &RetriPhase, 2);
       ImGui::BeginGroupPanel(OBFUSCATE("Retribution :"), ImVec2(0.0f, 0.0f));

        ImGui::Checkbox("Retri Buff", &AutoRetriBuff);                  
		ImGui::Checkbox("Retri Lord", &AutoRetriLord);
		ImGui::Checkbox("Retri Turtle", &AutoRetriTurtle);
		ImGui::Checkbox("Retri Litho", &AutoRetriLitho);
	//	ImGui::Checkbox("Retri Crab", &AutoRetriCrab);
		ImGui::EndGroupPanel();
}}
*/

	
    ImGui::EndFrame();
    ImGui::Render();
	glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	
	if (clearMousePos) {
        io->MousePos = ImVec2(-1, -1);
        clearMousePos = false;
    }
	
    return old_eglSwapBuffers(dpy, surface);
}


	
void *main_thread(void *) {
	
    while (!m_IL2CPP) {
        m_IL2CPP = Tools::GetBaseAddress("liblogic.so");
        sleep(1);
    }
	
	Il2CppAttach("liblogic.so");
    
    	if (BanFix){
    Tools::WriteAddr((void *) (m_IL2CPP + 0xAF84C3C0), (void *) "00 00 00 00 00 00 00 00", 4);
	Tools::WriteAddr((void *) (m_IL2CPP + 0xB04BD344), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xB0D56138), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xAF50653C), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xAF509010), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xB0360988), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xBA837EE0), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xB1013AD4), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xB037B8E0), (void *) "00 00 00 00 00 00 00 00", 4);
    Tools::WriteAddr((void *) (m_IL2CPP + 0xAEE4256C), (void *) "00 00 00 00 00 00 00 00", 4);
	}
	
	    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffce605804), (void *) Bypass1, (void **) &old_Bypass1);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffdd9ec0c), (void *) Bypass2, (void **) &old_Bypass2);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffde91604), (void *) Bypass3, (void **) &old_Bypass3);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffdd9beb8), (void *) Bypass4, (void **) &old_Bypass4);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffdd9c62c), (void *) Bypass5, (void **) &old_Bypass5);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffdd9cae0), (void *) Bypass6, (void **) &old_Bypass6);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffdd9c54c), (void *) Bypass7, (void **) &old_Bypass7);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffdd9cbd4), (void *) Bypass8, (void **) &old_Bypass8);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffffdd9d128), (void *) Bypass9, (void **) &old_Bypass9);  
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffff744eab8), (void *) Bypass10, (void **) &old_Bypass10);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffff744e604), (void *) Bypass11, (void **) &old_Bypass11);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffff744de90), (void *) Bypass12, (void **) &old_Bypass12);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffff75435dc), (void *) Bypass13, (void **) &old_Bypass13);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffff7450be4), (void *) Bypass14, (void **) &old_Bypass14);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xfffffffff759b6e0), (void *) Bypass15, (void **) &old_Bypass15);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffd22dc3e4), (void *) Bypass16, (void **) &old_Bypass16);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffd2c207e8), (void *) Bypass17, (void **) &old_Bypass17);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffd219d254), (void *) Bypass18, (void **) &old_Bypass18);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffd246f408), (void *) Bypass19, (void **) &old_Bypass19);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffd2471f6c), (void *) Bypass20, (void **) &old_Bypass20);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0x453694C), (void *) Bypass21, (void **) &old_Bypass21);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0x3B15108), (void *) Bypass22, (void **) &old_Bypass22);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0x4C992F4), (void *) Bypass23, (void **) &old_Bypass23);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0x351A104), (void *) Bypass24, (void **) &old_Bypass24);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0x351BF90), (void *) Bypass25, (void **) &old_Bypass25);
	Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0x1BCA544), (void *) Bypass26, (void **) &old_Bypass26);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0x56EF504), (void *) Bypass27, (void **) &old_Bypass27);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffcf1c1804), (void *) Bypass28, (void **) &old_Bypass28);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffcfb2cc18), (void *) Bypass29, (void **) &old_Bypass29);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffd0911cc8), (void *) Bypass31, (void **) &old_Bypass30);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffcf34f688), (void *) Bypass32, (void **) &old_Bypass31);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffcf3521ec), (void *) Bypass33, (void **) &old_Bypass32);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xcfb29c7084), (void *) Bypass34, (void **) &old_Bypass33);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xcf8de004), (void *) Bypass35, (void **) &old_Bypass34);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffcf8df294), (void *) Bypass36, (void **) &old_Bypass35);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffcf8df914), (void *) Bypass37, (void **) &old_Bypass36);
    Tools::Hook((void *)KittyMemory::getAbsoluteAddress("liblogic.so", 0xffffffffcf8de358), (void *) Bypass38, (void **) &old_Bypass38);
    
	kenPatches.IsMd5Log = MemoryPatch::createWithHex("liblogic.so", 0xB0C934B8, "01 00 A0 E3 1E FF 2F E1"); 
    kenPatches.OnErrorLog = MemoryPatch::createWithHex("liblogic.so", 0xAEE494DC, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.InitPlugInTesting = MemoryPatch::createWithHex("liblogic.so", 0xAEE49F14, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.PlugInTesting = MemoryPatch::createWithHex("liblogic.so", 0xAEE48614, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.SetAntiCheatReport = MemoryPatch::createWithHex("liblogic.so", 0xAF84C3C0, "01 00 A0 E3 1E FF 2F E1"); 
    kenPatches.HasSeasonReportRes = MemoryPatch::createWithHex("liblogic.so", 0xAE9582F4, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.SendUdpReport = MemoryPatch::createWithHex("liblogic.so", 0xAE9237B8, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.ipDeviceIdNotMatchReport = MemoryPatch::createWithHex("liblogic.so", 0xAEA0D9E0, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.OnRoleBan = MemoryPatch::createWithHex("liblogic.so", 0xAEA0E534, "01 00 A0 E3 1E FF 2F E1");  
    kenPatches.OnHelpBan = MemoryPatch::createWithHex("liblogic.so", 0xAEA0E598, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.NotifyRemoveActData = MemoryPatch::createWithHex("liblogic.so", 0xAEA0FED8, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.on_Notify_Activity_Incr_Reload = MemoryPatch::createWithHex("liblogic.so", 0xAEA10134, "01 00 A0 E3 1E FF 2F E1");  
    kenPatches.RefreshMsgCacheActivity = MemoryPatch::createWithHex("liblogic.so", 0xAEA103E8, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.SendMtrReportData = MemoryPatch::createWithHex("liblogic.so", 0xAEA1C67C, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.SendLargeGameReportData = MemoryPatch::createWithHex("liblogic.so", 0xAEA1CF48, "01 00 A0 E3 1E FF 2F E1");  
    kenPatches.IsLogicRvoSummon = MemoryPatch::createWithHex("liblogic.so", 0xB0C934A8, "01 00 A0 E3 1E FF 2F E1");  
    kenPatches.SendPackageReportData = MemoryPatch::createWithHex("liblogic.so", 0xAEE4A188, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.UpdateMainThreadLogic = MemoryPatch::createWithHex("liblogic.so", 0xAEE3D430, "01 00 A0 E3 1E FF 2F E1");
    kenPatches.IsBanPickNotSendGrey = MemoryPatch::createWithHex("liblogic.so", 0xB0C936F4, "01 00 A0 E3 1E FF 2F E1");
	
	
    
    //new patch
Tools::WriteAddr((void *) (logic + 0xA8243D0C), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa8243CB8), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa8243C84), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xa8243BCC), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243B90), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243B28), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243AE4), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243A54), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa8243A34), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243A24), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243A14), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xa8243A04), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA82439E4), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA82439D4), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA82439C4), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA82439B4), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa82439A4), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243994), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243984), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243954), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243944), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243934), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243924), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243914), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243904), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa82438F4), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243884), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243874), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243864), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa8243834), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243814), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243824), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa8243804), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA82437F4), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA82437D4), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA82437C4), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xa82437AC), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA82437A4), (void *) "\x00\x00\x00\x00", 4); 
Tools::WriteAddr((void *) (logic + 0xA8243794), (void *) "\x00\x00\x00\x00", 4);
Tools::WriteAddr((void *) (logic + 0xA8243784), (void *) "\x00\x00\x00\x00", 4);
    

	Loadbypass();
	Loadbypass1();
	Loadbypass2();
	BlatzN1();
//	Bypass1();
///	hookFunctions();
	//hook EGL
//	UnlockSkin();
//  FullSightHook();
	Tools::Hook((void *) DobbySymbolResolver(OBFUSCATE("/system/lib/libunity.so"), OBFUSCATE("eglSwapBuffers")), (void *) hook_eglSwapBuffers, (void **) &old_eglSwapBuffers);
	    
//aim&retri


Tools::Hook((void *) ShowSelfPlayer_TryUseSkill, (void *) TryUseSkill, (void **) &orig_TryUseSkill);  
   Tools::Hook((void *) ShowSelfPlayer_TryUseSkill2, (void *) TryUseSkill2, (void **) &orig_TryUseSkill2);  
	Tools::Hook((void *) ShowSelfPlayer_OnUpdate, (void *) UpdateRetribution, (void **) &orig_UpdateRetribution);

/*
    Tools::Hook((void *) ShowSelfPlayer_TryUseSkill, (void *) TryUseSkill, (void **) &orig_TryUseSkill);  
   Tools::Hook((void *) ShowSelfPlayer_TryUseSkill2, (void *) TryUseSkill2, (void **) &orig_TryUseSkill2);  
	Tools::Hook((void *) ShowSelfPlayer_OnUpdate, (void *) UpdateRetribution, (void **) &orig_UpdateRetribution);
	*/
	
    if (KEN1) {
    kenPatches.IsMd5Log.Modify();
    kenPatches.OnErrorLog.Modify();
    kenPatches.InitPlugInTesting.Modify();
    kenPatches.PlugInTesting.Modify();
    kenPatches.SetAntiCheatReport.Modify();
    kenPatches.HasSeasonReportRes.Modify();
    kenPatches.SendUdpReport.Modify();
    kenPatches.ipDeviceIdNotMatchReport.Modify();
	kenPatches.OnRoleBan.Modify();
    kenPatches.OnHelpBan.Modify();
	kenPatches.NotifyRemoveActData.Modify();
    kenPatches.on_Notify_Activity_Incr_Reload.Modify();
	kenPatches.RefreshMsgCacheActivity.Modify();
    kenPatches.SendMtrReportData.Modify();
	kenPatches.SendLargeGameReportData.Modify();
    kenPatches.IsLogicRvoSummon.Modify();
    kenPatches.SendPackageReportData.Modify();
    kenPatches.UpdateMainThreadLogic.Modify();
    kenPatches.IsBanPickNotSendGrey.Modify();
    } else {
    kenPatches.IsMd5Log.Restore();
    kenPatches.OnErrorLog.Restore();
    kenPatches.InitPlugInTesting.Restore();
    kenPatches.PlugInTesting.Restore();
    kenPatches.SetAntiCheatReport.Restore();
    kenPatches.HasSeasonReportRes.Restore();
    kenPatches.SendUdpReport.Restore();
    kenPatches.ipDeviceIdNotMatchReport.Restore();
	kenPatches.OnRoleBan.Restore();
    kenPatches.OnHelpBan.Restore();
	kenPatches.NotifyRemoveActData.Restore();
    kenPatches.on_Notify_Activity_Incr_Reload.Restore();
	kenPatches.RefreshMsgCacheActivity.Restore();
    kenPatches.SendMtrReportData.Restore();
	kenPatches.SendLargeGameReportData.Restore();
    kenPatches.IsLogicRvoSummon.Restore();
    kenPatches.SendPackageReportData.Restore();
    kenPatches.UpdateMainThreadLogic.Restore();
    kenPatches.IsBanPickNotSendGrey.Restore();
    }




	
	return 0;
}

/*

jint (JNICALL *Real_JNI_OnLoad)(JavaVM *vm, void *reserved);
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;

    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
	g_vm = vm;

	std::string apkPkg = getPackageName(GetJNIEnv(g_vm));
	std::string libAkSound = std::string(OBFUSCATE("libAkSoundEngine.so"));
    std::string libAkSoundOri1 = std::string(OBFUSCATE("libAkSoundEngine+.bytes"));
    std::string libAkSoundOri2 = std::string(OBFUSCATE("libAkSoundEngine2.so"));

    std::string localPath = std::string(OBFUSCATE("/storage/emulated/0/Android/data/")) + apkPkg + std::string(OBFUSCATE("/files/dragon2017/assets/comlibs/")) + std::string(ARCH);
    std::string rootPath = std::string(OBFUSCATE("/data/data/")) + apkPkg + std::string(OBFUSCATE("/app_libs"));
    std::string pathAkSound = rootPath + std::string(OBFUSCATE("/")) + libAkSound;
    std::string pathAkSoundOri1 = localPath + std::string(OBFUSCATE("/")) + libAkSoundOri1;
    std::string pathAkSoundOri2 = rootPath + std::string(OBFUSCATE("/")) + libAkSoundOri2;

    if (CopyFile(pathAkSoundOri1.c_str(), pathAkSoundOri2.c_str())) {
        void *handle = dlopen(pathAkSoundOri2.c_str(), RTLD_NOW);
        if (!handle) {
            handle = dlopen(pathAkSoundOri2.c_str(), RTLD_NOW);
            sleep(1);
        }
        auto Hook_JNI_OnLoad = dlsym(handle, OBFUSCATE("JNI_OnLoad"));
        if (Hook_JNI_OnLoad) {
            Real_JNI_OnLoad = decltype(Real_JNI_OnLoad)(Hook_JNI_OnLoad);
            pthread_t t;
            pthread_create(&t, nullptr, main_thread, nullptr);
            if (CheckFile(pathAkSoundOri2.c_str())) {
                std::remove(pathAkSound.c_str());
                std::rename(pathAkSoundOri2.c_str(), pathAkSound.c_str());
            }
            return Real_JNI_OnLoad(vm, reserved);
        }
    }
    return JNI_ERR;
	}
*/



__attribute__((constructor))




void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, main_thread, NULL);
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
	g_vm = vm;
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}




