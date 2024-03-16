#ifndef _player_stats_h
#define _player_stats_h

#include "../swiftly_memory.h"
#include "../types.h"
#include "../swiftly_utils.h"

class Stats
{
private:
    uint32_t m_playerSlot;

public:
    Stats(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Stats() {}

    int Get(PlayerStat stat)
    {
        REGISTER_METHOD(int, 0, scripting_Player_FetchMatchStat, this->m_playerSlot);
    }

    void Set(PlayerStat stat, int value)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMatchStat, this->m_playerSlot, stat, value);
    }
};

#endif