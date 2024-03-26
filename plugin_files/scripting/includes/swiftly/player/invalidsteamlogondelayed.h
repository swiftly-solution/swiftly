#ifndef _player_invalidsteamlogondelayed_h
#define _player_invalidsteamlogondelayed_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InvalidSteamLogonDelayed
{
private:
    uint32_t m_playerSlot;

public:
    InvalidSteamLogonDelayed(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InvalidSteamLogonDelayed() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInvalidSteamLogonDelayed, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInvalidSteamLogonDelayed, this->m_playerSlot, val);
    }
};

#endif