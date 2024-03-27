#ifndef _player_isspawning_h
#define _player_isspawning_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class IsSpawning
{
private:
    uint32_t m_playerSlot;

public:
    IsSpawning(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~IsSpawning() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetIsSpawning, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetIsSpawning, this->m_playerSlot, val);
    }
};

#endif