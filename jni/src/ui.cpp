#include "ui.hpp"
#include "widgets.hpp"
#include "util.hpp"
#include "config.h"
#include "esp.h"
#include "features.h"
#include "world.h"

using namespace ImGui;

void custom_interface_t::initialize() {
    auto& style = GetStyle();
    auto& col = GetStyle().Colors;

    style.ScrollbarSize = 6;
    style.ScrollbarRounding = 3;
    style.FrameRounding = 4;
    style.WindowRounding = 6;
    style.WindowBorderSize = 0;
    style.ItemSpacing = { 10, 10 };
    style.WindowMinSize = { 2, 2 };

    col[ImGuiCol_Border] = ImColor(28, 28, 28).Value;
    col[ImGuiCol_WindowBg] = ImColor(16, 16, 16).Value;
    col[ImGuiCol_ChildBg] = { 0, 0, 0, 0 };
    col[ImGuiCol_ScrollbarBg] = ImColor(10, 10, 10).Value;

    c_scale->current_scale = 2.f;
    style.ScaleAllSizes(c_scale->current_scale);
}

void custom_interface_t::initialize_fonts() {
    auto& io = GetIO();
    this->fonts.regular = io.Fonts->AddFontDefault();
    this->fonts.bold = io.Fonts->AddFontDefault();
    this->fonts.big_and_bold = io.Fonts->AddFontDefault();
    this->fonts.logo = io.Fonts->AddFontDefault();
    io.Fonts->Build();
}

void custom_interface_t::render(void *_vars) {
    cvars *vars = (cvars *)_vars;
    static bool isExpanded = true;
    static int currentTab = 0;

    PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });

    if (!isExpanded) {
        SetNextWindowSize({ 60, 60 });
        Begin("XenonMini", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus);
        SetCursorPos(ImVec2(20, 20));
        Text("X");
        End();
        PopStyleVar();
        return;
    }

    SetNextWindowSize({ 600, 400 }, ImGuiCond_FirstUseEver);
    Begin("Xenon", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus);

    auto draw = GetWindowDrawList();
    auto pos = GetWindowPos();

    draw->AddText(ImVec2(pos.x + 15, pos.y + 10), ImColor(0, 200, 255), "X");
    draw->AddText(ImVec2(pos.x + 40, pos.y + 14), ImColor(255, 255, 255), "@xenonst2");

    SetCursorPos(ImVec2(GetWindowSize().x - 50, 10));
    if (Button("-")) {
        isExpanded = !isExpanded;
    }

    SetCursorPos(ImVec2(10, 50));

    const char* icons[] = {"👁", "🌍", "⚡", "🎨", "🖥", "⚙"};
    int tabCount = 6;
    float tabWidth = 50.0f;

    for (int i = 0; i < tabCount; i++) {
        if (i > 0) SameLine();
        if (Selectable(icons[i], currentTab == i, ImGuiSelectableFlags_None, ImVec2(tabWidth, 40))) {
            currentTab = i;
        }
    }

    Separator();

    BeginChild("##content", ImVec2(0, 0), false);
    {
        switch (currentTab) {
            case 0:
                widgets::toggle("Enable ESP", &vars->bools.enable_esp);
                widgets::toggle("Box", &vars->bools.enable_box);
                widgets::toggle("Snap Line", &vars->bools.enable_line);
                widgets::toggle("Skeleton", &vars->bools.enable_skeleton);
                widgets::toggle("Health Bar", &vars->bools.enable_hpbar);
                widgets::toggle("Nickname", &vars->bools.enable_name);
                widgets::toggle("Weapon", &vars->bools.enable_weapon);
                widgets::toggle("Distance", &vars->bools.enable_distance);
                widgets::toggle("Head Dot", &vars->bools.enable_head_dot);
                widgets::toggle("Chams", &vars->bools.enable_chams);
                widgets::toggle("Wallhack", &vars->bools.enable_wallhack);
                break;
            case 1:
                widgets::toggle("Fog", &vars->bools.enable_fog);
                widgets::slider_float("Sky R", &vars->colors.skyColor[0], 0, 1);
                widgets::slider_float("Sky G", &vars->colors.skyColor[1], 0, 1);
                widgets::slider_float("Sky B", &vars->colors.skyColor[2], 0, 1);
                widgets::slider_float("Fog R", &vars->colors.fogColor[0], 0, 1);
                widgets::slider_float("Fog G", &vars->colors.fogColor[1], 0, 1);
                widgets::slider_float("Fog B", &vars->colors.fogColor[2], 0, 1);
                break;
            case 2:
                widgets::toggle("No Recoil", &vars->bools.no_recoil);
                widgets::toggle("Anti-Aim", &vars->bools.anti_aim);
                widgets::toggle("Triggerbot", &vars->bools.triggerbot);
                widgets::toggle("Anti-AFK", &vars->bools.anti_afk);
                widgets::toggle("No Flash", &vars->bools.no_flash);
                break;
            case 3:
                widgets::toggle("Crosshair", &vars->bools.crosshair);
                widgets::toggle("Hit Marker", &vars->bools.hit_marker);
                widgets::toggle("Damage Indicator", &vars->bools.damage_indicator);
                widgets::slider_float("Zoom", &vars->floats.zoom, 1, 4);
                widgets::slider_float("Brightness", &vars->floats.brightness, 0.5, 2);
                break;
            case 4:
                widgets::toggle("FPS Counter", &vars->bools.fps_counter);
                widgets::toggle("Ping Display", &vars->bools.ping_display);
                widgets::toggle("Match Time", &vars->bools.match_time);
                widgets::toggle("Hide HUD", &vars->bools.hide_hud);
                break;
            case 5:
                widgets::combo("Language", &vars->integers.language, languages, 5);
                widgets::combo("Theme", &vars->integers.theme, themes, 5);
                widgets::slider_float("Menu Size", &vars->floats.menu_scale, 50, 100);
                widgets::combo("Tab Position", &vars->integers.tab_position, tabPositions, 4);
                if (widgets::button("Save Config")) { saveConfig(); }
                if (widgets::button("Load Config")) { loadConfig(); }
                if (widgets::button("Reset Config")) { resetConfig(); }
                break;
        }
    }
    EndChild();

    End();
    PopStyleVar();
}
