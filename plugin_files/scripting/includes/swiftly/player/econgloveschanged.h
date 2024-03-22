#ifndef _player_econgloveschanged_h
#define _player_econgloveschanged_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class EconGlovesChanged
{
private:
    uint32_t m_playerSlot;

public:
    EconGlovesChanged(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~EconGlovesChanged() {}

    uint8_t Get()
    {
        REGISTER_METHOD(uint8_t, 0, scripting_Player_GetEconGlovesChanged, this->m_playerSlot);
    }

    void Set(uint8_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetEconGlovesChanged, this->m_playerSlot, val);
    }
};

#endif