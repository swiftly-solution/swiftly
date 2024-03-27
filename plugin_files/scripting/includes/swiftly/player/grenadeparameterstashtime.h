#ifndef _player_grenadeparameterstashtime_h
#define _player_grenadeparameterstashtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class GrenadeParameterStashTime
{
private:
    uint32_t m_playerSlot;

public:
    GrenadeParameterStashTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~GrenadeParameterStashTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetGrenadeParameterStashTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGrenadeParameterStashTime, this->m_playerSlot, val);
    }
};

#endif