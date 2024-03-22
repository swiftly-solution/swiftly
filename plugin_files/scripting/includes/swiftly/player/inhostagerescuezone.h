#ifndef _player_inhostagerescuezone_h
#define _player_inhostagerescuezone_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InHostageRescueZone
{
private:
    uint32_t m_playerSlot;

public:
    InHostageRescueZone(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InHostageRescueZone() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInHostageRescueZone, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInHostageRescueZone, this->m_playerSlot, val);
    }
};

#endif