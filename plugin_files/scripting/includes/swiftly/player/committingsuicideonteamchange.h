#ifndef _player_committingsuicideonteamchange_h
#define _player_committingsuicideonteamchange_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CommittingSuicideOnTeamChange
{
private:
    uint32_t m_playerSlot;

public:
    CommittingSuicideOnTeamChange(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CommittingSuicideOnTeamChange() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetCommittingSuicideOnTeamChange, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCommittingSuicideOnTeamChange, this->m_playerSlot, val);
    }
};

#endif