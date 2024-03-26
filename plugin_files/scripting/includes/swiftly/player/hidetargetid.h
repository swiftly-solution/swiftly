#ifndef _player_hidetargetid_h
#define _player_hidetargetid_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class HideTargetID
{
private:
    uint32_t m_playerSlot;

public:
    HideTargetID(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~HideTargetID() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetHideTargetID, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHideTargetID, this->m_playerSlot, val);
    }
};

#endif