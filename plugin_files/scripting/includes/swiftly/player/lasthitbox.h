#ifndef _player_lasthitbox_h
#define _player_lasthitbox_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastHitBox
{
private:
    uint32_t m_playerSlot;

public:
    LastHitBox(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastHitBox() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetLastHitBox, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastHitBox, this->m_playerSlot, val);
    }
};

#endif