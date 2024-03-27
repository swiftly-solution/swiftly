#ifndef _player_blockinguseactioninprogress_h
#define _player_blockinguseactioninprogress_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class BlockingUseActionInProgress
{
private:
    uint32_t m_playerSlot;

public:
    BlockingUseActionInProgress(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~BlockingUseActionInProgress() {}

    CSPlayerBlockingUseAction_t Get()
    {
        REGISTER_METHOD(CSPlayerBlockingUseAction_t, CSPlayerBlockingUseAction_t::k_CSPlayerBlockingUseAction_None, scripting_Player_GetBlockingUseActionInProgress, this->m_playerSlot);
    }

    void Set(CSPlayerBlockingUseAction_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetBlockingUseActionInProgress, this->m_playerSlot, val);
    }
};

#endif