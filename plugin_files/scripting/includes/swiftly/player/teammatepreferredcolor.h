#ifndef _player_teammatepreferredcolor_h
#define _player_teammatepreferredcolor_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class TeammatePreferredColor
{
private:
    uint32_t m_playerSlot;

public:
    TeammatePreferredColor(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~TeammatePreferredColor() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetTeammatePreferredColor, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetTeammatePreferredColor, this->m_playerSlot, val);
    }
};

#endif