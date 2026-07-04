#ifndef GUI_H
#define GUI_H

#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_opengl3.h"

#include "menu.h"
#include "esp.h"
#include "touches.h"

namespace fonts {
    extern ImFont* SFPro_font;
    extern ImFont* pixel_font;
    extern ImFont* tahoma;
}

namespace menu {
    extern void* _cheat;
    void init(void* cheat);
}

#endif
