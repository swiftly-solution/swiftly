#ifndef _player_lastattackedteammate_h
#define _player_lastattackedteammate_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastAttackedTeammate
{
private:
    uint32_t m_playerSlot;

public:
    LastAttackedTeammate(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastAttackedTeammate() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastAttackedTeammate, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastAttackedTeammate, this->m_playerSlot, val);
    }
};

#endif