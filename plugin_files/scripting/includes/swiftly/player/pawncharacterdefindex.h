#ifndef _player_pawncharacterdefindex_h
#define _player_pawncharacterdefindex_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PawnCharacterDefIndex
{
private:
    uint32_t m_playerSlot;

public:
    PawnCharacterDefIndex(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PawnCharacterDefIndex() {}

    uint16_t Get()
    {
        REGISTER_METHOD(uint16_t, 0, scripting_Player_GetPawnCharacterDefIndex, this->m_playerSlot);
    }

    void Set(uint16_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPawnCharacterDefIndex, this->m_playerSlot, val);
    }
};

#endif