#include "../../scripting.h"
#include "../../../PluginManager.h"
#include "../../../../gameevents/gameevents.h"
#include "../../../../player/PlayerManager.h"

#include <vector>
#include <msgpack.hpp>
#include <string>
#include <sstream>

GAME_EVENT(server_spawn)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("hostname")));
    eventData.push_back(msgpack::object(pEvent->GetString("address")));
    eventData.push_back(msgpack::object(pEvent->GetInt("port")));
    eventData.push_back(msgpack::object(pEvent->GetString("game")));
    eventData.push_back(msgpack::object(pEvent->GetString("mapname")));
    eventData.push_back(msgpack::object(pEvent->GetString("addonname")));
    eventData.push_back(msgpack::object(pEvent->GetInt("maxplayers")));
    eventData.push_back(msgpack::object(pEvent->GetString("os")));
    eventData.push_back(msgpack::object(pEvent->GetBool("dedicated")));
    eventData.push_back(msgpack::object(pEvent->GetBool("password")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnServerSpawn", ss.str(), event);
    delete event;
}

GAME_EVENT(server_pre_shutdown)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("reason")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnServerPreShutdown", ss.str(), event);
    delete event;
}

GAME_EVENT(server_shutdown)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("reason")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnServerShutdown", ss.str(), event);
    delete event;
}

GAME_EVENT(server_message)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("text")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnServerMessage", ss.str(), event);
    delete event;
}

GAME_EVENT(server_cvar)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("cvarname")));
    eventData.push_back(msgpack::object(pEvent->GetString("cvarvalue")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnServerCvar", ss.str(), event);
    delete event;
}

GAME_EVENT(player_activate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerActivate", ss.str(), event);
    delete event;
}

GAME_EVENT(player_connect_full)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerConnectFull", ss.str(), event);
    delete event;
}

GAME_EVENT(player_full_update)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("count")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerFullUpdate", ss.str(), event);
    delete event;
}

GAME_EVENT(player_connect)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("name")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("networkid")));
    eventData.push_back(msgpack::object(pEvent->GetUint64("xuid")));
    eventData.push_back(msgpack::object(pEvent->GetString("address")));
    eventData.push_back(msgpack::object(pEvent->GetBool("bot")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerConnect", ss.str(), event);
    delete event;
}

GAME_EVENT(player_disconnect)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("reason")));
    eventData.push_back(msgpack::object(pEvent->GetString("name")));
    eventData.push_back(msgpack::object(pEvent->GetString("networkid")));
    eventData.push_back(msgpack::object(pEvent->GetUint64("xuid")));
    eventData.push_back(msgpack::object(pEvent->GetInt("PlayerID")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerDisconnect", ss.str(), event);
    delete event;
}

GAME_EVENT(player_info)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("name")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetUint64("steamid")));
    eventData.push_back(msgpack::object(pEvent->GetBool("bot")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerInfo", ss.str(), event);
    delete event;
}

GAME_EVENT(player_spawn)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerSpawn", ss.str(), event);
    delete event;
}

GAME_EVENT(player_team)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("team")));
    eventData.push_back(msgpack::object(pEvent->GetInt("oldteam")));
    eventData.push_back(msgpack::object(pEvent->GetBool("disconnect")));
    eventData.push_back(msgpack::object(pEvent->GetBool("silent")));
    eventData.push_back(msgpack::object(pEvent->GetBool("isbot")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerTeam", ss.str(), event);
    delete event;
}

GAME_EVENT(local_player_team)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnLocalPlayerTeam", ss.str(), event);
    delete event;
}

GAME_EVENT(local_player_controller_team)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnLocalPlayerControllerTeam", ss.str(), event);
    delete event;
}

GAME_EVENT(player_changename)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("oldname")));
    eventData.push_back(msgpack::object(pEvent->GetString("newname")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerChangename", ss.str(), event);
    delete event;
}

GAME_EVENT(player_hurt)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("attacker").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("health")));
    eventData.push_back(msgpack::object(pEvent->GetInt("armor")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon")));
    eventData.push_back(msgpack::object(pEvent->GetInt("dmg_health")));
    eventData.push_back(msgpack::object(pEvent->GetInt("dmg_armor")));
    eventData.push_back(msgpack::object(pEvent->GetInt("hitgroup")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerHurt", ss.str(), event);
    delete event;
}

GAME_EVENT(player_chat)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("teamonly")));
    eventData.push_back(msgpack::object(pEvent->GetInt("userid")));
    eventData.push_back(msgpack::object(pEvent->GetString("text")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerChat", ss.str(), event);
    delete event;
}

GAME_EVENT(local_player_pawn_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnLocalPlayerPawnChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(teamplay_broadcast_audio)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("team")));
    eventData.push_back(msgpack::object(pEvent->GetString("sound")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTeamplayBroadcastAudio", ss.str(), event);
    delete event;
}

GAME_EVENT(finale_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("rushes")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnFinaleStart", ss.str(), event);
    delete event;
}

GAME_EVENT(player_stats_updated)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("forceupload")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerStatsUpdated", ss.str(), event);
    delete event;
}

GAME_EVENT(user_data_downloaded)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUserDataDownloaded", ss.str(), event);
    delete event;
}

GAME_EVENT(ragdoll_dissolved)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRagdollDissolved", ss.str(), event);
    delete event;
}

GAME_EVENT(team_info)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("teamid")));
    eventData.push_back(msgpack::object(pEvent->GetString("teamname")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTeamInfo", ss.str(), event);
    delete event;
}

GAME_EVENT(team_score)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("teamid")));
    eventData.push_back(msgpack::object(pEvent->GetInt("score")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTeamScore", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_cameraman)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvCameraman", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_chase)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("target1").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("target2").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("distance")));
    eventData.push_back(msgpack::object(pEvent->GetInt("theta")));
    eventData.push_back(msgpack::object(pEvent->GetInt("phi")));
    eventData.push_back(msgpack::object(pEvent->GetInt("inertia")));
    eventData.push_back(msgpack::object(pEvent->GetInt("ineye")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvChase", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_rank_camera)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("index")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("rank")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("target").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvRankCamera", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_rank_entity)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetFloat("rank")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("target").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvRankEntity", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_fixed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("posx")));
    eventData.push_back(msgpack::object(pEvent->GetInt("posy")));
    eventData.push_back(msgpack::object(pEvent->GetInt("posz")));
    eventData.push_back(msgpack::object(pEvent->GetInt("theta")));
    eventData.push_back(msgpack::object(pEvent->GetInt("phi")));
    eventData.push_back(msgpack::object(pEvent->GetInt("offset")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("fov")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("target").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvFixed", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_message)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("text")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvMessage", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_status)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("clients")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slots")));
    eventData.push_back(msgpack::object(pEvent->GetInt("proxies")));
    eventData.push_back(msgpack::object(pEvent->GetString("master")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvStatus", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_title)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("text")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvTitle", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_chat)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("text")));
    eventData.push_back(msgpack::object(pEvent->GetUint64("steamID")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvChat", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_versioninfo)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("version")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvVersioninfo", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_replay)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("delay")));
    eventData.push_back(msgpack::object(pEvent->GetInt("reason")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvReplay", ss.str(), event);
    delete event;
}

GAME_EVENT(demo_stop)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDemoStop", ss.str(), event);
    delete event;
}

GAME_EVENT(map_shutdown)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMapShutdown", ss.str(), event);
    delete event;
}

GAME_EVENT(map_transition)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMapTransition", ss.str(), event);
    delete event;
}

GAME_EVENT(hostname_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("hostname")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostnameChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(difficulty_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("newDifficulty")));
    eventData.push_back(msgpack::object(pEvent->GetInt("oldDifficulty")));
    eventData.push_back(msgpack::object(pEvent->GetString("strDifficulty")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDifficultyChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(game_message)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("target")));
    eventData.push_back(msgpack::object(pEvent->GetString("text")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameMessage", ss.str(), event);
    delete event;
}

GAME_EVENT(game_newmap)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("mapname")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameNewmap", ss.str(), event);
    delete event;
}

GAME_EVENT(round_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("timelimit")));
    eventData.push_back(msgpack::object(pEvent->GetInt("fraglimit")));
    eventData.push_back(msgpack::object(pEvent->GetString("objective")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundStart", ss.str(), event);
    delete event;
}

GAME_EVENT(warmup_end)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWarmupEnd", ss.str(), event);
    delete event;
}

GAME_EVENT(round_end)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("winner")));
    eventData.push_back(msgpack::object(pEvent->GetInt("reason")));
    eventData.push_back(msgpack::object(pEvent->GetString("message")));
    eventData.push_back(msgpack::object(pEvent->GetInt("legacy")));
    eventData.push_back(msgpack::object(pEvent->GetInt("player_count")));
    eventData.push_back(msgpack::object(pEvent->GetInt("nomusic")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundEnd", ss.str(), event);
    delete event;
}

GAME_EVENT(round_start_pre_entity)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundStartPreEntity", ss.str(), event);
    delete event;
}

GAME_EVENT(round_start_post_nav)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundStartPostNav", ss.str(), event);
    delete event;
}

GAME_EVENT(round_freeze_end)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundFreezeEnd", ss.str(), event);
    delete event;
}

GAME_EVENT(teamplay_round_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("full_reset")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTeamplayRoundStart", ss.str(), event);
    delete event;
}

GAME_EVENT(player_death)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("attacker").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("assister").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("assistedflash")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon_itemid")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon_fauxitemid")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon_originalowner_xuid")));
    eventData.push_back(msgpack::object(pEvent->GetBool("headshot")));
    eventData.push_back(msgpack::object(pEvent->GetInt("dominated")));
    eventData.push_back(msgpack::object(pEvent->GetInt("revenge")));
    eventData.push_back(msgpack::object(pEvent->GetInt("wipe")));
    eventData.push_back(msgpack::object(pEvent->GetInt("penetrated")));
    eventData.push_back(msgpack::object(pEvent->GetBool("noreplay")));
    eventData.push_back(msgpack::object(pEvent->GetBool("noscope")));
    eventData.push_back(msgpack::object(pEvent->GetBool("thrusmoke")));
    eventData.push_back(msgpack::object(pEvent->GetBool("attackerblind")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("distance")));
    eventData.push_back(msgpack::object(pEvent->GetInt("dmg_health")));
    eventData.push_back(msgpack::object(pEvent->GetInt("dmg_armor")));
    eventData.push_back(msgpack::object(pEvent->GetInt("hitgroup")));
    eventData.push_back(msgpack::object(pEvent->GetBool("attackerinair")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerDeath", ss.str(), event);
    delete event;
}

GAME_EVENT(player_footstep)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerFootstep", ss.str(), event);
    delete event;
}

GAME_EVENT(player_hintmessage)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("hintmessage")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerHintmessage", ss.str(), event);
    delete event;
}

GAME_EVENT(break_breakable)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("material")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBreakBreakable", ss.str(), event);
    delete event;
}

GAME_EVENT(break_prop)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBreakProp", ss.str(), event);
    delete event;
}

GAME_EVENT(entity_killed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex_killed")));
    eventData.push_back(msgpack::object(pEvent->GetInt("entindex_attacker")));
    eventData.push_back(msgpack::object(pEvent->GetInt("entindex_inflictor")));
    eventData.push_back(msgpack::object(pEvent->GetInt("damagebits")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEntityKilled", ss.str(), event);
    delete event;
}

GAME_EVENT(door_close)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("checkpoint")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDoorClose", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_started)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("issue")));
    eventData.push_back(msgpack::object(pEvent->GetString("param1")));
    eventData.push_back(msgpack::object(pEvent->GetInt("team")));
    eventData.push_back(msgpack::object(pEvent->GetInt("initiator")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteStarted", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_failed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("team")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteFailed", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_passed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("details")));
    eventData.push_back(msgpack::object(pEvent->GetString("param1")));
    eventData.push_back(msgpack::object(pEvent->GetInt("team")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVotePassed", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("vote_option1")));
    eventData.push_back(msgpack::object(pEvent->GetInt("vote_option2")));
    eventData.push_back(msgpack::object(pEvent->GetInt("vote_option3")));
    eventData.push_back(msgpack::object(pEvent->GetInt("vote_option4")));
    eventData.push_back(msgpack::object(pEvent->GetInt("vote_option5")));
    eventData.push_back(msgpack::object(pEvent->GetInt("potentialVotes")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_cast_yes)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("team")));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteCastYes", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_cast_no)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("team")));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteCastNo", ss.str(), event);
    delete event;
}

GAME_EVENT(achievement_event)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("achievement_name")));
    eventData.push_back(msgpack::object(pEvent->GetInt("cur_val")));
    eventData.push_back(msgpack::object(pEvent->GetInt("max_val")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAchievementEvent", ss.str(), event);
    delete event;
}

GAME_EVENT(achievement_earned)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("player").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("achievement")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAchievementEarned", ss.str(), event);
    delete event;
}

GAME_EVENT(achievement_write_failed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAchievementWriteFailed", ss.str(), event);
    delete event;
}

GAME_EVENT(bonus_updated)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("numadvanced")));
    eventData.push_back(msgpack::object(pEvent->GetInt("numbronze")));
    eventData.push_back(msgpack::object(pEvent->GetInt("numsilver")));
    eventData.push_back(msgpack::object(pEvent->GetInt("numgold")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBonusUpdated", ss.str(), event);
    delete event;
}

GAME_EVENT(spec_target_updated)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("target")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSpecTargetUpdated", ss.str(), event);
    delete event;
}

GAME_EVENT(spec_mode_updated)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSpecModeUpdated", ss.str(), event);
    delete event;
}

GAME_EVENT(entity_visible)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("subject")));
    eventData.push_back(msgpack::object(pEvent->GetString("classname")));
    eventData.push_back(msgpack::object(pEvent->GetString("entityname")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEntityVisible", ss.str(), event);
    delete event;
}

GAME_EVENT(gameinstructor_draw)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameinstructorDraw", ss.str(), event);
    delete event;
}

GAME_EVENT(gameinstructor_nodraw)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameinstructorNodraw", ss.str(), event);
    delete event;
}

GAME_EVENT(flare_ignite_npc)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnFlareIgniteNpc", ss.str(), event);
    delete event;
}

GAME_EVENT(helicopter_grenade_punt_miss)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHelicopterGrenadePuntMiss", ss.str(), event);
    delete event;
}

GAME_EVENT(physgun_pickup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("target")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPhysgunPickup", ss.str(), event);
    delete event;
}

GAME_EVENT(inventory_updated)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInventoryUpdated", ss.str(), event);
    delete event;
}

GAME_EVENT(cart_updated)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCartUpdated", ss.str(), event);
    delete event;
}

GAME_EVENT(store_pricesheet_updated)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnStorePricesheetUpdated", ss.str(), event);
    delete event;
}

GAME_EVENT(item_schema_initialized)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemSchemaInitialized", ss.str(), event);
    delete event;
}

GAME_EVENT(drop_rate_modified)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDropRateModified", ss.str(), event);
    delete event;
}

GAME_EVENT(event_ticket_modified)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEventTicketModified", ss.str(), event);
    delete event;
}

GAME_EVENT(gc_connected)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGcConnected", ss.str(), event);
    delete event;
}

GAME_EVENT(instructor_start_lesson)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_name")));
    eventData.push_back(msgpack::object(pEvent->GetInt("hint_target")));
    eventData.push_back(msgpack::object(pEvent->GetInt("vr_movement_type")));
    eventData.push_back(msgpack::object(pEvent->GetBool("vr_single_controller")));
    eventData.push_back(msgpack::object(pEvent->GetInt("vr_controller_type")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInstructorStartLesson", ss.str(), event);
    delete event;
}

GAME_EVENT(instructor_close_lesson)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_name")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInstructorCloseLesson", ss.str(), event);
    delete event;
}

GAME_EVENT(instructor_server_hint_create)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_name")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_replace_key")));
    eventData.push_back(msgpack::object(pEvent->GetInt("hint_target")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("hint_activator_userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("hint_timeout")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_icon_onscreen")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_icon_offscreen")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_caption")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_activator_caption")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_color")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("hint_icon_offset")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("hint_range")));
    eventData.push_back(msgpack::object(pEvent->GetInt("hint_flags")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_binding")));
    eventData.push_back(msgpack::object(pEvent->GetString("hint_gamepad_binding")));
    eventData.push_back(msgpack::object(pEvent->GetBool("hint_allow_nodraw_target")));
    eventData.push_back(msgpack::object(pEvent->GetBool("hint_nooffscreen")));
    eventData.push_back(msgpack::object(pEvent->GetBool("hint_forcecaption")));
    eventData.push_back(msgpack::object(pEvent->GetBool("hint_local_player_only")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInstructorServerHintCreate", ss.str(), event);
    delete event;
}

GAME_EVENT(clientside_lesson_closed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("lesson_name")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientsideLessonClosed", ss.str(), event);
    delete event;
}

GAME_EVENT(dynamic_shadow_light_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDynamicShadowLightChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(gameui_hidden)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameuiHidden", ss.str(), event);
    delete event;
}

GAME_EVENT(items_gifted)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("player").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("itemdef")));
    eventData.push_back(msgpack::object(pEvent->GetInt("numgifts")));
    eventData.push_back(msgpack::object(pEvent->GetInt("giftidx")));
    eventData.push_back(msgpack::object(pEvent->GetInt("accountid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemsGifted", ss.str(), event);
    delete event;
}

GAME_EVENT(player_score)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("kills")));
    eventData.push_back(msgpack::object(pEvent->GetInt("deaths")));
    eventData.push_back(msgpack::object(pEvent->GetInt("score")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerScore", ss.str(), event);
    delete event;
}

GAME_EVENT(player_shoot)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("weapon")));
    eventData.push_back(msgpack::object(pEvent->GetInt("mode")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerShoot", ss.str(), event);
    delete event;
}

GAME_EVENT(game_init)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameInit", ss.str(), event);
    delete event;
}

GAME_EVENT(game_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("roundslimit")));
    eventData.push_back(msgpack::object(pEvent->GetInt("timelimit")));
    eventData.push_back(msgpack::object(pEvent->GetInt("fraglimit")));
    eventData.push_back(msgpack::object(pEvent->GetString("objective")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameStart", ss.str(), event);
    delete event;
}

GAME_EVENT(game_end)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("winner")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGameEnd", ss.str(), event);
    delete event;
}

GAME_EVENT(round_announce_match_point)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundAnnounceMatchPoint", ss.str(), event);
    delete event;
}

GAME_EVENT(round_announce_final)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundAnnounceFinal", ss.str(), event);
    delete event;
}

GAME_EVENT(round_announce_last_round_half)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundAnnounceLastRoundHalf", ss.str(), event);
    delete event;
}

GAME_EVENT(round_announce_match_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundAnnounceMatchStart", ss.str(), event);
    delete event;
}

GAME_EVENT(round_announce_warmup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundAnnounceWarmup", ss.str(), event);
    delete event;
}

GAME_EVENT(round_end_upload_stats)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundEndUploadStats", ss.str(), event);
    delete event;
}

GAME_EVENT(round_officially_ended)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundOfficiallyEnded", ss.str(), event);
    delete event;
}

GAME_EVENT(round_time_warning)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundTimeWarning", ss.str(), event);
    delete event;
}

GAME_EVENT(ugc_map_info_received)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetUint64("published_file_id")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUgcMapInfoReceived", ss.str(), event);
    delete event;
}

GAME_EVENT(ugc_map_unsubscribed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetUint64("published_file_id")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUgcMapUnsubscribed", ss.str(), event);
    delete event;
}

GAME_EVENT(ugc_map_download_error)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetUint64("published_file_id")));
    eventData.push_back(msgpack::object(pEvent->GetInt("error_code")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUgcMapDownloadError", ss.str(), event);
    delete event;
}

GAME_EVENT(ugc_file_download_finished)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetUint64("hcontent")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUgcFileDownloadFinished", ss.str(), event);
    delete event;
}

GAME_EVENT(ugc_file_download_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetUint64("hcontent")));
    eventData.push_back(msgpack::object(pEvent->GetUint64("published_file_id")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUgcFileDownloadStart", ss.str(), event);
    delete event;
}

GAME_EVENT(begin_new_match)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBeginNewMatch", ss.str(), event);
    delete event;
}

GAME_EVENT(dm_bonus_weapon_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("time")));
    eventData.push_back(msgpack::object(pEvent->GetInt("Pos")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDmBonusWeaponStart", ss.str(), event);
    delete event;
}

GAME_EVENT(survival_announce_phase)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("phase")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSurvivalAnnouncePhase", ss.str(), event);
    delete event;
}

GAME_EVENT(broken_breakable)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("material")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBrokenBreakable", ss.str(), event);
    delete event;
}

GAME_EVENT(player_decal)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerDecal", ss.str(), event);
    delete event;
}

GAME_EVENT(set_instructor_group_enabled)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("group")));
    eventData.push_back(msgpack::object(pEvent->GetInt("enabled")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSetInstructorGroupEnabled", ss.str(), event);
    delete event;
}

GAME_EVENT(instructor_server_hint_stop)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("hint_name")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInstructorServerHintStop", ss.str(), event);
    delete event;
}

GAME_EVENT(read_game_titledata)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("controllerId")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnReadGameTitledata", ss.str(), event);
    delete event;
}

GAME_EVENT(write_game_titledata)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("controllerId")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWriteGameTitledata", ss.str(), event);
    delete event;
}

GAME_EVENT(reset_game_titledata)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("controllerId")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnResetGameTitledata", ss.str(), event);
    delete event;
}

GAME_EVENT(weaponhud_selection)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("mode")));
    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWeaponhudSelection", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_ended)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteEnded", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_cast)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("vote_option")));
    eventData.push_back(msgpack::object(pEvent->GetInt("team")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteCast", ss.str(), event);
    delete event;
}

GAME_EVENT(vote_options)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("count")));
    eventData.push_back(msgpack::object(pEvent->GetString("option1")));
    eventData.push_back(msgpack::object(pEvent->GetString("option2")));
    eventData.push_back(msgpack::object(pEvent->GetString("option3")));
    eventData.push_back(msgpack::object(pEvent->GetString("option4")));
    eventData.push_back(msgpack::object(pEvent->GetString("option5")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVoteOptions", ss.str(), event);
    delete event;
}

GAME_EVENT(endmatch_mapvote_selecting_map)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("count")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot1")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot2")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot3")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot4")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot5")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot6")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot7")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot8")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot9")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot10")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEndmatchMapvoteSelectingMap", ss.str(), event);
    delete event;
}

GAME_EVENT(endmatch_cmm_start_reveal_items)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEndmatchCmmStartRevealItems", ss.str(), event);
    delete event;
}

GAME_EVENT(client_loadout_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientLoadoutChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(add_player_sonar_icon)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetFloat("pos_x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("pos_y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("pos_z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAddPlayerSonarIcon", ss.str(), event);
    delete event;
}

GAME_EVENT(add_bullet_hit_marker)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("bone")));
    eventData.push_back(msgpack::object(pEvent->GetInt("pos_x")));
    eventData.push_back(msgpack::object(pEvent->GetInt("pos_y")));
    eventData.push_back(msgpack::object(pEvent->GetInt("pos_z")));
    eventData.push_back(msgpack::object(pEvent->GetInt("ang_x")));
    eventData.push_back(msgpack::object(pEvent->GetInt("ang_y")));
    eventData.push_back(msgpack::object(pEvent->GetInt("ang_z")));
    eventData.push_back(msgpack::object(pEvent->GetInt("start_x")));
    eventData.push_back(msgpack::object(pEvent->GetInt("start_y")));
    eventData.push_back(msgpack::object(pEvent->GetInt("start_z")));
    eventData.push_back(msgpack::object(pEvent->GetBool("hit")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAddBulletHitMarker", ss.str(), event);
    delete event;
}

GAME_EVENT(other_death)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("otherid")));
    eventData.push_back(msgpack::object(pEvent->GetString("othertype")));
    eventData.push_back(msgpack::object(pEvent->GetInt("attacker")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon_itemid")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon_fauxitemid")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon_originalowner_xuid")));
    eventData.push_back(msgpack::object(pEvent->GetBool("headshot")));
    eventData.push_back(msgpack::object(pEvent->GetInt("penetrated")));
    eventData.push_back(msgpack::object(pEvent->GetBool("noscope")));
    eventData.push_back(msgpack::object(pEvent->GetBool("thrusmoke")));
    eventData.push_back(msgpack::object(pEvent->GetBool("attackerblind")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnOtherDeath", ss.str(), event);
    delete event;
}

GAME_EVENT(item_purchase)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("team")));
    eventData.push_back(msgpack::object(pEvent->GetInt("loadout")));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemPurchase", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_beginplant)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("site")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombBeginplant", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_abortplant)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("site")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombAbortplant", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_planted)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("site")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombPlanted", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_defused)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("site")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombDefused", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_exploded)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("site")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombExploded", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_dropped)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombDropped", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_pickup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombPickup", ss.str(), event);
    delete event;
}

GAME_EVENT(defuser_dropped)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDefuserDropped", ss.str(), event);
    delete event;
}

GAME_EVENT(defuser_pickup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDefuserPickup", ss.str(), event);
    delete event;
}

GAME_EVENT(announce_phase_end)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAnnouncePhaseEnd", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_intermission)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsIntermission", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_begindefuse)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("haskit")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombBegindefuse", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_abortdefuse)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombAbortdefuse", ss.str(), event);
    delete event;
}

GAME_EVENT(hostage_follows)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("hostage")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostageFollows", ss.str(), event);
    delete event;
}

GAME_EVENT(hostage_hurt)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("hostage")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostageHurt", ss.str(), event);
    delete event;
}

GAME_EVENT(hostage_killed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("hostage")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostageKilled", ss.str(), event);
    delete event;
}

GAME_EVENT(hostage_rescued)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("hostage")));
    eventData.push_back(msgpack::object(pEvent->GetInt("site")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostageRescued", ss.str(), event);
    delete event;
}

GAME_EVENT(hostage_stops_following)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("hostage")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostageStopsFollowing", ss.str(), event);
    delete event;
}

GAME_EVENT(hostage_rescued_all)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostageRescuedAll", ss.str(), event);
    delete event;
}

GAME_EVENT(hostage_call_for_help)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("hostage")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHostageCallForHelp", ss.str(), event);
    delete event;
}

GAME_EVENT(vip_escaped)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVipEscaped", ss.str(), event);
    delete event;
}

GAME_EVENT(vip_killed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("attacker").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnVipKilled", ss.str(), event);
    delete event;
}

GAME_EVENT(player_radio)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerRadio", ss.str(), event);
    delete event;
}

GAME_EVENT(bomb_beep)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBombBeep", ss.str(), event);
    delete event;
}

GAME_EVENT(weapon_fire)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon")));
    eventData.push_back(msgpack::object(pEvent->GetBool("silenced")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWeaponFire", ss.str(), event);
    delete event;
}

GAME_EVENT(weapon_fire_on_empty)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWeaponFireOnEmpty", ss.str(), event);
    delete event;
}

GAME_EVENT(grenade_thrown)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("weapon")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGrenadeThrown", ss.str(), event);
    delete event;
}

GAME_EVENT(weapon_outofammo)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWeaponOutofammo", ss.str(), event);
    delete event;
}

GAME_EVENT(weapon_reload)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWeaponReload", ss.str(), event);
    delete event;
}

GAME_EVENT(weapon_zoom)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWeaponZoom", ss.str(), event);
    delete event;
}

GAME_EVENT(silencer_detach)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSilencerDetach", ss.str(), event);
    delete event;
}

GAME_EVENT(inspect_weapon)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInspectWeapon", ss.str(), event);
    delete event;
}

GAME_EVENT(weapon_zoom_rifle)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWeaponZoomRifle", ss.str(), event);
    delete event;
}

GAME_EVENT(player_spawned)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("inrestart")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerSpawned", ss.str(), event);
    delete event;
}

GAME_EVENT(item_pickup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("item")));
    eventData.push_back(msgpack::object(pEvent->GetBool("silent")));
    eventData.push_back(msgpack::object(pEvent->GetInt("defindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemPickup", ss.str(), event);
    delete event;
}

GAME_EVENT(item_pickup_slerp)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("index")));
    eventData.push_back(msgpack::object(pEvent->GetInt("behavior")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemPickupSlerp", ss.str(), event);
    delete event;
}

GAME_EVENT(item_pickup_failed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("item")));
    eventData.push_back(msgpack::object(pEvent->GetInt("reason")));
    eventData.push_back(msgpack::object(pEvent->GetInt("limit")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemPickupFailed", ss.str(), event);
    delete event;
}

GAME_EVENT(item_remove)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("item")));
    eventData.push_back(msgpack::object(pEvent->GetInt("defindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemRemove", ss.str(), event);
    delete event;
}

GAME_EVENT(ammo_pickup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("item")));
    eventData.push_back(msgpack::object(pEvent->GetInt("index")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAmmoPickup", ss.str(), event);
    delete event;
}

GAME_EVENT(item_equip)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("item")));
    eventData.push_back(msgpack::object(pEvent->GetInt("defindex")));
    eventData.push_back(msgpack::object(pEvent->GetBool("canzoom")));
    eventData.push_back(msgpack::object(pEvent->GetBool("hassilencer")));
    eventData.push_back(msgpack::object(pEvent->GetBool("issilenced")));
    eventData.push_back(msgpack::object(pEvent->GetBool("hastracers")));
    eventData.push_back(msgpack::object(pEvent->GetInt("weptype")));
    eventData.push_back(msgpack::object(pEvent->GetBool("ispainted")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnItemEquip", ss.str(), event);
    delete event;
}

GAME_EVENT(enter_buyzone)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("canbuy")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEnterBuyzone", ss.str(), event);
    delete event;
}

GAME_EVENT(exit_buyzone)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("canbuy")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnExitBuyzone", ss.str(), event);
    delete event;
}

GAME_EVENT(buytime_ended)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBuytimeEnded", ss.str(), event);
    delete event;
}

GAME_EVENT(enter_bombzone)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("hasbomb")));
    eventData.push_back(msgpack::object(pEvent->GetBool("isplanted")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEnterBombzone", ss.str(), event);
    delete event;
}

GAME_EVENT(exit_bombzone)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("hasbomb")));
    eventData.push_back(msgpack::object(pEvent->GetBool("isplanted")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnExitBombzone", ss.str(), event);
    delete event;
}

GAME_EVENT(enter_rescue_zone)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEnterRescueZone", ss.str(), event);
    delete event;
}

GAME_EVENT(exit_rescue_zone)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnExitRescueZone", ss.str(), event);
    delete event;
}

GAME_EVENT(silencer_off)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSilencerOff", ss.str(), event);
    delete event;
}

GAME_EVENT(silencer_on)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSilencerOn", ss.str(), event);
    delete event;
}

GAME_EVENT(buymenu_open)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBuymenuOpen", ss.str(), event);
    delete event;
}

GAME_EVENT(buymenu_close)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBuymenuClose", ss.str(), event);
    delete event;
}

GAME_EVENT(round_prestart)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundPrestart", ss.str(), event);
    delete event;
}

GAME_EVENT(round_poststart)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundPoststart", ss.str(), event);
    delete event;
}

GAME_EVENT(grenade_bounce)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGrenadeBounce", ss.str(), event);
    delete event;
}

GAME_EVENT(hegrenade_detonate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHegrenadeDetonate", ss.str(), event);
    delete event;
}

GAME_EVENT(flashbang_detonate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnFlashbangDetonate", ss.str(), event);
    delete event;
}

GAME_EVENT(smokegrenade_detonate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSmokegrenadeDetonate", ss.str(), event);
    delete event;
}

GAME_EVENT(smokegrenade_expired)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSmokegrenadeExpired", ss.str(), event);
    delete event;
}

GAME_EVENT(molotov_detonate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMolotovDetonate", ss.str(), event);
    delete event;
}

GAME_EVENT(decoy_detonate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDecoyDetonate", ss.str(), event);
    delete event;
}

GAME_EVENT(decoy_started)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDecoyStarted", ss.str(), event);
    delete event;
}

GAME_EVENT(tagrenade_detonate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTagrenadeDetonate", ss.str(), event);
    delete event;
}

GAME_EVENT(inferno_startburn)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInfernoStartburn", ss.str(), event);
    delete event;
}

GAME_EVENT(inferno_expire)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInfernoExpire", ss.str(), event);
    delete event;
}

GAME_EVENT(inferno_extinguish)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnInfernoExtinguish", ss.str(), event);
    delete event;
}

GAME_EVENT(decoy_firing)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDecoyFiring", ss.str(), event);
    delete event;
}

GAME_EVENT(bullet_impact)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBulletImpact", ss.str(), event);
    delete event;
}

GAME_EVENT(player_jump)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerJump", ss.str(), event);
    delete event;
}

GAME_EVENT(player_blind)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("attacker").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("blind_duration")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerBlind", ss.str(), event);
    delete event;
}

GAME_EVENT(player_falldamage)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetFloat("damage")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerFalldamage", ss.str(), event);
    delete event;
}

GAME_EVENT(door_moving)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDoorMoving", ss.str(), event);
    delete event;
}

GAME_EVENT(mb_input_lock_success)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMbInputLockSuccess", ss.str(), event);
    delete event;
}

GAME_EVENT(mb_input_lock_cancel)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMbInputLockCancel", ss.str(), event);
    delete event;
}

GAME_EVENT(nav_blocked)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("area")));
    eventData.push_back(msgpack::object(pEvent->GetBool("blocked")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnNavBlocked", ss.str(), event);
    delete event;
}

GAME_EVENT(nav_generate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnNavGenerate", ss.str(), event);
    delete event;
}

GAME_EVENT(achievement_info_loaded)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAchievementInfoLoaded", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_changed_mode)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("oldmode")));
    eventData.push_back(msgpack::object(pEvent->GetInt("newmode")));
    eventData.push_back(msgpack::object(pEvent->GetInt("obs_target")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvChangedMode", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_game_disconnected)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsGameDisconnected", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_round_final_beep)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsRoundFinalBeep", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_round_start_beep)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsRoundStartBeep", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_win_panel_round)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("show_timer_defend")));
    eventData.push_back(msgpack::object(pEvent->GetBool("show_timer_attack")));
    eventData.push_back(msgpack::object(pEvent->GetInt("timer_time")));
    eventData.push_back(msgpack::object(pEvent->GetInt("final_event")));
    eventData.push_back(msgpack::object(pEvent->GetString("funfact_token")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("funfact_player").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("funfact_data1")));
    eventData.push_back(msgpack::object(pEvent->GetInt("funfact_data2")));
    eventData.push_back(msgpack::object(pEvent->GetInt("funfact_data3")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsWinPanelRound", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_win_panel_match)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsWinPanelMatch", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_match_end_restart)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsMatchEndRestart", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_pre_restart)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsPreRestart", ss.str(), event);
    delete event;
}

GAME_EVENT(show_deathpanel)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("victim").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("killer")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("killer_controller").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("hits_taken")));
    eventData.push_back(msgpack::object(pEvent->GetInt("damage_taken")));
    eventData.push_back(msgpack::object(pEvent->GetInt("hits_given")));
    eventData.push_back(msgpack::object(pEvent->GetInt("damage_given")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnShowDeathpanel", ss.str(), event);
    delete event;
}

GAME_EVENT(hide_deathpanel)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHideDeathpanel", ss.str(), event);
    delete event;
}

GAME_EVENT(player_avenged_teammate)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("avenger_id").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("avenged_player_id").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerAvengedTeammate", ss.str(), event);
    delete event;
}

GAME_EVENT(achievement_earned_local)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("achievement")));
    eventData.push_back(msgpack::object(pEvent->GetInt("splitscreenplayer")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAchievementEarnedLocal", ss.str(), event);
    delete event;
}

GAME_EVENT(repost_xbox_achievements)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("splitscreenplayer")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRepostXboxAchievements", ss.str(), event);
    delete event;
}

GAME_EVENT(match_end_conditions)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("frags")));
    eventData.push_back(msgpack::object(pEvent->GetInt("max_rounds")));
    eventData.push_back(msgpack::object(pEvent->GetInt("win_rounds")));
    eventData.push_back(msgpack::object(pEvent->GetInt("time")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMatchEndConditions", ss.str(), event);
    delete event;
}

GAME_EVENT(round_mvp)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("reason")));
    eventData.push_back(msgpack::object(pEvent->GetInt("value")));
    eventData.push_back(msgpack::object(pEvent->GetInt("musickitmvps")));
    eventData.push_back(msgpack::object(pEvent->GetInt("nomusic")));
    eventData.push_back(msgpack::object(pEvent->GetInt("musickitid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnRoundMvp", ss.str(), event);
    delete event;
}

GAME_EVENT(show_survival_respawn_status)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("loc_token")));
    eventData.push_back(msgpack::object(pEvent->GetInt("duration")));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnShowSurvivalRespawnStatus", ss.str(), event);
    delete event;
}

GAME_EVENT(client_disconnect)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientDisconnect", ss.str(), event);
    delete event;
}

GAME_EVENT(gg_killed_enemy)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("victimid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("attackerid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("dominated")));
    eventData.push_back(msgpack::object(pEvent->GetInt("revenge")));
    eventData.push_back(msgpack::object(pEvent->GetBool("bonus")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGgKilledEnemy", ss.str(), event);
    delete event;
}

GAME_EVENT(switch_team)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("numPlayers")));
    eventData.push_back(msgpack::object(pEvent->GetInt("numSpectators")));
    eventData.push_back(msgpack::object(pEvent->GetInt("avg_rank")));
    eventData.push_back(msgpack::object(pEvent->GetInt("numTSlotsFree")));
    eventData.push_back(msgpack::object(pEvent->GetInt("numCTSlotsFree")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSwitchTeam", ss.str(), event);
    delete event;
}

GAME_EVENT(write_profile_data)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnWriteProfileData", ss.str(), event);
    delete event;
}

GAME_EVENT(trial_time_expired)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTrialTimeExpired", ss.str(), event);
    delete event;
}

GAME_EVENT(update_matchmaking_stats)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUpdateMatchmakingStats", ss.str(), event);
    delete event;
}

GAME_EVENT(player_reset_vote)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("vote")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerResetVote", ss.str(), event);
    delete event;
}

GAME_EVENT(enable_restart_voting)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("enable")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnEnableRestartVoting", ss.str(), event);
    delete event;
}

GAME_EVENT(sfuievent)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("action")));
    eventData.push_back(msgpack::object(pEvent->GetString("data")));
    eventData.push_back(msgpack::object(pEvent->GetInt("slot")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSfuievent", ss.str(), event);
    delete event;
}

GAME_EVENT(start_vote)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("type")));
    eventData.push_back(msgpack::object(pEvent->GetInt("vote_parameter")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnStartVote", ss.str(), event);
    delete event;
}

GAME_EVENT(player_given_c4)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerGivenC4", ss.str(), event);
    delete event;
}

GAME_EVENT(tr_player_flashbanged)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTrPlayerFlashbanged", ss.str(), event);
    delete event;
}

GAME_EVENT(tr_mark_complete)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("complete")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTrMarkComplete", ss.str(), event);
    delete event;
}

GAME_EVENT(tr_mark_best_time)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("time")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTrMarkBestTime", ss.str(), event);
    delete event;
}

GAME_EVENT(tr_exit_hint_trigger)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTrExitHintTrigger", ss.str(), event);
    delete event;
}

GAME_EVENT(bot_takeover)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("botid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBotTakeover", ss.str(), event);
    delete event;
}

GAME_EVENT(tr_show_finish_msgbox)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTrShowFinishMsgbox", ss.str(), event);
    delete event;
}

GAME_EVENT(tr_show_exit_msgbox)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTrShowExitMsgbox", ss.str(), event);
    delete event;
}

GAME_EVENT(jointeam_failed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("reason")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnJointeamFailed", ss.str(), event);
    delete event;
}

GAME_EVENT(teamchange_pending)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("toteam")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTeamchangePending", ss.str(), event);
    delete event;
}

GAME_EVENT(material_default_complete)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnMaterialDefaultComplete", ss.str(), event);
    delete event;
}

GAME_EVENT(cs_prev_next_spectator)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("next")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnCsPrevNextSpectator", ss.str(), event);
    delete event;
}

GAME_EVENT(nextlevel_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetString("nextlevel")));
    eventData.push_back(msgpack::object(pEvent->GetString("mapgroup")));
    eventData.push_back(msgpack::object(pEvent->GetString("skirmishmode")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnNextlevelChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(seasoncoin_levelup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("category")));
    eventData.push_back(msgpack::object(pEvent->GetInt("rank")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSeasoncoinLevelup", ss.str(), event);
    delete event;
}

GAME_EVENT(tournament_reward)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("defindex")));
    eventData.push_back(msgpack::object(pEvent->GetInt("totalrewards")));
    eventData.push_back(msgpack::object(pEvent->GetInt("accountid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTournamentReward", ss.str(), event);
    delete event;
}

GAME_EVENT(start_halftime)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnStartHalftime", ss.str(), event);
    delete event;
}

GAME_EVENT(ammo_refill)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetBool("success")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnAmmoRefill", ss.str(), event);
    delete event;
}

GAME_EVENT(parachute_pickup)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnParachutePickup", ss.str(), event);
    delete event;
}

GAME_EVENT(parachute_deploy)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnParachuteDeploy", ss.str(), event);
    delete event;
}

GAME_EVENT(dronegun_attack)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDronegunAttack", ss.str(), event);
    delete event;
}

GAME_EVENT(drone_dispatched)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("priority")));
    eventData.push_back(msgpack::object(pEvent->GetInt("drone_dispatched")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDroneDispatched", ss.str(), event);
    delete event;
}

GAME_EVENT(loot_crate_visible)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("subject")));
    eventData.push_back(msgpack::object(pEvent->GetString("type")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnLootCrateVisible", ss.str(), event);
    delete event;
}

GAME_EVENT(loot_crate_opened)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetString("type")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnLootCrateOpened", ss.str(), event);
    delete event;
}

GAME_EVENT(open_crate_instr)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("subject")));
    eventData.push_back(msgpack::object(pEvent->GetString("type")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnOpenCrateInstr", ss.str(), event);
    delete event;
}

GAME_EVENT(smoke_beacon_paradrop)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("paradrop")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSmokeBeaconParadrop", ss.str(), event);
    delete event;
}

GAME_EVENT(survival_paradrop_spawn)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSurvivalParadropSpawn", ss.str(), event);
    delete event;
}

GAME_EVENT(survival_paradrop_break)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSurvivalParadropBreak", ss.str(), event);
    delete event;
}

GAME_EVENT(drone_cargo_detached)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("cargo")));
    eventData.push_back(msgpack::object(pEvent->GetBool("delivered")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDroneCargoDetached", ss.str(), event);
    delete event;
}

GAME_EVENT(drone_above_roof)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("cargo")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDroneAboveRoof", ss.str(), event);
    delete event;
}

GAME_EVENT(choppers_incoming_warning)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("global")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnChoppersIncomingWarning", ss.str(), event);
    delete event;
}

GAME_EVENT(firstbombs_incoming_warning)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetBool("global")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnFirstbombsIncomingWarning", ss.str(), event);
    delete event;
}

GAME_EVENT(dz_item_interaction)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("subject")));
    eventData.push_back(msgpack::object(pEvent->GetString("type")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDzItemInteraction", ss.str(), event);
    delete event;
}

GAME_EVENT(survival_teammate_respawn)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSurvivalTeammateRespawn", ss.str(), event);
    delete event;
}

GAME_EVENT(survival_no_respawns_warning)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSurvivalNoRespawnsWarning", ss.str(), event);
    delete event;
}

GAME_EVENT(survival_no_respawns_final)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnSurvivalNoRespawnsFinal", ss.str(), event);
    delete event;
}

GAME_EVENT(player_ping)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("x")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("y")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("z")));
    eventData.push_back(msgpack::object(pEvent->GetBool("urgent")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerPing", ss.str(), event);
    delete event;
}

GAME_EVENT(player_ping_stop)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entityid")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerPingStop", ss.str(), event);
    delete event;
}

GAME_EVENT(player_sound)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("radius")));
    eventData.push_back(msgpack::object(pEvent->GetFloat("duration")));
    eventData.push_back(msgpack::object(pEvent->GetBool("step")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnPlayerSound", ss.str(), event);
    delete event;
}

GAME_EVENT(guardian_wave_restart)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGuardianWaveRestart", ss.str(), event);
    delete event;
}

GAME_EVENT(team_intro_start)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTeamIntroStart", ss.str(), event);
    delete event;
}

GAME_EVENT(team_intro_end)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnTeamIntroEnd", ss.str(), event);
    delete event;
}

GAME_EVENT(bullet_flight_resolution)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetPlayerSlot("userid").Get()));
    eventData.push_back(msgpack::object(pEvent->GetInt("pos_x")));
    eventData.push_back(msgpack::object(pEvent->GetInt("pos_y")));
    eventData.push_back(msgpack::object(pEvent->GetInt("pos_z")));
    eventData.push_back(msgpack::object(pEvent->GetInt("ang_x")));
    eventData.push_back(msgpack::object(pEvent->GetInt("ang_y")));
    eventData.push_back(msgpack::object(pEvent->GetInt("ang_z")));
    eventData.push_back(msgpack::object(pEvent->GetInt("start_x")));
    eventData.push_back(msgpack::object(pEvent->GetInt("start_y")));
    eventData.push_back(msgpack::object(pEvent->GetInt("start_z")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnBulletFlightResolution", ss.str(), event);
    delete event;
}

GAME_EVENT(door_break)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));
    eventData.push_back(msgpack::object(pEvent->GetInt("dmgstate")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDoorBreak", ss.str(), event);
    delete event;
}

GAME_EVENT(door_closed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDoorClosed", ss.str(), event);
    delete event;
}

GAME_EVENT(door_open)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("entindex")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnDoorOpen", ss.str(), event);
    delete event;
}

GAME_EVENT(game_phase_changed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("new_phase")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnGamePhaseChanged", ss.str(), event);
    delete event;
}

GAME_EVENT(hltv_replay_status)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(pEvent->GetInt("reason")));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", pEvent, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnHltvReplayStatus", ss.str(), event);
    delete event;
}