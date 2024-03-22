#ifndef _player_hasfemalevoice_h
#define _player_hasfemalevoice_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HasFemaleVoice
{
private:
    uint32_t m_playerSlot;

public:
    HasFemaleVoice(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HasFemaleVoice() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHasFemaleVoice, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHasFemaleVoice, this->m_playerSlot, val);
    }
};

#endif