#ifndef _player_competitiverankingpredicted_loss_h
#define _player_competitiverankingpredicted_loss_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CompetitiveRankingPredicted_Loss
{
private:
    uint32_t m_playerSlot;

public:
    CompetitiveRankingPredicted_Loss(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CompetitiveRankingPredicted_Loss() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetCompetitiveRankingPredicted_Loss, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveRankingPredicted_Loss, this->m_playerSlot, val);
    }
};

#endif