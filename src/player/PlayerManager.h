#ifndef _playermanager_h
#define _playermanager_h

#include "../common.h"
#include "Player.h"
#include "../hooks/Hooks.h"
#include "../components/Plugins/inc/Plugin.h"
#include <public/playerslot.h>

typedef void (*Plugin_OnPlayerRegister)(uint32, bool);
typedef void (*Plugin_OnPlayerUnregister)(uint32);

class PlayerManager
{
public:
    PlayerManager()
    {
    }

    ~PlayerManager()
    {
    }

    void LoadPlayers();
    void SetupHooks();

    inline void RegisterPlayer(Player *player)
    {
        if (playerCount < MAX_PLAYERS)
            ++playerCount;

        this->g_Players[player->GetSlot()->Get()] = player;

        for (uint32 i = 0; i < plugins.size(); i++)
        {
            Plugin *plugin = plugins[i];
            if (plugin->IsPluginLoaded())
            {
                plugin->ExecuteFunction<Plugin_OnPlayerRegister>("RegisterPlayer", player->GetSlot()->Get(), player->IsFakeClient());
            }
        }
    }

    inline void UnregisterPlayer(CPlayerSlot *slot)
    {
        int sl = slot->Get();

        for (uint32 i = 0; i < plugins.size(); i++)
        {
            Plugin *plugin = plugins[i];
            if (plugin->IsPluginLoaded())
            {
                plugin->ExecuteFunction<Plugin_OnPlayerUnregister>("UnregisterPlayer", sl);
            }
        }

        delete this->g_Players[sl];
        this->g_Players[sl] = nullptr;
        if (playerCount > 0)
            --playerCount;
    }

    inline uint16 GetPlayers() { return playerCount; }
    inline Player *GetPlayer(uint16 slot) { return this->g_Players[slot]; }
    inline Player *GetPlayer(CPlayerSlot *slot) { return this->g_Players[slot->Get()]; }
    inline const uint16 GetPlayerCap() { return MAX_PLAYERS; }
    inline CPlayerSlot GetSlotFromUserId(uint16 userid) { return CPlayerSlot(userid & 0xFF); }
    inline Player *FindPlayerBySteamID(uint64 steamid)
    {
        if (steamid == 0)
            return nullptr;

        for (int i = 0; i < this->GetPlayerCap(); i++)
        {
            Player *player = this->GetPlayer(i);
            if (!player)
                continue;

            if (player->GetSteamID() == steamid)
                return player;
        }
        return nullptr;
    }

private:
    Player *g_Players[MAX_PLAYERS] = {};
    uint16 playerCount = 0;
};

extern PlayerManager *g_playerManager;

#endif