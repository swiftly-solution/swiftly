#ifndef _swiftly_player_weapon_h
#define _swiftly_player_weapon_h

#include <stdint.h>
#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../types.h"
#include "../swiftly_utils.h"

typedef void (*Player_RemoveWeapon)(uint32_t, uint32_t);
typedef void (*Player_DropWeapon)(uint32_t, uint32_t);

typedef void (*Player_SetStatTrack)(uint32_t, uint32_t, bool);
typedef void (*Player_SetWear)(uint32_t, uint32_t, float);
typedef void (*Player_SetPaintKit)(uint32_t, uint32_t, int);
typedef void (*Player_SetSeed)(uint32_t, uint32_t, int);
typedef void (*Player_SetSticker)(uint32_t, uint32_t, int, uint32_t);

typedef bool (*Player_GetStatTrack)(uint32_t, uint32_t);
typedef float (*Player_GetWear)(uint32_t, uint32_t);
typedef int (*Player_GetPaintKit)(uint32_t, uint32_t);
typedef int (*Player_GetSeed)(uint32_t, uint32_t);

typedef bool (*Player_WeaponExists)(uint32_t, uint32_t);

typedef WeaponSlot (*Player_GetType)(uint32_t, uint32_t);

typedef const char *(*Player_GetWeaponName)(uint32_t, uint32_t);

typedef void (*Player_SetNametag)(uint32_t, uint32_t, const char *);

typedef void (*Player_SetClipAmmo)(uint32_t, uint32_t, int);
typedef void (*Player_SetReserveAmmo)(uint32_t, uint32_t, int);

typedef int32_t (*Player_Weapon_GetAttackTick)(uint32_t, uint32_t);
typedef void (*Player_Weapon_SetAttackTick)(uint32_t, uint32_t, int32_t);

typedef float (*Player_Weapon_GetAttackTickRatio)(uint32_t, uint32_t);
typedef void (*Player_Weapon_SetAttackTickRatio)(uint32_t, uint32_t, float);

typedef WeaponSilencerType (*Player_Weapon_GetSilencerType)(uint32_t, uint32_t);

class Weapon
{
private:
    uint32_t m_playerSlot;
    uint32_t m_weaponID;

public:
    Weapon(uint32_t playerSlot, uint32_t weaponID) : m_playerSlot(playerSlot), m_weaponID(weaponID) {}

    void Remove()
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_Remove, this->m_playerSlot, this->m_weaponID);
    }
    void Drop()
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_Drop, this->m_playerSlot, this->m_weaponID);
    }

    void SetStatTrack(bool stattrack)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetStatTrack, this->m_playerSlot, this->m_weaponID, stattrack);
    }
    void SetWear(float wear)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetWear, this->m_playerSlot, this->m_weaponID, wear);
    }
    void SetSticker(int stickerslot, uint32_t stickerid)
    {
        REGISTER_METHOD(scripting_Player_Weapon_SetSticker, this->m_playerSlot, this->m_weaponID, stickerslot, stickerid)
    }
    void SetPaintKit(int32_t paintkit)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetPaintKit, this->m_playerSlot, this->m_weaponID, paintkit);
    }
    void SetSeed(int32_t seed)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetSeed, this->m_playerSlot, this->m_weaponID, seed);
    }

    bool GetStatTrack()
    {
        REGISTER_METHOD(bool, false, scripting_Player_Weapon_GetStatTrack, this->m_playerSlot, this->m_weaponID);
    }
    float GetWear()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_Weapon_GetWear, this->m_playerSlot, this->m_weaponID);
    }
    int32_t GetPaintKit()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_Weapon_GetPaintKit, this->m_playerSlot, this->m_weaponID);
    }

    int32_t GetSeed()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_Weapon_GetSeed, this->m_playerSlot, this->m_weaponID);
    }

    WeaponSlot GetType()
    {
        REGISTER_METHOD(WeaponSlot, WeaponSlot::INVALID, scripting_Player_Weapon_GetType, this->m_playerSlot, this->m_weaponID);
    }

    const char *GetName()
    {
        REGISTER_METHOD(const char *, "", scripting_Player_Weapon_GetName, this->m_playerSlot, this->m_weaponID);
    }

    bool Exists()
    {
        REGISTER_METHOD(bool, false, scripting_Player_Weapon_Exists, this->m_playerSlot, this->m_weaponID);
    }

    void SetDefaultChangeSkinAttributes()
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetDefaultChangeSkinAttributes, this->m_playerSlot, this->m_weaponID);
    }

    void SetNametag(const char *text)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetNametag, this->m_playerSlot, this->m_weaponID, text);
    }

    void SetClipAmmo(int ammo)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetClipAmmo, this->m_playerSlot, this->m_weaponID, ammo);
    }

    void SetClip2Ammo(int ammo)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetClip2Ammo, this->m_playerSlot, this->m_weaponID, ammo);
    }

    void SetReserveAmmo(int ammo)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetReserveAmmo, this->m_playerSlot, this->m_weaponID, ammo);
    }

    int32_t GetNextPrimaryAttackTick()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_Weapon_GetNextPrimaryAttackTick, this->m_playerSlot, this->m_weaponID);
    }

    int32_t GetNextSecondaryAttackTick()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_Weapon_GetNextSecondaryAttackTick, this->m_playerSlot, this->m_weaponID);
    }

    void SetNextPrimaryAttackTick(int32_t tick)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetNextPrimaryAttackTick, this->m_playerSlot, this->m_weaponID, tick);
    }

    void SetNextSecondaryAttackTick(int32_t tick)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetNextSecondaryAttackTick, this->m_playerSlot, this->m_weaponID, tick);
    }

    float GetNextPrimaryAttackTickRatio()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_Weapon_GetNextPrimaryAttackTickRatio, this->m_playerSlot, this->m_weaponID);
    }

    float GetNextSecondaryAttackTickRatio()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_Weapon_GetNextSecondaryAttackTickRatio, this->m_playerSlot, this->m_weaponID);
    }

    void SetNextPrimaryAttackTickRatio(float ratio)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetNextPrimaryAttackTickRatio, this->m_playerSlot, this->m_weaponID, ratio);
    }

    void SetNextSecondaryAttackTickRatio(float ratio)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapon_SetNextSecondaryAttackTickRatio, this->m_playerSlot, this->m_weaponID, ratio);
    }

    WeaponSilencerType GetSilencerType()
    {
        REGISTER_METHOD(WeaponSilencerType, WeaponSilencerType::NONE, scripting_Player_Weapon_GetSilencerType, this->m_playerSlot, this->m_weaponID);
    }

    uint32_t GetID()
    {
        return this->m_weaponID;
    }
};

#endif