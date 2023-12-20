#ifndef _player_clantag_h
#define _player_clantag_h

#include <stdint.h>
#include "../swiftly_memory.h"
#include "../swiftly_utils.h"

class ClanTag
{
private:
    uint32_t m_playerSlot;

public:
    ClanTag(uint32_t playerSlot) : m_playerSlot(playerSlot) {}
    ~ClanTag() {}

    const char *Get()
    {
        void *player_GetClanTag = FetchFunctionPtr(nullptr, "scripting_Player_GetClanTag");
        if (player_GetClanTag)
            return reinterpret_cast<Player_GetClanTag>(player_GetClanTag)(this->m_playerSlot);
        else
        {
            NOT_SUPPORTED("scripting_Player_GetClanTag");
            return "";
        }
    }

    void Set(const char *text)
    {
        void *player_SetClanTag = FetchFunctionPtr(nullptr, "scripting_Player_SetClanTag");
        if (player_SetClanTag)
            reinterpret_cast<Player_SetClanTag>(player_SetClanTag)(this->m_playerSlot, text);
        else
            NOT_SUPPORTED("scripting_Player_SetClanTag");
    }
};

#endif