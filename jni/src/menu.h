#ifndef MENU_H
#define MENU_H

#include <stdbool.h>

// Инициализация меню
void initMenu();

// Отрисовка меню
void renderMenu();

// Свернуть/развернуть меню
void toggleMenu();

// Проверка видимости меню
bool isMenuVisible();
void setMenuVisible(bool visible);

// Текущая вкладка
int getCurrentTab();
void setCurrentTab(int tab);

// Размер меню (масштаб)
float getMenuScale();
void setMenuScale(float scale);

// Положение вкладок (0-сверху, 1-снизу, 2-слева, 3-справа)
int getTabPosition();
void setTabPosition(int pos);

// Вспомогательные функции отрисовки
void drawBackground();
void drawHeader();
void drawTabBar();
void drawTabContent(int tab);
void drawToggle(float x, float y, const char* label, bool* value);
void drawSlider(float x, float y, const char* label, float* value, float min, float max);
void drawMinimizedIcon();

#endif
