#ifndef _player_secondaryaddon_h
#define _player_secondaryaddon_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SecondaryAddon
{
private:
    uint32_t m_playerSlot;

public:
    SecondaryAddon(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SecondaryAddon() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetSecondaryAddon, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSecondaryAddon, this->m_playerSlot, val);
    }
};

#endif