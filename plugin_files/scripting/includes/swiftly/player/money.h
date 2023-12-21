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
        void *player_GetMoney = FetchFunctionPtr(nullptr, "scripting_Player_GetMoney");
        if (player_GetMoney)
            return reinterpret_cast<Player_GetMoney>(player_GetMoney)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetMoney");
            return 0;
        }
    }

    void Set(int money)
    {
        void *player_SetMoney = FetchFunctionPtr(nullptr, "scripting_Player_SetMoney");
        if (player_SetMoney)
            reinterpret_cast<Player_SetMoney>(player_SetMoney)(this->m_playerSlot, money);
        else
            NOT_SUPPORTED("scripting_Player_SetMoney");
    }

    void Take(int money)
    {
        void *player_TakeMoney = FetchFunctionPtr(nullptr, "scripting_Player_TakeMoney");
        if (player_TakeMoney)
            reinterpret_cast<Player_TakeMoney>(player_TakeMoney)(this->m_playerSlot, money);
        else
            NOT_SUPPORTED("scripting_Player_TakeMoney");
    }
};

#endif