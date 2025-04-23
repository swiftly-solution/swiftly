#include "manager.h"

#include <utils/utils.h>
#include <core/entrypoint.h>
#include <sdk/game.h>
#include <engine/vgui/vgui.h>

#include <server/configuration/configuration.h>
#include <engine/convars/query.h>
#include <plugins/manager.h>

SH_DECL_EXTERN3_void(IServerGameDLL, GameFrame, SH_NOATTRIB, 0, bool, bool, bool);
SH_DECL_EXTERN6(IServerGameClients, ClientConnect, SH_NOATTRIB, 0, bool, CPlayerSlot, const char*, uint64, const char*, bool, CBufferString*);
SH_DECL_EXTERN6_void(IServerGameClients, OnClientConnected, SH_NOATTRIB, 0, CPlayerSlot, const char*, uint64, const char*, const char*, bool);
SH_DECL_EXTERN5_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, CPlayerSlot, ENetworkDisconnectionReason, const char*, uint64, const char*);

uint64_t playerMask = 0;

PlayerManager::PlayerManager()
{
    g_Players = new Player * [GetMaxGameClients()];

    for (int i = 0; i < GetMaxGameClients(); i++) {
        g_Players[i] = nullptr;
    }
}

PlayerManager::~PlayerManager()
{
    for (int i = 0; i < GetMaxGameClients(); i++) {
        if (g_Players[i]) {
            delete g_Players[i];
        }
    }
    delete g_Players;
}

Player* PlayerManager::GetPlayer(CPlayerSlot slot)
{
    return GetPlayer(slot.Get());
}

Player* PlayerManager::GetPlayer(int slot)
{
    if (slot < 0 || slot > GetMaxGameClients() - 1) return nullptr;
    if ((playerMask & (1ULL << slot)) == 0) return nullptr;

    return g_Players[slot];
}

void PlayerManager::RegisterPlayer(CPlayerSlot slot, Player* player)
{
    int playerid = slot.Get();
    if (playerid < 0 || playerid >= GetMaxGameClients()) return;

    if (g_Players[playerid] != nullptr) return;

    g_Players[playerid] = player;
    playerMask |= (1ULL << playerid);
}

void PlayerManager::UnregisterPlayer(CPlayerSlot slot)
{
    int playerid = slot.Get();
    if (playerid < 0 || playerid >= GetMaxGameClients()) return;

    if ((playerMask & (1ULL << playerid)) != 0) return;

    delete g_Players[playerid];
    g_Players[playerid] = nullptr;
    playerMask &= ~(1ULL << playerid);
}

int PlayerManager::GetPlayers()
{
    int count = 0;

    for (int i = 0; i < GetMaxGameClients(); i++)
        if ((playerMask & (1ULL << i)) != 0)
            ++count;

    return count;
}

int PlayerManager::GetPlayerCap()
{
    return GetMaxGameClients();
}

void PlayerManager::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &PlayerManager::GameFrame, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &PlayerManager::ClientConnect, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &PlayerManager::OnClientConnected, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &PlayerManager::ClientDisconnect, true);
}

void PlayerManager::Shutdown()
{
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &PlayerManager::GameFrame, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &PlayerManager::ClientConnect, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &PlayerManager::OnClientConnected, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &PlayerManager::ClientDisconnect, true);
}

void PlayerManager::GameFrame(bool a, bool b, bool c)
{
    for (int i = 0; i < GetPlayerCap(); i++) {
        Player* player = GetPlayer(i);
        if (player) player->Think();
    }
}

bool PlayerManager::ClientConnect(CPlayerSlot slot, const char* pszName, uint64 xuid, const char* pszNetworkID, bool unk1, CBufferString* pRejectReason)
{
    std::string ip_address = explode(pszNetworkID, ":")[0];
    Player* player = new Player(false, slot.Get(), pszName, xuid, ip_address);
    RegisterPlayer(slot, player);

    ClassData data({ { "plugin_name", "core" } }, "Event", nullptr);
    g_pluginManager.ExecuteEvent("core", "OnClientConnect", { slot.Get() }, &data);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(data.GetData<std::any>("event_return"));
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    RETURN_META_VALUE(MRES_IGNORED, response);
}

void PlayerManager::OnClientConnected(CPlayerSlot slot, const char* pszName, uint64 xuid, const char* pszNetworkID, const char* pszAddress, bool bFakePlayer)
{
    if (bFakePlayer)
    {
        Player* player = new Player(true, slot.Get(), pszName, xuid, "127.0.0.1");
        RegisterPlayer(slot, player);
    }
    else {
        if (g_Config.FetchValue<bool>("core.use_player_language"))
            g_convarQuery.QueryCvarClient(slot, "cl_language");
    }
}

void PlayerManager::ClientDisconnect(CPlayerSlot slot, ENetworkDisconnectionReason reason, const char* pszName, uint64 xuid, const char* pszNetworkID)
{
    g_pluginManager.ExecuteEvent("core", "OnClientDisconnect", { slot.Get() }, nullptr);

    Player* player = GetPlayer(slot);
    if (player) {
        g_VGUI.Unregister(player);
        UnregisterPlayer(slot);
    }
}