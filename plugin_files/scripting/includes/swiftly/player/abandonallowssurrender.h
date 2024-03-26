#ifndef _player_abandonallowssurrender_h
#define _player_abandonallowssurrender_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AbandonAllowsSurrender
{
private:
    uint32_t m_playerSlot;

public:
    AbandonAllowsSurrender(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AbandonAllowsSurrender() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetAbandonAllowsSurrender, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAbandonAllowsSurrender, this->m_playerSlot, val);
    }
};

#endif