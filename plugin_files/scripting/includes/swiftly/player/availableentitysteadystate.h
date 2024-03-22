#ifndef _player_availableentitysteadystate_h
#define _player_availableentitysteadystate_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AvailableEntitySteadyState
{
private:
    uint32_t m_playerSlot;

public:
    AvailableEntitySteadyState(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AvailableEntitySteadyState() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetAvailableEntitySteadyState, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAvailableEntitySteadyState, this->m_playerSlot, val);
    }
};

#endif