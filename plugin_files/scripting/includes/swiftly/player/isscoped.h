#ifndef _player_isscoped_h
#define _player_isscoped_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsScoped
{
private:
    uint32_t m_playerSlot;

public:
    IsScoped(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsScoped() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsScoped, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsScoped, this->m_playerSlot, val);
    }
};

#endif