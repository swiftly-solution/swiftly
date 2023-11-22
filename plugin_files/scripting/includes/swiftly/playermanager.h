#ifndef _swiftly_playermanager_h
#define _swiftly_playermanager_h

#include "player.h"
#include <vector>
#include <cstdarg>
#include "swiftly_utils.h"

#define MAX_PLAYERS 64

class PlayerManager
{
public:
    PlayerManager()
    {
    }

    ~PlayerManager()
    {
    }

    inline void RegisterPlayer(Player *player)
    {
        if (playerCount < MAX_PLAYERS)
            ++playerCount;

        this->g_Players[player->GetSlot()] = player;
    }

    inline void UnregisterPlayer(uint16_t slot)
    {
        if (this->g_Players[slot] == nullptr)
            return;

        delete this->g_Players[slot];
        this->g_Players[slot] = nullptr;

        if (playerCount > 0)
            --playerCount;
    }

    inline uint16_t GetPlayers() { return playerCount; }
    inline Player *GetPlayer(int slot)
    {
        return this->g_Players[slot];
    }
    inline const uint16_t GetPlayerCap() { return MAX_PLAYERS; }

    void SendMsg(HudDestination dest, const char *message, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, message);
        UTIL_FormatArgs(buffer, sizeof(buffer), message, ap);
        va_end(ap);

        void *players_SendMessage = FetchFunctionPtr(nullptr, "scripting_Players_SendMessage");
        if (players_SendMessage)
            reinterpret_cast<Players_SendMessage>(players_SendMessage)(dest, buffer);
    }

private:
    Player *g_Players[MAX_PLAYERS] = {};
    uint16_t playerCount = 0;
};

extern PlayerManager *g_playerManager;

#endif