#ifndef _player_direction_h
#define _player_direction_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Direction
{
private:
    uint32_t m_playerSlot;

public:
    Direction(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Direction() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetDirection, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDirection, this->m_playerSlot, val);
    }
};

#endif