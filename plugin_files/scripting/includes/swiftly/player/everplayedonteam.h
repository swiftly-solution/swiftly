#ifndef _player_everplayedonteam_h
#define _player_everplayedonteam_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class EverPlayedOnTeam
{
private:
    uint32_t m_playerSlot;

public:
    EverPlayedOnTeam(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~EverPlayedOnTeam() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetEverPlayedOnTeam, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetEverPlayedOnTeam, this->m_playerSlot, val);
    }
};

#endif