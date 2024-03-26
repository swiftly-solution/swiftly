#ifndef _player_abandonoffersinstantsurrender_h
#define _player_abandonoffersinstantsurrender_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AbandonOffersInstantSurrender
{
private:
    uint32_t m_playerSlot;

public:
    AbandonOffersInstantSurrender(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AbandonOffersInstantSurrender() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetAbandonOffersInstantSurrender, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAbandonOffersInstantSurrender, this->m_playerSlot, val);
    }
};

#endif