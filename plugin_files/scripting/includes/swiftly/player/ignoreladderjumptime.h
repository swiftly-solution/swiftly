#ifndef _player_ignoreladderjumptime_h
#define _player_ignoreladderjumptime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IgnoreLadderJumpTime
{
private:
    uint32_t m_playerSlot;

public:
    IgnoreLadderJumpTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IgnoreLadderJumpTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetIgnoreLadderJumpTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIgnoreLadderJumpTime, this->m_playerSlot, val);
    }
};

#endif