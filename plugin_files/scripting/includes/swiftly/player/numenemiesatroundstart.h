#ifndef _player_numenemiesatroundstart_h
#define _player_numenemiesatroundstart_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NumEnemiesAtRoundStart
{
private:
    uint32_t m_playerSlot;

public:
    NumEnemiesAtRoundStart(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NumEnemiesAtRoundStart() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetNumEnemiesAtRoundStart, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNumEnemiesAtRoundStart, this->m_playerSlot, val);
    }
};

#endif