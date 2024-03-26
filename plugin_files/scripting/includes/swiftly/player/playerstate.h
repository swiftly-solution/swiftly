#ifndef _player_playerstate_h
#define _player_playerstate_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PlayerState
{
private:
    uint32_t m_playerSlot;

public:
    PlayerState(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PlayerState() {}

    CSPlayerState Get()
    {
        REGISTER_METHOD(CSPlayerState, CSPlayerState::STATE_ACTIVE, scripting_Player_GetPlayerState, this->m_playerSlot);
    }

    void Set(CSPlayerState val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPlayerState, this->m_playerSlot, val);
    }
};

#endif