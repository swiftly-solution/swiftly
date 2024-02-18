#ifndef _player_gravity_h
#define _player_gravity_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Gravity
{
private:
    uint32_t m_playerSlot;

public:
    Gravity(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Gravity() {}

    float Get()
    {
        void *player_GetGravity = FetchFunctionPtr(nullptr, "scripting_Player_GetGravity");
        if (player_GetGravity)
            return reinterpret_cast<Player_GetGravity>(player_GetGravity)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetGravity");
            return 0.0f;
        }
    }

    void Set(float gravity)
    {
        void *player_SetGravity = FetchFunctionPtr(nullptr, "scripting_Player_SetGravity");
        if (player_SetGravity)
            reinterpret_cast<Player_SetGravity>(player_SetGravity)(this->m_playerSlot, gravity);
        else
            NOT_SUPPORTED("scripting_Player_SetGravity");
    }
};

#endif