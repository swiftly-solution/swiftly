#ifndef _player_diedairborne_h
#define _player_diedairborne_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DiedAirborne
{
private:
    uint32_t m_playerSlot;

public:
    DiedAirborne(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DiedAirborne() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetDiedAirborne, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDiedAirborne, this->m_playerSlot, val);
    }
};

#endif