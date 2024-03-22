#ifndef _player_lastlandtime_h
#define _player_lastlandtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastLandTime
{
private:
    uint32_t m_playerSlot;

public:
    LastLandTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastLandTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastLandTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastLandTime, this->m_playerSlot, val);
    }
};

#endif