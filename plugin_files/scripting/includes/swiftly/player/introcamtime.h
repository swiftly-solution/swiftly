#ifndef _player_introcamtime_h
#define _player_introcamtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IntroCamTime
{
private:
    uint32_t m_playerSlot;

public:
    IntroCamTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IntroCamTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetIntroCamTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIntroCamTime, this->m_playerSlot, val);
    }
};

#endif