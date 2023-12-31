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

void OnClientSpawn(const OnPlayerSpawn *e)
{
    CBasePlayerController *controller = (CBasePlayerController *)e->pEvent->GetPlayerController("userid");
    if (!controller)
        return;

    CPlayerSlot slot = e->pEvent->GetPlayerSlot("userid");
    Player *player = g_playerManager->GetPlayer(&slot);
    if (!player)
        return;

    player->SetEHandlerIdx(controller->GetRefEHandle().GetEntryIndex());
}

void PlayerManager::SetupHooks()
{
    gameevents::on<OnPlayerSpawn>(OnClientSpawn);
}