#ifndef _player_innodefusearea_h
#define _player_innodefusearea_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class InNoDefuseArea
{
private:
    uint32_t m_playerSlot;

public:
    InNoDefuseArea(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~InNoDefuseArea() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetInNoDefuseArea, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetInNoDefuseArea, this->m_playerSlot, val);
    }
};

#endif