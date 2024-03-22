#ifndef _player_gamepaused_h
#define _player_gamepaused_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class GamePaused
{
private:
    uint32_t m_playerSlot;

public:
    GamePaused(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~GamePaused() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetGamePaused, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGamePaused, this->m_playerSlot, val);
    }
};

#endif