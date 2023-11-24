#ifndef _main_h
#define _main_h

#include <stdint.h>
#include <swiftly/swiftly.h>

void OnPluginStart() __attribute__((weak));
void OnPluginStop() __attribute__((weak));
void OnProgramLoad(const char *pluginName, const char *mainFilePath);
bool OnClientConnected(Player *player) __attribute__((weak));
bool OnClientConnect(Player *player) __attribute__((weak));
void OnPlayerSpawn(Player *player) __attribute__((weak));
void OnGameTick(bool simulating, bool bFirstTick, bool bLastTick) __attribute__((weak));
bool OnPlayerChat(Player *player, const char *text, bool teamonly) __attribute__((weak));
void OnRoundStart(long timelimit, long fraglimit, const char *objective) __attribute__((weak));
void OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic) __attribute__((weak));
void OnRoundPrestart() __attribute__((weak));
void OnBombBeginPlant(Player *player, unsigned short site) __attribute__((weak));
void OnBombAbortPlant(Player *player, unsigned short site) __attribute__((weak));
void OnBombPlanted(Player *player, unsigned short site) __attribute__((weak));
void OnBombBeginDefuse(Player *player, unsigned short site) __attribute__((weak));
void OnBombAbortDefuse(Player *player, unsigned short site) __attribute__((weak));
void OnBombDefused(Player *player, unsigned short site) __attribute__((weak));
void OnBombExploded(Player *player, unsigned short site) __attribute__((weak));
void OnBombDropped(Player *player) __attribute__((weak));
void OnBombPickup(Player *player) __attribute__((weak));
void OnMapLoad(const char *mapName) __attribute__((weak));
void OnMapUnload(const char *mapName) __attribute__((weak));

extern "C"
{
    void Internal_OnPluginStart()
    {
        print("");
        if (OnPluginStart)
            OnPluginStart();
    }
    void Internal_OnPluginStop()
    {
        if (OnPluginStop)
            OnPluginStop();
    }
    void Internal_OnProgramLoad(const char *pluginName, const char *mainFilePath)
    {
        OnProgramLoad(pluginName, mainFilePath);
    }
    bool Internal_OnClientConnected(uint32_t slot)
    {
        if (!OnClientConnected)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnClientConnected(player);
    }
    bool Internal_OnClientConnect(uint32_t slot)
    {
        if (!OnClientConnect)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnClientConnect(player);
    }
    void Internal_OnPlayerSpawn(uint32_t slot)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnPlayerSpawn)
            OnPlayerSpawn(player);

        if (player->IsFirstSpawn())
            player->SetFirstSpawn(true);
    }
    bool Internal_OnPlayerChat(uint32_t slot, const char *text, bool teamonly)
    {
        if (!OnPlayerChat)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnPlayerChat(player, text, teamonly);
    }
    void Internal_RegisterPlayer(uint32_t slot, bool fakeClient)
    {
        g_playerManager->RegisterPlayer(new Player(slot, fakeClient));
    }
    void Internal_UnregisterPlayer(uint32_t slot)
    {
        g_playerManager->UnregisterPlayer(slot);
    }
    void Internal_OnGameTick(bool simulating, bool bFirstTick, bool bLastTick)
    {
        if (OnGameTick)
            OnGameTick(simulating, bFirstTick, bLastTick);
    }
    void Internal_OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic)
    {
        if (OnRoundEnd)
            OnRoundEnd(winner, reason, message, legacy, player_count, nomusic);
    }
    void Internal_OnRoundStart(long timelimit, long fraglimit, const char *objective)
    {
        if (OnRoundStart)
            OnRoundStart(timelimit, fraglimit, objective);
    }
    void Internal_OnRoundPrestart()
    {
        if (OnRoundPrestart)
            OnRoundPrestart();
    }

    void Internal_BombBeginPlant(uint32_t slot, uint16_t site)
    {
        if (!OnBombBeginPlant)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombBeginPlant(player, site);
    }

    void Internal_BombAbortPlant(uint32_t slot, uint16_t site)
    {
        if (!OnBombAbortPlant)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombAbortPlant(player, site);
    }

    void Internal_BombPlanted(uint32_t slot, uint16_t site)
    {
        if (!OnBombPlanted)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombPlanted(player, site);
    }

    void Internal_BombBeginDefuse(uint32_t slot, uint16_t site)
    {
        if (!OnBombBeginDefuse)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombBeginDefuse(player, site);
    }

    void Internal_BombAbortDefuse(uint32_t slot, uint16_t site)
    {
        if (!OnBombAbortDefuse)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombAbortDefuse(player, site);
    }

    void Internal_BombDefused(uint32_t slot, uint16_t site)
    {
        if (!OnBombDefused)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombDefused(player, site);
    }

    void Internal_BombExploded(uint32_t slot, uint16_t site)
    {
        if (!OnBombExploded)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombExploded(player, site);
    }

    void Internal_BombDropped(uint32_t slot)
    {
        if (!OnBombDropped)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombDropped(player);
    }

    void Internal_BombPickup(uint32_t slot)
    {
        if (!OnBombPickup)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnBombPickup(player);
    }

    void Internal_OnMapLoad(const char *mapName)
    {
        if (OnMapLoad)
            OnMapLoad(mapName);
    }

    void Internal_OnMapUnload(const char *mapName)
    {
        if (OnMapUnload)
            OnMapUnload(mapName);
    }

    const char *GetPluginAuthor();
    const char *GetPluginVersion();
    const char *GetPluginName();
    const char *GetPluginWebsite();
}

#endif