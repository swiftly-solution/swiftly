#ifndef _player_accumulateddistancetraveled_h
#define _player_accumulateddistancetraveled_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AccumulatedDistanceTraveled
{
private:
    uint32_t m_playerSlot;

public:
    AccumulatedDistanceTraveled(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AccumulatedDistanceTraveled() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetAccumulatedDistanceTraveled, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAccumulatedDistanceTraveled, this->m_playerSlot, val);
    }
};

#endif