#ifndef _player_wasinbuyzone_h
#define _player_wasinbuyzone_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class WasInBuyZone
{
private:
    uint32_t m_playerSlot;

public:
    WasInBuyZone(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~WasInBuyZone() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetWasInBuyZone, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetWasInBuyZone, this->m_playerSlot, val);
    }
};

#endif