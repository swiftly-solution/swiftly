#ifndef _player_health_h
#define _player_health_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Health
{
private:
    uint32_t m_playerSlot;

public:
    Health(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Health() {}

    int Get()
    {
        REGISTER_METHOD(int, 0, scripting_Player_GetHealth, this->m_playerSlot);
    }

    void Set(int health)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHealth, this->m_playerSlot, health);
    }

    void Take(int health)
    {
        REGISTER_METHOD_VOID(scripting_Player_TakeHealth, this->m_playerSlot, health);
    }

    int GetMax()
    {
        REGISTER_METHOD(int, 0, scripting_Player_GetMaxHealth, this->m_playerSlot);
    }

    void SetMax(int health)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMaxHealth, this->m_playerSlot, health);
    }
};

#endif