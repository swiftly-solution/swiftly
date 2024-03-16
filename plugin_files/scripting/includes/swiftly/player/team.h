#ifndef _player_team_h
#define _player_team_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

#define TEAM_NONE 0
#define TEAM_SPECTATOR 1
#define TEAM_T 2
#define TEAM_CT 3

class Team
{
private:
    uint32_t m_playerSlot;

public:
    Team(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Team() {}

    int Get()
    {
        REGISTER_METHOD(int, 0, scripting_Player_GetTeam, this->m_playerSlot);
    }

    void Set(int team)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetTeam, this->m_playerSlot, team);
    }
};

#endif