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
        REGISTER_METHOD(const char *, "", scripting_Player_GetClanTag, this->m_playerSlot);
    }

    void Set(const char *text)
    {
        if (!text)
            return;

        REGISTER_METHOD_VOID(scripting_Player_SetClanTag, this->m_playerSlot, text);
    }
};

#endif