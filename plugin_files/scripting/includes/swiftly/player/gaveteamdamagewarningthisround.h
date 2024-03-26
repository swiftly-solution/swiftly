#ifndef _player_gaveteamdamagewarningthisround_h
#define _player_gaveteamdamagewarningthisround_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class GaveTeamDamageWarningThisRound
{
private:
    uint32_t m_playerSlot;

public:
    GaveTeamDamageWarningThisRound(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~GaveTeamDamageWarningThisRound() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetGaveTeamDamageWarningThisRound, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGaveTeamDamageWarningThisRound, this->m_playerSlot, val);
    }
};

#endif