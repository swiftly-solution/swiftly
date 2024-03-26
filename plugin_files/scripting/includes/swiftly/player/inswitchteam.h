#ifndef _player_inswitchteam_h
#define _player_inswitchteam_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InSwitchTeam
{
private:
    uint32_t m_playerSlot;

public:
    InSwitchTeam(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InSwitchTeam() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInSwitchTeam, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInSwitchTeam, this->m_playerSlot, val);
    }
};

#endif