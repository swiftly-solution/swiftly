#ifndef _player_mvps_h
#define _player_mvps_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class MVPs
{
private:
    uint32_t m_playerSlot;

public:
    MVPs(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~MVPs() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetMVPs, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMVPs, this->m_playerSlot, val);
    }
};

#endif