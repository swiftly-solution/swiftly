#ifndef _player_hidehud_h
#define _player_hidehud_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HideHUD
{
private:
    uint32_t m_playerSlot;

public:
    HideHUD(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HideHUD() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetHideHUD, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHideHUD, this->m_playerSlot, val);
    }
};

#endif