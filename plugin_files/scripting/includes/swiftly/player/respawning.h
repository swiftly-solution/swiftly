#ifndef _player_respawning_h
#define _player_respawning_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Respawning
{
private:
    uint32_t m_playerSlot;

public:
    Respawning(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Respawning() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetRespawning, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRespawning, this->m_playerSlot, val);
    }
};

#endif