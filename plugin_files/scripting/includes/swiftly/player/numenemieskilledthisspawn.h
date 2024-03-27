#ifndef _player_numenemieskilledthisspawn_h
#define _player_numenemieskilledthisspawn_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NumEnemiesKilledThisSpawn
{
private:
    uint32_t m_playerSlot;

public:
    NumEnemiesKilledThisSpawn(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NumEnemiesKilledThisSpawn() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetNumEnemiesKilledThisSpawn, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNumEnemiesKilledThisSpawn, this->m_playerSlot, val);
    }
};

#endif