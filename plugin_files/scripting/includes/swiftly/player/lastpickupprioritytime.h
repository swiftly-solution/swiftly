#ifndef _player_lastpickupprioritytime_h
#define _player_lastpickupprioritytime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastPickupPriorityTime
{
private:
    uint32_t m_playerSlot;

public:
    LastPickupPriorityTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastPickupPriorityTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastPickupPriorityTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastPickupPriorityTime, this->m_playerSlot, val);
    }
};

#endif