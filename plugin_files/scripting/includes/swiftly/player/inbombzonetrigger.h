#ifndef _player_inbombzonetrigger_h
#define _player_inbombzonetrigger_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InBombZoneTrigger
{
private:
    uint32_t m_playerSlot;

public:
    InBombZoneTrigger(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InBombZoneTrigger() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInBombZoneTrigger, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInBombZoneTrigger, this->m_playerSlot, val);
    }
};

#endif