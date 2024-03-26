#ifndef _player_spotrules_h
#define _player_spotrules_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SpotRules
{
private:
    uint32_t m_playerSlot;

public:
    SpotRules(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SpotRules() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetSpotRules, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSpotRules, this->m_playerSlot, val);
    }
};

#endif