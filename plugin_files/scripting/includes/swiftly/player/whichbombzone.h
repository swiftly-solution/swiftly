#ifndef _player_whichbombzone_h
#define _player_whichbombzone_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class WhichBombZone
{
private:
    uint32_t m_playerSlot;

public:
    WhichBombZone(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~WhichBombZone() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetWhichBombZone, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetWhichBombZone, this->m_playerSlot, val);
    }
};

#endif