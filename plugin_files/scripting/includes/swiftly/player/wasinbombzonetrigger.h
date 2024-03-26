#ifndef _player_wasinbombzonetrigger_h
#define _player_wasinbombzonetrigger_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class WasInBombZoneTrigger
{
private:
    uint32_t m_playerSlot;

public:
    WasInBombZoneTrigger(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~WasInBombZoneTrigger() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetWasInBombZoneTrigger, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetWasInBombZoneTrigger, this->m_playerSlot, val);
    }
};

#endif