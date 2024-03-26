#ifndef _player_hasdeathinfo_h
#define _player_hasdeathinfo_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasDeathInfo
{
private:
    uint32_t m_playerSlot;

public:
    HasDeathInfo(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasDeathInfo() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasDeathInfo, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasDeathInfo, this->m_playerSlot, val);
    }
};

#endif