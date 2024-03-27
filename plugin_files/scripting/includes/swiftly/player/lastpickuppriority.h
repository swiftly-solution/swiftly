#ifndef _player_lastpickuppriority_h
#define _player_lastpickuppriority_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastPickupPriority
{
private:
    uint32_t m_playerSlot;

public:
    LastPickupPriority(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastPickupPriority() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetLastPickupPriority, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastPickupPriority, this->m_playerSlot, val);
    }
};

#endif