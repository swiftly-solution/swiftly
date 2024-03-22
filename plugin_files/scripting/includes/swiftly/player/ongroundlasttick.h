#ifndef _player_ongroundlasttick_h
#define _player_ongroundlasttick_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class OnGroundLastTick
{
private:
    uint32_t m_playerSlot;

public:
    OnGroundLastTick(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~OnGroundLastTick() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetOnGroundLastTick, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetOnGroundLastTick, this->m_playerSlot, val);
    }
};

#endif