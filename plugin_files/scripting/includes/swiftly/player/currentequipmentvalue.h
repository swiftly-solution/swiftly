#ifndef _player_currentequipmentvalue_h
#define _player_currentequipmentvalue_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CurrentEquipmentValue
{
private:
    uint32_t m_playerSlot;

public:
    CurrentEquipmentValue(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CurrentEquipmentValue() {}

    uint16_t Get()
    {
        REGISTER_METHOD(uint16_t, 0, scripting_Player_GetCurrentEquipmentValue, this->m_playerSlot);
    }

    void Set(uint16_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCurrentEquipmentValue, this->m_playerSlot, val);
    }
};

#endif