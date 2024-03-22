#ifndef _player_ragdolldamagebone_h
#define _player_ragdolldamagebone_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RagdollDamageBone
{
private:
    uint32_t m_playerSlot;

public:
    RagdollDamageBone(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RagdollDamageBone() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetRagdollDamageBone, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRagdollDamageBone, this->m_playerSlot, val);
    }
};

#endif