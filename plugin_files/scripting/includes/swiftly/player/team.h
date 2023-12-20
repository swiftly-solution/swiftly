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
        void *player_GetTeam = FetchFunctionPtr(nullptr, "scripting_Player_GetTeam");
        if (player_GetTeam)
            return reinterpret_cast<Player_GetTeam>(player_GetTeam)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetTeam");
            return 0;
        }
    }

    void Set(int team)
    {
        void *player_SetTeam = FetchFunctionPtr(nullptr, "scripting_Player_SetTeam");
        if (player_SetTeam)
            reinterpret_cast<Player_SetTeam>(player_SetTeam)(this->m_playerSlot, team);
        else
            NOT_SUPPORTED("scripting_Player_SetTeam");
    }
};

#endif