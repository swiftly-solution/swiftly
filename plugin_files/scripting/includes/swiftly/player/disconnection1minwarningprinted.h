#ifndef _player_disconnection1minwarningprinted_h
#define _player_disconnection1minwarningprinted_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Disconnection1MinWarningPrinted
{
private:
    uint32_t m_playerSlot;

public:
    Disconnection1MinWarningPrinted(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Disconnection1MinWarningPrinted() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetDisconnection1MinWarningPrinted, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetDisconnection1MinWarningPrinted, this->m_playerSlot, val);
    }
};

#endif