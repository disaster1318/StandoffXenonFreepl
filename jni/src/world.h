#ifndef WORLD_H
#define WORLD_H

#include <stdbool.h>

extern bool fogEnabled;
extern float skyColor[3];
extern float fogColor[3];
extern float worldColor[3];
extern int timeMode;

void applyWorldChanges();
void setSkyColor(float r, float g, float b);
void setFogColor(float r, float g, float b);
void setWorldColor(float r, float g, float b);
void setTimeMode(int mode);

#endif
