#ifndef _player_gungameimmunity_h
#define _player_gungameimmunity_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class GunGameImmunity
{
private:
    uint32_t m_playerSlot;

public:
    GunGameImmunity(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~GunGameImmunity() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetGunGameImmunity, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGunGameImmunity, this->m_playerSlot, val);
    }
};

#endif