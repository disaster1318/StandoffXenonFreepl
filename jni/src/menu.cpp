#include "menu.h"
#include "utils.h"
#include "offsets.h"
#include "esp.h"
#include "features.h"
#include "world.h"
#include "config.h"
#include <GLES2/gl2.h>
#include <string.h>

static bool menuVisible = true;
static bool isExpanded = true;
static int currentTab = 0;
static float menuScale = 0.7f;
static int tabPosition = 0; // 0-top, 1-bottom, 2-left, 3-right
static float animTime = 0.0f;

// Переменные для настроек (временные, позже будут из config)
static bool espEnabled = true;
static bool boxEnabled = true;
static bool snapLineEnabled = false;
static bool skeletonEnabled = false;
static bool healthBarEnabled = true;
static bool nicknameEnabled = true;
static bool weaponEnabled = true;
static bool avatarEnabled = false;
static bool chamsEnabled = true;
static bool glassChams = false;
static float chamsIntensity = 2.6f;
static bool wallhackEnabled = true;
static bool distanceEnabled = false;
static bool headDotEnabled = false;
static bool tracersEnabled = false;
static bool soundEspEnabled = false;

static bool fogEnabled = false;
static float skyColor[3] = {0.5f, 0.7f, 1.0f};
static float fogColor[3] = {0.5f, 0.5f, 0.5f};
static float worldColor[3] = {1.0f, 1.0f, 1.0f};
static int timeMode = 0;

static bool noRecoilEnabled = false;
static bool headshotSoundEnabled = false;
static bool antiAimEnabled = false;
static int antiAimMode = 0;
static float spinSpeed = 2.0f;
static bool triggerbotEnabled = false;
static float triggerbotDelay = 0.1f;
static bool antiAFKEnabled = false;
static bool screenshotCleanerEnabled = false;
static bool autoWallbangEnabled = false;
static bool noFlashEnabled = false;
static bool radarHackEnabled = false;

// Языки
static int currentLanguage = 0;
static const char* languages[] = {"Русский", "English", "中文", "Türkçe", "Español"};
static const int languageCount = 5;

// Темы
static int currentTheme = 0;
static const char* themes[] = {"Синяя", "Красная", "Зелёная", "Фиолетовая", "Белая"};
static const int themeCount = 5;

void initMenu() {
    menuVisible = true;
    isExpanded = true;
    currentTab = 0;
    animTime = 0.0f;
}

void toggleMenu() {
    isExpanded = !isExpanded;
}

bool isMenuVisible() { return menuVisible; }
void setMenuVisible(bool visible) { menuVisible = visible; }
int getCurrentTab() { return currentTab; }
void setCurrentTab(int tab) { currentTab = tab; }
float getMenuScale() { return menuScale; }
void setMenuScale(float scale) { menuScale = scale; }
int getTabPosition() { return tabPosition; }
void setTabPosition(int pos) { tabPosition = pos; }

void drawBackground() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.05f, 0.05f, 0.1f, 0.88f);
    float w = 0.8f;
    float h = 0.6f;
    glBegin(GL_QUADS);
    glVertex2f(-w/2, -h/2);
    glVertex2f(w/2, -h/2);
    glVertex2f(w/2, h/2);
    glVertex2f(-w/2, h/2);
    glEnd();
    glDisable(GL_BLEND);
}

void drawHeader() {
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    // Заголовок XENON
    // Кнопка свёртки
    glColor4f(0.5f, 0.5f, 0.5f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.33f, 0.25f);
    glVertex2f(0.33f, 0.22f);
    glVertex2f(0.3f, 0.22f);
    glEnd();
}

void drawTabBar() {
    const char* icons[] = {"ESP", "WORLD", "ДОП", "ВИЗУАЛ", "ИНТЕРФЕЙС", "НАСТР"};
    const int count = 6;
    float startX = -0.35f;
    float y = 0.25f;
    float step = 0.12f;
    
    for (int i = 0; i < count; i++) {
        float x = startX + i * step;
        if (i == currentTab) {
            glColor4f(0.0f, 0.8f, 1.0f, 1.0f);
        } else {
            glColor4f(0.6f, 0.6f, 0.6f, 0.8f);
        }
        glBegin(GL_QUADS);
        glVertex2f(x - 0.025f, y - 0.025f);
        glVertex2f(x + 0.025f, y - 0.025f);
        glVertex2f(x + 0.025f, y + 0.025f);
        glVertex2f(x - 0.025f, y + 0.025f);
        glEnd();
    }
}

void drawToggle(float x, float y, const char* label, bool* value) {
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    float size = 0.02f;
    if (*value) {
        glColor4f(0.0f, 0.8f, 1.0f, 1.0f);
    } else {
        glColor4f(0.3f, 0.3f, 0.3f, 1.0f);
    }
    glBegin(GL_QUADS);
    glVertex2f(x + 0.25f, y - size);
    glVertex2f(x + 0.25f + 0.05f, y - size);
    glVertex2f(x + 0.25f + 0.05f, y + size);
    glVertex2f(x + 0.25f, y + size);
    glEnd();
}

void drawSlider(float x, float y, const char* label, float* value, float min, float max) {
    // Простой ползунок (заглушка)
    glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.25f, y - 0.015f);
    glVertex2f(x + 0.45f, y - 0.015f);
    glVertex2f(x + 0.45f, y + 0.015f);
    glVertex2f(x + 0.25f, y + 0.015f);
    glEnd();
    float ratio = (*value - min) / (max - min);
    glColor4f(0.0f, 0.8f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x + 0.25f, y - 0.015f);
    glVertex2f(x + 0.25f + 0.2f * ratio, y - 0.015f);
    glVertex2f(x + 0.25f + 0.2f * ratio, y + 0.015f);
    glVertex2f(x + 0.25f, y + 0.015f);
    glEnd();
}

void drawMinimizedIcon() {
    // Иконка X при свёрнутом меню
    glColor4f(1.0f, 1.0f, 1.0f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.04f, -0.03f);
    glVertex2f(0.04f, -0.03f);
    glVertex2f(0.04f, 0.03f);
    glVertex2f(-0.04f, 0.03f);
    glEnd();
}

void drawTabContent(int tab) {
    float yStart = 0.15f;
    float step = -0.045f;
    float x = -0.3f;
    
    switch(tab) {
        case 0: // ESP
            drawToggle(x, yStart, "ESP", &espEnabled);
            drawToggle(x, yStart + step, "Box", &boxEnabled);
            drawToggle(x, yStart + step*2, "Snap Line", &snapLineEnabled);
            drawToggle(x, yStart + step*3, "Skeleton", &skeletonEnabled);
            drawToggle(x, yStart + step*4, "Health Bar", &healthBarEnabled);
            drawToggle(x, yStart + step*5, "Nickname", &nicknameEnabled);
            drawToggle(x, yStart + step*6, "Weapon", &weaponEnabled);
            drawToggle(x, yStart + step*7, "Chams", &chamsEnabled);
            drawToggle(x, yStart + step*8, "Glass", &glassChams);
            drawSlider(x, yStart + step*9, "Intensity", &chamsIntensity, 0.0f, 5.0f);
            drawToggle(x, yStart + step*10, "Wallhack", &wallhackEnabled);
            drawToggle(x, yStart + step*11, "Distance", &distanceEnabled);
            drawToggle(x, yStart + step*12, "Head Dot", &headDotEnabled);
            break;
        case 1: // WORLD
            drawToggle(x, yStart, "Fog", &fogEnabled);
            drawSlider(x, yStart + step*2, "Sky R", &skyColor[0], 0.0f, 1.0f);
            drawSlider(x, yStart + step*3, "Sky G", &skyColor[1], 0.0f, 1.0f);
            drawSlider(x, yStart + step*4, "Sky B", &skyColor[2], 0.0f, 1.0f);
            drawSlider(x, yStart + step*5, "Fog R", &fogColor[0], 0.0f, 1.0f);
            drawSlider(x, yStart + step*6, "Fog G", &fogColor[1], 0.0f, 1.0f);
            drawSlider(x, yStart + step*7, "Fog B", &fogColor[2], 0.0f, 1.0f);
            drawSlider(x, yStart + step*8, "World R", &worldColor[0], 0.0f, 1.0f);
            drawSlider(x, yStart + step*9, "World G", &worldColor[1], 0.0f, 1.0f);
            drawSlider(x, yStart + step*10, "World B", &worldColor[2], 0.0f, 1.0f);
            break;
        case 2: // ДОП
            drawToggle(x, yStart, "No Recoil", &noRecoilEnabled);
            drawToggle(x, yStart + step, "Headshot Sound", &headshotSoundEnabled);
            drawToggle(x, yStart + step*2, "Anti-Aim", &antiAimEnabled);
            drawToggle(x, yStart + step*3, "Triggerbot", &triggerbotEnabled);
            drawToggle(x, yStart + step*4, "Anti-AFK", &antiAFKEnabled);
            drawToggle(x, yStart + step*5, "No Flash", &noFlashEnabled);
            drawToggle(x, yStart + step*6, "Radar Hack", &radarHackEnabled);
            break;
        case 3: // ВИЗУАЛ
            drawToggle(x, yStart, "Crosshair", &espEnabled);
            drawToggle(x, yStart + step, "Hit Marker", &snapLineEnabled);
            drawToggle(x, yStart + step*2, "Damage Indicator", &healthBarEnabled);
            drawToggle(x, yStart + step*3, "Zoom", &nicknameEnabled);
            drawToggle(x, yStart + step*4, "Brightness", &weaponEnabled);
            drawToggle(x, yStart + step*5, "Anti-Flash", &chamsEnabled);
            break;
        case 4: // ИНТЕРФЕЙС
            drawToggle(x, yStart, "FPS Counter", &wallhackEnabled);
            drawToggle(x, yStart + step, "Ping Display", &distanceEnabled);
            drawToggle(x, yStart + step*2, "Match Time", &headDotEnabled);
            drawToggle(x, yStart + step*3, "Hide HUD", &tracersEnabled);
            break;
        case 5: // НАСТР
            // Язык, тема, размер, положение вкладок
            drawToggle(x, yStart, "Show FOV", &espEnabled);
            break;
    }
}

void renderMenu() {
    if (!menuVisible) return;
    if (!isExpanded) {
        drawMinimizedIcon();
        return;
    }
    glPushMatrix();
    float centerX = 0.0f;
    float centerY = 0.0f;
    glTranslatef(centerX, centerY, 0.0f);
    glScalef(menuScale, menuScale, 1.0f);
    drawBackground();
    drawHeader();
    drawTabBar();
    drawTabContent(currentTab);
    glPopMatrix();
}
