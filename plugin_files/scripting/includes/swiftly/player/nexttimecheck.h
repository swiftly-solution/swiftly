#ifndef _player_nexttimecheck_h
#define _player_nexttimecheck_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NextTimeCheck
{
private:
    uint32_t m_playerSlot;

public:
    NextTimeCheck(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NextTimeCheck() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetNextTimeCheck, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNextTimeCheck, this->m_playerSlot, val);
    }
};

#endif