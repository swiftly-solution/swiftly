#ifndef _player_cannotbekicked_h
#define _player_cannotbekicked_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CannotBeKicked
{
private:
    uint32_t m_playerSlot;

public:
    CannotBeKicked(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CannotBeKicked() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetCannotBeKicked, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCannotBeKicked, this->m_playerSlot, val);
    }
};

#endif