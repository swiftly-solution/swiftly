#ifndef _player_vcollisioninitted_h
#define _player_vcollisioninitted_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class VCollisionInitted
{
private:
    uint32_t m_playerSlot;

public:
    VCollisionInitted(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~VCollisionInitted() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetVCollisionInitted, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetVCollisionInitted, this->m_playerSlot, val);
    }
};

#endif