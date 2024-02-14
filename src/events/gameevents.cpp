#include "gameevents.h"
#include "../sdk/entity/CBasePlayerController.h"
#include "../sdk/entity/CBasePlayerPawn.h"
#include "../hooks/GameEvents.h"

CUtlVector<CGameEventListener *> g_GameEventListener;

void RegisterEventListeners()
{
    if (!g_gameEventManager)
        return;

    FOR_EACH_VEC(g_GameEventListener, i)
    {
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
    gameevents::emit<OnPlayerSpawn>(pEvent);
}

GAME_EVENT(round_prestart)
{
    gameevents::emit<OnRoundPrestart>(pEvent);
}

GAME_EVENT(round_poststart)
{
    gameevents::emit<OnRoundPostStart>(pEvent);
}

GAME_EVENT(round_start)
{
    gameevents::emit<OnRoundStart>(pEvent);
}

GAME_EVENT(round_end)
{
    gameevents::emit<OnRoundEnd>(pEvent);
}

GAME_EVENT(bomb_beginplant)
{
    gameevents::emit<BombBeginPlant>(pEvent);
}

GAME_EVENT(bomb_abortplant)
{
    gameevents::emit<BombAbortPlant>(pEvent);
}

GAME_EVENT(bomb_planted)
{
    gameevents::emit<BombPlanted>(pEvent);
}

GAME_EVENT(bomb_begindefuse)
{
    gameevents::emit<BombBeginDefuse>(pEvent);
}

GAME_EVENT(bomb_abortdefuse)
{
    gameevents::emit<BombAbortDefuse>(pEvent);
}

GAME_EVENT(bomb_defused)
{
    gameevents::emit<BombDefused>(pEvent);
}

GAME_EVENT(bomb_exploded)
{
    gameevents::emit<BombExploded>(pEvent);
}

GAME_EVENT(bomb_dropped)
{
    gameevents::emit<BombDropped>(pEvent);
}

GAME_EVENT(bomb_pickup)
{
    gameevents::emit<BombPickup>(pEvent);
}

GAME_EVENT(player_death)
{
    gameevents::emit<PlayerDeath>(pEvent);
}

GAME_EVENT(player_hurt)
{
    gameevents::emit<PlayerHurt>(pEvent);
}

GAME_EVENT(player_blind)
{
    gameevents::emit<PlayerBlind>(pEvent);
}

GAME_EVENT(player_full_update)
{
    gameevents::emit<PlayerFullUpdate>(pEvent);
}

GAME_EVENT(item_pickup)
{
    gameevents::emit<ItemPickup>(pEvent);
}

GAME_EVENT(enter_buyzone)
{
    gameevents::emit<EnterBuyzone>(pEvent);
}

GAME_EVENT(enter_bombzone)
{
    gameevents::emit<EnterBombzone>(pEvent);
}

GAME_EVENT(exit_bombzone)
{
    gameevents::emit<ExitBombzone>(pEvent);
}

GAME_EVENT(exit_buyzone)
{
    gameevents::emit<ExitBuyzone>(pEvent);
}

GAME_EVENT(player_jump)
{
    gameevents::emit<PlayerJump>(pEvent);
}

GAME_EVENT(player_connect_full)
{
    gameevents::emit<ClientFullConnected>(pEvent);
}

GAME_EVENT(player_falldamage)
{
    gameevents::emit<PlayerFallDamage>(pEvent);
}