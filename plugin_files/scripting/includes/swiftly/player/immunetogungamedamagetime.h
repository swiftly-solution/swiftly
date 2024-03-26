#ifndef _player_immunetogungamedamagetime_h
#define _player_immunetogungamedamagetime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ImmuneToGunGameDamageTime
{
private:
    uint32_t m_playerSlot;

public:
    ImmuneToGunGameDamageTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ImmuneToGunGameDamageTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetImmuneToGunGameDamageTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetImmuneToGunGameDamageTime, this->m_playerSlot, val);
    }
};

#endif