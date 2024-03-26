#ifndef _player_flinchstack_h
#define _player_flinchstack_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class FlinchStack
{
private:
    uint32_t m_playerSlot;

public:
    FlinchStack(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~FlinchStack() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetFlinchStack, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetFlinchStack, this->m_playerSlot, val);
    }
};

#endif