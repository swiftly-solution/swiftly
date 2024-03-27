#ifndef _player_hostageskilled_h
#define _player_hostageskilled_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HostagesKilled
{
private:
    uint32_t m_playerSlot;

public:
    HostagesKilled(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HostagesKilled() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetHostagesKilled, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHostagesKilled, this->m_playerSlot, val);
    }
};

#endif