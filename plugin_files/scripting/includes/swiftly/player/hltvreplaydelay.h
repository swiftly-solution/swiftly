#ifndef _player_hltvreplaydelay_h
#define _player_hltvreplaydelay_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HltvReplayDelay
{
private:
    uint32_t m_playerSlot;

public:
    HltvReplayDelay(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HltvReplayDelay() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetHltvReplayDelay, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHltvReplayDelay, this->m_playerSlot, val);
    }
};

#endif