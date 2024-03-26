#ifndef _player_teamchanged_h
#define _player_teamchanged_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class TeamChanged
{
private:
    uint32_t m_playerSlot;

public:
    TeamChanged(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~TeamChanged() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetTeamChanged, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetTeamChanged, this->m_playerSlot, val);
    }
};

#endif