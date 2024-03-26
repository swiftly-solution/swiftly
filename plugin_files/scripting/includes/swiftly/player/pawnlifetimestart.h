#ifndef _player_pawnlifetimestart_h
#define _player_pawnlifetimestart_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PawnLifetimeStart
{
private:
    uint32_t m_playerSlot;

public:
    PawnLifetimeStart(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PawnLifetimeStart() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetPawnLifetimeStart, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPawnLifetimeStart, this->m_playerSlot, val);
    }
};

#endif