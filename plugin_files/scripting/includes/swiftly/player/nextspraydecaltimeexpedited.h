#ifndef _player_nextspraydecaltimeexpedited_h
#define _player_nextspraydecaltimeexpedited_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NextSprayDecalTimeExpedited
{
private:
    uint32_t m_playerSlot;

public:
    NextSprayDecalTimeExpedited(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NextSprayDecalTimeExpedited() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetNextSprayDecalTimeExpedited, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNextSprayDecalTimeExpedited, this->m_playerSlot, val);
    }
};

#endif