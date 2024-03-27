#ifndef _player_lastcollisionceilingchangetime_h
#define _player_lastcollisionceilingchangetime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastCollisionCeilingChangeTime
{
private:
    uint32_t m_playerSlot;

public:
    LastCollisionCeilingChangeTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastCollisionCeilingChangeTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastCollisionCeilingChangeTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastCollisionCeilingChangeTime, this->m_playerSlot, val);
    }
};

#endif