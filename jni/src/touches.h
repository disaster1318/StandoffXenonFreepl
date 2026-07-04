#ifndef TOUCHES_H
#define TOUCHES_H

#include "imgui.h"
#include <android/log.h>

#define LOG_TAG "XenonTouch"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

// Заглушка для обработки касаний
namespace touches {
    inline void init() {
        LOGI("Touches initialized");
    }
    
    inline void update() {
        // Здесь будет обработка касаний
    }
}

#endif
