#ifndef _player_lastgivendefusertime_h
#define _player_lastgivendefusertime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastGivenDefuserTime
{
private:
    uint32_t m_playerSlot;

public:
    LastGivenDefuserTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastGivenDefuserTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastGivenDefuserTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastGivenDefuserTime, this->m_playerSlot, val);
    }
};

#endif