#ifndef _player_canmoveduringfreezeperiod_h
#define _player_canmoveduringfreezeperiod_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CanMoveDuringFreezePeriod
{
private:
    uint32_t m_playerSlot;

public:
    CanMoveDuringFreezePeriod(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CanMoveDuringFreezePeriod() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetCanMoveDuringFreezePeriod, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCanMoveDuringFreezePeriod, this->m_playerSlot, val);
    }
};

#endif