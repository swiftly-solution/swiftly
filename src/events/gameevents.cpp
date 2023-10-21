#include "gameevents.h"
#include "../utils.h"
#include "../sdk/CBasePlayerController.h"
#include "../sdk/CBasePlayerPawn.h"

CUtlVector<CGameEventListener *> g_GameEventListener;

void RegisterEventListeners()
{
    if (!g_gameEventManager)
        return;

    FOR_EACH_VEC(g_GameEventListener, i)
    {
        // PRINTF("DEBUG", "Loading Game Event: %s\n", g_GameEventListener[i]->GetName());
        g_gameEventManager->AddListener(g_GameEventListener[i], g_GameEventListener[i]->GetName(), true);
    }
}

void UnregisterEventListeners()
{
    if (!g_gameEventManager)
        return;

    FOR_EACH_VEC(g_GameEventListener, i)
    {
        g_gameEventManager->RemoveListener(g_GameEventListener[i]);
    }

    g_GameEventListener.Purge();
}

GAME_EVENT(player_spawn)
{
    CBasePlayerController *controller = (CBasePlayerController *)pEvent->GetPlayerController("userid");
    CBasePlayerPawn *pawn = (CBasePlayerPawn *)pEvent->GetPlayerPawn("userid");
    CPlayerSlot *slot = &pEvent->GetPlayerSlot("userid");

    if (!controller || !pawn)
        return;

    PRINTF("DEBUG Game Events", "player_spawn(%d, %d, %d, %d, %s)\n", pawn->m_iHealth(), pawn->m_iTeamNum(), pawn->m_iMaxHealth(), slot->Get(), controller->m_iszPlayerName());
    PRINTF("DEBUG Game Events", "Player SteamID: %llu\n", controller->m_steamID());
}
