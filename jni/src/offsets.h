#ifndef OFFSETS_H
#define OFFSETS_H

#include <cstddef>

namespace offsets {
    // IL2CPP
    constexpr ::std::ptrdiff_t String$$CreateString = 0x3FA355C;
    constexpr ::std::ptrdiff_t il2cpp_domain_get_offsets = 0x21368EC;
    constexpr ::std::ptrdiff_t il2cpp_class_from_name_offsets = 0x2136770;
    constexpr ::std::ptrdiff_t il2cpp_class_get_methods_offsets = 0x21367F0;
    constexpr ::std::ptrdiff_t il2cpp_thread_attach = 0x2136D38;
    constexpr ::std::ptrdiff_t il2cpp_thread_detach = 0x2136D3C;
    constexpr ::std::ptrdiff_t mono_domain_get_assemblies_offsets = 0x2136F48;
    constexpr ::std::ptrdiff_t il2cpp_object_new = 0x2136CB0;
    constexpr ::std::ptrdiff_t il2cpp_image_get_class = 0x2112194;
    constexpr ::std::ptrdiff_t il2cpp_image_get_class_obj = 0x2110818;

    // Player
    constexpr ::std::ptrdiff_t playerControls_TypeInfo = 14;
    constexpr ::std::ptrdiff_t PlayerControls$$GetInputs = 18;
    constexpr ::std::ptrdiff_t PlayerControls$$SetInputs = 19;
    constexpr ::std::ptrdiff_t get_playerList = 0x23E3400;
    constexpr ::std::ptrdiff_t GetTrPlayersCount = 0x25FC148;
    constexpr ::std::ptrdiff_t GetCtPlayersCount = 0x25FBD38;
    constexpr ::std::ptrdiff_t GetPlayerWithId = 0x26BF7C8;
    constexpr ::std::ptrdiff_t SelectedCt = 0x25CAEA8;
    constexpr ::std::ptrdiff_t SelectedTr = 0x25CAE0C;

    // Health & Money
    constexpr ::std::ptrdiff_t PhotonPlayerGameExtension$$SetMoney1 = 20;
    constexpr ::std::ptrdiff_t PhotonPlayerGameExtension$$GetMoney1 = 21;
    constexpr ::std::ptrdiff_t PhotonPlayerGameExtension$$AddKill = 22;
    constexpr ::std::ptrdiff_t SetHealth = 0x27A1228;

    // Camera & World
    constexpr ::std::ptrdiff_t CAMERA$$GET_FIELDOFVIEW = 0x497CD64;
    constexpr ::std::ptrdiff_t TRANSFORM$$GET_ROTATION = 0x49B7BA0;
    constexpr ::std::ptrdiff_t GET_WIDTH = 0x4987400;
    constexpr ::std::ptrdiff_t GET_HEIGHT = 0x4987428;
    constexpr ::std::ptrdiff_t render_settings = 0x9ABD24;
    constexpr ::std::ptrdiff_t render_settings2 = 0x9B0CC4;
    constexpr ::std::ptrdiff_t currentSpeedXZ = 0x2393B8C;

    // Aim
    constexpr ::std::ptrdiff_t AimController$$ApplyRotation = 27;
    constexpr ::std::ptrdiff_t _AngleAxis = 0x5388C50;

    // Weapon
    constexpr ::std::ptrdiff_t isFiring = 0x23AC89C;
    constexpr ::std::ptrdiff_t PlayerSoundController$$IsLoudShooting = 0x22398AC;
    constexpr ::std::ptrdiff_t WeaponDropManager_TypeInfo = 0x514AEC8;

    // Network
    constexpr ::std::ptrdiff_t PhotonNetwork$$get_time = 0x23E3AF8;
    constexpr ::std::ptrdiff_t GetRoom = 0x23E5AB8;
    constexpr ::std::ptrdiff_t GetGameStateId = 0x282E9A0;
    constexpr ::std::ptrdiff_t get_roundsCount = 0x282FEE0;
    constexpr ::std::ptrdiff_t GetWarmUp = 0x225B550;

    // Misc
    constexpr ::std::ptrdiff_t Input$$GetTouch = 0x49FBCB0;
    constexpr ::std::ptrdiff_t DelegateTouchCountHook = 0x538A2F8;
    constexpr ::std::ptrdiff_t IsGrounded = 0x538A7C0;
    constexpr ::std::ptrdiff_t SetTime = 0x282D9BC;
    constexpr ::std::ptrdiff_t GetExtension = 0x30CCCB4;

    // Occlusion / Bypass
    constexpr ::std::ptrdiff_t OCCLUSIONCONTROL$$SETIGNORERAYCASTING = 0x26A1BD0;
    constexpr ::std::ptrdiff_t func_objectocclude_bool = 0x510A890;
    constexpr ::std::ptrdiff_t GetOcclusionControl = 0x513CA08;
}

// Твои старые оффсеты (оставляем для совместимости)
#define MOVEMENT_CONTROLLER 0x98
#define PLAYER_HIT_CONTROLLER 0xA8
#define CAMERA 0xE8
#define PHOTON_PLAYER 0x160
#define AIM_CONTROLLER 0x80
#define WEAPON 0x88
#define TRANSFORM 0x70
#define POSITION 0x24
#define HEALTH 0x20
#define TEAM 0x70
#define VIEW_DIRECTION 0x224
#define CAMERA_POSITION 0x18
#define FOV 0x30
#define PLAYER_SIZE 0x100
#define IS_VISIBLE 0x18
#define LOCAL_PLAYER 0x70
#define PLAYER_LIST 0x28
#define VIEW_MATRIX_A 0xE8
#define VIEW_MATRIX_B 0x28
#define VIEW_MATRIX_C 0x38
#define RECOIL_1 0x18
#define RECOIL_2 0x1C
#define RECOIL_3 0x20
#define RECOIL_4 0x24
#define RECOIL_5 0x28
#define RECOIL_6 0x2C
#define FOG_COLOR 0x60
#define SKYBOX_OVERRIDE 0x70

#endif
