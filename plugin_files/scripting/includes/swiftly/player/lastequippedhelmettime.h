#ifndef _player_lastequippedhelmettime_h
#define _player_lastequippedhelmettime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastEquippedHelmetTime
{
private:
    uint32_t m_playerSlot;

public:
    LastEquippedHelmetTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastEquippedHelmetTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastEquippedHelmetTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastEquippedHelmetTime, this->m_playerSlot, val);
    }
};

#endif