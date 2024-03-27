#ifndef _player_removeallitemsonnextroundreset_h
#define _player_removeallitemsonnextroundreset_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RemoveAllItemsOnNextRoundReset
{
private:
    uint32_t m_playerSlot;

public:
    RemoveAllItemsOnNextRoundReset(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RemoveAllItemsOnNextRoundReset() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetRemoveAllItemsOnNextRoundReset, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRemoveAllItemsOnNextRoundReset, this->m_playerSlot, val);
    }
};

#endif