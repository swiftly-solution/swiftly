#include "../scripting.h"

#include "../../../player/PlayerManager.h"
#include "../../../commands/CommandsManager.h"
#include "../../../precacher/precacher.h"

#include "generated/classes.h"

PluginPlayer::PluginPlayer(std::string m_plugin_name, int m_playerId)
{
    this->plugin_name = m_plugin_name;
    this->playerId = m_playerId;
}

PluginPlayer::~PluginPlayer()
{
    for (auto it = this->ptrs.begin(); it != this->ptrs.end(); ++it)
    {
        delete it->second;
    }
    this->ptrs.clear();
}

GCBaseEntity *PluginPlayer::GetCBaseEntity()
{
    if (this->ptrs.find("CBaseEntity") == this->ptrs.end())
    {
        Player *player = g_playerManager->GetPlayer(this->playerId);

        void *ptr = (void *)(new GCBaseEntity(player->GetPlayerPawn()));
        this->ptrs.insert({"CBaseEntity", ptr});
    }

    return (GCBaseEntity *)this->ptrs.at("CBaseEntity");
}

GCBasePlayerController *PluginPlayer::GetCBasePlayerController()
{
    if (this->ptrs.find("CBasePlayerController") == this->ptrs.end())
    {
        Player *player = g_playerManager->GetPlayer(this->playerId);

        void *ptr = (void *)(new GCBasePlayerController(player->GetController()));
        this->ptrs.insert({"CBasePlayerController", ptr});
    }

    return (GCBasePlayerController *)this->ptrs.at("CBasePlayerController");
}

GCBasePlayerPawn *PluginPlayer::GetCBasePlayerPawn()
{
    if (this->ptrs.find("CBasePlayerPawn") == this->ptrs.end())
    {
        Player *player = g_playerManager->GetPlayer(this->playerId);

        void *ptr = (void *)(new GCBasePlayerPawn(player->GetPawn()));
        this->ptrs.insert({"CBasePlayerPawn", ptr});
    }

    return (GCBasePlayerPawn *)this->ptrs.at("CBasePlayerPawn");
}

GCCSPlayerController *PluginPlayer::GetCCSPlayerController()
{
    if (this->ptrs.find("CCSPlayerController") == this->ptrs.end())
    {
        Player *player = g_playerManager->GetPlayer(this->playerId);

        void *ptr = (void *)(new GCBaseEntity(player->GetPlayerController()));
        this->ptrs.insert({"CCSPlayerController", ptr});
    }

    return (GCCSPlayerController *)this->ptrs.at("CCSPlayerController");
}

GCCSPlayerPawn *PluginPlayer::GetCCSPlayerPawn()
{
    if (this->ptrs.find("CCSPlayerPawn") == this->ptrs.end())
    {
        Player *player = g_playerManager->GetPlayer(this->playerId);

        void *ptr = (void *)(new GCCSPlayerPawn(player->GetPlayerPawn()));
        this->ptrs.insert({"CCSPlayerPawn", ptr});
    }

    return (GCCSPlayerPawn *)this->ptrs.at("CCSPlayerPawn");
}

GCCSPlayerPawnBase *PluginPlayer::GetCCSPlayerPawnBase()
{
    if (this->ptrs.find("CCSPlayerPawnBase") == this->ptrs.end())
    {
        Player *player = g_playerManager->GetPlayer(this->playerId);

        void *ptr = (void *)(new GCCSPlayerPawnBase(player->GetPlayerBasePawn()));
        this->ptrs.insert({"CCSPlayerPawnBase", ptr});
    }

    return (GCCSPlayerPawnBase *)this->ptrs.at("CCSPlayerPawnBase");
}

void PluginPlayer::Drop(int reason)
{
    if (reason < 0 || reason > 69)
        return;

    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    if (!engine)
        return;

    engine->DisconnectClient(player->GetSlot(), (ENetworkDisconnectionReason)reason);
}

std::string PluginPlayer::GetChatTag()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";

    return player->tag;
}

void PluginPlayer::SetChatTag(std::string tag)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->tag = tag;
}

void PluginPlayer::SetChatTagColor(std::string color)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->tagcolor = color;
}

void PluginPlayer::SetNameColor(std::string color)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->namecolor = color;
}

void PluginPlayer::SetChatColor(std::string color)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->chatcolor = color;
}

void PluginPlayer::ExecuteCommand(std::string cmd)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    if (starts_with(cmd, "sw_"))
    {
        CCommand tokenizedArgs;
        tokenizedArgs.Tokenize(cmd.c_str());

        std::vector<std::string> cmdString;
        for (int i = 1; i < tokenizedArgs.ArgC(); i++)
            cmdString.push_back(tokenizedArgs[i]);

        std::string commandName = replace(tokenizedArgs[0], "sw_", "");

        Command *command = g_commandsManager->FetchCommand(commandName);
        if (command)
            command->Execute(player->GetSlot().Get(), cmdString, true);
    }
    else
        engine->ClientCommand(player->GetSlot().Get(), cmd.c_str());
}

std::string PluginPlayer::GetConvarValue(std::string name)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";

    if (!engine)
        return "";

    return engine->GetClientConVarValue(player->GetSlot(), name.c_str());
}

void PluginPlayer::SetConvar(std::string name, std::string value)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->SetClientConvar(name, value);
}

std::string PluginPlayer::GetIPAddress()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return "";

    return player->GetIPAddress();
}

int PluginPlayer::GetSlot()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return -1;

    return player->GetSlot().Get();
}

uint64_t PluginPlayer::GetSteamID()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return 0;

    return player->GetSteamID();
}

std::string PluginPlayer::GetSteamID2()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
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
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    if (!player->HasMenuShown())
        return;

    player->HideMenu();
}

bool PluginPlayer::IsFakeClient()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return false;

    return player->IsFakeClient();
}

bool PluginPlayer::IsFirstSpawn()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return false;

    return player->IsFirstSpawn();
}

void PluginPlayer::Kill()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    CBasePlayerPawn *pawn = player->GetPawn();
    if (!pawn)
        return;

    pawn->CommitSuicide(false, true);
}

void PluginPlayer::Respawn()
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    CCSPlayerController *controller = player->GetPlayerController();
    if (!controller)
        return;

    controller->Respawn();
}

void PluginPlayer::SendMsg(int dest, std::string msg)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->SendMsg(dest, msg.c_str());
}

void PluginPlayer::SetModel(std::string model)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    CCSPlayerPawn *pawn = player->GetPlayerPawn();
    if (!pawn)
        return;

    pawn->SetModel(model.c_str());
}

void PluginPlayer::ShowMenu(std::string menuid)
{
    Player *player = g_playerManager->GetPlayer(this->playerId);
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

    Player *player = g_playerManager->GetPlayer(this->playerId);
    if (!player)
        return;

    player->SwitchTeam(team);
}

std::any PluginPlayer::GetVarValue(std::string key)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return nullptr;

    return player->GetInternalVar(key);
}

luabridge::LuaRef PluginPlayer::GetVarValueLua(std::string key, lua_State *L)
{
    luabridge::LuaRef val = LuaSerializeData(GetVarValue(key), L);

    return val;
}

void PluginPlayer::SetVarValue(std::string key, std::any value)
{
    Player *player = g_playerManager->GetPlayer(playerId);
    if (!player)
        return;

    player->SetInternalVar(key, value);
}

void PluginPlayer::SetVarValueLua(std::string key, luabridge::LuaRef value)
{
    std::any returnValue;

    if (value.isBool())
        returnValue = value.cast<bool>();
    else if (value.isNil())
        returnValue = nullptr;
    else if (value.isNumber())
        returnValue = value.cast<int64_t>();
    else if (value.isString())
        returnValue = value.cast<std::string>();
    else
        returnValue = nullptr;

    this->SetVarValue(key, returnValue);
}