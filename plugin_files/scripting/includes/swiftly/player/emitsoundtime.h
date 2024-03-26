#ifndef _player_emitsoundtime_h
#define _player_emitsoundtime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class EmitSoundTime
{
private:
    uint32_t m_playerSlot;

public:
    EmitSoundTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~EmitSoundTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetEmitSoundTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetEmitSoundTime, this->m_playerSlot, val);
    }
};

#endif