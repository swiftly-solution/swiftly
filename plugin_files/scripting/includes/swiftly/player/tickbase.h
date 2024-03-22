#ifndef _player_tickbase_h
#define _player_tickbase_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class TickBase
{
private:
    uint32_t m_playerSlot;

public:
    TickBase(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~TickBase() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetTickBase, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetTickBase, this->m_playerSlot, val);
    }
};

#endif