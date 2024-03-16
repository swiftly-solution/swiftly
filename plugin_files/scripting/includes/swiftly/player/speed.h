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
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetSpeed, this->m_playerSlot);
    }

    void Set(float speed)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSpeed, this->m_playerSlot, speed);
    }
};

#endif