#ifndef _player_draftindex_h
#define _player_draftindex_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class DraftIndex
{
private:
    uint32_t m_playerSlot;

public:
    DraftIndex(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~DraftIndex() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetDraftIndex, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDraftIndex, this->m_playerSlot, val);
    }
};

#endif