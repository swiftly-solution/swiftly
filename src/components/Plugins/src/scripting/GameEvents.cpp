#include "../../inc/Scripting.h"

#define CALL_PFUNCTION_VOID_ARGS(FUNCTION_NAME, ...)                                                   \
    for (uint32 i = 0; i < plugins.size(); i++)                                                        \
    {                                                                                                  \
        Plugin *plugin = plugins[i];                                                                   \
        if (plugin->IsPluginLoaded())                                                                  \
        {                                                                                              \
            ExecuteGameEventWithNoReturn<Plugin_##FUNCTION_NAME>(plugin, #FUNCTION_NAME, __VA_ARGS__); \
        }                                                                                              \
    }

#define CALL_PFUNCTION_VOID_NOARGS(FUNCTION_NAME)                                         \
    for (uint32 i = 0; i < plugins.size(); i++)                                           \
    {                                                                                     \
        Plugin *plugin = plugins[i];                                                      \
        if (plugin->IsPluginLoaded())                                                     \
        {                                                                                 \
            ExecuteGameEventWithNoReturn<Plugin_##FUNCTION_NAME>(plugin, #FUNCTION_NAME); \
        }                                                                                 \
    }

#define CALL_PFUNCTION_BOOL_ARGS(FUNCTION_NAME, FALSE_VALUE, RET_VALUE, ...)                                                                \
    for (uint32 i = 0; i < plugins.size(); i++)                                                                                             \
    {                                                                                                                                       \
        Plugin *plugin = plugins[i];                                                                                                        \
        if (plugin->IsPluginLoaded())                                                                                                       \
        {                                                                                                                                   \
            if (plugin->FunctionExists(#FUNCTION_NAME))                                                                                     \
            {                                                                                                                               \
                if (!ExecuteGameEventWithReturn<bool, Plugin_##FUNCTION_NAME>(plugin, FALSE_VALUE, RET_VALUE, #FUNCTION_NAME, __VA_ARGS__)) \
                    return FALSE_VALUE;                                                                                                     \
            }                                                                                                                               \
        }                                                                                                                                   \
    }                                                                                                                                       \
    return RET_VALUE;

std::vector<int> GetBombSites()
{
    std::vector<int> sites;

    CEntityInstance *siteEntity = nullptr;
    while ((siteEntity = UTIL_FindEntityByClassname(siteEntity, "func_bomb_target")) != nullptr)
        sites.push_back(siteEntity->GetEntityIndex().Get());

    return sites;
}

extern std::map<std::string, std::map<std::string, std::vector<luacpp::LuaObject>>> lua_game_events;

template <typename T, typename... Args>
void ExecuteGameEventWithNoReturn(Plugin *plugin, std::string game_event_name, Args &&...args)
{
    if (plugin->GetPluginType() == PluginType_t::PLUGIN_CPP)
        plugin->ExecuteFunction<T>(game_event_name, args...);
    else if (plugin->GetPluginType() == PluginType_t::PLUGIN_LUA)
    {
        if (lua_game_events.find(plugin->GetName()) == lua_game_events.end())
            return;

        std::map<std::string, std::vector<luacpp::LuaObject>> game_events = lua_game_events.at(plugin->GetName());
        if (game_events.find(game_event_name) == game_events.end())
            return;

        std::vector<luacpp::LuaObject> eventsList = game_events.at(game_event_name);

        for (luacpp::LuaObject &obj : eventsList)
        {
            LuaFuncWrapper func(obj);
            func.PrepForExec();
            luacpp::PushValues(func.GetML(), std::forward<Args>(args)...);
            func.ExecuteNoReturn(game_event_name, sizeof...(Args));
        }
    }
}

template <typename Ret, typename T, typename... Args>
Ret ExecuteGameEventWithReturn(Plugin *plugin, Ret falseValue, Ret trueValue, std::string game_event_name, Args &&...args)
{
    if (plugin->GetPluginType() == PluginType_t::PLUGIN_CPP)
        return plugin->ExecuteFunctionWithReturn<Ret, T>(game_event_name, args...);
    else if (plugin->GetPluginType() == PluginType_t::PLUGIN_LUA)
    {
        if (lua_game_events.find(plugin->GetName()) == lua_game_events.end())
            return falseValue;

        std::map<std::string, std::vector<luacpp::LuaObject>> game_events = lua_game_events.at(plugin->GetName());
        if (game_events.find(game_event_name) == game_events.end())
            return falseValue;

        std::vector<luacpp::LuaObject> eventsList = game_events.at(game_event_name);

        for (luacpp::LuaObject &obj : eventsList)
        {
            LuaFuncWrapper func(obj);
            func.PrepForExec();
            luacpp::PushValues(func.GetML(), std::forward<Args>(args)...);
            if (func.ExecuteWithReturn<Ret>(game_event_name, sizeof...(Args)) == falseValue)
                return falseValue;
        }

        return trueValue;
    }
    else
        return falseValue;
}

bool scripting_OnClientConnect(const OnClientConnect *e)
{
    CALL_PFUNCTION_BOOL_ARGS(OnClientConnect, false, true, e->slot->Get())
}

void scripting_OnClientDisconnect(const OnClientDisconnect *e)
{
    CALL_PFUNCTION_VOID_ARGS(OnClientDisconnect, e->slot->Get())
}

void scripting_PlayerDeath(const PlayerDeath *e)
{
    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    CPlayerSlot attacker = e->pEvent->GetPlayerSlot("attacker");
    CPlayerSlot assister = e->pEvent->GetPlayerSlot("assister");
    bool assistedflash = e->pEvent->GetBool("assistedflash");
    std::string weapon = e->pEvent->GetString("weapon");
    bool headshot = e->pEvent->GetBool("headshot");
    short dominated = e->pEvent->GetInt("dominated");
    short revenge = e->pEvent->GetInt("revenge");
    short wipe = e->pEvent->GetInt("wipe");
    short penetrated = e->pEvent->GetInt("penetrated");
    bool noreplay = e->pEvent->GetBool("noreplay");
    bool noscope = e->pEvent->GetBool("noscope");
    bool thrusmoke = e->pEvent->GetBool("thrusmoke");
    bool attackerblind = e->pEvent->GetBool("attackerblind");
    float distance = e->pEvent->GetFloat("distance");
    short dmg_health = e->pEvent->GetInt("dmg_health");
    short dmg_armor = e->pEvent->GetInt("dmg_armor");
    short hitgroup = e->pEvent->GetInt("hitgroup");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerDeath, slot.Get(), attacker.Get(), assister.Get(), assistedflash, weapon.c_str(), headshot, dominated, revenge, wipe, penetrated, noreplay, noscope, thrusmoke, attackerblind, distance, dmg_health, dmg_armor, hitgroup)
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

    CALL_PFUNCTION_VOID_ARGS(OnPlayerSpawn, player->GetSlot()->Get())
}

void scripting_OnRoundPrestart(const OnRoundPrestart *e)
{
    CALL_PFUNCTION_VOID_NOARGS(OnRoundPrestart)
}

void scripting_OnRoundStart(const OnRoundStart *e)
{
    long timelimit = e->pEvent->GetUint64("timelimit");
    long fraglimit = e->pEvent->GetUint64("fraglimit");
    const char *objective = e->pEvent->GetString("objective");

    CALL_PFUNCTION_VOID_ARGS(OnRoundStart, timelimit, fraglimit, objective)
}

void scripting_OnRoundEnd(const OnRoundEnd *e)
{
    unsigned char winner = e->pEvent->GetInt("winner");
    unsigned char reason = e->pEvent->GetInt("reason");
    const char *message = e->pEvent->GetString("message");
    unsigned char legacy = e->pEvent->GetInt("legacy");
    short player_count = e->pEvent->GetInt("player_count");
    unsigned char nomusic = e->pEvent->GetInt("nomusic");

    CALL_PFUNCTION_VOID_ARGS(OnRoundEnd, winner, reason, message, legacy, player_count, nomusic)
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

    CALL_PFUNCTION_BOOL_ARGS(OnPlayerChat, false, true, player->GetSlot()->Get(), text, teamonly)
}

bool scripting_OnClientGameMessage(CBasePlayerController *controller, int destination, const char *text)
{
    CPlayerSlot sl = g_playerManager->GetSlotFromUserId(controller->GetRefEHandle().GetEntryIndex() - 1);
    CPlayerSlot *slot = &sl;
    if (!slot)
        return false;

    Player *player = g_playerManager->GetPlayer(slot);
    if (!player)
        return false;

    CALL_PFUNCTION_BOOL_ARGS(OnClientGameMessage, false, true, player->GetSlot()->Get(), destination, text)
}

void scripting_OnGameTick(const OnGameFrame *e)
{
    CALL_PFUNCTION_VOID_ARGS(OnGameTick, e->simulating, e->bFirstTick, e->bFirstTick)
}

void scripting_BombBeginPlant(const BombBeginPlant *e)
{
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

    CALL_PFUNCTION_VOID_ARGS(BombBeginPlant, player->GetSlot()->Get(), site)
}

void scripting_BombAbortPlant(const BombAbortPlant *e)
{
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

    CALL_PFUNCTION_VOID_ARGS(BombAbortPlant, player->GetSlot()->Get(), site)
}

void scripting_BombPlanted(const BombPlanted *e)
{
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

    CALL_PFUNCTION_VOID_ARGS(BombPlanted, player->GetSlot()->Get(), site)
}

void scripting_BombDefused(const BombDefused *e)
{
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

    CALL_PFUNCTION_VOID_ARGS(BombDefused, player->GetSlot()->Get(), site)
}

void scripting_BombExploded(const BombExploded *e)
{
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

    CALL_PFUNCTION_VOID_ARGS(BombExploded, player->GetSlot()->Get(), site)
}

void scripting_BombDropped(const BombDropped *e)
{
    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    CALL_PFUNCTION_VOID_ARGS(BombDropped, player->GetSlot()->Get())
}

void scripting_BombPickup(const BombPickup *e)
{
    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    CALL_PFUNCTION_VOID_ARGS(BombPickup, player->GetSlot()->Get())
}

void scripting_BombBeginDefuse(const BombBeginDefuse *e)
{
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

    CALL_PFUNCTION_VOID_ARGS(BombBeginDefuse, player->GetSlot()->Get(), site)
}

void scripting_BombAbortDefuse(const BombAbortDefuse *e)
{
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

    CALL_PFUNCTION_VOID_ARGS(BombAbortDefuse, player->GetSlot()->Get(), site)
}

void scripting_OnMapLoad(const OnMapLoad *e)
{
    CALL_PFUNCTION_VOID_ARGS(OnMapLoad, e->map)
}

void scripting_OnMapUnload(const OnMapUnload *e)
{
    CALL_PFUNCTION_VOID_ARGS(OnMapUnload, e->map)
}

void scripting_PlayerHurt(const PlayerHurt *e)
{
    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    CPlayerSlot attacker = e->pEvent->GetPlayerSlot("attacker");
    short dmgHealth = e->pEvent->GetInt("dmg_health");
    short dmgArmor = e->pEvent->GetInt("dmg_armor");
    short hitgroup = e->pEvent->GetInt("hitgroup");
    std::string weapon = e->pEvent->GetString("weapon");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerHurt, slot.Get(), attacker.Get(), dmgHealth, dmgArmor, hitgroup, weapon.c_str())
}

bool scripting_ShouldHearVoice(Player *player)
{
    CALL_PFUNCTION_BOOL_ARGS(ShouldHearVoice, false, true, player->GetSlot()->Get())
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
    gameevents::on<PlayerDeath>(scripting_PlayerDeath);
    gameevents::on<PlayerHurt>(scripting_PlayerHurt);

    hooks::on<OnMapLoad>(scripting_OnMapLoad);
    hooks::on<OnMapUnload>(scripting_OnMapUnload);
}