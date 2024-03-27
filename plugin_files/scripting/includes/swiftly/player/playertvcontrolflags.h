#ifndef _player_playertvcontrolflags_h
#define _player_playertvcontrolflags_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PlayerTvControlFlags
{
private:
    uint32_t m_playerSlot;

public:
    PlayerTvControlFlags(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PlayerTvControlFlags() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetPlayerTvControlFlags, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPlayerTvControlFlags, this->m_playerSlot, val);
    }
};

#endif