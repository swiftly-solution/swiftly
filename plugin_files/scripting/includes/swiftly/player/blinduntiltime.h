#ifndef _player_blinduntiltime_h
#define _player_blinduntiltime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class BlindUntilTime
{
private:
    uint32_t m_playerSlot;

public:
    BlindUntilTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~BlindUntilTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetBlindUntilTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetBlindUntilTime, this->m_playerSlot, val);
    }
};

#endif