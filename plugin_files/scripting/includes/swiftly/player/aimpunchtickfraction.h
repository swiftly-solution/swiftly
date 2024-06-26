#ifndef _player_aimpunchtickfraction_h
#define _player_aimpunchtickfraction_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AimPunchTickFraction
{
private:
    uint32_t m_playerSlot;

public:
    AimPunchTickFraction(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AimPunchTickFraction() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetAimPunchTickFraction, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAimPunchTickFraction, this->m_playerSlot, val);
    }
};

#endif