#ifndef _player_highestgeneratedserverviewanglechangeindex_h
#define _player_highestgeneratedserverviewanglechangeindex_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HighestGeneratedServerViewAngleChangeIndex
{
private:
    uint32_t m_playerSlot;

public:
    HighestGeneratedServerViewAngleChangeIndex(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HighestGeneratedServerViewAngleChangeIndex() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetHighestGeneratedServerViewAngleChangeIndex, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHighestGeneratedServerViewAngleChangeIndex, this->m_playerSlot, val);
    }
};

#endif