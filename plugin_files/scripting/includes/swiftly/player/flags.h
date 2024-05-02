#ifndef _player_flags_h
#define _player_flags_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Flags
{
private:
    uint32_t m_playerSlot;

public:
    Flags(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Flags() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetFlags, this->m_playerSlot);
    }

    void Set(uint32_t flag)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetFlags, this->m_playerSlot, flag);
    }
};

#endif