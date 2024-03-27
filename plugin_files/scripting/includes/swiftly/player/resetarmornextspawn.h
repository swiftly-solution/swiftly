#ifndef _player_resetarmornextspawn_h
#define _player_resetarmornextspawn_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ResetArmorNextSpawn
{
private:
    uint32_t m_playerSlot;

public:
    ResetArmorNextSpawn(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ResetArmorNextSpawn() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetResetArmorNextSpawn, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetResetArmorNextSpawn, this->m_playerSlot, val);
    }
};

#endif