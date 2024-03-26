#ifndef _player_slopedropheight_h
#define _player_slopedropheight_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SlopeDropHeight
{
private:
    uint32_t m_playerSlot;

public:
    SlopeDropHeight(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SlopeDropHeight() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetSlopeDropHeight, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSlopeDropHeight, this->m_playerSlot, val);
    }
};

#endif