#ifndef _player_showhints_h
#define _player_showhints_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ShowHints
{
private:
    uint32_t m_playerSlot;

public:
    ShowHints(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ShowHints() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetShowHints, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetShowHints, this->m_playerSlot, val);
    }
};

#endif