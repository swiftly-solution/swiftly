#ifndef _player_lerptime_h
#define _player_lerptime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LerpTime
{
private:
    uint32_t m_playerSlot;

public:
    LerpTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LerpTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLerpTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLerpTime, this->m_playerSlot, val);
    }
};

#endif