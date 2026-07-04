#pragma once
#include "imgui.h"
#include <vector>
#include <functional>

namespace widgets {
    bool toggle(const char* name, bool* v);
    bool slider_float(const char* name, float* v, float mn, float mx, const char* fmt = "%.1f");
    bool combo(const char* name, int* v, const std::vector<const char*>& items);
    bool combo(const char* name, int* v, const char* items[], int count);
    void color_edit_4(const char* name, float* v);
    bool button(const char* name, std::function<void()> on_click = nullptr);
}
