#ifndef _player_punishforteamkill_h
#define _player_punishforteamkill_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PunishForTeamKill
{
private:
    uint32_t m_playerSlot;

public:
    PunishForTeamKill(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PunishForTeamKill() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetPunishForTeamKill, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPunishForTeamKill, this->m_playerSlot, val);
    }
};

#endif