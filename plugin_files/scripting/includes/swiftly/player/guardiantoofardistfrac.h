#ifndef _player_guardiantoofardistfrac_h
#define _player_guardiantoofardistfrac_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class GuardianTooFarDistFrac
{
private:
    uint32_t m_playerSlot;

public:
    GuardianTooFarDistFrac(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~GuardianTooFarDistFrac() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetGuardianTooFarDistFrac, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGuardianTooFarDistFrac, this->m_playerSlot, val);
    }
};

#endif