#ifndef _player_health_h
#define _player_health_h

#include <stdint.h>
#include "../swiftly_memory.h"

class Health
{
private:
    uint32_t m_playerSlot;

public:
    Health(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Health() {}

    int Get()
    {
        void *player_GetHealth = FetchFunctionPtr(nullptr, "scripting_Player_GetHealth");
        if (player_GetHealth)
            return reinterpret_cast<Player_GetHealth>(player_GetHealth)(this->m_playerSlot);
        else
            return 0;
    }

    void Set(int health)
    {
        void *player_SetHealth = FetchFunctionPtr(nullptr, "scripting_Player_SetHealth");
        if (player_SetHealth)
            reinterpret_cast<Player_SetHealth>(player_SetHealth)(this->m_playerSlot, health);
    }

    void Take(int health)
    {
        void *player_TakeHealth = FetchFunctionPtr(nullptr, "scripting_Player_TakeHealth");
        if (player_TakeHealth)
            reinterpret_cast<Player_TakeHealth>(player_TakeHealth)(this->m_playerSlot, health);
    }
};

#endif