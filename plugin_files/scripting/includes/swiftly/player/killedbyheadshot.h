#ifndef _player_killedbyheadshot_h
#define _player_killedbyheadshot_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class KilledByHeadshot
{
private:
    uint32_t m_playerSlot;

public:
    KilledByHeadshot(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~KilledByHeadshot() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetKilledByHeadshot, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetKilledByHeadshot, this->m_playerSlot, val);
    }
};

#endif