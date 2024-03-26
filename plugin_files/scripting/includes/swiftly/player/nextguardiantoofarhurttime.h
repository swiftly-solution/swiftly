#ifndef _player_nextguardiantoofarhurttime_h
#define _player_nextguardiantoofarhurttime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NextGuardianTooFarHurtTime
{
private:
    uint32_t m_playerSlot;

public:
    NextGuardianTooFarHurtTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NextGuardianTooFarHurtTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetNextGuardianTooFarHurtTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNextGuardianTooFarHurtTime, this->m_playerSlot, val);
    }
};

#endif