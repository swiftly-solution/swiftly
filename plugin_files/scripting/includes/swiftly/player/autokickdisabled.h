#ifndef _player_autokickdisabled_h
#define _player_autokickdisabled_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AutoKickDisabled
{
private:
    uint32_t m_playerSlot;

public:
    AutoKickDisabled(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AutoKickDisabled() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetAutoKickDisabled, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAutoKickDisabled, this->m_playerSlot, val);
    }
};

#endif