#ifndef _player_wasinhostagerescuezone_h
#define _player_wasinhostagerescuezone_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class WasInHostageRescueZone
{
private:
    uint32_t m_playerSlot;

public:
    WasInHostageRescueZone(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~WasInHostageRescueZone() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetWasInHostageRescueZone, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetWasInHostageRescueZone, this->m_playerSlot, val);
    }
};

#endif