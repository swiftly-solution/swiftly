#ifndef _player_aimpunchtickbase_h
#define _player_aimpunchtickbase_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AimPunchTickBase
{
private:
    uint32_t m_playerSlot;

public:
    AimPunchTickBase(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AimPunchTickBase() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetAimPunchTickBase, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAimPunchTickBase, this->m_playerSlot, val);
    }
};

#endif