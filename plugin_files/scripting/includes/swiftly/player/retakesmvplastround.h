#ifndef _player_retakesmvplastround_h
#define _player_retakesmvplastround_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RetakesMVPLastRound
{
private:
    uint32_t m_playerSlot;

public:
    RetakesMVPLastRound(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RetakesMVPLastRound() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetRetakesMVPLastRound, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRetakesMVPLastRound, this->m_playerSlot, val);
    }
};

#endif