#ifndef _player_nightvisionon_h
#define _player_nightvisionon_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NightVisionOn
{
private:
    uint32_t m_playerSlot;

public:
    NightVisionOn(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NightVisionOn() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetNightVisionOn, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNightVisionOn, this->m_playerSlot, val);
    }
};

#endif