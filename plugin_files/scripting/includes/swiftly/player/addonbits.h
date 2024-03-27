#ifndef _player_addonbits_h
#define _player_addonbits_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AddonBits
{
private:
    uint32_t m_playerSlot;

public:
    AddonBits(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AddonBits() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetAddonBits, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAddonBits, this->m_playerSlot, val);
    }
};

#endif