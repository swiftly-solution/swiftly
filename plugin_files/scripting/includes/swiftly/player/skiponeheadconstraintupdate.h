#ifndef _player_skiponeheadconstraintupdate_h
#define _player_skiponeheadconstraintupdate_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class SkipOneHeadConstraintUpdate
{
private:
    uint32_t m_playerSlot;

public:
    SkipOneHeadConstraintUpdate(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~SkipOneHeadConstraintUpdate() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetSkipOneHeadConstraintUpdate, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetSkipOneHeadConstraintUpdate, this->m_playerSlot, val);
    }
};

#endif