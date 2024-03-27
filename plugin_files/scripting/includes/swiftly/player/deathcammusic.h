#ifndef _player_deathcammusic_h
#define _player_deathcammusic_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DeathCamMusic
{
private:
    uint32_t m_playerSlot;

public:
    DeathCamMusic(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DeathCamMusic() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetDeathCamMusic, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDeathCamMusic, this->m_playerSlot, val);
    }
};

#endif