#ifndef _player_dealtdamagetoenemymostrecenttimestamp_h
#define _player_dealtdamagetoenemymostrecenttimestamp_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DealtDamageToEnemyMostRecentTimestamp
{
private:
    uint32_t m_playerSlot;

public:
    DealtDamageToEnemyMostRecentTimestamp(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DealtDamageToEnemyMostRecentTimestamp() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetDealtDamageToEnemyMostRecentTimestamp, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDealtDamageToEnemyMostRecentTimestamp, this->m_playerSlot, val);
    }
};

#endif