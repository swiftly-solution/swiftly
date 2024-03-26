#ifndef _player_activequestid_h
#define _player_activequestid_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ActiveQuestId
{
private:
    uint32_t m_playerSlot;

public:
    ActiveQuestId(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ActiveQuestId() {}

    uint16_t Get()
    {
        REGISTER_METHOD(uint16_t, 0, scripting_Player_GetActiveQuestId, this->m_playerSlot);
    }

    void Set(uint16_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetActiveQuestId, this->m_playerSlot, val);
    }
};

#endif