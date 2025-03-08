#include "../../core.h"
#include "../../../../player/playermanager/PlayerManager.h"

PluginPlayer* scripting_GetPlayer(int playerid, EContext* state)
{
    Player* player = g_playerManager->GetPlayer(playerid);
    if (!player)
        return nullptr;

    return player->GetPlayerObject();
}

LoadScriptingComponent(
    player,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginPlayer>("Player", state)
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
            .addFunction("QueryConvar", &PluginPlayer::QueryConvar)
            .addFunction("PerformMenuAction", &PluginPlayer::PerformMenuAction)
            .addFunction("IsValid", &PluginPlayer::IsValid)
            .endClass();

        GetGlobalNamespace(state)
            .addFunction("GetPlayer", scripting_GetPlayer);
    }
)