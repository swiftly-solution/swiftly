#ifndef _player_playerlocked_h
#define _player_playerlocked_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PlayerLocked
{
private:
    uint32_t m_playerSlot;

public:
    PlayerLocked(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PlayerLocked() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetPlayerLocked, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPlayerLocked, this->m_playerSlot, val);
    }
};

#endif