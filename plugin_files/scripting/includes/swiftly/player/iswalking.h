#ifndef _player_iswalking_h
#define _player_iswalking_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsWalking
{
private:
    uint32_t m_playerSlot;

public:
    IsWalking(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsWalking() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsWalking, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsWalking, this->m_playerSlot, val);
    }
};

#endif