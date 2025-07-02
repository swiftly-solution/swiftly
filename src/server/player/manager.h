#ifndef _server_player_h
#define _server_player_h

#include "player.h"

#include <core/entrypoint.h>
#include <public/playerslot.h>
#include <steam/steam_api_common.h>
#include <steam/isteamuser.h>
#include <steam/steamclientpublic.h>

class PlayerManager
{
private:
    Player** g_Players = nullptr;
public:
    PlayerManager();
    ~PlayerManager();

    Player* GetPlayer(CPlayerSlot slot);
    Player* GetPlayer(int slot);

    void RegisterPlayer(CPlayerSlot slot, Player* player);
    void UnregisterPlayer(CPlayerSlot slot);
    int GetPlayers();
    int GetPlayerCap();

    void Initialize();
    void Shutdown();

    void GameFrame(bool a, bool b, bool c);
    bool ClientConnect(CPlayerSlot slot, const char* pszName, uint64 xuid, const char* pszNetworkID, bool unk1, CBufferString* pRejectReason);
    void OnClientConnected(CPlayerSlot slot, const char* pszName, uint64 xuid, const char* pszNetworkID, const char* pszAddress, bool bFakePlayer);
    void ClientDisconnect(CPlayerSlot slot, ENetworkDisconnectionReason reason, const char* pszName, uint64 xuid, const char* pszNetworkID);
    void OnClientPutInServer(CPlayerSlot slot, char const* pszName, int type, uint64 xuid);

    void SteamAPIServerActivated();

    STEAM_GAMESERVER_CALLBACK_MANUAL(PlayerManager, OnValidateAuthTicket, ValidateAuthTicketResponse_t, m_CallbackValidateAuthTicketResponse);
};

extern PlayerManager g_playerManager;

#endif