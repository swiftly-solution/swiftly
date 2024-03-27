#ifndef _player_lastweaponfireusercmd_h
#define _player_lastweaponfireusercmd_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastWeaponFireUsercmd
{
private:
    uint32_t m_playerSlot;

public:
    LastWeaponFireUsercmd(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastWeaponFireUsercmd() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetLastWeaponFireUsercmd, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastWeaponFireUsercmd, this->m_playerSlot, val);
    }
};

#endif