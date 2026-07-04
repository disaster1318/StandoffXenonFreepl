#pragma once
#include "imgui.h"
#include "imgui_internal.h"

struct scale_t {
    float current_scale = 1.0f;
    inline float get(float value) { return value * current_scale; }
};

struct utils_t {
    ImColor get_accent_imc(float alpha = 1.0f);
    ImVec4 get_accent_imv4(float alpha = 1.0f, float brightness = 1.0f);
    float* get_accent_imv4_ptr();
    ImVec4 process_alpha(ImVec4 col, float alpha);
};

inline scale_t* c_scale = new scale_t();
inline utils_t* c_utils = new utils_t();
