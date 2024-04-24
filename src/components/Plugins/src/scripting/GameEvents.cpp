#include "../../inc/Scripting.h"
#include "../../../../menus/Menus.h"
#include "../../../../sdk/entity/CTakeDamageInfo.h"
#include "../../../../commands/CommandsManager.h"
#include "../../../../events/gameevents.h"
#include "../../../../resourcemonitor/ResourceMonitor.h"

#define CALL_PFUNCTION_VOID_ARGS(FUNCTION_NAME, ...)                                                                                                                                \
    for (uint32 i = 0; i < plugins.size(); i++)                                                                                                                                     \
    {                                                                                                                                                                               \
        Plugin *plugin = plugins[i];                                                                                                                                                \
        if (plugin->IsPluginLoaded())                                                                                                                                               \
        {                                                                                                                                                                           \
            auto start = std::chrono::high_resolution_clock::now();                                                                                                                 \
            ExecuteGameEventWithNoReturn(plugin, #FUNCTION_NAME, __VA_ARGS__);                                                                                                      \
            auto elapsed = std::chrono::high_resolution_clock::now() - start;                                                                                                       \
            if (g_ResourceMonitor->IsEnabled())                                                                                                                                     \
                g_ResourceMonitor->RecordTime(plugin->GetName(), "Game Event (" #FUNCTION_NAME ")", std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() / 1000); \
        }                                                                                                                                                                           \
    }

#define CALL_PFUNCTION_VOID_NOARGS(FUNCTION_NAME)                                                                                                                                   \
    for (uint32 i = 0; i < plugins.size(); i++)                                                                                                                                     \
    {                                                                                                                                                                               \
        Plugin *plugin = plugins[i];                                                                                                                                                \
        if (plugin->IsPluginLoaded())                                                                                                                                               \
        {                                                                                                                                                                           \
            auto start = std::chrono::high_resolution_clock::now();                                                                                                                 \
            ExecuteGameEventWithNoReturn(plugin, #FUNCTION_NAME);                                                                                                                   \
            auto elapsed = std::chrono::high_resolution_clock::now() - start;                                                                                                       \
            if (g_ResourceMonitor->IsEnabled())                                                                                                                                     \
                g_ResourceMonitor->RecordTime(plugin->GetName(), "Game Event (" #FUNCTION_NAME ")", std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() / 1000); \
        }                                                                                                                                                                           \
    }

#define CALL_PFUNCTION_BOOL_ARGS(FUNCTION_NAME, FALSE_VALUE, RET_VALUE, ...)                                                                                                        \
    for (uint32 i = 0; i < plugins.size(); i++)                                                                                                                                     \
    {                                                                                                                                                                               \
        Plugin *plugin = plugins[i];                                                                                                                                                \
        if (plugin->IsPluginLoaded())                                                                                                                                               \
        {                                                                                                                                                                           \
            auto start = std::chrono::high_resolution_clock::now();                                                                                                                 \
            bool res = ExecuteGameEventWithReturn<bool, Plugin_WrapperBool>(plugin, FALSE_VALUE, RET_VALUE, #FUNCTION_NAME, __VA_ARGS__);                                           \
            auto elapsed = std::chrono::high_resolution_clock::now() - start;                                                                                                       \
            if (g_ResourceMonitor->IsEnabled())                                                                                                                                     \
                g_ResourceMonitor->RecordTime(plugin->GetName(), "Game Event (" #FUNCTION_NAME ")", std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count() / 1000); \
                                                                                                                                                                                    \
            if (!res)                                                                                                                                                               \
                return FALSE_VALUE;                                                                                                                                                 \
        }                                                                                                                                                                           \
    }                                                                                                                                                                               \
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
    {
        if (!plugin->FunctionExists(game_event_name))
        {
            plugin->RegisterFunction("Internal_" + game_event_name);
            if (!plugin->FunctionExists("Internal_" + game_event_name))
                return trueValue;
        }
        return plugin->ExecuteFunctionWithReturn<Ret, T>(game_event_name, args...);
    }
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

    if (player->IsFirstSpawn() == true)
        player->SetFirstSpawn(false);
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

void scripting_OnGameTick(bool simulating, bool firsttick, bool lasttick){
    CALL_PFUNCTION_VOID_ARGS(OnGameTick, simulating, firsttick, lasttick)}

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
                CCommand tokenizedArgs;
                tokenizedArgs.Tokenize(cmd.c_str());

                std::vector<std::string> cmdString;
                for (int i = 1; i < tokenizedArgs.ArgC(); i++)
                    cmdString.push_back(tokenizedArgs[i]);

                std::string commandName = replace(tokenizedArgs[0], "sw_", "");

                Command *cmd = g_commandsManager->FetchCommand(commandName);
                if (cmd)
                    cmd->Exec(player->GetSlot()->Get(), cmdString, true);
            }
            else if (cmd != "")
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

GAME_EVENT(server_pre_shutdown)
{
    std::string reason = pEvent->GetString("reason");

    CALL_PFUNCTION_VOID_ARGS(OnServerPreshutdown, reason.c_str())
}

GAME_EVENT(server_shutdown)
{
    std::string reason = pEvent->GetString("reason");

    CALL_PFUNCTION_VOID_ARGS(OnServerShutdown, reason.c_str())
}

GAME_EVENT(server_message)
{
    std::string text = pEvent->GetString("text");

    CALL_PFUNCTION_VOID_ARGS(OnServerMesssage, text.c_str())
}

GAME_EVENT(player_activate)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerActivate, player_slot.Get())
}

GAME_EVENT(local_player_team){

    CALL_PFUNCTION_VOID_NOARGS(OnLocalPlayerTeam)}

GAME_EVENT(local_player_controller_team){

    CALL_PFUNCTION_VOID_NOARGS(OnLocalPlayerControllerTeam)}

GAME_EVENT(local_player_pawn_changed){

    CALL_PFUNCTION_VOID_NOARGS(OnLocalPlayerPawnChanged)}

GAME_EVENT(teamplay_broadcast_audio)
{
    unsigned char team = pEvent->GetInt("team");
    std::string sound = pEvent->GetString("sound");

    CALL_PFUNCTION_VOID_ARGS(OnTeamplayBroadcastAudio, team, sound.c_str())
}

GAME_EVENT(finale_start)
{
    short rushes = pEvent->GetInt("rushes");

    CALL_PFUNCTION_VOID_ARGS(OnFinaleStart, rushes)
}

GAME_EVENT(player_stats_updated)
{
    bool forceupload = pEvent->GetBool("forceupload");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerStatsUpdated, forceupload)
}

GAME_EVENT(user_data_downloaded){

    CALL_PFUNCTION_VOID_NOARGS(OnUserDataDownloaded)}

GAME_EVENT(ragdoll_dissolved)
{
    long entindex = pEvent->GetInt("entindex");

    CALL_PFUNCTION_VOID_ARGS(OnRagdollDissolved, entindex)
}

GAME_EVENT(team_info)
{
    unsigned char teamid = pEvent->GetInt("teamid");
    std::string teamname = pEvent->GetString("teamname");

    CALL_PFUNCTION_VOID_ARGS(OnTeamInfo, teamid, teamname.c_str())
}

GAME_EVENT(team_score)
{
    unsigned char teamid = pEvent->GetInt("teamid");
    short score = pEvent->GetInt("score");

    CALL_PFUNCTION_VOID_ARGS(OnTeamScore, teamid, score)
}

GAME_EVENT(hltv_cameraman)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVCameraman, player_slot.Get())
}

GAME_EVENT(hltv_chase)
{
    CPlayerSlot target1_slot = pEvent->GetPlayerSlot("target1");
    CPlayerSlot target2_slot = pEvent->GetPlayerSlot("target2");
    short distance = pEvent->GetInt("distance");
    short theta = pEvent->GetInt("theta");
    short phi = pEvent->GetInt("phi");
    unsigned char inertia = pEvent->GetInt("inertia");
    unsigned char ineye = pEvent->GetInt("ineye");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVChase, target1_slot.Get(), target2_slot.Get(), distance, theta, phi, inertia, ineye)
}

GAME_EVENT(hltv_rank_camera)
{
    unsigned char index = pEvent->GetInt("index");
    float rank = pEvent->GetFloat("rank");
    CPlayerSlot target_slot = pEvent->GetPlayerSlot("target");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVRankCamera, index, rank, target_slot.Get())
}

GAME_EVENT(hltv_rank_entity)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    float rank = pEvent->GetFloat("rank");
    CPlayerSlot target_slot = pEvent->GetPlayerSlot("target");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVRankEntity, player_slot.Get(), rank, target_slot.Get())
}

GAME_EVENT(hltv_fixed)
{
    long posx = pEvent->GetInt("posx");
    long posy = pEvent->GetInt("posy");
    long posz = pEvent->GetInt("posz");
    short theta = pEvent->GetInt("theta");
    short phi = pEvent->GetInt("phi");
    short offset = pEvent->GetInt("offset");
    float fov = pEvent->GetFloat("fov");
    CPlayerSlot target_slot = pEvent->GetPlayerSlot("target");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVFixed, posx, posy, posz, theta, phi, offset, fov, target_slot.Get())
}

GAME_EVENT(hltv_message)
{
    std::string text = pEvent->GetString("text");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVMessage, text.c_str())
}

GAME_EVENT(hltv_status)
{
    long clients = pEvent->GetInt("clients");
    long slots = pEvent->GetInt("slots");
    short proxies = pEvent->GetInt("proxies");
    std::string master = pEvent->GetString("master");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVStatus, clients, slots, proxies, master.c_str())
}

GAME_EVENT(hltv_title)
{
    std::string text = pEvent->GetString("text");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVTitle, text.c_str())
}

GAME_EVENT(hltv_chat)
{
    std::string text = pEvent->GetString("text");
    uint64_t steamID = pEvent->GetUint64("steamID");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVChat, text.c_str(), steamID)
}

GAME_EVENT(hltv_versioninfo)
{
    long version = pEvent->GetInt("version");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVVersioninfo, version)
}

GAME_EVENT(hltv_replay)
{
    long delay = pEvent->GetInt("delay");
    long reason = pEvent->GetInt("reason");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVReplay, delay, reason)
}

GAME_EVENT(map_shutdown){

    CALL_PFUNCTION_VOID_NOARGS(OnMapShutdown)}

GAME_EVENT(map_transition){

    CALL_PFUNCTION_VOID_NOARGS(OnMapTransition)}

GAME_EVENT(hostname_changed)
{
    std::string hostname = pEvent->GetString("hostname");

    CALL_PFUNCTION_VOID_ARGS(OnHostnameChanged, hostname.c_str())
}

GAME_EVENT(difficulty_changed)
{
    short newDifficulty = pEvent->GetInt("newDifficulty");
    short oldDifficulty = pEvent->GetInt("oldDifficulty");
    std::string strDifficulty = pEvent->GetString("strDifficulty");

    CALL_PFUNCTION_VOID_ARGS(OnDifficultyChanged, newDifficulty, oldDifficulty, strDifficulty.c_str())
}

GAME_EVENT(game_message)
{
    unsigned char target = pEvent->GetInt("target");
    std::string text = pEvent->GetString("text");

    CALL_PFUNCTION_VOID_ARGS(OnGameMessage, target, text.c_str())
}

GAME_EVENT(game_newmap)
{
    std::string mapname = pEvent->GetString("mapname");

    CALL_PFUNCTION_VOID_ARGS(OnGameNewmap, mapname.c_str())
}

GAME_EVENT(round_start_pre_entity){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundStartPreEntity)}

GAME_EVENT(round_start_post_nav){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundStartPostNav)}

GAME_EVENT(round_freeze_end){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundFreezeEnd)}

GAME_EVENT(teamplay_round_start)
{
    bool full_reset = pEvent->GetBool("full_reset");

    CALL_PFUNCTION_VOID_ARGS(OnTeamplayRoundStart, full_reset)
}

GAME_EVENT(player_footstep)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerFootstep, player_slot.Get())
}

GAME_EVENT(player_hintmessage)
{
    std::string hintmessage = pEvent->GetString("hintmessage");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerHintmessage, hintmessage.c_str())
}

GAME_EVENT(break_breakable)
{
    long entindex = pEvent->GetInt("entindex");
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    unsigned char material = pEvent->GetInt("material");

    CALL_PFUNCTION_VOID_ARGS(OnBreakBreakable, entindex, player_slot.Get(), material)
}

GAME_EVENT(break_prop)
{
    long entindex = pEvent->GetInt("entindex");
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnBreakProp, entindex, player_slot.Get())
}

GAME_EVENT(entity_killed)
{
    long entindex_killed = pEvent->GetInt("entindex_killed");
    long entindex_attacker = pEvent->GetInt("entindex_attacker");
    long entindex_inflictor = pEvent->GetInt("entindex_inflictor");
    long damagebits = pEvent->GetInt("damagebits");

    CALL_PFUNCTION_VOID_ARGS(OnEntityKilled, entindex_killed, entindex_attacker, entindex_inflictor, damagebits)
}

GAME_EVENT(door_close)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    bool checkpoint = pEvent->GetBool("checkpoint");

    CALL_PFUNCTION_VOID_ARGS(OnDoorClose, player_slot.Get(), checkpoint)
}

GAME_EVENT(vote_started)
{
    std::string issue = pEvent->GetString("issue");
    std::string param1 = pEvent->GetString("param1");
    unsigned char team = pEvent->GetInt("team");
    long initiator = pEvent->GetInt("initiator");

    CALL_PFUNCTION_VOID_ARGS(OnVoteStarted, issue.c_str(), param1.c_str(), team, initiator)
}

GAME_EVENT(vote_failed)
{
    unsigned char team = pEvent->GetInt("team");

    CALL_PFUNCTION_VOID_ARGS(OnVoteFailed, team)
}

GAME_EVENT(vote_passed)
{
    std::string details = pEvent->GetString("details");
    std::string param1 = pEvent->GetString("param1");
    unsigned char team = pEvent->GetInt("team");

    CALL_PFUNCTION_VOID_ARGS(OnVotePassed, details.c_str(), param1.c_str(), team)
}

GAME_EVENT(vote_changed)
{
    unsigned char vote_option1 = pEvent->GetInt("vote_option1");
    unsigned char vote_option2 = pEvent->GetInt("vote_option2");
    unsigned char vote_option3 = pEvent->GetInt("vote_option3");
    unsigned char vote_option4 = pEvent->GetInt("vote_option4");
    unsigned char vote_option5 = pEvent->GetInt("vote_option5");
    unsigned char potentialVotes = pEvent->GetInt("potentialVotes");

    CALL_PFUNCTION_VOID_ARGS(OnVoteChanged, vote_option1, vote_option2, vote_option3, vote_option4, vote_option5, potentialVotes)
}

GAME_EVENT(vote_cast_yes)
{
    unsigned char team = pEvent->GetInt("team");
    long entityid = pEvent->GetInt("entityid");

    CALL_PFUNCTION_VOID_ARGS(OnVoteCastYes, team, entityid)
}

GAME_EVENT(vote_cast_no)
{
    unsigned char team = pEvent->GetInt("team");
    long entityid = pEvent->GetInt("entityid");

    CALL_PFUNCTION_VOID_ARGS(OnVoteCastNo, team, entityid)
}

GAME_EVENT(achievement_event)
{
    std::string achievement_name = pEvent->GetString("achievement_name");
    short cur_val = pEvent->GetInt("cur_val");
    short max_val = pEvent->GetInt("max_val");

    CALL_PFUNCTION_VOID_ARGS(OnAchievementEvent, achievement_name.c_str(), cur_val, max_val)
}

GAME_EVENT(achievement_earned)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short achievement = pEvent->GetInt("achievement");

    CALL_PFUNCTION_VOID_ARGS(OnAchievementEarned, player_slot.Get(), achievement)
}

GAME_EVENT(achievement_write_failed){

    CALL_PFUNCTION_VOID_NOARGS(OnAchievementWriteFailed)}

GAME_EVENT(bonus_updated)
{
    short numadvanced = pEvent->GetInt("numadvanced");
    short numbronze = pEvent->GetInt("numbronze");
    short numsilver = pEvent->GetInt("numsilver");
    short numgold = pEvent->GetInt("numgold");

    CALL_PFUNCTION_VOID_ARGS(OnBonusUpdated, numadvanced, numbronze, numsilver, numgold)
}

GAME_EVENT(spec_target_updated)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    long target = pEvent->GetInt("target");

    CALL_PFUNCTION_VOID_ARGS(OnSpecTargetUpdated, player_slot.Get(), target)
}

GAME_EVENT(spec_mode_updated)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnSpecModeUpdated, player_slot.Get())
}

GAME_EVENT(entity_visible)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short subject = pEvent->GetInt("subject");
    std::string classname = pEvent->GetString("classname");
    std::string entityname = pEvent->GetString("entityname");

    CALL_PFUNCTION_VOID_ARGS(OnEntityVisible, player_slot.Get(), subject, classname.c_str(), entityname.c_str())
}

GAME_EVENT(gameinstructor_draw){

    CALL_PFUNCTION_VOID_NOARGS(OnGameInstructorDraw)}

GAME_EVENT(gameinstructor_nodraw){

    CALL_PFUNCTION_VOID_NOARGS(OnGameInstructorNodraw)}

GAME_EVENT(flare_ignite_npc)
{
    long entindex = pEvent->GetInt("entindex");

    CALL_PFUNCTION_VOID_ARGS(OnFlareIgniteNCP, entindex)
}

GAME_EVENT(helicopter_grenade_punt_miss){

    CALL_PFUNCTION_VOID_NOARGS(OnHelicoptedGrenadePuntMiss)}

GAME_EVENT(physgun_pickup)
{
    long target = pEvent->GetInt("target");

    CALL_PFUNCTION_VOID_ARGS(OnPhysgunPickup, target)
}

GAME_EVENT(inventory_updated){

    CALL_PFUNCTION_VOID_NOARGS(OnInventoryUpdated)}

GAME_EVENT(cart_updated){

    CALL_PFUNCTION_VOID_NOARGS(OnCarUpdated)}

GAME_EVENT(store_pricesheet_updated){

    CALL_PFUNCTION_VOID_NOARGS(OnStorePricesheetUpdated)}

GAME_EVENT(item_schema_initialized){

    CALL_PFUNCTION_VOID_NOARGS(OnItemSchemaInitialized)}

GAME_EVENT(drop_rate_modified){

    CALL_PFUNCTION_VOID_NOARGS(OnDropRateModified)}

GAME_EVENT(event_ticket_modified){

    CALL_PFUNCTION_VOID_NOARGS(OnEventTicketModified)}

GAME_EVENT(gc_connected){

    CALL_PFUNCTION_VOID_NOARGS(OnGCConnected)}

GAME_EVENT(instructor_start_lesson)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string hint_name = pEvent->GetString("hint_name");
    long hint_target = pEvent->GetInt("hint_target");
    unsigned char vr_movement_type = pEvent->GetInt("vr_movement_type");
    bool vr_single_controller = pEvent->GetBool("vr_single_controller");
    unsigned char vr_controller_type = pEvent->GetInt("vr_controller_type");

    CALL_PFUNCTION_VOID_ARGS(OnInstructorStartLesson, player_slot.Get(), hint_name.c_str(), hint_target, vr_movement_type, vr_single_controller, vr_controller_type)
}

GAME_EVENT(instructor_close_lesson)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string hint_name = pEvent->GetString("hint_name");

    CALL_PFUNCTION_VOID_ARGS(OnInstructorCloseLesson, player_slot.Get(), hint_name.c_str())
}

GAME_EVENT(instructor_server_hint_create)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string hint_name = pEvent->GetString("hint_name");
    std::string hint_replace_key = pEvent->GetString("hint_replace_key");
    long hint_target = pEvent->GetInt("hint_target");
    CPlayerSlot hint_activator_user_slot = pEvent->GetPlayerSlot("hint_activator_user");
    short hint_timeout = pEvent->GetInt("hint_timeout");
    std::string hint_icon_onscreen = pEvent->GetString("hint_icon_onscreen");
    std::string hint_icon_offscreen = pEvent->GetString("hint_icon_offscreen");
    std::string hint_caption = pEvent->GetString("hint_caption");
    std::string hint_activator_caption = pEvent->GetString("hint_activator_caption");
    std::string hint_color = pEvent->GetString("hint_color");
    float hint_icon_offset = pEvent->GetFloat("hint_icon_offset");
    float hint_range = pEvent->GetFloat("hint_range");
    long hint_flags = pEvent->GetInt("hint_flags");
    std::string hint_binding = pEvent->GetString("hint_binding");
    std::string hint_gamepad_binding = pEvent->GetString("hint_gamepad_binding");
    bool hint_allow_nodraw_target = pEvent->GetBool("hint_allow_nodraw_target");
    bool hint_nooffscreen = pEvent->GetBool("hint_nooffscreen");
    bool hint_forcecaption = pEvent->GetBool("hint_forcecaption");
    bool hint_local_player_only = pEvent->GetBool("hint_local_player_only");

    CALL_PFUNCTION_VOID_ARGS(OnInstructorServerHintCreate, player_slot.Get(), hint_name.c_str(), hint_replace_key.c_str(), hint_target, hint_activator_user_slot.Get(), hint_timeout, hint_icon_onscreen.c_str(), hint_icon_offscreen.c_str(), hint_caption.c_str(), hint_activator_caption.c_str(), hint_color.c_str(), hint_icon_offset, hint_range, hint_flags, hint_binding.c_str(), hint_gamepad_binding.c_str(), hint_allow_nodraw_target, hint_nooffscreen, hint_forcecaption, hint_local_player_only)
}

GAME_EVENT(clientside_lesson_closed)
{
    std::string lesson_name = pEvent->GetString("lesson_name");

    CALL_PFUNCTION_VOID_ARGS(OnClinetsideLessonClosed, lesson_name.c_str())
}

GAME_EVENT(dynamic_shadow_light_changed){

    CALL_PFUNCTION_VOID_NOARGS(OnDynamicShadowLightChanged)}

GAME_EVENT(gameui_hidden){

    CALL_PFUNCTION_VOID_NOARGS(OnGameuiHidden)}

GAME_EVENT(items_gifted)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    long itemdef = pEvent->GetInt("itemdef");
    short numgifts = pEvent->GetInt("numgifts");
    long giftidx = pEvent->GetInt("giftidx");
    long accountid = pEvent->GetInt("accountid");

    CALL_PFUNCTION_VOID_ARGS(OnItemsGifted, player_slot.Get(), itemdef, numgifts, giftidx, accountid)
}

GAME_EVENT(player_score)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short kills = pEvent->GetInt("kills");
    short deaths = pEvent->GetInt("deaths");
    short score = pEvent->GetInt("score");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerScore, player_slot.Get(), kills, deaths, score)
}

GAME_EVENT(player_shoot)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    unsigned char weapon = pEvent->GetInt("weapon");
    unsigned char mode = pEvent->GetInt("mode");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerShoot, player_slot.Get(), weapon, mode)
}

GAME_EVENT(game_init){

    CALL_PFUNCTION_VOID_NOARGS(OnGameInit)}

GAME_EVENT(game_start)
{
    long roundslimit = pEvent->GetInt("roundslimit");
    long timelimit = pEvent->GetInt("timelimit");
    long fraglimit = pEvent->GetInt("fraglimit");
    std::string objective = pEvent->GetString("objective");

    CALL_PFUNCTION_VOID_ARGS(OnGameStart, roundslimit, timelimit, fraglimit, objective.c_str())
}

GAME_EVENT(game_end)
{
    unsigned char winner = pEvent->GetInt("winner");

    CALL_PFUNCTION_VOID_ARGS(OnGameEnd, winner)
}

GAME_EVENT(round_announce_match_point){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundAnnounceMatchPoint)}

GAME_EVENT(round_announce_final){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundAnnounceFinal)}

GAME_EVENT(round_announce_last_round_half){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundAnnounceLastRoundHalf)}

GAME_EVENT(round_announce_match_start){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundAnnouceMatchStart)}

GAME_EVENT(round_announce_warmup){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundAnnounceWarmup)}

GAME_EVENT(round_end_upload_stats){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundEndUploadStats)}

GAME_EVENT(round_officially_ended){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundOfficiallyEnded)}

GAME_EVENT(round_time_warning){

    CALL_PFUNCTION_VOID_NOARGS(OnRoundTimeWarning)}

GAME_EVENT(ugc_map_info_received)
{
    uint64_t published_file_id = pEvent->GetUint64("published_file_id");

    CALL_PFUNCTION_VOID_ARGS(OnUGCMapInfoReceived, published_file_id)
}

GAME_EVENT(ugc_map_unsubscribed)
{
    uint64_t published_file_id = pEvent->GetUint64("published_file_id");

    CALL_PFUNCTION_VOID_ARGS(OnUGCMapUnsubscribed, published_file_id)
}

GAME_EVENT(ugc_map_download_error)
{
    uint64_t published_file_id = pEvent->GetUint64("published_file_id");
    long error_code = pEvent->GetInt("error_code");

    CALL_PFUNCTION_VOID_ARGS(OnUGCMapDownloadError, published_file_id, error_code)
}

GAME_EVENT(ugc_file_download_finished)
{
    uint64_t hcontent = pEvent->GetUint64("hcontent");

    CALL_PFUNCTION_VOID_ARGS(OnUGCFileDownloadFinished, hcontent)
}

GAME_EVENT(ugc_file_download_start)
{
    uint64_t hcontent = pEvent->GetUint64("hcontent");
    uint64_t published_file_id = pEvent->GetUint64("published_file_id");

    CALL_PFUNCTION_VOID_ARGS(OnUGCFileDownloadStart, hcontent, published_file_id)
}

GAME_EVENT(begin_new_match){

    CALL_PFUNCTION_VOID_NOARGS(OnBeginNewMatch)}

GAME_EVENT(dm_bonus_weapon_start)
{
    short time = pEvent->GetInt("time");
    short Pos = pEvent->GetInt("Pos");

    CALL_PFUNCTION_VOID_ARGS(OnDMBonusWeaponStart, time, Pos)
}

GAME_EVENT(survival_announce_phase)
{
    short phase = pEvent->GetInt("phase");

    CALL_PFUNCTION_VOID_ARGS(OnSurvivalAnnouncePhase, phase)
}

GAME_EVENT(broken_breakable)
{
    long entindex = pEvent->GetInt("entindex");
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    unsigned char material = pEvent->GetInt("material");

    CALL_PFUNCTION_VOID_ARGS(OnBrokenBreakable, entindex, player_slot.Get(), material)
}

GAME_EVENT(player_decal)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerDecal, player_slot.Get())
}

GAME_EVENT(set_instructor_group_enabled)
{
    std::string group = pEvent->GetString("group");
    short enabled = pEvent->GetInt("enabled");

    CALL_PFUNCTION_VOID_ARGS(OnSetInstructorGroupEnabled, group.c_str(), enabled)
}

GAME_EVENT(instructor_server_hint_stop)
{
    std::string hint_name = pEvent->GetString("hint_name");

    CALL_PFUNCTION_VOID_ARGS(OnInstructorServerHintStop, hint_name.c_str())
}

GAME_EVENT(read_game_titledata)
{
    short controllerId = pEvent->GetInt("controllerId");

    CALL_PFUNCTION_VOID_ARGS(OnReadGameTitledata, controllerId)
}

GAME_EVENT(write_game_titledata)
{
    short controllerId = pEvent->GetInt("controllerId");

    CALL_PFUNCTION_VOID_ARGS(OnWriteGameTitledata, controllerId)
}

GAME_EVENT(reset_game_titledata)
{
    short controllerId = pEvent->GetInt("controllerId");

    CALL_PFUNCTION_VOID_ARGS(OnResetGameTitledata, controllerId)
}

GAME_EVENT(weaponhud_selection)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    unsigned char mode = pEvent->GetInt("mode");
    long entindex = pEvent->GetInt("entindex");

    CALL_PFUNCTION_VOID_ARGS(OnWeaponhudSelection, player_slot.Get(), mode, entindex)
}

GAME_EVENT(vote_ended){

    CALL_PFUNCTION_VOID_NOARGS(OnVoteEnded)}

GAME_EVENT(vote_cast)
{
    unsigned char vote_option = pEvent->GetInt("vote_option");
    short team = pEvent->GetInt("team");
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnVoteCast, vote_option, team, player_slot.Get())
}

GAME_EVENT(vote_options)
{
    unsigned char count = pEvent->GetInt("count");
    std::string option1 = pEvent->GetString("option1");
    std::string option2 = pEvent->GetString("option2");
    std::string option3 = pEvent->GetString("option3");
    std::string option4 = pEvent->GetString("option4");
    std::string option5 = pEvent->GetString("option5");

    CALL_PFUNCTION_VOID_ARGS(OnVoteOptions, count, option1.c_str(), option2.c_str(), option3.c_str(), option4.c_str(), option5.c_str())
}

GAME_EVENT(endmatch_mapvote_selecting_map)
{
    unsigned char count = pEvent->GetInt("count");
    unsigned char slot1 = pEvent->GetInt("slot1");
    unsigned char slot2 = pEvent->GetInt("slot2");
    unsigned char slot3 = pEvent->GetInt("slot3");
    unsigned char slot4 = pEvent->GetInt("slot4");
    unsigned char slot5 = pEvent->GetInt("slot5");
    unsigned char slot6 = pEvent->GetInt("slot6");
    unsigned char slot7 = pEvent->GetInt("slot7");
    unsigned char slot8 = pEvent->GetInt("slot8");
    unsigned char slot9 = pEvent->GetInt("slot9");
    unsigned char slot10 = pEvent->GetInt("slot10");

    CALL_PFUNCTION_VOID_ARGS(OnEndmatchMapvoteSelectingMap, count, slot1, slot2, slot3, slot4, slot5, slot6, slot7, slot8, slot9, slot10)
}

GAME_EVENT(endmatch_cmm_start_reveal_items){

    CALL_PFUNCTION_VOID_NOARGS(OnEndmatchCMMStartRevealItems)}

GAME_EVENT(client_loadout_changed){

    CALL_PFUNCTION_VOID_NOARGS(OnClientLoadoutChanged)}

GAME_EVENT(add_player_sonar_icon)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    float pos_x = pEvent->GetFloat("pos_x");
    float pos_y = pEvent->GetFloat("pos_y");
    float pos_z = pEvent->GetFloat("pos_z");

    CALL_PFUNCTION_VOID_ARGS(OnAddPlayerSonarIcon, player_slot.Get(), pos_x, pos_y, pos_z)
}

GAME_EVENT(add_bullet_hit_marker)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short bone = pEvent->GetInt("bone");
    short pos_x = pEvent->GetInt("pos_x");
    short pos_y = pEvent->GetInt("pos_y");
    short pos_z = pEvent->GetInt("pos_z");
    short ang_x = pEvent->GetInt("ang_x");
    short ang_y = pEvent->GetInt("ang_y");
    short ang_z = pEvent->GetInt("ang_z");
    short start_x = pEvent->GetInt("start_x");
    short start_y = pEvent->GetInt("start_y");
    short start_z = pEvent->GetInt("start_z");
    bool hit = pEvent->GetBool("hit");

    CALL_PFUNCTION_VOID_ARGS(OnAddBulletHitMarker, player_slot.Get(), bone, pos_x, pos_y, pos_z, ang_x, ang_y, ang_z, start_x, start_y, start_z, hit)
}

GAME_EVENT(other_death)
{
    short otherid = pEvent->GetInt("otherid");
    std::string othertype = pEvent->GetString("othertype");
    short attacker = pEvent->GetInt("attacker");
    std::string weapon = pEvent->GetString("weapon");
    std::string weapon_itemid = pEvent->GetString("weapon_itemid");
    std::string weapon_fauxitemid = pEvent->GetString("weapon_fauxitemid");
    std::string weapon_originalowner_xuid = pEvent->GetString("weapon_originalowner_xuid");
    bool headshot = pEvent->GetBool("headshot");
    short penetrated = pEvent->GetInt("penetrated");
    bool noscope = pEvent->GetBool("noscope");
    bool thrusmoke = pEvent->GetBool("thrusmoke");
    bool attackerblind = pEvent->GetBool("attackerblind");

    CALL_PFUNCTION_VOID_ARGS(OnOtherDeath, otherid, othertype.c_str(), attacker, weapon.c_str(), weapon_itemid.c_str(), weapon_fauxitemid.c_str(), weapon_originalowner_xuid.c_str(), headshot, penetrated, noscope, thrusmoke, attackerblind)
}

GAME_EVENT(item_purchase)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short team = pEvent->GetInt("team");
    short loadout = pEvent->GetInt("loadout");
    std::string weapon = pEvent->GetString("weapon");

    CALL_PFUNCTION_VOID_ARGS(OnItemPurchase, player_slot.Get(), team, loadout, weapon.c_str())
}

GAME_EVENT(defuser_dropped)
{
    long entityid = pEvent->GetInt("entityid");

    CALL_PFUNCTION_VOID_ARGS(OnDefuserDropped, entityid)
}

GAME_EVENT(defuser_pickup)
{
    long entityid = pEvent->GetInt("entityid");
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnDefuserPickup, entityid, player_slot.Get())
}

GAME_EVENT(announce_phase_end){

    CALL_PFUNCTION_VOID_NOARGS(OnAnnouncePhaseEnd)}

GAME_EVENT(cs_intermission){

    CALL_PFUNCTION_VOID_NOARGS(OnCSIntermission)}

GAME_EVENT(hostage_follows)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short hostage = pEvent->GetInt("hostage");

    CALL_PFUNCTION_VOID_ARGS(OnHostageFollows, player_slot.Get(), hostage)
}

GAME_EVENT(hostage_hurt)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short hostage = pEvent->GetInt("hostage");

    CALL_PFUNCTION_VOID_ARGS(OnHostageHurt, player_slot.Get(), hostage)
}

GAME_EVENT(hostage_killed)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short hostage = pEvent->GetInt("hostage");

    CALL_PFUNCTION_VOID_ARGS(OnHostageKilled, player_slot.Get(), hostage)
}

GAME_EVENT(hostage_rescued)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short hostage = pEvent->GetInt("hostage");
    short site = pEvent->GetInt("site");

    CALL_PFUNCTION_VOID_ARGS(OnHostageRescued, player_slot.Get(), hostage, site)
}

GAME_EVENT(hostage_stops_following)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short hostage = pEvent->GetInt("hostage");

    CALL_PFUNCTION_VOID_ARGS(OnHostageStopsFollowing, player_slot.Get(), hostage)
}

GAME_EVENT(hostage_rescued_all){

    CALL_PFUNCTION_VOID_NOARGS(OnHostageRescuedAll)}

GAME_EVENT(hostage_call_for_help)
{
    short hostage = pEvent->GetInt("hostage");

    CALL_PFUNCTION_VOID_ARGS(OnHostageCallForHelp, hostage)
}

GAME_EVENT(vip_escaped)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnVIPEscaped, player_slot.Get())
}

GAME_EVENT(vip_killed)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    CPlayerSlot attacker_slot = pEvent->GetPlayerSlot("attacker");

    CALL_PFUNCTION_VOID_ARGS(OnVIPKilled, player_slot.Get(), attacker_slot.Get())
}

GAME_EVENT(player_radio)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short slot = pEvent->GetInt("slot");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerRadio, player_slot.Get(), slot)
}

GAME_EVENT(bomb_beep)
{
    long entindex = pEvent->GetInt("entindex");

    CALL_PFUNCTION_VOID_ARGS(OnBombBeep, entindex)
}

GAME_EVENT(weapon_fire)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string weapon = pEvent->GetString("weapon");
    bool silenced = pEvent->GetBool("silenced");

    CALL_PFUNCTION_VOID_ARGS(OnWeaponFire, player_slot.Get(), weapon.c_str(), silenced)
}

GAME_EVENT(weapon_fire_on_empty)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string weapon = pEvent->GetString("weapon");

    CALL_PFUNCTION_VOID_ARGS(OnWeaponFireOnEmpty, player_slot.Get(), weapon.c_str())
}

GAME_EVENT(grenade_thrown)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string weapon = pEvent->GetString("weapon");

    CALL_PFUNCTION_VOID_ARGS(OnGrenadeThrown, player_slot.Get(), weapon.c_str())
}

GAME_EVENT(weapon_outofammo)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnWeaponOutOfAmmo, player_slot.Get())
}

GAME_EVENT(weapon_reload)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnWeaponReload, player_slot.Get())
}

GAME_EVENT(weapon_zoom)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnWeaponZoom, player_slot.Get())
}

GAME_EVENT(silencer_detach)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnSilencerDetach, player_slot.Get())
}

GAME_EVENT(inspect_weapon)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnInspectWeapon, player_slot.Get())
}

GAME_EVENT(weapon_zoom_rifle)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnWeaponZoomRifle, player_slot.Get())
}

GAME_EVENT(player_spawned)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    bool inrestart = pEvent->GetBool("inrestart");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerSpawned, player_slot.Get(), inrestart)
}

GAME_EVENT(item_pickup_slerp)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short index = pEvent->GetInt("index");
    short behavior = pEvent->GetInt("behavior");

    CALL_PFUNCTION_VOID_ARGS(OnItemPickupSlerp, player_slot.Get(), index, behavior)
}

GAME_EVENT(item_pickup_failed)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string item = pEvent->GetString("item");
    short reason = pEvent->GetInt("reason");
    short limit = pEvent->GetInt("limit");

    CALL_PFUNCTION_VOID_ARGS(OnItemPickupFailed, player_slot.Get(), item.c_str(), reason, limit)
}

GAME_EVENT(item_remove)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string item = pEvent->GetString("item");
    long defindex = pEvent->GetInt("defindex");

    CALL_PFUNCTION_VOID_ARGS(OnItemRemove, player_slot.Get(), item.c_str(), defindex)
}

GAME_EVENT(ammo_pickup)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string item = pEvent->GetString("item");
    long index = pEvent->GetInt("index");

    CALL_PFUNCTION_VOID_ARGS(OnAmmoPickup, player_slot.Get(), item.c_str(), index)
}

GAME_EVENT(item_equip)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string item = pEvent->GetString("item");
    long defindex = pEvent->GetInt("defindex");
    bool canzoom = pEvent->GetBool("canzoom");
    bool hassilencer = pEvent->GetBool("hassilencer");
    bool issilenced = pEvent->GetBool("issilenced");
    bool hastracers = pEvent->GetBool("hastracers");
    short weptype = pEvent->GetInt("weptype");
    bool ispainted = pEvent->GetBool("ispainted");

    CALL_PFUNCTION_VOID_ARGS(OnItemEquip, player_slot.Get(), item.c_str(), defindex, canzoom, hassilencer, issilenced, hastracers, weptype, ispainted)
}

GAME_EVENT(buytime_ended){

    CALL_PFUNCTION_VOID_NOARGS(OnBuytimeEnded)}

GAME_EVENT(enter_rescue_zone)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnEnterRescueZone, player_slot.Get())
}

GAME_EVENT(exit_rescue_zone)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnExitRescueZone, player_slot.Get())
}

GAME_EVENT(silencer_off)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnSilencerOff, player_slot.Get())
}

GAME_EVENT(silencer_on)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnSilencerOn, player_slot.Get())
}

GAME_EVENT(buymenu_open)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnBuyMenuOpen, player_slot.Get())
}

GAME_EVENT(buymenu_close)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnBuyMenuClose, player_slot.Get())
}

GAME_EVENT(grenade_bounce)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnGrenadeBounce, player_slot.Get())
}

GAME_EVENT(hegrenade_detonate)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnHEGrenadeDetonate, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(flashbang_detonate)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnFlashbangDetonate, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(smokegrenade_detonate)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnSmokeGrenadeDetonate, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(smokegrenade_expired)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnSmokeGrenadeExpired, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(molotov_detonate)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnMolotovDetonate, player_slot.Get(), x, y, z)
}

GAME_EVENT(decoy_detonate)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnDecoyDetonate, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(decoy_started)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnDecoyStarted, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(tagrenade_detonate)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnTagrenadeDetonate, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(inferno_startburn)
{
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnInfernoStartBurn, entityid, x, y, z)
}

GAME_EVENT(inferno_expire)
{
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnInfernoExpire, entityid, x, y, z)
}

GAME_EVENT(inferno_extinguish)
{
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnInfernoExtinguish, entityid, x, y, z)
}

GAME_EVENT(decoy_firing)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnDecoyFiring, player_slot.Get(), entityid, x, y, z)
}

GAME_EVENT(bullet_impact)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");

    CALL_PFUNCTION_VOID_ARGS(OnBulletImpact, player_slot.Get(), x, y, z)
}

GAME_EVENT(door_moving)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    long entindex = pEvent->GetInt("entindex");

    CALL_PFUNCTION_VOID_ARGS(OnDoorMoving, player_slot.Get(), entindex)
}

GAME_EVENT(mb_input_lock_success){

    CALL_PFUNCTION_VOID_NOARGS(OnMBInputLockSuccess)}

GAME_EVENT(mb_input_lock_cancel){

    CALL_PFUNCTION_VOID_NOARGS(OnMBInputLockCancel)}

GAME_EVENT(nav_blocked)
{
    long area = pEvent->GetInt("area");
    bool blocked = pEvent->GetBool("blocked");

    CALL_PFUNCTION_VOID_ARGS(OnNavBlocked, area, blocked)
}

GAME_EVENT(nav_generate){

    CALL_PFUNCTION_VOID_NOARGS(OnNavGenerate)}

GAME_EVENT(achievement_info_loaded){

    CALL_PFUNCTION_VOID_NOARGS(OnAchievementInfoLoaded)}

GAME_EVENT(hltv_changed_mode)
{
    long oldmode = pEvent->GetInt("oldmode");
    long newmode = pEvent->GetInt("newmode");
    long obs_target = pEvent->GetInt("obs_target");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVChangedMode, oldmode, newmode, obs_target)
}

GAME_EVENT(cs_game_disconnected){

    CALL_PFUNCTION_VOID_NOARGS(OnCSGameDisconnected)}

GAME_EVENT(cs_round_final_beep){

    CALL_PFUNCTION_VOID_NOARGS(OnCSRoundFinalBeep)}

GAME_EVENT(cs_round_start_beep){

    CALL_PFUNCTION_VOID_NOARGS(OnCSRoundStartBeep)}

GAME_EVENT(cs_win_panel_round)
{
    bool show_timer_defend = pEvent->GetBool("show_timer_defend");
    bool show_timer_attack = pEvent->GetBool("show_timer_attack");
    short timer_time = pEvent->GetInt("timer_time");
    unsigned char final_event = pEvent->GetInt("final_event");
    std::string funfact_token = pEvent->GetString("funfact_token");
    CPlayerSlot funfact_player_slot = pEvent->GetPlayerSlot("funfact_player");
    long funfact_data1 = pEvent->GetInt("funfact_data1");
    long funfact_data2 = pEvent->GetInt("funfact_data2");
    long funfact_data3 = pEvent->GetInt("funfact_data3");

    CALL_PFUNCTION_VOID_ARGS(OnCSWinPanelRound, show_timer_defend, show_timer_attack, timer_time, final_event, funfact_token.c_str(), funfact_player_slot.Get(), funfact_data1, funfact_data2, funfact_data3)
}

GAME_EVENT(cs_win_panel_match){

    CALL_PFUNCTION_VOID_NOARGS(OnCSWinPanelMatch)}

GAME_EVENT(cs_match_end_restart){

    CALL_PFUNCTION_VOID_NOARGS(OnCSMatchEndRestart)}

GAME_EVENT(cs_pre_restart){

    CALL_PFUNCTION_VOID_NOARGS(OnCSPreRestart)}

GAME_EVENT(show_deathpanel)
{
    CPlayerSlot victim_slot = pEvent->GetPlayerSlot("victim");
    long killer = pEvent->GetInt("killer");
    CPlayerSlot killer_controller_slot = pEvent->GetPlayerSlot("killer_controller");
    short hits_taken = pEvent->GetInt("hits_taken");
    short damage_taken = pEvent->GetInt("damage_taken");
    short hits_given = pEvent->GetInt("hits_given");
    short damage_given = pEvent->GetInt("damage_given");

    CALL_PFUNCTION_VOID_ARGS(OnShowDeathpanel, victim_slot.Get(), killer, killer_controller_slot.Get(), hits_taken, damage_taken, hits_given, damage_given)
}

GAME_EVENT(hide_deathpanel){

    CALL_PFUNCTION_VOID_NOARGS(OnHideDeathpanel)}

GAME_EVENT(achievement_earned_local)
{
    short achievement = pEvent->GetInt("achievement");
    short splitscreenplayer = pEvent->GetInt("splitscreenplayer");

    CALL_PFUNCTION_VOID_ARGS(OnAchievementEarnedLocal, achievement, splitscreenplayer)
}

GAME_EVENT(repost_xbox_achievements)
{
    short splitscreenplayer = pEvent->GetInt("splitscreenplayer");

    CALL_PFUNCTION_VOID_ARGS(OnRepostXboxAchievements, splitscreenplayer)
}

GAME_EVENT(match_end_conditions)
{
    long frags = pEvent->GetInt("frags");
    long max_rounds = pEvent->GetInt("max_rounds");
    long win_rounds = pEvent->GetInt("win_rounds");
    long time = pEvent->GetInt("time");

    CALL_PFUNCTION_VOID_ARGS(OnMatchEndConditions, frags, max_rounds, win_rounds, time)
}

GAME_EVENT(show_survival_respawn_status)
{
    std::string loc_token = pEvent->GetString("loc_token");
    long duration = pEvent->GetInt("duration");
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnShowSurvivalRespawnStatus, loc_token.c_str(), duration, player_slot.Get())
}

GAME_EVENT(gg_killed_enemy)
{
    CPlayerSlot victim_slot = pEvent->GetPlayerSlot("victim");
    CPlayerSlot attacker_slot = pEvent->GetPlayerSlot("attacker");
    short dominated = pEvent->GetInt("dominated");
    short revenge = pEvent->GetInt("revenge");
    bool bonus = pEvent->GetBool("bonus");

    CALL_PFUNCTION_VOID_ARGS(OnGGKilledEnemy, victim_slot.Get(), attacker_slot.Get(), dominated, revenge, bonus)
}

GAME_EVENT(switch_team)
{
    short numPlayers = pEvent->GetInt("numPlayers");
    short numSpectators = pEvent->GetInt("numSpectators");
    short avg_rank = pEvent->GetInt("avg_rank");
    short numTSlotsFree = pEvent->GetInt("numTSlotsFree");
    short numCTSlotsFree = pEvent->GetInt("numCTSlotsFree");

    CALL_PFUNCTION_VOID_ARGS(OnSwitchTeam, numPlayers, numSpectators, avg_rank, numTSlotsFree, numCTSlotsFree)
}

GAME_EVENT(write_profile_data){

    CALL_PFUNCTION_VOID_NOARGS(OnWriteProfileData)}

GAME_EVENT(trial_time_expired)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnTrialTimeExpired, player_slot.Get())
}

GAME_EVENT(update_matchmaking_stats){

    CALL_PFUNCTION_VOID_NOARGS(OnUpdateMatchmakingStats)}

GAME_EVENT(player_reset_vote)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    bool vote = pEvent->GetBool("vote");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerResetVote, player_slot.Get(), vote)
}

GAME_EVENT(enable_restart_voting)
{
    bool enable = pEvent->GetBool("enable");

    CALL_PFUNCTION_VOID_ARGS(OnEnableRestartVoting, enable)
}

GAME_EVENT(sfuievent)
{
    std::string action = pEvent->GetString("action");
    std::string data = pEvent->GetString("data");
    unsigned char slot = pEvent->GetInt("slot");

    CALL_PFUNCTION_VOID_ARGS(OnSfuievent, action.c_str(), data.c_str(), slot)
}

GAME_EVENT(start_vote)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    unsigned char type = pEvent->GetInt("type");
    short vote_parameter = pEvent->GetInt("vote_parameter");

    CALL_PFUNCTION_VOID_ARGS(OnStartVote, player_slot.Get(), type, vote_parameter)
}

GAME_EVENT(player_given_c4)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerGivenBomb, player_slot.Get())
}

GAME_EVENT(tr_player_flashbanged)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnTRPlayerFlashbanged, player_slot.Get())
}

GAME_EVENT(tr_mark_complete)
{
    short complete = pEvent->GetInt("complete");

    CALL_PFUNCTION_VOID_ARGS(OnTRMarkComplete, complete)
}

GAME_EVENT(tr_mark_best_time)
{
    long time = pEvent->GetInt("time");

    CALL_PFUNCTION_VOID_ARGS(OnTRMarkBestTime, time)
}

GAME_EVENT(tr_exit_hint_trigger){

    CALL_PFUNCTION_VOID_NOARGS(OnTRExitHintTrigger)}

GAME_EVENT(bot_takeover)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    CPlayerSlot bot_slot = pEvent->GetPlayerSlot("bot");

    CALL_PFUNCTION_VOID_ARGS(OnBotTakeover, player_slot.Get(), bot_slot.Get())
}

GAME_EVENT(tr_show_finish_msgbox){

    CALL_PFUNCTION_VOID_NOARGS(OnTRShowFinishMsgbox)}

GAME_EVENT(tr_show_exit_msgbox){

    CALL_PFUNCTION_VOID_NOARGS(OnTRShowExitMsgbox)}

GAME_EVENT(jointeam_failed)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    unsigned char reason = pEvent->GetInt("reason");

    CALL_PFUNCTION_VOID_ARGS(OnJoinTeamFailed, player_slot.Get(), reason)
}

GAME_EVENT(teamchange_pending)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    unsigned char toteam = pEvent->GetInt("toteam");

    CALL_PFUNCTION_VOID_ARGS(OnTeamChangePending, player_slot.Get(), toteam)
}

GAME_EVENT(material_default_complete){

    CALL_PFUNCTION_VOID_NOARGS(OnMaterialDefaultComplete)}

GAME_EVENT(cs_prev_next_spectator)
{
    bool next = pEvent->GetBool("next");

    CALL_PFUNCTION_VOID_ARGS(OnCSPrevNextSpectator, next)
}

GAME_EVENT(nextlevel_changed)
{
    std::string nextlevel = pEvent->GetString("nextlevel");
    std::string mapgroup = pEvent->GetString("mapgroup");
    std::string skirmishmode = pEvent->GetString("skirmishmode");

    CALL_PFUNCTION_VOID_ARGS(OnNextLevelChanged, nextlevel.c_str(), mapgroup.c_str(), skirmishmode.c_str())
}

GAME_EVENT(seasoncoin_levelup)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short category = pEvent->GetInt("category");
    short rank = pEvent->GetInt("rank");

    CALL_PFUNCTION_VOID_ARGS(OnSeasoncoinLevelup, player_slot.Get(), category, rank)
}

GAME_EVENT(tournament_reward)
{
    long defindex = pEvent->GetInt("defindex");
    long totalrewards = pEvent->GetInt("totalrewards");
    long accountid = pEvent->GetInt("accountid");

    CALL_PFUNCTION_VOID_ARGS(OnTournamentReward, defindex, totalrewards, accountid)
}

GAME_EVENT(start_halftime){

    CALL_PFUNCTION_VOID_NOARGS(OnStartHalftime)}

GAME_EVENT(ammo_refill)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    bool success = pEvent->GetBool("success");

    CALL_PFUNCTION_VOID_ARGS(OnAmmoRefill, player_slot.Get(), success)
}

GAME_EVENT(parachute_pickup)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnParachutePickup, player_slot.Get())
}

GAME_EVENT(parachute_deploy)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnParachuteDeploy, player_slot.Get())
}

GAME_EVENT(dronegun_attack)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnDronegunAttack, player_slot.Get())
}

GAME_EVENT(drone_dispatched)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short priority = pEvent->GetInt("priority");
    short drone_dispatched = pEvent->GetInt("drone_dispatched");

    CALL_PFUNCTION_VOID_ARGS(OnDroneDispatched, player_slot.Get(), priority, drone_dispatched)
}

GAME_EVENT(loot_crate_visible)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short subject = pEvent->GetInt("subject");
    std::string type = pEvent->GetString("type");

    CALL_PFUNCTION_VOID_ARGS(OnLootCrateVisible, player_slot.Get(), subject, type.c_str())
}

GAME_EVENT(loot_crate_opened)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    std::string type = pEvent->GetString("type");

    CALL_PFUNCTION_VOID_ARGS(OnLootCrateOpened, player_slot.Get(), type.c_str())
}

GAME_EVENT(open_crate_instr)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short subject = pEvent->GetInt("subject");
    std::string type = pEvent->GetString("type");

    CALL_PFUNCTION_VOID_ARGS(OnOpenCrateInstructions, player_slot.Get(), subject, type.c_str())
}

GAME_EVENT(smoke_beacon_paradrop)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short paradrop = pEvent->GetInt("paradrop");

    CALL_PFUNCTION_VOID_ARGS(OnSmokeBeaconParadrop, player_slot.Get(), paradrop)
}

GAME_EVENT(survival_paradrop_spawn)
{
    short entityid = pEvent->GetInt("entityid");

    CALL_PFUNCTION_VOID_ARGS(OnSurvivalParadropSpawn, entityid)
}

GAME_EVENT(survival_paradrop_break)
{
    short entityid = pEvent->GetInt("entityid");

    CALL_PFUNCTION_VOID_ARGS(OnSurvivalParadropBreak, entityid)
}

GAME_EVENT(drone_cargo_detached)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short cargo = pEvent->GetInt("cargo");
    bool delivered = pEvent->GetBool("delivered");

    CALL_PFUNCTION_VOID_ARGS(OnDroneCargoDetached, player_slot.Get(), cargo, delivered)
}

GAME_EVENT(drone_above_roof)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short cargo = pEvent->GetInt("cargo");

    CALL_PFUNCTION_VOID_ARGS(OnDroneAboveRoof, player_slot.Get(), cargo)
}

GAME_EVENT(choppers_incoming_warning)
{
    bool global = pEvent->GetBool("global");

    CALL_PFUNCTION_VOID_ARGS(OnChoppersIncomingWarning, global)
}

GAME_EVENT(firstbombs_incoming_warning)
{
    bool global = pEvent->GetBool("global");

    CALL_PFUNCTION_VOID_ARGS(OnFirstbombsIncomingWarning, global)
}

GAME_EVENT(dz_item_interaction)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short subject = pEvent->GetInt("subject");
    std::string type = pEvent->GetString("type");

    CALL_PFUNCTION_VOID_ARGS(OnDZItemInteraction, player_slot.Get(), subject, type.c_str())
}

GAME_EVENT(survival_teammate_respawn)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnSurvivalTeammateRespawn, player_slot.Get())
}

GAME_EVENT(survival_no_respawns_warning)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnSurvivalNoRespawnsWarning, player_slot.Get())
}

GAME_EVENT(survival_no_respawns_final)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");

    CALL_PFUNCTION_VOID_ARGS(OnSurvivalNoRespawnsFinal, player_slot.Get())
}

GAME_EVENT(player_ping)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short entityid = pEvent->GetInt("entityid");
    float x = pEvent->GetFloat("x");
    float y = pEvent->GetFloat("y");
    float z = pEvent->GetFloat("z");
    bool urgent = pEvent->GetBool("urgent");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerPing, player_slot.Get(), entityid, x, y, z, urgent)
}

GAME_EVENT(player_ping_stop)
{
    short entityid = pEvent->GetInt("entityid");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerPingStop, entityid)
}

GAME_EVENT(player_sound)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    long radius = pEvent->GetInt("radius");
    float duration = pEvent->GetFloat("duration");
    bool step = pEvent->GetBool("step");

    CALL_PFUNCTION_VOID_ARGS(OnPlayerSound, player_slot.Get(), radius, duration, step)
}

GAME_EVENT(guardian_wave_restart){

    CALL_PFUNCTION_VOID_NOARGS(OnGuardianWaveRestart)}

GAME_EVENT(team_intro_start){

    CALL_PFUNCTION_VOID_NOARGS(OnTeamIntroStart)}

GAME_EVENT(team_intro_end){

    CALL_PFUNCTION_VOID_NOARGS(OnTeamIntroEnd)}

GAME_EVENT(bullet_flight_resolution)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    short pos_x = pEvent->GetInt("pos_x");
    short pos_y = pEvent->GetInt("pos_y");
    short pos_z = pEvent->GetInt("pos_z");
    short ang_x = pEvent->GetInt("ang_x");
    short ang_y = pEvent->GetInt("ang_y");
    short ang_z = pEvent->GetInt("ang_z");
    short start_x = pEvent->GetInt("start_x");
    short start_y = pEvent->GetInt("start_y");
    short start_z = pEvent->GetInt("start_z");

    CALL_PFUNCTION_VOID_ARGS(OnBulletFlightResolution, player_slot.Get(), pos_x, pos_y, pos_z, ang_x, ang_y, ang_z, start_x, start_y, start_z)
}

GAME_EVENT(door_break)
{
    long entindex = pEvent->GetInt("entindex");
    long dmgstate = pEvent->GetInt("dmgstate");

    CALL_PFUNCTION_VOID_ARGS(OnDoorBreak, entindex, dmgstate)
}

GAME_EVENT(door_closed)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    long entindex = pEvent->GetInt("entindex");

    CALL_PFUNCTION_VOID_ARGS(OnDoorClosed, player_slot.Get(), entindex)
}

GAME_EVENT(door_open)
{
    CPlayerSlot player_slot = pEvent->GetPlayerSlot("userid");
    long entindex = pEvent->GetInt("entindex");

    CALL_PFUNCTION_VOID_ARGS(OnDoorOpen, player_slot.Get(), entindex)
}

GAME_EVENT(game_phase_changed)
{
    short new_phase = pEvent->GetInt("new_phase");

    CALL_PFUNCTION_VOID_ARGS(OnGamePhaseChanged, new_phase)
}

GAME_EVENT(hltv_replay_status)
{
    long reason = pEvent->GetInt("reason");

    CALL_PFUNCTION_VOID_ARGS(OnHLTVReplayStatus, reason)
}

bool scripting_OnClientCommand(OnClientCommand *e)
{
    CALL_PFUNCTION_BOOL_ARGS(OnClientCommand, false, true, e->slot->Get(), e->command);
}

bool scripting_OnPlayerPrePostThink(CPlayerSlot slot)
{
    CALL_PFUNCTION_BOOL_ARGS(OnPlayerPrePostThink, false, true, slot.Get());
}

void scripting_OnPlayerPostThink(CPlayerSlot slot)
{
    CALL_PFUNCTION_VOID_ARGS(OnPlayerPostThink, slot.Get());
}

void scripting_OnPlayerFallDamage(CPlayerSlot slot, float damage)
{
    CALL_PFUNCTION_VOID_ARGS(OnPlayerFallDamage, slot.Get(), damage);
}

bool scripting_OnPlayerDamage(CPlayerSlot slot, float damage, DamageTypes_t damagetype, uint8_t bullettype, TakeDamageFlags_t damageflags)
{
    CALL_PFUNCTION_BOOL_ARGS(OnPlayerDamage, false, true, slot.Get(), damage, (uint32_t)damagetype, bullettype, (uint32_t)damageflags);
}

bool scripting_OnPlayerDamagePlayer(CPlayerSlot slot, CPlayerSlot attacker, float damage, DamageTypes_t damagetype, uint8_t bullettype, TakeDamageFlags_t damageflags)
{
    CALL_PFUNCTION_BOOL_ARGS(OnPlayerDamagePlayer, false, true, slot.Get(), attacker.Get(), damage, (uint32_t)damagetype, bullettype, (uint32_t)damageflags);
}

bool scripting_OnPlayerPreJump(int slot)
{
    CALL_PFUNCTION_BOOL_ARGS(OnPlayerPreJump, false, true, slot);
}

void scripting_OnPlayerPostJump(int slot)
{
    CALL_PFUNCTION_VOID_ARGS(OnPlayerPostJump, slot);
}

void PluginsComponent::RegisterGameEvents()
{
    hooks::on<OnMapLoad>(scripting_OnMapLoad);
    hooks::on<OnMapUnload>(scripting_OnMapUnload);
    hooks::on<OnClientKeyStateChange>(scripting_OnClientKeyStateChange);

    hooks::on<OnWeaponSpawned>(scripting_OnWeaponSpawned);
    hooks::on<OnClientExecuteCommand>(scripting_OnClientExecuteCommand);
}