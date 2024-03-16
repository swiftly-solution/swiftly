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
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetGravity, this->m_playerSlot);
    }

    void Set(float gravity)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGravity, this->m_playerSlot, gravity);
    }
};

#endif