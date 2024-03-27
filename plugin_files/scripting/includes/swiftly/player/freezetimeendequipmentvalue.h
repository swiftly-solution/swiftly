#ifndef _player_freezetimeendequipmentvalue_h
#define _player_freezetimeendequipmentvalue_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class FreezetimeEndEquipmentValue
{
private:
    uint32_t m_playerSlot;

public:
    FreezetimeEndEquipmentValue(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~FreezetimeEndEquipmentValue() {}

    uint16_t Get()
    {
        REGISTER_METHOD(uint16_t, 0, scripting_Player_GetFreezetimeEndEquipmentValue, this->m_playerSlot);
    }

    void Set(uint16_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetFreezetimeEndEquipmentValue, this->m_playerSlot, val);
    }
};

#endif