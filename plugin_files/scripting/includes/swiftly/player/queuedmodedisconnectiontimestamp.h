#ifndef _player_queuedmodedisconnectiontimestamp_h
#define _player_queuedmodedisconnectiontimestamp_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class QueuedModeDisconnectionTimestamp
{
private:
    uint32_t m_playerSlot;

public:
    QueuedModeDisconnectionTimestamp(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~QueuedModeDisconnectionTimestamp() {}

    uint32_t Get()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetQueuedModeDisconnectionTimestamp, this->m_playerSlot);
    }

    void Set(uint32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetQueuedModeDisconnectionTimestamp, this->m_playerSlot, val);
    }
};

#endif