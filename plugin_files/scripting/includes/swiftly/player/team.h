#ifndef _player_team_h
#define _player_team_h

#include <stdint.h>
#include "../swiftly_memory.h"

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

    uint8_t Get()
    {
        void *player_GetTeam = FetchFunctionPtr(nullptr, "scripting_Player_GetTeam");
        if (player_GetTeam)
            return reinterpret_cast<Player_GetTeam>(player_GetTeam)(this->m_playerSlot);
        else
            return 0;
    }
};

#endif