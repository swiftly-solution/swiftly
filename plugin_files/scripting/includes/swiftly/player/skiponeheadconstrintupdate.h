#ifndef _player_skiponeheadconstrintupdate_h
#define _player_skiponeheadconstrintupdate_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SkipOneHeadConstrintUpdate
{
private:
    uint32_t m_playerSlot;

public:
    SkipOneHeadConstrintUpdate(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SkipOneHeadConstrintUpdate() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetSkipOneHeadConstrintUpdate, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSkipOneHeadConstrintUpdate, this->m_playerSlot, val);
    }
};

#endif