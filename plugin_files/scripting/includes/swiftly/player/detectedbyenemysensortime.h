#ifndef _player_detectedbyenemysensortime_h
#define _player_detectedbyenemysensortime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DetectedByEnemySensorTime
{
private:
    uint32_t m_playerSlot;

public:
    DetectedByEnemySensorTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DetectedByEnemySensorTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetDetectedByEnemySensorTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDetectedByEnemySensorTime, this->m_playerSlot, val);
    }
};

#endif