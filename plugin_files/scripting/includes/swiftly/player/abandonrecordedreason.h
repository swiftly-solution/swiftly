#ifndef _player_abandonrecordedreason_h
#define _player_abandonrecordedreason_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AbandonRecordedReason
{
private:
    uint32_t m_playerSlot;

public:
    AbandonRecordedReason(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AbandonRecordedReason() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetAbandonRecordedReason, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAbandonRecordedReason, this->m_playerSlot, val);
    }
};

#endif