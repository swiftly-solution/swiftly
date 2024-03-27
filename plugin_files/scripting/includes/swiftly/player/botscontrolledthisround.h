#ifndef _player_botscontrolledthisround_h
#define _player_botscontrolledthisround_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class BotsControlledThisRound
{
private:
    uint32_t m_playerSlot;

public:
    BotsControlledThisRound(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~BotsControlledThisRound() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetBotsControlledThisRound, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetBotsControlledThisRound, this->m_playerSlot, val);
    }
};

#endif