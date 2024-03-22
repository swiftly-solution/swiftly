#ifndef _player_isbuymenuopen_h
#define _player_isbuymenuopen_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsBuyMenuOpen
{
private:
    uint32_t m_playerSlot;

public:
    IsBuyMenuOpen(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsBuyMenuOpen() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsBuyMenuOpen, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsBuyMenuOpen, this->m_playerSlot, val);
    }
};

#endif