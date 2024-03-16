#ifndef _swiftly_player_weapons_h
#define _swiftly_player_weapons_h

#include <stdint.h>
#include <map>
#include <string>

#include "../swiftly_memory.h"
#include "../types.h"
#include "../swiftly_utils.h"

#include "weapon.h"

typedef void (*Player_DropWeapons)(uint32_t);
typedef void (*Player_RemoveWeapons)(uint32_t);
typedef void (*Player_GiveWeapon)(uint32_t, const char *);
typedef uint32_t (*Player_GetWeaponID)(uint32_t, uint32_t);
typedef void (*Player_SetActiveWeapon)(uint32_t, uint32_t);

class Weapons
{
private:
    uint32_t m_playerSlot;

public:
    Weapons(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Weapons() {}

    void DropWeapons()
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapons_Drop, this->m_playerSlot);
    }

    void RemoveWeapons()
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapons_Remove, this->m_playerSlot);
    }

    void GiveWeapon(const char *name)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapons_Give, this->m_playerSlot, name);
    }

    Weapon *GetWeaponFromSlot(WeaponSlot slot)
    {
        void *player_GetWeaponID = FetchFunctionPtr(nullptr, "scripting_Player_Weapons_GetWeaponID");
        if (player_GetWeaponID)
            return (new Weapon(this->m_playerSlot, reinterpret_cast<Player_GetWeaponID>(player_GetWeaponID)(this->m_playerSlot, slot)));
        else
        {
            NOT_SUPPORTED("scripting_Player_Weapons_GetWeaponID");
            return (new Weapon(this->m_playerSlot, 0));
        }
    }

    Weapon *GetWeapon(uint32_t weaponID)
    {
        return (new Weapon(this->m_playerSlot, weaponID));
    }

    void SetActiveWeapon(WeaponSlot slot)
    {
        REGISTER_METHOD_VOID(scripting_Player_Weapons_SetActiveWeapon, this->m_playerSlot, slot);
    }
};

#endif