#ifndef _player_gaveteamdamagewarning_h
#define _player_gaveteamdamagewarning_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class GaveTeamDamageWarning
{
private:
    uint32_t m_playerSlot;

public:
    GaveTeamDamageWarning(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~GaveTeamDamageWarning() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetGaveTeamDamageWarning, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGaveTeamDamageWarning, this->m_playerSlot, val);
    }
};

#endif