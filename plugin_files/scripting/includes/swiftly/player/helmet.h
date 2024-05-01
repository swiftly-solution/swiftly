#ifndef _player_helmet_h
#define _player_helmet_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Helmet
{
private:
    uint32_t m_playerSlot;

public:
    Helmet(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Helmet() {}

    bool Has()
    {
        REGISTER_METHOD(bool, false, scripting_Player_HasHelmet, this->m_playerSlot);
    }

    void Give()
    {
        REGISTER_METHOD_VOID(scripting_Player_GiveHelmet, this->m_playerSlot);
    }

    void Remove()
    {
        REGISTER_METHOD_VOID(scripting_Player_RemoveHelmet, this->m_playerSlot);
    }
};

#endif