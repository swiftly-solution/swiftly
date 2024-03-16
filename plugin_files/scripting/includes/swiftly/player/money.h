#ifndef _player_money_h
#define _player_money_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class Money
{
private:
    uint32_t m_playerSlot;

public:
    Money(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~Money() {}

    int Get()
    {
        REGISTER_METHOD(int, 0, scripting_Player_GetMoney, this->m_playerSlot);
    }

    void Set(int money)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMoney, this->m_playerSlot, money);
    }

    void Take(int money)
    {
        REGISTER_METHOD_VOID(scripting_Player_TakeMoney, this->m_playerSlot, money);
    }
};

#endif