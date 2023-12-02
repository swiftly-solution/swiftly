#include "../../inc/Scripting.h"

std::vector<int> GetBombSites()
{
    std::vector<int> sites;

    CEntityInstance *siteEntity = nullptr;
    while ((siteEntity = UTIL_FindEntityByClassname(siteEntity, "func_bomb_target")) != nullptr)
        sites.push_back(siteEntity->GetEntityIndex().Get());

    return sites;
}

void scripting_OnClientConnected(const OnClientConnected *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnClientConnected = plugin->FetchFunction("Internal_OnClientConnected");
            if (plugin_OnClientConnected)
                reinterpret_cast<Plugin_OnClientConnected>(plugin_OnClientConnected)(e->slot->Get());
        }
    }
}

bool scripting_OnClientConnect(const OnClientConnect *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnClientConnect = plugin->FetchFunction("Internal_OnClientConnect");
            if (plugin_OnClientConnect)
                if (!reinterpret_cast<Plugin_OnClientConnect>(plugin_OnClientConnect)(e->slot->Get()))
                    return false;
        }
    }

    return true;
}

void scripting_OnClientDisconnect(const OnClientDisconnect *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnClientDisconnect = plugin->FetchFunction("Internal_OnClientDisconnect");
            if (plugin_OnClientDisconnect)
                reinterpret_cast<Plugin_OnClientDisconnect>(plugin_OnClientDisconnect)(e->slot->Get());
        }
    }
}

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

void scripting_BombBeginPlant(const BombBeginPlant *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = e->pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_BombBeginPlant = plugin->FetchFunction("Internal_BombBeginPlant");
            if (plugin_BombBeginPlant)
            {
                reinterpret_cast<Plugin_BombBeginPlant>(plugin_BombBeginPlant)(player->GetSlot()->Get(), site);
            }
        }
    }
}

void scripting_BombAbortPlant(const BombAbortPlant *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = e->pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_BombAbortPlant = plugin->FetchFunction("Internal_BombAbortPlant");
            if (plugin_BombAbortPlant)
            {
                reinterpret_cast<Plugin_BombAbortPlant>(plugin_BombAbortPlant)(player->GetSlot()->Get(), site);
            }
        }
    }
}

void scripting_BombPlanted(const BombPlanted *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = e->pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_BombPlanted = plugin->FetchFunction("Internal_BombPlanted");
            if (plugin_BombPlanted)
            {
                reinterpret_cast<Plugin_BombPlanted>(plugin_BombPlanted)(player->GetSlot()->Get(), site);
            }
        }
    }
}

void scripting_BombDefused(const BombDefused *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = e->pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_BombDefused = plugin->FetchFunction("Internal_BombDefused");
            if (plugin_BombDefused)
            {
                reinterpret_cast<Plugin_BombDefused>(plugin_BombDefused)(player->GetSlot()->Get(), site);
            }
        }
    }
}

void scripting_BombExploded(const BombExploded *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = e->pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_BombExploded = plugin->FetchFunction("Internal_BombExploded");
            if (plugin_BombExploded)
            {
                reinterpret_cast<Plugin_BombExploded>(plugin_BombExploded)(player->GetSlot()->Get(), site);
            }
        }
    }
}

void scripting_BombDropped(const BombDropped *e)
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
            void *plugin_BombDropped = plugin->FetchFunction("Internal_BombDropped");
            if (plugin_BombDropped)
            {
                reinterpret_cast<Plugin_BombDropped>(plugin_BombDropped)(player->GetSlot()->Get());
            }
        }
    }
}

void scripting_BombPickup(const BombPickup *e)
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
            void *plugin_BombPickup = plugin->FetchFunction("Internal_BombPickup");
            if (plugin_BombPickup)
            {
                reinterpret_cast<Plugin_BombPickup>(plugin_BombPickup)(player->GetSlot()->Get());
            }
        }
    }
}

void scripting_BombBeginDefuse(const BombBeginDefuse *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = e->pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_BombBeginDefuse = plugin->FetchFunction("Internal_BombBeginDefuse");
            if (plugin_BombBeginDefuse)
            {
                reinterpret_cast<Plugin_BombBeginDefuse>(plugin_BombBeginDefuse)(player->GetSlot()->Get(), site);
            }
        }
    }
}

void scripting_BombAbortDefuse(const BombAbortDefuse *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = e->pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_BombAbortDefuse = plugin->FetchFunction("Internal_BombAbortDefuse");
            if (plugin_BombAbortDefuse)
            {
                reinterpret_cast<Plugin_BombAbortDefuse>(plugin_BombAbortDefuse)(player->GetSlot()->Get(), site);
            }
        }
    }
}

void scripting_OnMapLoad(const OnMapLoad *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnMapLoad = plugin->FetchFunction("Internal_OnMapLoad");
            if (plugin_OnMapLoad)
            {
                reinterpret_cast<Plugin_OnMapLoad>(plugin_OnMapLoad)(e->map);
            }
        }
    }
}

void scripting_OnMapUnload(const OnMapUnload *e)
{
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin->IsPluginLoaded())
        {
            void *plugin_OnMapUnload = plugin->FetchFunction("Internal_OnMapUnload");
            if (plugin_OnMapUnload)
            {
                reinterpret_cast<Plugin_OnMapUnload>(plugin_OnMapUnload)(e->map);
            }
        }
    }
}

void PluginsComponent::RegisterGameEvents()
{
    hooks::on<OnGameFrame>(scripting_OnGameTick);

    gameevents::on<OnRoundPrestart>(scripting_OnRoundPrestart);
    gameevents::on<OnRoundStart>(scripting_OnRoundStart);
    gameevents::on<OnRoundEnd>(scripting_OnRoundEnd);
    gameevents::on<OnPlayerSpawn>(scripting_OnClientSpawn);

    gameevents::on<BombBeginPlant>(scripting_BombBeginPlant);
    gameevents::on<BombAbortPlant>(scripting_BombAbortPlant);
    gameevents::on<BombPlanted>(scripting_BombPlanted);
    gameevents::on<BombBeginDefuse>(scripting_BombBeginDefuse);
    gameevents::on<BombAbortDefuse>(scripting_BombAbortDefuse);
    gameevents::on<BombDefused>(scripting_BombDefused);
    gameevents::on<BombExploded>(scripting_BombExploded);
    gameevents::on<BombDropped>(scripting_BombDropped);
    gameevents::on<BombPickup>(scripting_BombPickup);

    hooks::on<OnMapLoad>(scripting_OnMapLoad);
    hooks::on<OnMapUnload>(scripting_OnMapUnload);
}