#ifndef _player_retakesoffering_h
#define _player_retakesoffering_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RetakesOffering
{
private:
    uint32_t m_playerSlot;

public:
    RetakesOffering(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RetakesOffering() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetRetakesOffering, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRetakesOffering, this->m_playerSlot, val);
    }
};

#endif