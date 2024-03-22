#ifndef _player_landseconds_h
#define _player_landseconds_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Landseconds
{
private:
    uint32_t m_playerSlot;

public:
    Landseconds(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Landseconds() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLandseconds, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLandseconds, this->m_playerSlot, val);
    }
};

#endif