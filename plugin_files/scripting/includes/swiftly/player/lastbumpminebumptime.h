#ifndef _player_lastbumpminebumptime_h
#define _player_lastbumpminebumptime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastBumpMineBumpTime
{
private:
    uint32_t m_playerSlot;

public:
    LastBumpMineBumpTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastBumpMineBumpTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastBumpMineBumpTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastBumpMineBumpTime, this->m_playerSlot, val);
    }
};

#endif