#pragma once
#include "imgui.h"

struct bools_t {
    bool enable_esp = true;
    bool enable_box = true;
    bool enable_line = false;
    bool enable_skeleton = false;
    bool enable_hpbar = true;
    bool enable_name = true;
    bool enable_weapon = true;
    bool enable_distance = false;
    bool enable_head_dot = false;
    bool enable_chams = true;
    bool enable_wallhack = true;
    bool enable_fog = false;
    bool no_recoil = false;
    bool anti_aim = false;
    bool triggerbot = false;
    bool anti_afk = false;
    bool no_flash = false;
    bool crosshair = false;
    bool hit_marker = false;
    bool damage_indicator = false;
    bool fps_counter = false;
    bool ping_display = false;
    bool match_time = false;
    bool hide_hud = false;
};

struct colors_t {
    ImVec4 box_color = ImVec4(1, 0, 0, 1);
    ImVec4 skeleton_visible = ImVec4(0, 1, 0, 1);
    ImVec4 skeleton_invisible = ImVec4(0.5, 0.5, 0.5, 0.5);
    float skyColor[3] = {0.5f, 0.7f, 1.0f};
    float fogColor[3] = {0.5f, 0.5f, 0.5f};
};

struct floats_t {
    float menu_scale = 70.0f;
    float zoom = 1.0f;
    float brightness = 1.0f;
};

struct integers_t {
    int language = 0;
    int theme = 0;
    int tab_position = 0;
};

struct cvars {
    bools_t bools;
    colors_t colors;
    floats_t floats;
    integers_t integers;
};

extern const char* languages[];
extern const char* themes[];
extern const char* tab_positions[];
