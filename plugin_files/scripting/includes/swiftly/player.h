#ifndef _swiftly_player_h
#define _swiftly_player_h

#include <stdint.h>
#include "swiftly_memory.h"
#include "types.h"
#include <cstdarg>
#include "swiftly_utils.h"

#include "player/health.h"
#include "player/armor.h"
#include "player/clantag.h"
#include "player/team.h"

class Player
{
private:
    uint32_t m_playerSlot;
    bool m_firstSpawn = false;
    bool m_fakeClient = false;
    Health *health;
    Armor *armor;
    ClanTag *clantag;
    Team *team;

public:
    Player(uint32_t playerSlot, bool fakeClient) : m_playerSlot(playerSlot), m_fakeClient(fakeClient)
    {
        this->health = new Health(playerSlot);
        this->armor = new Armor(playerSlot);
        this->clantag = new ClanTag(playerSlot);
        this->team = new Team(playerSlot);
    }

    ~Player()
    {
        delete this->health;
        delete this->armor;
        delete this->clantag;
        delete this->team;
    }

    uint32_t GetSlot() { return this->m_playerSlot; }

    const char *GetName()
    {
        void *player_GetName = FetchFunctionPtr(nullptr, "scripting_Player_GetName");
        if (player_GetName)
            return reinterpret_cast<Player_GetName>(player_GetName)(this->m_playerSlot);
        else
            return "";
    }

    uint64_t GetSteamID()
    {
        if (this->IsFakeClient())
            return 0;

        void *player_GetSteamID = FetchFunctionPtr(nullptr, "scripting_Player_GetSteamID");
        if (player_GetSteamID)
            return reinterpret_cast<Player_GetSteamID>(player_GetSteamID)(this->m_playerSlot);
        else
            return 0;
    }

    bool IsFirstSpawn() { return !this->m_firstSpawn; }
    bool IsFakeClient() { return this->m_fakeClient; }

    void SetFirstSpawn(bool val) { this->m_firstSpawn = val; }

    void Drop(ENetworkDisconnectionReason reason)
    {
        if (this->IsFakeClient())
            return;

        void *player_Drop = FetchFunctionPtr(nullptr, "scripting_Player_Drop");
        if (player_Drop)
            reinterpret_cast<Player_Drop>(player_Drop)(this->m_playerSlot, reason);
    }

    bool IsAuthenticated()
    {
        void *player_IsAuthenticated = FetchFunctionPtr(nullptr, "scripting_Player_IsAuthenticated");
        if (player_IsAuthenticated)
            return reinterpret_cast<Player_IsAuthenticated>(player_IsAuthenticated)(this->m_playerSlot);
        else
            return false;
    }

    const char *GetConvarValue(const char *name)
    {
        if (name == nullptr)
            return "";

        void *player_GetConvar = FetchFunctionPtr(nullptr, "scripting_Player_GetConvar");
        if (player_GetConvar)
            return reinterpret_cast<Player_GetConvar>(player_GetConvar)(this->m_playerSlot, name);
        else
            return "";
    }

    void SendMsg(HudDestination dest, const char *message, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, message);
        UTIL_FormatArgs(buffer, sizeof(buffer), message, ap);
        va_end(ap);

        void *player_SendMessage = FetchFunctionPtr(nullptr, "scripting_Player_SendMessage");
        if (player_SendMessage)
            reinterpret_cast<Player_SendMessage>(player_SendMessage)(this->m_playerSlot, dest, buffer);
    }
};

#endif