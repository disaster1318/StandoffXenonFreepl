#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"
#include "util.hpp"
#include "vars.h"
#include <string>
#include <vector>
#include "notifications.hpp"

struct fonts_t {
    ImFont* regular;
    ImFont* bold;
    ImFont* big_and_bold;
    ImFont* logo;
};

struct tab_t {
    const char* name;
    int default_sub;
};

struct subtab_t {
    const char* name;
    int parent;
};

class custom_interface_t {
private:
    int current_tab{};
    int current_subtab{};
    std::vector<tab_t> tabs{};
    std::vector<subtab_t> subtabs{};
    fonts_t fonts{};
public:
    void render(void *vars);
    void initialize();
    void initialize_fonts();
};

inline custom_interface_t* c_ui = new custom_interface_t();
