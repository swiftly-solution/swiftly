#ifndef _player_suspicioushitcount_h
#define _player_suspicioushitcount_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SuspiciousHitCount
{
private:
    uint32_t m_playerSlot;

public:
    SuspiciousHitCount(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SuspiciousHitCount() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetSuspiciousHitCount, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSuspiciousHitCount, this->m_playerSlot, val);
    }
};

#endif