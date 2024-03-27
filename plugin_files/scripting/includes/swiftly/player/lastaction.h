#ifndef _player_lastaction_h
#define _player_lastaction_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastAction
{
private:
    uint32_t m_playerSlot;

public:
    LastAction(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastAction() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastAction, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastAction, this->m_playerSlot, val);
    }
};

#endif