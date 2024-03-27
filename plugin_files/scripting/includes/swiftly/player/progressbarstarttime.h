#ifndef _player_progressbarstarttime_h
#define _player_progressbarstarttime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ProgressBarStartTime
{
private:
    uint32_t m_playerSlot;

public:
    ProgressBarStartTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ProgressBarStartTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetProgressBarStartTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetProgressBarStartTime, this->m_playerSlot, val);
    }
};

#endif