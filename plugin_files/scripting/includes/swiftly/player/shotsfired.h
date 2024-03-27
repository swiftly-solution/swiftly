#ifndef _player_shotsfired_h
#define _player_shotsfired_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ShotsFired
{
private:
    uint32_t m_playerSlot;

public:
    ShotsFired(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ShotsFired() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetShotsFired, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetShotsFired, this->m_playerSlot, val);
    }
};

#endif