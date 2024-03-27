#ifndef _player_displayhistorybits_h
#define _player_displayhistorybits_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DisplayHistoryBits
{
private:
    uint32_t m_playerSlot;

public:
    DisplayHistoryBits(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DisplayHistoryBits() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetDisplayHistoryBits, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDisplayHistoryBits, this->m_playerSlot, val);
    }
};

#endif