#ifndef _player_lastconcurrentkilled_h
#define _player_lastconcurrentkilled_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastConcurrentKilled
{
private:
    uint32_t m_playerSlot;

public:
    LastConcurrentKilled(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastConcurrentKilled() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetLastConcurrentKilled, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastConcurrentKilled, this->m_playerSlot, val);
    }
};

#endif