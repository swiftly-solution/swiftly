#ifndef _player_ragdolldamageheadshot_h
#define _player_ragdolldamageheadshot_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RagdollDamageHeadshot
{
private:
    uint32_t m_playerSlot;

public:
    RagdollDamageHeadshot(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RagdollDamageHeadshot() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetRagdollDamageHeadshot, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRagdollDamageHeadshot, this->m_playerSlot, val);
    }
};

#endif