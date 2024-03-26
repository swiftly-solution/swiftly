#ifndef _player_lastreceivedpacketplatfloattime_h
#define _player_lastreceivedpacketplatfloattime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastReceivedPacketPlatFloatTime
{
private:
    uint32_t m_playerSlot;

public:
    LastReceivedPacketPlatFloatTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastReceivedPacketPlatFloatTime() {}

    double Get()
    {
        REGISTER_METHOD(double, 0.0f, scripting_Player_GetLastReceivedPacketPlatFloatTime, this->m_playerSlot);
    }

    void Set(double val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastReceivedPacketPlatFloatTime, this->m_playerSlot, val);
    }
};

#endif