#include "util.hpp"

ImColor utils_t::get_accent_imc(float alpha) {
    return ImColor(0, 200, 255, (int)(alpha * 255));
}

ImVec4 utils_t::get_accent_imv4(float alpha, float brightness) {
    return ImVec4(0.0f, 0.8f * brightness, 1.0f, alpha);
}

float* utils_t::get_accent_imv4_ptr() {
    static ImVec4 color = ImVec4(0.0f, 0.8f, 1.0f, 1.0f);
    return &color.x;
}

ImVec4 utils_t::process_alpha(ImVec4 col, float alpha) {
    col.w *= alpha;
    return col;
}
