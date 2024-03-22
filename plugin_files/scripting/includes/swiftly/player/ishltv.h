#ifndef _player_ishltv_h
#define _player_ishltv_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsHLTV
{
private:
    uint32_t m_playerSlot;

public:
    IsHLTV(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsHLTV() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsHLTV, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsHLTV, this->m_playerSlot, val);
    }
};

#endif