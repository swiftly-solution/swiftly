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