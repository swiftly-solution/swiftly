#ifndef _player_lagcompensation_h
#define _player_lagcompensation_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LagCompensation
{
private:
    uint32_t m_playerSlot;

public:
    LagCompensation(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LagCompensation() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetLagCompensation, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLagCompensation, this->m_playerSlot, val);
    }
};

#endif