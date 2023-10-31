#include "PlayerManager.h"
#include "../hooks/Hooks.h"
#include "../hooks/GameEvents.h"

void PlayerManager::LoadPlayers()
{
    for (uint16 i = 0; i < MAX_PLAYERS; i++)
    {
        Player *player = this->GetPlayer(i);
        if (!player)
            continue;

        if (player->IsAuthenticated() || player->IsFakeClient())
            continue;

        if (engine->IsClientFullyAuthenticated(i))
        {
            player->Authenticate();
        }
    }
}

void OnClientConnectedOnServer(const OnClientConnected *e)
{
    if (e->bFakePlayer)
    {
        Player *player = new Player(true, *e->slot, e->pszName, 0);
        g_playerManager->RegisterPlayer(player);
    }
};

void OnClientConnectOnServer(const OnClientConnect *e)
{
    Player *player = new Player(false, *e->slot, e->pszName, e->xuid);
    g_playerManager->RegisterPlayer(player);

    player->SetConnected(true);
};

void OnClientDisconnected(const OnClientDisconnect *e)
{
    Player *player = g_playerManager->GetPlayer(e->slot);
    if (!player)
        return;

    g_playerManager->UnregisterPlayer(e->slot);
};

void OnClientSpawn(const OnPlayerSpawn *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    Player *player = g_playerManager->GetPlayer(&e->pEvent->GetPlayerSlot("userid"));
    if (!player)
        return;

    player->SetEHandlerIdx(controller->GetRefEHandle().GetEntryIndex());
};

void PlayerManager::SetupHooks()
{
    hooks::on<OnClientConnected>(OnClientConnectedOnServer);
    hooks::on<OnClientConnect>(OnClientConnectOnServer);
    hooks::on<OnClientDisconnect>(OnClientDisconnected);

    gameevents::on<OnPlayerSpawn>(OnClientSpawn);
}