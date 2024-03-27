#ifndef _player_primaryaddon_h
#define _player_primaryaddon_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PrimaryAddon
{
private:
    uint32_t m_playerSlot;

public:
    PrimaryAddon(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PrimaryAddon() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetPrimaryAddon, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPrimaryAddon, this->m_playerSlot, val);
    }
};

#endif