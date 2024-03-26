#ifndef _player_hascommunicationabusemute_h
#define _player_hascommunicationabusemute_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasCommunicationAbuseMute
{
private:
    uint32_t m_playerSlot;

public:
    HasCommunicationAbuseMute(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasCommunicationAbuseMute() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasCommunicationAbuseMute, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasCommunicationAbuseMute, this->m_playerSlot, val);
    }
};

#endif