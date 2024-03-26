#ifndef _player_molotovdamagetime_h
#define _player_molotovdamagetime_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class MolotovDamageTime
{
private:
    uint32_t m_playerSlot;

public:
    MolotovDamageTime(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~MolotovDamageTime() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetMolotovDamageTime, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMolotovDamageTime, this->m_playerSlot, val);
    }
};

#endif