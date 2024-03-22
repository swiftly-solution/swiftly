#ifndef _player_inhostageresetzone_h
#define _player_inhostageresetzone_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InHostageResetZone
{
private:
    uint32_t m_playerSlot;

public:
    InHostageResetZone(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InHostageResetZone() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInHostageResetZone, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInHostageResetZone, this->m_playerSlot, val);
    }
};

#endif