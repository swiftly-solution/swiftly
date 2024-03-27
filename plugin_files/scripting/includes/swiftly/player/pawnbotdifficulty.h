#ifndef _player_pawnbotdifficulty_h
#define _player_pawnbotdifficulty_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class PawnBotDifficulty
{
private:
    uint32_t m_playerSlot;

public:
    PawnBotDifficulty(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~PawnBotDifficulty() {}

    int32_t Get()
    {
        REGISTER_METHOD(int32_t, 0, scripting_Player_GetPawnBotDifficulty, this->m_playerSlot);
    }

    void Set(int32_t val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPawnBotDifficulty, this->m_playerSlot, val);
    }
};

#endif