#ifndef _player_numdangerzonedamagehits_h
#define _player_numdangerzonedamagehits_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class NumDangerZoneDamageHits
{
private:
    uint32_t m_playerSlot;

public:
    NumDangerZoneDamageHits(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~NumDangerZoneDamageHits() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetNumDangerZoneDamageHits, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNumDangerZoneDamageHits, this->m_playerSlot, val);
    }
};

#endif