#ifndef _player_stats_h
#define _player_stats_h

#include "../swiftly_memory.h"
#include "../types.h"

class Stats
{
private:
    uint32_t m_playerSlot;

public:
    Stats(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Stats() {}

    int Get(PlayerStat stat)
    {
        void *player_FetchStat = FetchFunctionPtr(nullptr, "scripting_Player_FetchMatchStat");
        if (player_FetchStat)
            return reinterpret_cast<Player_FetchStat>(player_FetchStat)(this->m_playerSlot, stat);
        else
            return 0;
    }

    void Set(PlayerStat stat, int value)
    {
        void *player_SetStats = FetchFunctionPtr(nullptr, "scripting_Player_SetMatchStat");
        if (player_SetStats)
            reinterpret_cast<Player_SetStat>(player_SetStats)(this->m_playerSlot, stat, value);
    }
};

#endif