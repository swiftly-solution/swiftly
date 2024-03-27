#ifndef _player_isgrabbinghostage_h
#define _player_isgrabbinghostage_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsGrabbingHostage
{
private:
    uint32_t m_playerSlot;

public:
    IsGrabbingHostage(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsGrabbingHostage() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsGrabbingHostage, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsGrabbingHostage, this->m_playerSlot, val);
    }
};

#endif