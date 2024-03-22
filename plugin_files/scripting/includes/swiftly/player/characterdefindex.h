#ifndef _player_characterdefindex_h
#define _player_characterdefindex_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class CharacterDefIndex
{
private:
    uint32_t m_playerSlot;

public:
    CharacterDefIndex(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~CharacterDefIndex() {}

    uint16_t Get()
    {
        REGISTER_METHOD(uint16_t, 0, scripting_Player_GetCharacterDefIndex, this->m_playerSlot);
    }

    void Set(uint16_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCharacterDefIndex, this->m_playerSlot, val);
    }
};

#endif