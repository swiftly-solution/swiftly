#ifndef _player_killedbytaser_h
#define _player_killedbytaser_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class KilledByTaser
{
private:
    uint32_t m_playerSlot;

public:
    KilledByTaser(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~KilledByTaser() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetKilledByTaser, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetKilledByTaser, this->m_playerSlot, val);
    }
};

#endif