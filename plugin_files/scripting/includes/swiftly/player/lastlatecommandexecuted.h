#ifndef _player_lastlatecommandexecuted_h
#define _player_lastlatecommandexecuted_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastLateCommandExecuted
{
private:
    uint32_t m_playerSlot;

public:
    LastLateCommandExecuted(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastLateCommandExecuted() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetLastLateCommandExecuted, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastLateCommandExecuted, this->m_playerSlot, val);
    }
};

#endif