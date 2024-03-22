#ifndef _player_timeoflastinjury_h
#define _player_timeoflastinjury_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class TimeOfLastInjury
{
private:
    uint32_t m_playerSlot;

public:
    TimeOfLastInjury(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~TimeOfLastInjury() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetTimeOfLastInjury, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetTimeOfLastInjury, this->m_playerSlot, val);
    }
};

#endif