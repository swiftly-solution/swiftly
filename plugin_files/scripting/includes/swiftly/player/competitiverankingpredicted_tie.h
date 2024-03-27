#ifndef _player_competitiverankingpredicted_tie_h
#define _player_competitiverankingpredicted_tie_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CompetitiveRankingPredicted_Tie
{
private:
    uint32_t m_playerSlot;

public:
    CompetitiveRankingPredicted_Tie(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CompetitiveRankingPredicted_Tie() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetCompetitiveRankingPredicted_Tie, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveRankingPredicted_Tie, this->m_playerSlot, val);
    }
};

#endif