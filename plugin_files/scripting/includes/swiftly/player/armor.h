#ifndef _player_armor_h
#define _player_armor_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Armor
{
private:
    uint32_t m_playerSlot;

public:
    Armor(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Armor() {}

    int Get()
    {
        REGISTER_METHOD(int, 0, scripting_Player_GetArmor, this->m_playerSlot);
    }

    void Set(int armor)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetArmor, this->m_playerSlot, armor);
    }

    void Take(int armor)
    {
        REGISTER_METHOD_VOID(scripting_Player_TakeArmor, this->m_playerSlot, armor);
    }
};

#endif