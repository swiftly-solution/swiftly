#ifndef _player_lastfriendlyfiredamagereductionratio_h
#define _player_lastfriendlyfiredamagereductionratio_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class LastFriendlyFireDamageReductionRatio
{
private:
    uint32_t m_playerSlot;

public:
    LastFriendlyFireDamageReductionRatio(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~LastFriendlyFireDamageReductionRatio() {}

    float Get()
    {
        REGISTER_METHOD(float, 0.0f, scripting_Player_GetLastFriendlyFireDamageReductionRatio, this->m_playerSlot);
    }

    void Set(float val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetLastFriendlyFireDamageReductionRatio, this->m_playerSlot, val);
    }
};

#endif