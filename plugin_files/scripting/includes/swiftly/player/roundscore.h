#ifndef _player_roundscore_h
#define _player_roundscore_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RoundScore
{
private:
    uint32_t m_playerSlot;

public:
    RoundScore(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RoundScore() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetRoundScore, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRoundScore, this->m_playerSlot, val);
    }
};

#endif