#ifndef _player_justbecamespectator_h
#define _player_justbecamespectator_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class JustBecameSpectator
{
private:
    uint32_t m_playerSlot;

public:
    JustBecameSpectator(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~JustBecameSpectator() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetJustBecameSpectator, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetJustBecameSpectator, this->m_playerSlot, val);
    }
};

#endif