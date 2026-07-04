#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

template<typename T>
T readMemory(void* address) {
    if (address == nullptr) return T();
    return *reinterpret_cast<T*>(address);
}

template<typename T>
void writeMemory(void* address, T value) {
    if (address == nullptr) return;
    *reinterpret_cast<T*>(address) = value;
}

uintptr_t followPointerChain(uintptr_t base, int offsets[], int count);
uintptr_t getBaseAddress();
bool worldToScreen(float* worldPos, float* screenPos, float* viewMatrix);
bool isPlayerValid(uintptr_t player);
float getDistance3D(float* pos1, float* pos2);

// Декларации функций из main.cpp
int getLocalPlayer();
uintptr_t getPlayerList();
int getPlayerCount();
uintptr_t getPlayerFromList(uintptr_t list, int index);
void getPlayerPosition(uintptr_t player, float* pos);
float getPlayerHealth(uintptr_t player);
const char* getPlayerName(uintptr_t player);
const char* getPlayerWeapon(uintptr_t player);
float getDistance(uintptr_t local, uintptr_t player);
void getViewMatrix(float* matrix);
uintptr_t getWorldPtr();

#endif
