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

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
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

void scripting_OnRoundPrestart(const OnRoundPrestart *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnRoundPrestart = plugin->FetchFunction("Internal_OnRoundPrestart");
            if (plugin_OnRoundPrestart)
            {
                reinterpret_cast<Plugin_OnRoundPrestart>(plugin_OnRoundPrestart)();
            }
        }
    }
}

void scripting_OnRoundStart(const OnRoundStart *e)
{
    long timelimit = e->pEvent->GetUint64("timelimit");
    long fraglimit = e->pEvent->GetUint64("fraglimit");
    const char *objective = e->pEvent->GetString("objective");

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnRoundStart = plugin->FetchFunction("Internal_OnRoundStart");
            if (plugin_OnRoundStart)
            {
                reinterpret_cast<Plugin_OnRoundStart>(plugin_OnRoundStart)(timelimit, fraglimit, objective);
            }
        }
    }
}

void scripting_OnRoundEnd(const OnRoundEnd *e)
{
    unsigned char winner = e->pEvent->GetInt("winner");
    unsigned char reason = e->pEvent->GetInt("reason");
    const char *message = e->pEvent->GetString("message");
    unsigned char legacy = e->pEvent->GetInt("legacy");
    short player_count = e->pEvent->GetInt("player_count");
    unsigned char nomusic = e->pEvent->GetInt("nomusic");

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnRoundEnd = plugin->FetchFunction("Internal_OnRoundEnd");
            if (plugin_OnRoundEnd)
            {
                reinterpret_cast<Plugin_OnRoundEnd>(plugin_OnRoundEnd)(winner, reason, message, legacy, player_count, nomusic);
            }
        }
    }
}

bool scripting_OnClientChat(CBasePlayerController *controller, const char *text, bool teamonly)
{
    CPlayerSlot sl = g_playerManager->GetSlotFromUserId(controller->GetRefEHandle().GetEntryIndex() - 1);
    CPlayerSlot *slot = &sl;
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

void scripting_OnPlayerUnregister(const OnPlayerUnregistered *e)
{
    Player *player = g_playerManager->GetPlayer(e->slot);
    if (!player)
        return;

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_UnregisterPlayer = plugin->FetchFunction("Internal_UnregisterPlayer");
            if (plugin_UnregisterPlayer)
                reinterpret_cast<Plugin_OnPlayerUnregister>(plugin_UnregisterPlayer)(player->GetSlot()->Get());
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
    hooks::on<OnPlayerUnregistered>(scripting_OnPlayerUnregister);
    hooks::on<OnGameFrame>(scripting_OnGameTick);

    gameevents::on<OnRoundPrestart>(scripting_OnRoundPrestart);
    gameevents::on<OnRoundStart>(scripting_OnRoundStart);
    gameevents::on<OnRoundEnd>(scripting_OnRoundEnd);
    gameevents::on<OnPlayerSpawn>(scripting_OnClientSpawn);
}