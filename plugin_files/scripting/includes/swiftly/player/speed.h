#ifndef _player_speed_h
#define _player_speed_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Speed
{
private:
    uint32_t m_playerSlot;

public:
    Speed(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Speed() {}

    float Get()
    {
        void *player_GetSpeed = FetchFunctionPtr(nullptr, "scripting_Player_GetSpeed");
        if (player_GetSpeed)
            return reinterpret_cast<Player_GetGravity>(player_GetSpeed)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetSpeed");
            return 0.0f;
        }
    }

    void Set(float speed)
    {
        void *player_SetSpeed = FetchFunctionPtr(nullptr, "scripting_Player_SetSpeed");
        if (player_SetSpeed)
            reinterpret_cast<Player_SetGravity>(player_SetSpeed)(this->m_playerSlot, speed);
        else
            NOT_SUPPORTED("scripting_Player_SetSpeed");
    }
};

#endif