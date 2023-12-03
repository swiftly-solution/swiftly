#ifndef _swiftly_h
#define _swiftly_h

#include "swiftly_memory.h"
#include "swiftly_utils.h"
#include "playermanager.h"
#include <cstdarg>
#include <stdint.h>

#define SITE_A 0
#define SITE_B 1
#define SITE_UNKNOWN 2

void ThreadFunction() __attribute__((weak));

typedef void (*PrintFunction)(const char *);
typedef const char *(*FetchTranslationFunction)(const char *);

const char *filePath;
const char *plName;

void print(const char *str, ...)
{
    void *printfunc = FetchFunctionPtr(filePath, "scripting_Print");
    if (printfunc != nullptr)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, str);
        UTIL_FormatArgs(buffer, sizeof(buffer), str, ap);
        va_end(ap);

        reinterpret_cast<PrintFunction>(printfunc)(buffer);
    }
};

const char *FetchTranslation(const char *key)
{
    void *translationfunc = FetchFunctionPtr(nullptr, "scripting_Translations_Fetch");
    if (translationfunc)
        return reinterpret_cast<FetchTranslationFunction>(translationfunc)(key);
    else
        return nullptr;
}

void Swiftly_Setup(const char *pluginName, const char *mainFilePath)
{
    filePath = mainFilePath;
    plName = pluginName;
}

void OnPluginStart() __attribute__((weak));
void OnPluginStop() __attribute__((weak));
void OnProgramLoad(const char *pluginName, const char *mainFilePath);
bool OnClientConnect(Player *player) __attribute__((weak));
void OnClientDisconnect(Player *player) __attribute__((weak));
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
bool OnClientGameMessage(Player *player, int destination, const char *message) __attribute__((weak));

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
    void Internal_OnClientDisconnect(uint32_t slot)
    {
        if (!OnClientDisconnect)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnClientDisconnect(player);
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
    bool Internal_OnClientGameMessage(uint32_t slot, int destination, const char *message)
    {
        if (!OnClientGameMessage)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnClientGameMessage(player, destination, message);
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
        if (ThreadFunction)
            ThreadFunction();

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