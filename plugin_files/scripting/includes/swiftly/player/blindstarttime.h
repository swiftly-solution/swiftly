#ifndef _player_blindstarttime_h
#define _player_blindstarttime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class BlindStartTime
{
private:
    uint32_t m_playerSlot;

public:
    BlindStartTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~BlindStartTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetBlindStartTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetBlindStartTime, this->m_playerSlot, val);
    }
};

#endif