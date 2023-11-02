#include "../../../../common.h"
#include "../../../../hooks/Hooks.h"
#include "../../../../hooks/GameEvents.h"
#include "../../../../player/Player.h"
#include "../../../../player/PlayerManager.h"
#include "../../inc/PluginsComponent.h"
#include "../../inc/Plugin.h"

typedef bool (*Plugin_OnClientConnected)(uint32);
typedef bool (*Plugin_OnClientConnect)(uint32);
typedef void (*Plugin_OnPlayerSpawn)(uint32);
typedef void (*Plugin_OnPlayerRegister)(uint32, bool);
typedef void (*Plugin_OnGameTick)(bool, bool, bool);
typedef void (*Plugin_OnPlayerChat)(uint32, const char *, bool);

void scripting_OnClientConnected(const OnClientConnected *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnClientConnected = plugin->FetchFunction("Internal_OnClientConnected");
            if (plugin_OnClientConnected)
                if (!reinterpret_cast<Plugin_OnClientConnected>(plugin_OnClientConnected)(e->slot->Get()))
                    break;
        }
    }
};

void scripting_OnClientConnect(const OnClientConnect *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnClientConnect = plugin->FetchFunction("Internal_OnClientConnect");
            if (plugin_OnClientConnect)
                if (!reinterpret_cast<Plugin_OnClientConnect>(plugin_OnClientConnect)(e->slot->Get()))
                    break;
        }
    }
};

void scripting_OnClientSpawn(const OnPlayerSpawn *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    Player *player = g_playerManager->GetPlayer(&e->pEvent->GetPlayerSlot("userid"));
    if (!player)
        return;

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnPlayerSpawn = plugin->FetchFunction("Internal_OnPlayerSpawn");
            if (plugin_OnPlayerSpawn)
            {
                reinterpret_cast<Plugin_OnPlayerSpawn>(plugin_OnPlayerSpawn)(player->GetSlot()->Get());
            }
        }
    }
}

void scripting_OnClientChat(const OnPlayerChat *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    Player *player = g_playerManager->GetPlayer(&e->pEvent->GetPlayerSlot("userid"));
    if (!player)
        return;

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnPlayerChat = plugin->FetchFunction("Internal_OnPlayerChat");
            if (plugin_OnPlayerChat)
            {
                reinterpret_cast<Plugin_OnPlayerChat>(plugin_OnPlayerChat)(player->GetSlot()->Get(), e->pEvent->GetString("text"), e->pEvent->GetBool("teamonly"));
            }
        }
    }
}

void scripting_OnPlayerRegister(const OnPlayerRegistered *e)
{
    Player *player = g_playerManager->GetPlayer(e->slot);
    if (!player)
        return;

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_RegisterPlayer = plugin->FetchFunction("Internal_RegisterPlayer");
            if (plugin_RegisterPlayer)
                reinterpret_cast<Plugin_OnPlayerRegister>(plugin_RegisterPlayer)(player->GetSlot()->Get(), player->IsFakeClient());
        }
    }
}

void scripting_OnGameTick(const OnGameFrame *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnGameTick = plugin->FetchFunction("Internal_OnGameTick");
            if (plugin_OnGameTick)
            {
                reinterpret_cast<Plugin_OnGameTick>(plugin_OnGameTick)(e->simulating, e->bFirstTick, e->bFirstTick);
            }
        }
    }
}

void PluginsComponent::RegisterGameEvents()
{
    hooks::on<OnClientConnected>(scripting_OnClientConnected);
    hooks::on<OnClientConnect>(scripting_OnClientConnect);
    hooks::on<OnPlayerRegistered>(scripting_OnPlayerRegister);
    hooks::on<OnGameFrame>(scripting_OnGameTick);

    gameevents::on<OnPlayerSpawn>(scripting_OnClientSpawn);
    gameevents::on<OnPlayerChat>(scripting_OnClientChat);
}