#ifndef _player_heavyassaultsuitcooldownremaining_h
#define _player_heavyassaultsuitcooldownremaining_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HeavyAssaultSuitCooldownRemaining
{
private:
    uint32_t m_playerSlot;

public:
    HeavyAssaultSuitCooldownRemaining(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HeavyAssaultSuitCooldownRemaining() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetHeavyAssaultSuitCooldownRemaining, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHeavyAssaultSuitCooldownRemaining, this->m_playerSlot, val);
    }
};

#endif