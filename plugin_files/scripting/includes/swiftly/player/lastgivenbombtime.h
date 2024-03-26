#ifndef _player_lastgivenbombtime_h
#define _player_lastgivenbombtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastGivenBombTime
{
private:
    uint32_t m_playerSlot;

public:
    LastGivenBombTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastGivenBombTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastGivenBombTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastGivenBombTime, this->m_playerSlot, val);
    }
};

#endif