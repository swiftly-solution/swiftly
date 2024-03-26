#ifndef _player_scorereported_h
#define _player_scorereported_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ScoreReported
{
private:
    uint32_t m_playerSlot;

public:
    ScoreReported(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ScoreReported() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetScoreReported, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetScoreReported, this->m_playerSlot, val);
    }
};

#endif