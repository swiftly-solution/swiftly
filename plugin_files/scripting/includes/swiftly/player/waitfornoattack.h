#ifndef _player_waitfornoattack_h
#define _player_waitfornoattack_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class WaitForNoAttack
{
private:
    uint32_t m_playerSlot;

public:
    WaitForNoAttack(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~WaitForNoAttack() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetWaitForNoAttack, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetWaitForNoAttack, this->m_playerSlot, val);
    }
};

#endif