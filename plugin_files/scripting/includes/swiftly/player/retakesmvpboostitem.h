#ifndef _player_retakesmvpboostitem_h
#define _player_retakesmvpboostitem_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RetakesMVPBoostItem
{
private:
    uint32_t m_playerSlot;

public:
    RetakesMVPBoostItem(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RetakesMVPBoostItem() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetRetakesMVPBoostItem, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRetakesMVPBoostItem, this->m_playerSlot, val);
    }
};

#endif