#ifndef _player_cancontrolobservedbot_h
#define _player_cancontrolobservedbot_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CanControlObservedBot
{
private:
    uint32_t m_playerSlot;

public:
    CanControlObservedBot(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CanControlObservedBot() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetCanControlObservedBot, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCanControlObservedBot, this->m_playerSlot, val);
    }
};

#endif