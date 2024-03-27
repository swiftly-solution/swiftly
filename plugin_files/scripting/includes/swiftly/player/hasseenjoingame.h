#ifndef _player_hasseenjoingame_h
#define _player_hasseenjoingame_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasSeenJoinGame
{
private:
    uint32_t m_playerSlot;

public:
    HasSeenJoinGame(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasSeenJoinGame() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasSeenJoinGame, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasSeenJoinGame, this->m_playerSlot, val);
    }
};

#endif