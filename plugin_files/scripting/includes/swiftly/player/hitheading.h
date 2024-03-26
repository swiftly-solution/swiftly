#ifndef _player_hitheading_h
#define _player_hitheading_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HitHeading
{
private:
    uint32_t m_playerSlot;

public:
    HitHeading(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HitHeading() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetHitHeading, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHitHeading, this->m_playerSlot, val);
    }
};

#endif