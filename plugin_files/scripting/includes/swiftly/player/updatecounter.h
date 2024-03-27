#ifndef _player_updatecounter_h
#define _player_updatecounter_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class UpdateCounter
{
private:
    uint32_t m_playerSlot;

public:
    UpdateCounter(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~UpdateCounter() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetUpdateCounter, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetUpdateCounter, this->m_playerSlot, val);
    }
};

#endif