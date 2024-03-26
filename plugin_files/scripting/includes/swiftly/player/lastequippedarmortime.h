#ifndef _player_lastequippedarmortime_h
#define _player_lastequippedarmortime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastEquippedArmorTime
{
private:
    uint32_t m_playerSlot;

public:
    LastEquippedArmorTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastEquippedArmorTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastEquippedArmorTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastEquippedArmorTime, this->m_playerSlot, val);
    }
};

#endif