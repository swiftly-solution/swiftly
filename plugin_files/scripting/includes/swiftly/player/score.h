#ifndef _player_score_h
#define _player_score_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Score
{
private:
    uint32_t m_playerSlot;

public:
    Score(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Score() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetScore, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetScore, this->m_playerSlot, val);
    }
};

#endif