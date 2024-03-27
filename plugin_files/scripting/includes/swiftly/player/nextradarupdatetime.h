#ifndef _player_nextradarupdatetime_h
#define _player_nextradarupdatetime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NextRadarUpdateTime
{
private:
    uint32_t m_playerSlot;

public:
    NextRadarUpdateTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NextRadarUpdateTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetNextRadarUpdateTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNextRadarUpdateTime, this->m_playerSlot, val);
    }
};

#endif