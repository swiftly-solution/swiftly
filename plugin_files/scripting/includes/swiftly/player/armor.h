#ifndef _player_armor_h
#define _player_armor_h

#include <stdint.h>
#include "../swiftly_memory.h"

class Armor
{
private:
    uint32_t m_playerSlot;

public:
    Armor(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Armor() {}

    int Get()
    {
        void *player_GetArmor = FetchFunctionPtr(nullptr, "scripting_Player_GetArmor");
        if (player_GetArmor)
            return reinterpret_cast<Player_GetArmor>(player_GetArmor)(this->m_playerSlot);
        else
            return 0;
    }

    void Set(int armor)
    {
        void *player_SetArmor = FetchFunctionPtr(nullptr, "scripting_Player_SetArmor");
        if (player_SetArmor)
            reinterpret_cast<Player_SetArmor>(player_SetArmor)(this->m_playerSlot, armor);
    }

    void Take(int armor)
    {
        void *player_TakeArmor = FetchFunctionPtr(nullptr, "scripting_Player_TakeArmor");
        if (player_TakeArmor)
            reinterpret_cast<Player_TakeArmor>(player_TakeArmor)(this->m_playerSlot, armor);
    }
};

#endif