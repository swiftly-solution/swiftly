#ifndef _player_lastcollisionceiling_h
#define _player_lastcollisionceiling_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastCollisionCeiling
{
private:
    uint32_t m_playerSlot;

public:
    LastCollisionCeiling(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastCollisionCeiling() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastCollisionCeiling, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastCollisionCeiling, this->m_playerSlot, val);
    }
};

#endif