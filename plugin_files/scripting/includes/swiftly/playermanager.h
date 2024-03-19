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
        this->g_Players[player->GetSlot()] = player;
    }

    inline void UnregisterPlayer(uint16_t slot)
    {
        if (this->g_Players[slot] == nullptr)
            return;

        delete this->g_Players[slot];
        this->g_Players[slot] = nullptr;
    }

    inline uint16_t GetPlayers()
    {
        uint16_t count = 0;
        for (uint16_t i = 0; i < MAX_PLAYERS; i++)
        {
            if (this->g_Players[i] == nullptr)
                continue;
            ++count;
        }
        return count;
    }
    inline Player *GetPlayer(int slot)
    {
        if (slot < 0 || slot >= MAX_PLAYERS)
            return nullptr;
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

        REGISTER_METHOD_VOID(scripting_Players_SendMessage, dest, buffer);
    }

private:
    Player *g_Players[MAX_PLAYERS] = {};
};

extern PlayerManager *g_playerManager;

#endif