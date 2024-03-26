#ifndef _player_lastdistancetravelednotice_h
#define _player_lastdistancetravelednotice_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastDistanceTraveledNotice
{
private:
    uint32_t m_playerSlot;

public:
    LastDistanceTraveledNotice(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastDistanceTraveledNotice() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastDistanceTraveledNotice, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastDistanceTraveledNotice, this->m_playerSlot, val);
    }
};

#endif