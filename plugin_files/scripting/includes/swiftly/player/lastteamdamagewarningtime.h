#ifndef _player_lastteamdamagewarningtime_h
#define _player_lastteamdamagewarningtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastTeamDamageWarningTime
{
private:
    uint32_t m_playerSlot;

public:
    LastTeamDamageWarningTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastTeamDamageWarningTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastTeamDamageWarningTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastTeamDamageWarningTime, this->m_playerSlot, val);
    }
};

#endif