#ifndef _player_hasnightvision_h
#define _player_hasnightvision_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasNightVision
{
private:
    uint32_t m_playerSlot;

public:
    HasNightVision(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasNightVision() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasNightVision, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasNightVision, this->m_playerSlot, val);
    }
};

#endif