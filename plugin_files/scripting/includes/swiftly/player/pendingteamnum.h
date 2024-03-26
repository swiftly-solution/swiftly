#ifndef _player_pendingteamnum_h
#define _player_pendingteamnum_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PendingTeamNum
{
private:
    uint32_t m_playerSlot;

public:
    PendingTeamNum(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PendingTeamNum() {}

    uint8_t Get()
    {
        REGISTER_METHOD(uint8_t, 0, scripting_Player_GetPendingTeamNum, this->m_playerSlot);
    }

    void Set(uint8_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPendingTeamNum, this->m_playerSlot, val);
    }
};

#endif