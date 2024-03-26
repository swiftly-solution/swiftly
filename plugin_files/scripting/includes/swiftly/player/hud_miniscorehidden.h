#ifndef _player_hud_miniscorehidden_h
#define _player_hud_miniscorehidden_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Hud_MiniScoreHidden
{
private:
    uint32_t m_playerSlot;

public:
    Hud_MiniScoreHidden(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Hud_MiniScoreHidden() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHud_MiniScoreHidden, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHud_MiniScoreHidden, this->m_playerSlot, val);
    }
};

#endif