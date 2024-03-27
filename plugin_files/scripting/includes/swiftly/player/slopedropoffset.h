#ifndef _player_slopedropoffset_h
#define _player_slopedropoffset_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SlopeDropOffset
{
private:
    uint32_t m_playerSlot;

public:
    SlopeDropOffset(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SlopeDropOffset() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetSlopeDropOffset, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSlopeDropOffset, this->m_playerSlot, val);
    }
};

#endif