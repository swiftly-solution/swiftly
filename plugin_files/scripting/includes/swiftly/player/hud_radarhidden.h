#ifndef _player_hud_radarhidden_h
#define _player_hud_radarhidden_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Hud_RadarHidden
{
private:
    uint32_t m_playerSlot;

public:
    Hud_RadarHidden(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Hud_RadarHidden() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHud_RadarHidden, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHud_RadarHidden, this->m_playerSlot, val);
    }
};

#endif