#ifndef _player_islowviolence_h
#define _player_islowviolence_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsLowViolence
{
private:
    uint32_t m_playerSlot;

public:
    IsLowViolence(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsLowViolence() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsLowViolence, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsLowViolence, this->m_playerSlot, val);
    }
};

#endif