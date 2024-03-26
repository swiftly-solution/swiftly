#ifndef _player_controllingbot_h
#define _player_controllingbot_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ControllingBot
{
private:
    uint32_t m_playerSlot;

public:
    ControllingBot(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ControllingBot() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetControllingBot, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetControllingBot, this->m_playerSlot, val);
    }
};

#endif