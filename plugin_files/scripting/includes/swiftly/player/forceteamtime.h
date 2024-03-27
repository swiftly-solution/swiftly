#ifndef _player_forceteamtime_h
#define _player_forceteamtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ForceTeamTime
{
private:
    uint32_t m_playerSlot;

public:
    ForceTeamTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ForceTeamTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetForceTeamTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetForceTeamTime, this->m_playerSlot, val);
    }
};

#endif