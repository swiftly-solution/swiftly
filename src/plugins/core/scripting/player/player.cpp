#include "../../scripting.h"

#include "../../../../player/playermanager/PlayerManager.h"
#include "../../../../server/commands/CommandsManager.h"
#include "../../../../entitysystem/precacher/precacher.h"
#include "../../../../engine/convars/convars.h"

typedef IGameEventListener2* (*GetLegacyGameEventListener)(CPlayerSlot slot);

PluginPlayer::PluginPlayer(std::string m_plugin_name, int m_playerId)
{
    this->plugin_name = m_plugin_name;
    this->playerId = m_playerId;

    pCBaseEntity = new SDKBaseClass(nullptr, "CBaseEntity");
    pCBasePlayerController = new SDKBaseClass(nullptr, "CBasePlayerController");
    pCBasePlayerPawn = new SDKBaseClass(nullptr, "CBasePlayerPawn");
    pCCSPlayerController = new SDKBaseClass(nullptr, "CCSPlayerController");
    pCCSPlayerPawn = new SDKBaseClass(nullptr, "CCSPlayerPawn");
    pCCSPlayerPawnBase = new SDKBaseClass(nullptr, "CCSPlayerPawnBase");
}

PluginPlayer::~PluginPlayer() {
    delete pCBaseEntity;
    delete pCBasePlayerController;
    delete pCBasePlayerPawn;
    delete pCCSPlayerController;
    delete pCCSPlayerPawn;
    delete pCCSPlayerPawnBase;
}

SDKBaseClass* PluginPlayer::GetCBaseEntity()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player) pCBaseEntity->SetPtr(nullptr);
    else if(player->GetPlayerPawn() != pCBaseEntity->GetPtr()) pCBaseEntity->SetPtr(player->GetPlayerPawn());
    return pCBaseEntity;
}

SDKBaseClass* PluginPlayer::GetCBasePlayerController()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player) pCBasePlayerController->SetPtr(nullptr);
    else if(player->GetController() != pCBasePlayerController->GetPtr()) pCBasePlayerController->SetPtr(player->GetController());
    return pCBasePlayerController;
}

SDKBaseClass* PluginPlayer::GetCBasePlayerPawn()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player) pCBasePlayerPawn->SetPtr(nullptr);
    else if(player->GetPawn() != pCBasePlayerPawn->GetPtr()) pCBasePlayerPawn->SetPtr(player->GetPawn());
    return pCBasePlayerPawn;
}

SDKBaseClass* PluginPlayer::GetCCSPlayerController()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player) pCCSPlayerController->SetPtr(nullptr);
    else if(player->GetPlayerController() != pCCSPlayerController->GetPtr()) pCCSPlayerController->SetPtr(player->GetPlayerController());
    return pCCSPlayerController;
}

SDKBaseClass* PluginPlayer::GetCCSPlayerPawn()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player) pCCSPlayerPawn->SetPtr(nullptr);
    else if(player->GetPlayerPawn() != pCCSPlayerPawn->GetPtr()) pCCSPlayerPawn->SetPtr(player->GetPlayerPawn());
    return pCCSPlayerPawn;
}

SDKBaseClass* PluginPlayer::GetCCSPlayerPawnBase()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player) pCCSPlayerPawnBase->SetPtr(nullptr);
    else if(player->GetPlayerBasePawn() != pCCSPlayerPawnBase->GetPtr()) pCCSPlayerPawnBase->SetPtr(player->GetPlayerBasePawn());
    return pCCSPlayerPawnBase;
}

void PluginPlayer::Drop(int reason)
{
    if (reason < 0 || reason > 69)
        return;

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    if (!engine)
        return;

    engine->DisconnectClient(player->GetSlot(), (ENetworkDisconnectionReason)reason);
}

std::string PluginPlayer::GetChatTag()
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";

    return player->tag;
}

void PluginPlayer::SetChatTag(std::string tag)
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->tag = tag;
}

void PluginPlayer::SetChatTagColor(std::string color)
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->tagcolor = color;
}

void PluginPlayer::SetNameColor(std::string color)
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->namecolor = color;
}

void PluginPlayer::SetChatColor(std::string color)
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->chatcolor = color;
}

std::string PluginPlayer::GetChatTagColor()
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";
    return player->tagcolor;
}

std::string PluginPlayer::GetNameColor()
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";
    return player->namecolor;
}

std::string PluginPlayer::GetChatColor()
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";
    return player->chatcolor;
}

void PluginPlayer::ExecuteCommand(std::string cmd)
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    if (starts_with(cmd, "sw_"))
    {
        CCommand tokenizedArgs;
        tokenizedArgs.Tokenize(cmd.c_str());

        std::vector<std::string> cmdString = TokenizeCommand(cmd);
        cmdString.erase(cmdString.begin());

        std::string commandName = replace(tokenizedArgs[0], "sw_", "");

        Command* command = g_commandsManager->FetchCommand(commandName);
        if (command)
            command->Execute(player->GetSlot().Get(), cmdString, true, "sw_");
    }
    else
        engine->ClientCommand(player->GetSlot().Get(), cmd.c_str());
}

std::string PluginPlayer::GetConvarValue(std::string name)
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";

    if (!engine)
        return "";

    return engine->GetClientConVarValue(player->GetSlot(), name.c_str());
}

void PluginPlayer::SetConvar(std::string name, std::string value)
{

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->SetClientConvar(name, value);
}

std::string PluginPlayer::GetIPAddress()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";

    return player->GetIPAddress();
}

int PluginPlayer::GetSlot()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return -1;

    return player->GetSlot().Get();
}

uint64_t PluginPlayer::GetSteamID()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return 0;

    return player->GetSteamID();
}

std::string PluginPlayer::GetSteamID2()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "STEAM_0:0:000000000";

    uint64_t steamid = player->GetSteamID();

    if (steamid == 0)
        return "STEAM_0:0:000000000";

    static const uint64_t base = 76561197960265728;
    std::string data = string_format("STEAM_0:%d:%llu", (steamid - base) % 2, (steamid - base) / 2);

    return data;
}

void PluginPlayer::HideMenu()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    if (!player->HasMenuShown())
        return;

    player->HideMenu();
}

bool PluginPlayer::IsFakeClient()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return false;

    return player->IsFakeClient();
}

bool PluginPlayer::IsFirstSpawn()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return false;

    return player->IsFirstSpawn();
}

void PluginPlayer::Kill()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    CBasePlayerPawn* pawn = player->GetPawn();
    if (!pawn)
        return;

    pawn->CommitSuicide(false, true);
}

void PluginPlayer::Respawn()
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    CCSPlayerController* controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->Respawn();
}

void PluginPlayer::SendMsg(int dest, std::string msg)
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->SendMsg(dest, msg.c_str());
}

void PluginPlayer::ShowMenu(std::string menuid)
{
    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    if (player->HasMenuShown())
        return;

    player->ShowMenu(menuid);
}

void PluginPlayer::SwitchTeam(int team)
{
    if (team < 0 || team > 3)
        return;

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->SwitchTeam(team);
}

void PluginPlayer::ChangeTeam(int team)
{
    if (team < 0 || team > 3)
        return;

    Player* player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->ChangeTeam(team);
}

std::any PluginPlayer::GetVarValue(std::string key)
{
    Player* player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return nullptr;

    return player->GetInternalVar(key);
}

void PluginPlayer::SetVarValue(std::string key, std::any value)
{
    Player* player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->SetInternalVar(key, value);
}

void PluginPlayer::SetListening(int playerid, int listenOverride)
{
    Player* player = g_playerManager->GetPlayer(playerid);
    if (!player)
        return;

    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self)
        return;

    self->SetListen(playerid, (ListenOverride)listenOverride);
}

int PluginPlayer::GetListening(int playerid)
{
    Player* player = g_playerManager->GetPlayer(playerid);
    if (!player)
        return ListenOverride::Listen_Default;

    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self)
        return ListenOverride::Listen_Default;

    return self->GetListen(playerid);
}

void PluginPlayer::SetVoiceFlags(int flags)
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self)
        return;

    self->SetVoiceFlags((VoiceFlag_t)flags);
}

int PluginPlayer::GetVoiceFlags()
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self)
        return 0;

    return self->GetVoiceFlags();
}

uint32_t PluginPlayer::GetConnectedTime()
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self)
        return 0;

    return self->GetConnectedTime();
}

PluginWeaponManager PluginPlayer::GetWeaponManager()
{
    return PluginWeaponManager(playerId);
}

void PluginPlayer::SetBunnyhop(bool state)
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self)
        return;

    self->SetClientConvar("sv_autobunnyhopping", state ? "true" : "false");
    self->bunnyhopState = state;
}

bool PluginPlayer::GetBunnyhop()
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self)
        return false;

    return self->bunnyhopState;
}

void PluginPlayer::QueryConvar(std::string cvar_name)
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self) return;
    if (self->IsFakeClient()) return;

    g_cvarQuery->QueryCvarClient(self->GetSlot(), cvar_name);
}

bool PluginPlayer::IsListeningToGameEvent(std::string game_event)
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self) return false;
    if (self->IsFakeClient()) return false;

    IGameEventListener2* playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(self->GetSlot());
    return g_gameEventManager->FindListener(playerListener, game_event.c_str());
}

bool PluginPlayer::IsValid()
{
    Player* self = g_playerManager->GetPlayer(this->playerId);
    if (!self) return false;
    if (self->IsFirstSpawn()) return false;

    CBasePlayerController* controller = self->GetController();
    if (!controller) return false;
    if (controller->m_bIsHLTV()) return false;
    if (controller->m_iConnected() != CPlayerConnectedState::PlayerConnected) return false;

    CBasePlayerPawn* pawn = self->GetPawn();
    if (!pawn) return false;

    return true;
}