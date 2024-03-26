#ifndef _player_lasttimeplayerwasdisconnectedforpawnsremove_h
#define _player_lasttimeplayerwasdisconnectedforpawnsremove_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastTimePlayerWasDisconnectedForPawnsRemove
{
private:
    uint32_t m_playerSlot;

public:
    LastTimePlayerWasDisconnectedForPawnsRemove(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastTimePlayerWasDisconnectedForPawnsRemove() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastTimePlayerWasDisconnectedForPawnsRemove, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastTimePlayerWasDisconnectedForPawnsRemove, this->m_playerSlot, val);
    }
};

#endif