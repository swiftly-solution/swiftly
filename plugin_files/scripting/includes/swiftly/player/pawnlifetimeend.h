#ifndef _player_pawnlifetimeend_h
#define _player_pawnlifetimeend_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PawnLifetimeEnd
{
private:
    uint32_t m_playerSlot;

public:
    PawnLifetimeEnd(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PawnLifetimeEnd() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetPawnLifetimeEnd, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPawnLifetimeEnd, this->m_playerSlot, val);
    }
};

#endif