#ifndef _player_hltvreplayend_h
#define _player_hltvreplayend_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HltvReplayEnd
{
private:
    uint32_t m_playerSlot;

public:
    HltvReplayEnd(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HltvReplayEnd() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetHltvReplayEnd, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHltvReplayEnd, this->m_playerSlot, val);
    }
};

#endif