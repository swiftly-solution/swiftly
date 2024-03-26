#ifndef _player_isdefusing_h
#define _player_isdefusing_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsDefusing
{
private:
    uint32_t m_playerSlot;

public:
    IsDefusing(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsDefusing() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsDefusing, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsDefusing, this->m_playerSlot, val);
    }
};

#endif