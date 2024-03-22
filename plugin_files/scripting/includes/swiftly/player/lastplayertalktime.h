#ifndef _player_lastplayertalktime_h
#define _player_lastplayertalktime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastPlayerTalkTime
{
private:
    uint32_t m_playerSlot;

public:
    LastPlayerTalkTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastPlayerTalkTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastPlayerTalkTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastPlayerTalkTime, this->m_playerSlot, val);
    }
};

#endif