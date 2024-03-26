#ifndef _player_justdidteamkill_h
#define _player_justdidteamkill_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class JustDidTeamKill
{
private:
    uint32_t m_playerSlot;

public:
    JustDidTeamKill(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~JustDidTeamKill() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetJustDidTeamKill, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetJustDidTeamKill, this->m_playerSlot, val);
    }
};

#endif