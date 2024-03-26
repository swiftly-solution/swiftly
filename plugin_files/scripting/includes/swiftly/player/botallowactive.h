#ifndef _player_botallowactive_h
#define _player_botallowactive_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class BotAllowActive
{
private:
    uint32_t m_playerSlot;

public:
    BotAllowActive(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~BotAllowActive() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetBotAllowActive, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetBotAllowActive, this->m_playerSlot, val);
    }
};

#endif