#ifndef _player_inithud_h
#define _player_inithud_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InitHUD
{
private:
    uint32_t m_playerSlot;

public:
    InitHUD(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InitHUD() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInitHUD, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInitHUD, this->m_playerSlot, val);
    }
};

#endif