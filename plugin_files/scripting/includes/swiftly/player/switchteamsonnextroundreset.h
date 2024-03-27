#ifndef _player_switchteamsonnextroundreset_h
#define _player_switchteamsonnextroundreset_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SwitchTeamsOnNextRoundReset
{
private:
    uint32_t m_playerSlot;

public:
    SwitchTeamsOnNextRoundReset(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SwitchTeamsOnNextRoundReset() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetSwitchTeamsOnNextRoundReset, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSwitchTeamsOnNextRoundReset, this->m_playerSlot, val);
    }
};

#endif