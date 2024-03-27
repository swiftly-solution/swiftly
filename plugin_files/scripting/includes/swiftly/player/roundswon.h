#ifndef _player_roundswon_h
#define _player_roundswon_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RoundsWon
{
private:
    uint32_t m_playerSlot;

public:
    RoundsWon(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RoundsWon() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetRoundsWon, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRoundsWon, this->m_playerSlot, val);
    }
};

#endif