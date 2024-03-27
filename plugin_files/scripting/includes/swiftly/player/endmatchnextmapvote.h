#ifndef _player_endmatchnextmapvote_h
#define _player_endmatchnextmapvote_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class EndMatchNextMapVote
{
private:
    uint32_t m_playerSlot;

public:
    EndMatchNextMapVote(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~EndMatchNextMapVote() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetEndMatchNextMapVote, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetEndMatchNextMapVote, this->m_playerSlot, val);
    }
};

#endif