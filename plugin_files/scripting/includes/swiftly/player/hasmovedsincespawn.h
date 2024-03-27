#ifndef _player_hasmovedsincespawn_h
#define _player_hasmovedsincespawn_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasMovedSinceSpawn
{
private:
    uint32_t m_playerSlot;

public:
    HasMovedSinceSpawn(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasMovedSinceSpawn() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasMovedSinceSpawn, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasMovedSinceSpawn, this->m_playerSlot, val);
    }
};

#endif