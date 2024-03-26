#ifndef _player_strafing_h
#define _player_strafing_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Strafing
{
private:
    uint32_t m_playerSlot;

public:
    Strafing(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Strafing() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetStrafing, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetStrafing, this->m_playerSlot, val);
    }
};

#endif