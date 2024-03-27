#ifndef _player_shouldhavecash_h
#define _player_shouldhavecash_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ShouldHaveCash
{
private:
    uint32_t m_playerSlot;

public:
    ShouldHaveCash(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ShouldHaveCash() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetShouldHaveCash, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetShouldHaveCash, this->m_playerSlot, val);
    }
};

#endif