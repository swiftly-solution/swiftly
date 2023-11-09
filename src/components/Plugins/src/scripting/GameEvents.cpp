#include "../../inc/Scripting.h"

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

bool scripting_OnClientChat(CBasePlayerController *controller, const char *text, bool teamonly)
{
    CPlayerSlot *slot = &g_playerManager->GetSlotFromUserId(controller->GetRefEHandle().GetEntryIndex() - 1);
    if (!slot)
        return false;

    Player *player = g_playerManager->GetPlayer(slot);
    if (!player)
        return false;

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnPlayerChat = plugin->FetchFunction("Internal_OnPlayerChat");
            if (plugin_OnPlayerChat)
            {
                if (!reinterpret_cast<Plugin_OnPlayerChat>(plugin_OnPlayerChat)(player->GetSlot()->Get(), text, teamonly))
                    return false;
            }
        }
    }

    return true;
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
}