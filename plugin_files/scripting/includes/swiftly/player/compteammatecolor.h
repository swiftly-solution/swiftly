#ifndef _player_compteammatecolor_h
#define _player_compteammatecolor_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CompTeammateColor
{
private:
    uint32_t m_playerSlot;

public:
    CompTeammateColor(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CompTeammateColor() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetCompTeammateColor, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompTeammateColor, this->m_playerSlot, val);
    }
};

#endif