#ifndef _player_lowerbodyyawtarget_h
#define _player_lowerbodyyawtarget_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LowerBodyYawTarget
{
private:
    uint32_t m_playerSlot;

public:
    LowerBodyYawTarget(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LowerBodyYawTarget() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLowerBodyYawTarget, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLowerBodyYawTarget, this->m_playerSlot, val);
    }
};

#endif