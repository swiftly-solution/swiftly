#ifndef _player_progressbarduration_h
#define _player_progressbarduration_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ProgressBarDuration
{
private:
    uint32_t m_playerSlot;

public:
    ProgressBarDuration(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ProgressBarDuration() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetProgressBarDuration, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetProgressBarDuration, this->m_playerSlot, val);
    }
};

#endif