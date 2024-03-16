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
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetDesiredFOV, this->m_playerSlot);
    }

    void Set(uint32_t fov)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDesiredFOV, this->m_playerSlot, fov);
    }
};

#endif