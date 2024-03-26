#ifndef _player_lasthealth_h
#define _player_lasthealth_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastHealth
{
private:
    uint32_t m_playerSlot;

public:
    LastHealth(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastHealth() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetLastHealth, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastHealth, this->m_playerSlot, val);
    }
};

#endif