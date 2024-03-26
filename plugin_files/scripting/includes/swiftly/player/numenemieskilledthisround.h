#ifndef _player_numenemieskilledthisround_h
#define _player_numenemieskilledthisround_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NumEnemiesKilledThisRound
{
private:
    uint32_t m_playerSlot;

public:
    NumEnemiesKilledThisRound(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NumEnemiesKilledThisRound() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetNumEnemiesKilledThisRound, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNumEnemiesKilledThisRound, this->m_playerSlot, val);
    }
};

#endif