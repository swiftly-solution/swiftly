#ifndef _player_competitiverankingpredicted_win_h
#define _player_competitiverankingpredicted_win_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CompetitiveRankingPredicted_Win
{
private:
    uint32_t m_playerSlot;

public:
    CompetitiveRankingPredicted_Win(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CompetitiveRankingPredicted_Win() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetCompetitiveRankingPredicted_Win, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveRankingPredicted_Win, this->m_playerSlot, val);
    }
};

#endif