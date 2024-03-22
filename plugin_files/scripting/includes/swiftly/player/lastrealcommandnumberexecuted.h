#ifndef _player_lastrealcommandnumberexecuted_h
#define _player_lastrealcommandnumberexecuted_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastRealCommandNumberExecuted
{
private:
    uint32_t m_playerSlot;

public:
    LastRealCommandNumberExecuted(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastRealCommandNumberExecuted() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetLastRealCommandNumberExecuted, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastRealCommandNumberExecuted, this->m_playerSlot, val);
    }
};

#endif