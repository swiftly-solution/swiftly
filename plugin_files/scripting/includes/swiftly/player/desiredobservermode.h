#ifndef _player_desiredobservermode_h
#define _player_desiredobservermode_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DesiredObserverMode
{
private:
    uint32_t m_playerSlot;

public:
    DesiredObserverMode(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DesiredObserverMode() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetDesiredObserverMode, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDesiredObserverMode, this->m_playerSlot, val);
    }
};

#endif