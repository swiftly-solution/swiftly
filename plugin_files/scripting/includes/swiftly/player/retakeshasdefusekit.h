#ifndef _player_retakeshasdefusekit_h
#define _player_retakeshasdefusekit_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class RetakesHasDefuseKit
{
private:
    uint32_t m_playerSlot;

public:
    RetakesHasDefuseKit(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~RetakesHasDefuseKit() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetRetakesHasDefuseKit, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetRetakesHasDefuseKit, this->m_playerSlot, val);
    }
};

#endif