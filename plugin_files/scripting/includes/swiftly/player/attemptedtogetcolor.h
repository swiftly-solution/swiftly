#ifndef _player_attemptedtogetcolor_h
#define _player_attemptedtogetcolor_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class AttemptedToGetColor
{
private:
    uint32_t m_playerSlot;

public:
    AttemptedToGetColor(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~AttemptedToGetColor() {}

    bool Get()
    {
        REGISTER_METHOD(bool, false, scripting_Player_GetAttemptedToGetColor, this->m_playerSlot);
    }

    void Set(bool val)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetAttemptedToGetColor, this->m_playerSlot, val);
    }
};

#endif