#include <dobby/dobby.h>
#include "Tools/Tools.h"
#include <android/log.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <cstddef>
#include <jni.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <inttypes.h>
#include <sys/uio.h>




#define LOGD(...) ((void)__android_log_print(3, TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(6, TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(4, TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(5, TAG, __VA_ARGS__))

typedef unsigned long DWORD;

// ==================================================================================================================================== //
bool SetProtRWX(void *addr) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    void *p = (void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size);

    return mprotect(p, (size_t) size, PROT_READ | PROT_WRITE | PROT_EXEC) == 0;
}

void HookFunc(void *address, void *replace, void **backup) {
    if (SetProtRWX(address)) {
        Tools::Hook(address, replace, backup);
    }
}

void WriteAddr(void *address, void *buf, size_t size) {
    if (SetProtRWX(address)) {
        memcpy(address, buf, size);
    }
}
// ==================================================================================================================================== //
#define DefineHook(RET, NAME, ARGS) \
    RET (*o ## NAME) ARGS; \
    RET NAME ARGS

