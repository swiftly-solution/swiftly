#include "../../inc/Scripting.h"
#include "../../../../menus/Menus.h"
#include "../../../../commands/CommandsManager.h"
#include "../../../../events/gameevents.h"

#define CALL_PFUNCTION_VOID_ARGS(FUNCTION_NAME, ...)                           \
    for (uint32 i = 0; i < plugins.size(); i++)                                \
    {                                                                          \
        Plugin *plugin = plugins[i];                                           \
        if (plugin->IsPluginLoaded())                                          \
        {                                                                      \
            ExecuteGameEventWithNoReturn(plugin, #FUNCTION_NAME, __VA_ARGS__); \
        }                                                                      \
    }

#define CALL_PFUNCTION_VOID_NOARGS(FUNCTION_NAME)                 \
    for (uint32 i = 0; i < plugins.size(); i++)                   \
    {                                                             \
        Plugin *plugin = plugins[i];                              \
        if (plugin->IsPluginLoaded())                             \
        {                                                         \
            ExecuteGameEventWithNoReturn(plugin, #FUNCTION_NAME); \
        }                                                         \
    }

#define CALL_PFUNCTION_BOOL_ARGS(FUNCTION_NAME, FALSE_VALUE, RET_VALUE, ...)                                                        \
    for (uint32 i = 0; i < plugins.size(); i++)                                                                                     \
    {                                                                                                                               \
        Plugin *plugin = plugins[i];                                                                                                \
        if (plugin->IsPluginLoaded())                                                                                               \
        {                                                                                                                           \
            if (!ExecuteGameEventWithReturn<bool, Plugin_WrapperBool>(plugin, FALSE_VALUE, RET_VALUE, #FUNCTION_NAME, __VA_ARGS__)) \
                return FALSE_VALUE;                                                                                                 \
        }                                                                                                                           \
    }                                                                                                                               \
    return RET_VALUE;

CUtlVector<CGameEventListener *> g_GameEventListener;

std::vector<int> GetBombSites()
{
    std::vector<int> sites;

    CEntityInstance *siteEntity = nullptr;
    while ((siteEntity = UTIL_FindEntityByClassname(siteEntity, "func_bomb_target")) != nullptr)
        sites.push_back(siteEntity->GetEntityIndex().Get());

    return sites;
}

extern std::map<std::string, std::map<std::string, std::vector<luacpp::LuaObject>>> lua_game_events;

template <typename... Args>
void ExecuteGameEventWithNoReturn(Plugin *plugin, std::string game_event_name, Args &&...args)
{
    if (plugin->GetPluginType() == PluginType_t::PLUGIN_CPP)
        plugin->ExecuteFunction<Plugin_WrapperVoid>(game_event_name, args...);
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
            return trueValue;

        std::map<std::string, std::vector<luacpp::LuaObject>> game_events = lua_game_events.at(plugin->GetName());
        if (game_events.find(game_event_name) == game_events.end())
            return trueValue;

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
    CALL_PFUNCTION_BOOL_ARGS(OnClientConnect, false, true, e->slot->Get());
}

GAME_EVENT(player_connect_full)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnClientFullConnected, slot.Get())
}

void scripting_OnClientDisconnect(const OnClientDisconnect *e)
{
    CALL_PFUNCTION_VOID_ARGS(OnClientDisconnect, e->slot->Get());
}

GAME_EVENT(player_death)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    CPlayerSlot attacker = pEvent->GetPlayerSlot("attacker");
    CPlayerSlot assister = pEvent->GetPlayerSlot("assister");
    bool assistedflash = pEvent->GetBool("assistedflash");
    std::string weapon = pEvent->GetString("weapon");
    bool headshot = pEvent->GetBool("headshot");
    short dominated = pEvent->GetInt("dominated");
    short revenge = pEvent->GetInt("revenge");
    short wipe = pEvent->GetInt("wipe");
    short penetrated = pEvent->GetInt("penetrated");
    bool noreplay = pEvent->GetBool("noreplay");
    bool noscope = pEvent->GetBool("noscope");
    bool thrusmoke = pEvent->GetBool("thrusmoke");
    bool attackerblind = pEvent->GetBool("attackerblind");
    float distance = pEvent->GetFloat("distance");
    short dmg_health = pEvent->GetInt("dmg_health");
    short dmg_armor = pEvent->GetInt("dmg_armor");
    short hitgroup = pEvent->GetInt("hitgroup");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerDeath, slot.Get(), attacker.Get(), assister.Get(), assistedflash, weapon.c_str(), headshot, dominated, revenge, wipe, penetrated, noreplay, noscope, thrusmoke, attackerblind, distance, dmg_health, dmg_armor, hitgroup)
}

GAME_EVENT(player_blind)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    CPlayerSlot attacker = pEvent->GetPlayerSlot("attacker");
    short entityid = pEvent->GetInt("entityid");
    float duration = pEvent->GetFloat("blind_duration");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerBlind, slot.Get(), attacker.Get(), entityid, duration)
}

GAME_EVENT(player_team)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    unsigned char team = pEvent->GetInt("team");
    unsigned char oldteam = pEvent->GetInt("oldteam");
    bool disconnect = pEvent->GetBool("disconnect");
    bool silent = pEvent->GetBool("silent");
    bool isbot = pEvent->GetBool("isbot");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerTeam, slot.Get(), team, oldteam, disconnect, silent, isbot)
}

GAME_EVENT(player_changename)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    const char *oldname = pEvent->GetString("oldname");
    const char *newname = pEvent->GetString("newname");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerChangeName, slot.Get(), oldname, newname)
}

GAME_EVENT(player_info)
{
    std::string name = pEvent->GetString("name");
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    uint64_t steamid = pEvent->GetInt("steamid");
    bool bot = pEvent->GetBool("bot");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerInfo, name.c_str(), slot.Get(), steamid, bot)
}

GAME_EVENT(item_pickup)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    const char *item = pEvent->GetString("item");
    bool silent = pEvent->GetBool("silent");
    long defindex = pEvent->GetInt("defindex");

    CALL_PFUNCTION_VOID_ARGS(OnItemPickup, slot.Get(), item, silent, defindex)
}

GAME_EVENT(enter_buyzone)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    bool canbuy = pEvent->GetBool("canbuy");

    CALL_PFUNCTION_VOID_ARGS(OnEnterBuyzone, slot.Get(), canbuy)
}

GAME_EVENT(enter_bombzone)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    bool hasbomb = pEvent->GetBool("hasbomb");
    bool isplanted = pEvent->GetBool("isplanted");

    CALL_PFUNCTION_VOID_ARGS(OnEnterBombzone, slot.Get(), hasbomb, isplanted)
}

GAME_EVENT(exit_bombzone)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    bool hasbomb = pEvent->GetBool("hasbomb");
    bool isplanted = pEvent->GetBool("isplanted");

    CALL_PFUNCTION_VOID_ARGS(OnExitBombzone, slot.Get(), hasbomb, isplanted)
}

GAME_EVENT(exit_buyzone)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    bool canbuy = pEvent->GetBool("canbuy");

    CALL_PFUNCTION_VOID_ARGS(OnExitBuyzone, slot.Get(), canbuy)
}

GAME_EVENT(player_full_update)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    short count = pEvent->GetInt("count");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerFullUpdate, slot.Get(), count)
}

GAME_EVENT(player_falldamage)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    float damage = pEvent->GetFloat("damage");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerFallDamage, slot.Get(), damage)
}

GAME_EVENT(player_jump)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerJump, slot.Get())
}

GAME_EVENT(player_spawn)
{
    CBasePlayerController *controller = (CBasePlayerController *)pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    CALL_PFUNCTION_VOID_ARGS(OnPlayerSpawn, player->GetSlot()->Get())
}

GAME_EVENT(round_prestart)
{
    CALL_PFUNCTION_VOID_NOARGS(OnRoundPrestart);
}

GAME_EVENT(round_poststart)
{
    CALL_PFUNCTION_VOID_NOARGS(OnRoundPostStart);
}

GAME_EVENT(round_start)
{
    long timelimit = pEvent->GetUint64("timelimit");
    long fraglimit = pEvent->GetUint64("fraglimit");
    const char *objective = pEvent->GetString("objective");

    CALL_PFUNCTION_VOID_ARGS(OnRoundStart, timelimit, fraglimit, objective)
}

GAME_EVENT(round_mvp)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    short reason = pEvent->GetInt("reason");
    long value = pEvent->GetInt("value");
    long musickitmvps = pEvent->GetInt("musickitmvps");
    unsigned char nomusic = pEvent->GetInt("nomusic");
    long musickitid = pEvent->GetInt("musickitid");

    CALL_PFUNCTION_VOID_ARGS(OnRoundMVP, slot.Get(), reason, value, musickitmvps, nomusic, musickitid)
}

GAME_EVENT(round_end)
{
    unsigned char winner = pEvent->GetInt("winner");
    unsigned char reason = pEvent->GetInt("reason");
    const char *message = pEvent->GetString("message");
    unsigned char legacy = pEvent->GetInt("legacy");
    short player_count = pEvent->GetInt("player_count");
    unsigned char nomusic = pEvent->GetInt("nomusic");

    CALL_PFUNCTION_VOID_ARGS(OnRoundEnd, winner, reason, message, legacy, player_count, nomusic)
}

bool scripting_OnClientChat(CBasePlayerController *controller, const char *text, bool teamonly)
{
    if (std::string(text) == "")
        return false;

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

void scripting_OnGameTick(const OnGameFrame *e){
    CALL_PFUNCTION_VOID_ARGS(OnGameTick, e->simulating, e->bFirstTick, e->bFirstTick)}

GAME_EVENT(bomb_beginplant)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    CALL_PFUNCTION_VOID_ARGS(BombBeginPlant, player->GetSlot()->Get(), site)
}

GAME_EVENT(bomb_abortplant)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    CALL_PFUNCTION_VOID_ARGS(BombAbortPlant, player->GetSlot()->Get(), site)
}

GAME_EVENT(bomb_planted)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    CALL_PFUNCTION_VOID_ARGS(BombPlanted, player->GetSlot()->Get(), site)
}

GAME_EVENT(bomb_defused)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    CALL_PFUNCTION_VOID_ARGS(BombDefused, player->GetSlot()->Get(), site)
}

GAME_EVENT(bomb_exploded)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    CALL_PFUNCTION_VOID_ARGS(BombExploded, player->GetSlot()->Get(), site)
}

GAME_EVENT(bomb_dropped)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    CALL_PFUNCTION_VOID_ARGS(BombDropped, player->GetSlot()->Get())
}

GAME_EVENT(bomb_pickup)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    CALL_PFUNCTION_VOID_ARGS(BombPickup, player->GetSlot()->Get())
}

GAME_EVENT(bomb_begindefuse)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = pEvent->GetInt("site");
    if (sites.size() == 0)
        site = SITE_UNKNOWN;
    else
        site = (sites[0] == site ? SITE_A : SITE_B);

    CALL_PFUNCTION_VOID_ARGS(BombBeginDefuse, player->GetSlot()->Get(), site)
}

GAME_EVENT(bomb_abortdefuse)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    std::vector<int> sites = GetBombSites();
    uint16 site = pEvent->GetInt("site");
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
    CALL_PFUNCTION_VOID_ARGS(OnMapUnload, e->map);
}

GAME_EVENT(player_hurt)
{
    CPlayerSlot slot = pEvent->GetPlayerSlot("userid");
    CPlayerSlot attacker = pEvent->GetPlayerSlot("attacker");
    short dmgHealth = pEvent->GetInt("dmg_health");
    short dmgArmor = pEvent->GetInt("dmg_armor");
    short hitgroup = pEvent->GetInt("hitgroup");
    std::string weapon = pEvent->GetString("weapon");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerHurt, slot.Get(), attacker.Get(), dmgHealth, dmgArmor, hitgroup, weapon.c_str())
}

bool scripting_ShouldHearVoice(Player *player)
{
    CALL_PFUNCTION_BOOL_ARGS(ShouldHearVoice, false, true, player->GetSlot()->Get())
}

void scripting_OnWeaponSpawned(const OnWeaponSpawned *e)
{
    CBasePlayerWeapon *weapon = e->pEntity;
    uint64_t steamid = weapon->m_OriginalOwnerXuidLow();
    Player *player = g_playerManager->FindPlayerBySteamID(steamid);
    if (!player)
        return;

    if (player->IsFakeClient())
        return;

    CALL_PFUNCTION_VOID_ARGS(OnWeaponSpawned, player->GetSlot()->Get(), weapon->m_AttributeManager().m_Item().m_iItemDefinitionIndex());
}

void scripting_OnClientExecuteCommand(const OnClientExecuteCommand *e)
{
    Player *player = g_playerManager->GetPlayer(e->slot);
    if (!player)
        return;

    CALL_PFUNCTION_VOID_ARGS(OnClientExecuteCommand, player->GetSlot()->Get(), e->command);
}

void scripting_OnClientKeyStateChange(const OnClientKeyStateChange *e)
{
    Player *player = g_playerManager->GetPlayer(e->slot);
    if (!player)
        return;

    if (player->HasMenuShown() && e->pressed)
    {
        std::string but = e->button;
        if (but == "shift")
        {
            player->MoveSelection();
            player->RenderMenu();
        }
        else if (but == "e")
        {
            std::string cmd = player->GetMenu()->GetCommandFromOption(player->GetPage(), player->GetSelection());
            if (cmd == "menunext")
            {
                player->SetPage(player->GetPage() + 1);
                player->RenderMenu();
            }
            else if (cmd == "menuback")
            {
                player->SetPage(player->GetPage() - 1);
                player->RenderMenu();
            }
            else if (cmd == "menuexit")
                player->HideMenu();
            else if (g_menus->FetchMenu(cmd))
            {
                player->HideMenu();
                player->ShowMenu(cmd);
            }
            else if (starts_with(cmd, "sw_"))
            {
                std::vector<std::string> cmdString = explode(cmd, " ");
                std::string commandName = replace(cmdString[0], "sw_", "");
                cmdString.erase(cmdString.begin());

                Command *cmd = g_commandsManager->FetchCommand(commandName);
                if (cmd)
                    cmd->Exec(player->GetSlot()->Get(), cmdString, true);
            }
            else
                engine->ClientCommand(*player->GetSlot(), cmd.c_str());
        }
    }

    CALL_PFUNCTION_VOID_ARGS(OnClientKeyStateChange, e->slot->Get(), e->button, e->pressed);
}

GAME_EVENT(server_cvar)
{
    std::string cvarname = pEvent->GetString("cvarname");
    std::string cvarvalue = pEvent->GetString("cvarvalue");

    CALL_PFUNCTION_VOID_ARGS(OnServerCvarChange, cvarname.c_str(), cvarvalue.c_str())
}

bool scripting_OnClientCommand(OnClientCommand *e)
{
    CALL_PFUNCTION_BOOL_ARGS(OnClientCommand, false, true, e->slot->Get(), e->command);
}

void PluginsComponent::RegisterGameEvents()
{
    hooks::on<OnGameFrame>(scripting_OnGameTick);

    hooks::on<OnMapLoad>(scripting_OnMapLoad);
    hooks::on<OnMapUnload>(scripting_OnMapUnload);
    hooks::on<OnClientKeyStateChange>(scripting_OnClientKeyStateChange);

    hooks::on<OnWeaponSpawned>(scripting_OnWeaponSpawned);
    hooks::on<OnClientExecuteCommand>(scripting_OnClientExecuteCommand);
}