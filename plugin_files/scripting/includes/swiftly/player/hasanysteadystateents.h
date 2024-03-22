#ifndef _player_hasanysteadystateents_h
#define _player_hasanysteadystateents_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasAnySteadyStateEnts
{
private:
    uint32_t m_playerSlot;

public:
    HasAnySteadyStateEnts(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasAnySteadyStateEnts() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasAnySteadyStateEnts, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasAnySteadyStateEnts, this->m_playerSlot, val);
    }
};

#endif