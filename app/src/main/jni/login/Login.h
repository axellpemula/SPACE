#pragma once
#include "curl/curl.h"
#include "Tools.h"
#include "json.hpp"
#include "obfuscate/obfuscate.h"
using json = nlohmann::ordered_json;
std::string expired, tittle,valid;
std::string g_Token, g_Auth;
bool bValid = false;
int selectedFeature = 1;
bool bInitDone;

#define g_LogTag OBFUSCATE("Hello-LOGGER")


static std::string title = OBFUSCATE("@russ1b4u");
std::string idaccmlbb = OBFUSCATE("");
std::string uptdmod = OBFUSCATE("");
std::string failed = OBFUSCATE("");
std::string Version = OBFUSCATE("1.5");
std::string Patch = OBFUSCATE("2.1.61.11705");
std::string Status = OBFUSCATE(" SAFE ");
std::string Devv1 = OBFUSCATE(" russ1b4u ");

std::string EXP = " ";
std::string storedKey =" ";

//std::string vrsicheats = OBFUSCATE("Versi Edit Sendiri");
std::string gamemod = OBFUSCATE(" Mobile Legends: Bang-Bang ");


std::string mod_status = " ";
std::string DeviceID;
std::string DeviceModel = " ";
std::string DeviceBrand;
std::string DateTime;
std::string Abi;


#if defined(__aarch64__)
std::string armmod = OBFUSCATE("arm64-v8a (64 bit)");
#elif defined(__arm__)
std::string armmod = OBFUSCATE("armeabi-v7a (32 bit)");
#endif


struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    
    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

int ShowSoftKeyboardInput() {
    jint result;
    jint flags = 0;
    
    JNIEnv *env;
    g_vm->AttachCurrentThread(&env, NULL);
    
    jclass looperClass = env->FindClass(OBFUSCATE("android/os/Looper"));
    auto prepareMethod = env->GetStaticMethodID(looperClass, OBFUSCATE("prepare"), OBFUSCATE("()V"));
    env->CallStaticVoidMethod(looperClass, prepareMethod);
    
    jclass activityThreadClass = env->FindClass(OBFUSCATE("android/app/ActivityThread"));
    jfieldID sCurrentActivityThreadField = env->GetStaticFieldID(activityThreadClass, OBFUSCATE("sCurrentActivityThread"), OBFUSCATE("Landroid/app/ActivityThread;"));
    jobject sCurrentActivityThread = env->GetStaticObjectField(activityThreadClass, sCurrentActivityThreadField);
    
    jfieldID mInitialApplicationField = env->GetFieldID(activityThreadClass, OBFUSCATE("mInitialApplication"), OBFUSCATE("Landroid/app/Application;"));
    jobject mInitialApplication = env->GetObjectField(sCurrentActivityThread, mInitialApplicationField);
    
    jclass contextClass = env->FindClass(OBFUSCATE("android/content/Context"));
    jfieldID fieldINPUT_METHOD_SERVICE = env->GetStaticFieldID(contextClass, OBFUSCATE("INPUT_METHOD_SERVICE"), OBFUSCATE("Ljava/lang/String;"));
    jobject INPUT_METHOD_SERVICE = env->GetStaticObjectField(contextClass, fieldINPUT_METHOD_SERVICE);
    jmethodID getSystemServiceMethod = env->GetMethodID(contextClass, OBFUSCATE("getSystemService"), OBFUSCATE("(Ljava/lang/String;)Ljava/lang/Object;"));
    jobject callObjectMethod = env->CallObjectMethod(mInitialApplication, getSystemServiceMethod, INPUT_METHOD_SERVICE);
    
    jclass classInputMethodManager = env->FindClass(OBFUSCATE("android/view/inputmethod/InputMethodManager"));
    jmethodID toggleSoftInputId = env->GetMethodID(classInputMethodManager, OBFUSCATE("toggleSoftInput"), OBFUSCATE("(II)V"));
    
    if (result) {
        env->CallVoidMethod(callObjectMethod, toggleSoftInputId, 2, flags);
    } else {
        env->CallVoidMethod(callObjectMethod, toggleSoftInputId, flags, flags);
    }
    
    env->DeleteLocalRef(classInputMethodManager);
    env->DeleteLocalRef(callObjectMethod);
    env->DeleteLocalRef(contextClass);
    env->DeleteLocalRef(mInitialApplication);
    env->DeleteLocalRef(activityThreadClass);
    g_vm->DetachCurrentThread();
    
    return result;
}

std::string getClipboard() {
    std::string result;
    JNIEnv *env;
    
    g_vm->AttachCurrentThread(&env, NULL);
    
    auto looperClass = env->FindClass(OBFUSCATE("android/os/Looper"));
    auto prepareMethod = env->GetStaticMethodID(looperClass, OBFUSCATE("prepare"), OBFUSCATE("()V"));
    env->CallStaticVoidMethod(looperClass, prepareMethod);
    
    jclass activityThreadClass = env->FindClass(OBFUSCATE("android/app/ActivityThread"));
    jfieldID sCurrentActivityThreadField = env->GetStaticFieldID(activityThreadClass, OBFUSCATE("sCurrentActivityThread"), OBFUSCATE("Landroid/app/ActivityThread;"));
    jobject sCurrentActivityThread = env->GetStaticObjectField(activityThreadClass, sCurrentActivityThreadField);
    
    jfieldID mInitialApplicationField = env->GetFieldID(activityThreadClass, OBFUSCATE("mInitialApplication"), OBFUSCATE("Landroid/app/Application;"));
    jobject mInitialApplication = env->GetObjectField(sCurrentActivityThread, mInitialApplicationField);
    
    auto contextClass = env->FindClass(OBFUSCATE("android/content/Context"));
    auto getSystemServiceMethod = env->GetMethodID(contextClass, OBFUSCATE("getSystemService"), OBFUSCATE("(Ljava/lang/String;)Ljava/lang/Object;"));
    
    auto str = env->NewStringUTF(OBFUSCATE("clipboard"));
    auto clipboardManager = env->CallObjectMethod(mInitialApplication, getSystemServiceMethod, str);
    env->DeleteLocalRef(str);
    
    jclass ClipboardManagerClass = env->FindClass(OBFUSCATE("android/content/ClipboardManager"));
    auto getText = env->GetMethodID(ClipboardManagerClass, OBFUSCATE("getText"), OBFUSCATE("()Ljava/lang/CharSequence;"));

    jclass CharSequenceClass = env->FindClass(OBFUSCATE("java/lang/CharSequence"));
    auto toStringMethod = env->GetMethodID(CharSequenceClass, OBFUSCATE("toString"), OBFUSCATE("()Ljava/lang/String;"));

    auto text = env->CallObjectMethod(clipboardManager, getText);
    if (text) {
        str = (jstring) env->CallObjectMethod(text, toStringMethod);
        result = env->GetStringUTFChars(str, 0);
        env->DeleteLocalRef(str);
        env->DeleteLocalRef(text);
    }
    
    env->DeleteLocalRef(CharSequenceClass);
    env->DeleteLocalRef(ClipboardManagerClass);
    env->DeleteLocalRef(clipboardManager);
    env->DeleteLocalRef(contextClass);
    env->DeleteLocalRef(mInitialApplication);
    env->DeleteLocalRef(activityThreadClass);   
    g_vm->DetachCurrentThread();
    return result.c_str();
}


std::string UKeys;
std::string Login(const char *user_key) {
UKeys = user_key;
    JNIEnv *env;
    g_vm->AttachCurrentThread(&env, 0);
    
    auto looperClass = env->FindClass(OBFUSCATE("android/os/Looper"));
    auto prepareMethod = env->GetStaticMethodID(looperClass, OBFUSCATE("prepare"), OBFUSCATE("()V"));
    env->CallStaticVoidMethod(looperClass, prepareMethod);
    
    jclass activityThreadClass = env->FindClass(OBFUSCATE("android/app/ActivityThread"));
    jfieldID sCurrentActivityThreadField = env->GetStaticFieldID(activityThreadClass, OBFUSCATE("sCurrentActivityThread"), OBFUSCATE("Landroid/app/ActivityThread;"));
    jobject sCurrentActivityThread = env->GetStaticObjectField(activityThreadClass, sCurrentActivityThreadField);
    
    jfieldID mInitialApplicationField = env->GetFieldID(activityThreadClass, OBFUSCATE("mInitialApplication"), OBFUSCATE("Landroid/app/Application;"));
    jobject mInitialApplication = env->GetObjectField(sCurrentActivityThread, mInitialApplicationField);
    
    std::string hwid = user_key;
    hwid += GetAndroidID(env, mInitialApplication);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
    DeviceBrand = GetDeviceBrand(env);
    DeviceModel = GetDeviceModel(env);
    DeviceID = GetAndroidID(env, mInitialApplication);
    g_vm->DetachCurrentThread();
    std::string errMsg;
    
    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;
    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    
    if (curl) {
    
    
    std::string api_key = OBFUSCATE("https://cyberfluxaosphosting.x10.network/connect");
    
   
        curl_easy_setopt(curl, CURLOPT_URL, api_key.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, OBFUSCATE("Content-Type: application/x-www-form-urlencoded"));


        std::string data = "game=MLBB";
		//std::string data = "game=PUBG";

		data += "&user_key=" + std::string(user_key);
		data += "&serial=" + UUID;

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[std::string(OBFUSCATE("status"))] == true) {
                    std::string token = result[std::string(OBFUSCATE("data"))][std::string(OBFUSCATE("token"))].get<std::string>();
                    time_t rng = result[std::string(OBFUSCATE("data"))][std::string(OBFUSCATE("rng"))].get<time_t>();
					
                    if (rng + 30 > time(0)) {
                        std::string auth = OBFUSCATE("MLBB");
                        //std::string auth = OBFUSCATE("PUBG");
                        auth += std::string(OBFUSCATE("-"));
                        auth += user_key;
                        auth += std::string(OBFUSCATE("-"));
                        auth += UUID;
                        auth += std::string(OBFUSCATE("-"));
						auto DATA = std::string{OBFUSCATE_KEY("data", '~')};
						auto EXPIRED = std::string{OBFUSCATE_KEY("EXP", '~')}; 
						expired = result[DATA][EXPIRED].get<std::string>();
					    EXP = result["data"]["EXP"].get<std::string>();
                        auth += std::string(OBFUSCATE("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E"));
                        std::string outputAuth = Tools::CalcMD5(auth);
                        g_Token = token;
                        g_Auth = outputAuth;
                        bValid = g_Token == g_Auth;
                        
                        if (bValid) {
                            bInitDone = true;
                        } else {
                            exit(0);
                        }
                    }
                } else {
                    errMsg = result[std::string(OBFUSCATE("reason"))].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    g_vm->DetachCurrentThread();
    return bValid ? "OK" : errMsg;
}


