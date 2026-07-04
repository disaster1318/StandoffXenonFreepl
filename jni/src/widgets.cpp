#include "widgets.hpp"

namespace widgets {

bool toggle(const char* name, bool* v) {
    return ImGui::Checkbox(name, v);
}

bool slider_float(const char* name, float* v, float mn, float mx, const char* fmt) {
    return ImGui::SliderFloat(name, v, mn, mx, fmt);
}

bool combo(const char* name, int* v, const std::vector<const char*>& items) {
    return ImGui::Combo(name, v, items.data(), items.size());
}

bool combo(const char* name, int* v, const char* items[], int count) {
    return ImGui::Combo(name, v, items, count);
}

void color_edit_4(const char* name, float* v) {
    ImGui::ColorEdit4(name, v);
}

bool button(const char* name, std::function<void()> on_click) {
    if (ImGui::Button(name)) {
        if (on_click) on_click();
        return true;
    }
    return false;
}

}
