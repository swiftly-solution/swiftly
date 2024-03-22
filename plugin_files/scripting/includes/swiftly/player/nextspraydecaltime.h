#ifndef _player_nextspraydecaltime_h
#define _player_nextspraydecaltime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NextSprayDecalTime
{
private:
    uint32_t m_playerSlot;

public:
    NextSprayDecalTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NextSprayDecalTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetNextSprayDecalTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNextSprayDecalTime, this->m_playerSlot, val);
    }
};

#endif