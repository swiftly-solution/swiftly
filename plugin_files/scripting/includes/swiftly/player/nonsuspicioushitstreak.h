#ifndef _player_nonsuspicioushitstreak_h
#define _player_nonsuspicioushitstreak_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NonSuspiciousHitStreak
{
private:
    uint32_t m_playerSlot;

public:
    NonSuspiciousHitStreak(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NonSuspiciousHitStreak() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetNonSuspiciousHitStreak, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNonSuspiciousHitStreak, this->m_playerSlot, val);
    }
};

#endif