#ifndef _player_hitbodypart_h
#define _player_hitbodypart_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HitBodyPart
{
private:
    uint32_t m_playerSlot;

public:
    HitBodyPart(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HitBodyPart() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetHitBodyPart, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHitBodyPart, this->m_playerSlot, val);
    }
};

#endif