#ifndef _main_h
#define _main_h

#include <stdint.h>
#include <swiftly/swiftly.h>

void OnPluginStart();
void OnPluginStop();
void OnProgramLoad(const char *pluginName, const char *mainFilePath);
bool OnClientConnected(Player *player);
bool OnClientConnect(Player *player);
void OnPlayerSpawn(Player *player);
void OnGameTick(bool simulating, bool bFirstTick, bool bLastTick);
bool OnPlayerChat(Player *player, const char *text, bool teamonly);
void OnRoundStart(long timelimit, long fraglimit, const char *objective);
void OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic);
void OnRoundPrestart();

extern "C"
{
    void Internal_OnPluginStart()
    {
        print("");
        OnPluginStart();
    }
    void Internal_OnPluginStop()
    {
        OnPluginStop();
    }
    void Internal_OnProgramLoad(const char *pluginName, const char *mainFilePath)
    {
        OnProgramLoad(pluginName, mainFilePath);
    }
    bool Internal_OnClientConnected(uint32_t slot)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnClientConnected(player);
    }
    bool Internal_OnClientConnect(uint32_t slot)
    {
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

        OnPlayerSpawn(player);

        if (player->IsFirstSpawn())
            player->SetFirstSpawn(true);
    }
    bool Internal_OnPlayerChat(uint32_t slot, const char *text, bool teamonly)
    {
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
        OnGameTick(simulating, bFirstTick, bLastTick);
    }
    void Internal_OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic)
    {
        OnRoundEnd(winner, reason, message, legacy, player_count, nomusic);
    }
    void Internal_OnRoundStart(long timelimit, long fraglimit, const char *objective)
    {
        OnRoundStart(timelimit, fraglimit, objective);
    }
    void Internal_OnRoundPrestart()
    {
        OnRoundPrestart();
    }
    const char *GetPluginAuthor();
    const char *GetPluginVersion();
    const char *GetPluginName();
    const char *GetPluginWebsite();
}

#endif