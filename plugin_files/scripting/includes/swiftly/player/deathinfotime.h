#ifndef _player_deathinfotime_h
#define _player_deathinfotime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DeathInfoTime
{
private:
    uint32_t m_playerSlot;

public:
    DeathInfoTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DeathInfoTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetDeathInfoTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDeathInfoTime, this->m_playerSlot, val);
    }
};

#endif