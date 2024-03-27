#ifndef _player_survivalteamnumber_h
#define _player_survivalteamnumber_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SurvivalTeamNumber
{
private:
    uint32_t m_playerSlot;

public:
    SurvivalTeamNumber(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SurvivalTeamNumber() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetSurvivalTeamNumber, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSurvivalTeamNumber, this->m_playerSlot, val);
    }
};

#endif