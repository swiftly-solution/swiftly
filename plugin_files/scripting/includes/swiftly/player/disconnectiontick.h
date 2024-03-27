#ifndef _player_disconnectiontick_h
#define _player_disconnectiontick_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DisconnectionTick
{
private:
    uint32_t m_playerSlot;

public:
    DisconnectionTick(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DisconnectionTick() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetDisconnectionTick, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDisconnectionTick, this->m_playerSlot, val);
    }
};

#endif