#ifndef _player_inbuyzone_h
#define _player_inbuyzone_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InBuyZone
{
private:
    uint32_t m_playerSlot;

public:
    InBuyZone(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InBuyZone() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInBuyZone, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInBuyZone, this->m_playerSlot, val);
    }
};

#endif