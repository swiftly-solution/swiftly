#ifndef _player_wasnotkillednaturally_h
#define _player_wasnotkillednaturally_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class WasNotKilledNaturally
{
private:
    uint32_t m_playerSlot;

public:
    WasNotKilledNaturally(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~WasNotKilledNaturally() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetWasNotKilledNaturally, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetWasNotKilledNaturally, this->m_playerSlot, val);
    }
};

#endif