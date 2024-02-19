#ifndef _player_fov_h
#define _player_fov_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Fov
{
private:
    uint32_t m_playerSlot;

public:
    Fov(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Fov() {}

    uint32_t Get()
    {
        void *player_GetDesiredFOV = FetchFunctionPtr(nullptr, "scripting_Player_GetDesiredFOV");
        if (player_GetDesiredFOV)
            return reinterpret_cast<Player_GetDesiredFOV>(player_GetDesiredFOV)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetDesiredFOV");
            return 0;
        }
    }

    void Set(uint32_t fov)
    {
        void *player_SetDesiredFOV = FetchFunctionPtr(nullptr, "scripting_Player_SetDesiredFOV");
        if (player_SetDesiredFOV)
            reinterpret_cast<Player_SetDesiredFOV>(player_SetDesiredFOV)(this->m_playerSlot, fov);
        else
            NOT_SUPPORTED("scripting_Player_SetDesiredFOV");
    }
};

#endif