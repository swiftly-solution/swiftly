#ifndef _player_lastentitysteadystate_h
#define _player_lastentitysteadystate_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastEntitySteadyState
{
private:
    uint32_t m_playerSlot;

public:
    LastEntitySteadyState(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastEntitySteadyState() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastEntitySteadyState, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastEntitySteadyState, this->m_playerSlot, val);
    }
};

#endif