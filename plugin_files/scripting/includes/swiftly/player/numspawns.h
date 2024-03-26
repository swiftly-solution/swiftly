#ifndef _player_numspawns_h
#define _player_numspawns_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NumSpawns
{
private:
    uint32_t m_playerSlot;

public:
    NumSpawns(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NumSpawns() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetNumSpawns, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNumSpawns, this->m_playerSlot, val);
    }
};

#endif