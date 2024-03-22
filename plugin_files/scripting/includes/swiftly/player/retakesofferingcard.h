#ifndef _player_retakesofferingcard_h
#define _player_retakesofferingcard_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RetakesOfferingCard
{
private:
    uint32_t m_playerSlot;

public:
    RetakesOfferingCard(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RetakesOfferingCard() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetRetakesOfferingCard, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRetakesOfferingCard, this->m_playerSlot, val);
    }
};

#endif