#ifndef _player_roundstartequipmentvalue_h
#define _player_roundstartequipmentvalue_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RoundStartEquipmentValue
{
private:
    uint32_t m_playerSlot;

public:
    RoundStartEquipmentValue(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RoundStartEquipmentValue() {}

    uint16_t Get()
    {
        REGISTER_METHOD(uint16_t, 0, scripting_Player_GetRoundStartEquipmentValue, this->m_playerSlot);
    }

    void Set(uint16_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRoundStartEquipmentValue, this->m_playerSlot, val);
    }
};

#endif