#include "esp.h"
#include "utils.h"
#include "offsets.h"
#include <GLES2/gl2.h>
#include <math.h>
#include <stdio.h>

bool espEnabled = true;
bool boxEnabled = true;
bool snapLineEnabled = false;
bool skeletonEnabled = false;
bool healthBarEnabled = true;
bool nicknameEnabled = true;
bool weaponEnabled = true;
bool avatarEnabled = false;
bool chamsEnabled = true;
bool glassChams = false;
float chamsIntensity = 2.6f;
bool wallhackEnabled = true;
bool distanceEnabled = false;
bool headDotEnabled = false;
bool tracersEnabled = false;
bool soundEspEnabled = false;

static float color[3] = {1.0f, 0.0f, 0.0f};

void renderESP() {
    if (!espEnabled) return;
    
    uintptr_t localPlayer = getLocalPlayer();
    if (!localPlayer) return;
    
    uintptr_t playerList = getPlayerList();
    if (!playerList) return;
    
    float viewMatrix[16];
    getViewMatrix(viewMatrix);
    
    int playerCount = getPlayerCount();
    if (playerCount <= 0) return;
    
    float localPos[3];
    getPlayerPosition(localPlayer, localPos);
    
    for (int i = 0; i < playerCount; i++) {
        uintptr_t player = getPlayerFromList(playerList, i);
        if (!player || player == localPlayer) continue;
        
        float pos[3];
        getPlayerPosition(player, pos);
        
        float screen[2];
        if (!worldToScreen(pos, screen, viewMatrix)) continue;
        
        float health = getPlayerHealth(player);
        float maxHealth = 100.0f;
        
        float boxHeight = 1.0f / screen[1] * 200.0f;
        float boxWidth = boxHeight * 0.4f;
        float x = screen[0] - boxWidth / 2;
        float y = screen[1] - boxHeight;
        
        // Box
        if (boxEnabled) {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(color[0], color[1], color[2], 0.8f);
            glLineWidth(1.5f);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x, y);
            glVertex2f(x + boxWidth, y);
            glVertex2f(x + boxWidth, y + boxHeight);
            glVertex2f(x, y + boxHeight);
            glEnd();
            glDisable(GL_BLEND);
        }
        
        // Snap Line
        if (snapLineEnabled) {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
            glLineWidth(1.0f);
            glBegin(GL_LINES);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(screen[0], screen[1]);
            glEnd();
            glDisable(GL_BLEND);
        }
        
        // Health Bar
        if (healthBarEnabled) {
            float ratio = health / maxHealth;
            float hw = 30.0f;
            float hh = 3.0f;
            float r = 1.0f - ratio;
            float g = ratio;
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
            glBegin(GL_QUADS);
            glVertex2f(x, y - 10.0f);
            glVertex2f(x + hw, y - 10.0f);
            glVertex2f(x + hw, y - 10.0f + hh);
            glVertex2f(x, y - 10.0f + hh);
            glEnd();
            glColor4f(r, g, 0.0f, 1.0f);
            glBegin(GL_QUADS);
            glVertex2f(x, y - 10.0f);
            glVertex2f(x + hw * ratio, y - 10.0f);
            glVertex2f(x + hw * ratio, y - 10.0f + hh);
            glVertex2f(x, y - 10.0f + hh);
            glEnd();
            glDisable(GL_BLEND);
        }
        
        // Distance
        if (distanceEnabled) {
            float dist = getDistance(localPlayer, player);
            char text[16];
            snprintf(text, sizeof(text), "%.0fm", dist);
            // Заглушка для текста
        }
    }
}

void drawPlayerBox(float x, float y, float w, float h, float color[3]) {
    // Реализация в renderESP
}

void drawSnapLine(float x, float y, float color[3]) {
    // Реализация в renderESP
}

void drawHealthBar(float x, float y, float health, float maxHealth) {
    // Реализация в renderESP
}

void drawNickname(float x, float y, const char* name) {
    // Заглушка
}

void drawWeapon(float x, float y, const char* weapon) {
    // Заглушка
}

void drawChams(void* player, float color[3], bool glass) {
    // Заглушка
}

void drawDistance(float x, float y, float dist) {
    // Заглушка
}

void drawHeadDot(float x, float y, float color[3]) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(color[0], color[1], color[2], 1.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glDisable(GL_BLEND);
}
