#ifndef _player_allowautofollowtime_h
#define _player_allowautofollowtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class allowAutoFollowTime
{
private:
    uint32_t m_playerSlot;

public:
    allowAutoFollowTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~allowAutoFollowTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetallowAutoFollowTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetallowAutoFollowTime, this->m_playerSlot, val);
    }
};

#endif