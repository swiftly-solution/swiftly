#ifndef _player_everfullyconnected_h
#define _player_everfullyconnected_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class EverFullyConnected
{
private:
    uint32_t m_playerSlot;

public:
    EverFullyConnected(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~EverFullyConnected() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetEverFullyConnected, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetEverFullyConnected, this->m_playerSlot, val);
    }
};

#endif