#ifndef _player_hasbeencontrolledbyplayerthisround_h
#define _player_hasbeencontrolledbyplayerthisround_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasBeenControlledByPlayerThisRound
{
private:
    uint32_t m_playerSlot;

public:
    HasBeenControlledByPlayerThisRound(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasBeenControlledByPlayerThisRound() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasBeenControlledByPlayerThisRound, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasBeenControlledByPlayerThisRound, this->m_playerSlot, val);
    }
};

#endif