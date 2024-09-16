#include "../core.h"
#include "../../../../player/PlayerManager.h"

std::map<int, std::pair<uint64_t, PluginPlayer*>> playerObjectCache;

PluginPlayer* scripting_GetPlayer(int playerid, lua_State* state)
{
    Player* player = g_playerManager->GetPlayer(playerid);
    if (!player)
        return nullptr;

    PluginPlayer* pl = nullptr;
    bool found = (playerObjectCache.find(playerid) != playerObjectCache.end());
    if (found)
    {
        auto pair = playerObjectCache[playerid];
        if (pair.first != player->GetSteamID())
        {
            delete pair.second;
            found = false;
        }
        else
            pl = pair.second;
    }

    if (!found)
    {
        uint64_t steamid = player->GetSteamID();

        pl = new PluginPlayer(FetchPluginName(state), playerid);
        playerObjectCache.insert({ playerid, {steamid, pl} });
    }

    return pl;
}

LoadLuaScriptingComponent(
    player,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<PluginPlayer>("Player")
            .addFunction("CBaseEntity", &PluginPlayer::GetCBaseEntity)
            .addFunction("CBasePlayerController", &PluginPlayer::GetCBasePlayerController)
            .addFunction("CBasePlayerPawn", &PluginPlayer::GetCBasePlayerPawn)
            .addFunction("CCSPlayerController", &PluginPlayer::GetCCSPlayerController)
            .addFunction("CCSPlayerPawn", &PluginPlayer::GetCCSPlayerPawn)
            .addFunction("CCSPlayerPawnBase", &PluginPlayer::GetCCSPlayerPawnBase)
            .addFunction("Drop", &PluginPlayer::Drop)
            .addFunction("GetChatTag", &PluginPlayer::GetChatTag)
            .addFunction("SetChatTag", &PluginPlayer::SetChatTag)
            .addFunction("GetChatTagColor", &PluginPlayer::GetChatTagColor)
            .addFunction("SetChatTagColor", &PluginPlayer::SetChatTagColor)
            .addFunction("GetNameColor", &PluginPlayer::GetNameColor)
            .addFunction("SetNameColor", &PluginPlayer::SetNameColor)
            .addFunction("GetChatColor", &PluginPlayer::GetChatColor)
            .addFunction("SetChatColor", &PluginPlayer::SetChatColor)
            .addFunction("ExecuteCommand", &PluginPlayer::ExecuteCommand)
            .addFunction("GetConvar", &PluginPlayer::GetConvarValue)
            .addFunction("SetConvar", &PluginPlayer::SetConvar)
            .addFunction("GetIPAddress", &PluginPlayer::GetIPAddress)
            .addFunction("GetSlot", &PluginPlayer::GetSlot)
            .addFunction("GetSteamID", &PluginPlayer::GetSteamID)
            .addFunction("GetSteamID2", &PluginPlayer::GetSteamID2)
            .addFunction("HideMenu", &PluginPlayer::HideMenu)
            .addFunction("IsFakeClient", &PluginPlayer::IsFakeClient)
            .addFunction("IsFirstSpawn", &PluginPlayer::IsFirstSpawn)
            .addFunction("Kill", &PluginPlayer::Kill)
            .addFunction("Respawn", &PluginPlayer::Respawn)
            .addFunction("SendMsg", &PluginPlayer::SendMsg)
            .addFunction("SwitchTeam", &PluginPlayer::SwitchTeam)
            .addFunction("ChangeTeam", &PluginPlayer::ChangeTeam)
            .addFunction("ShowMenu", &PluginPlayer::ShowMenu)
            .addFunction("GetVar", &PluginPlayer::GetVarValue)
            .addFunction("SetVar", &PluginPlayer::SetVarValue)
            .addFunction("SetListening", &PluginPlayer::SetListening)
            .addFunction("GetVoiceFlags", &PluginPlayer::GetVoiceFlags)
            .addFunction("SetVoiceFlags", &PluginPlayer::SetVoiceFlags)
            .addFunction("GetConnectedTime", &PluginPlayer::GetConnectedTime)
            .addFunction("GetWeaponManager", &PluginPlayer::GetWeaponManager)
            .addFunction("SetBunnyhop", &PluginPlayer::SetBunnyhop)
            .addFunction("GetBunnyhop", &PluginPlayer::GetBunnyhop)
            .addFunction("IsValid", &PluginPlayer::IsValid)
            .endClass()
            .addFunction("GetPlayer", scripting_GetPlayer);
    }
)