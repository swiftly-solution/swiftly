#ifndef _player_movestate_h
#define _player_movestate_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class MoveState
{
private:
    uint32_t m_playerSlot;

public:
    MoveState(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~MoveState() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetMoveState, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMoveState, this->m_playerSlot, val);
    }
};

#endif