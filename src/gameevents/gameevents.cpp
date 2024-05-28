#include "gameevents.h"
#include "../hooks/FuncHook.h"

FuncHook<decltype(Hook_CGameEventManager_Init)> TCGameEventManager_Init(Hook_CGameEventManager_Init, "CGameEventManager_Init");

void Hook_CGameEventManager_Init(IGameEventManager2 *pGameEventManager)
{
    g_gameEventManager = pGameEventManager;
    TCGameEventManager_Init(pGameEventManager);

    PLUGIN_PRINT("Game Events", "Loading game events...\n");
    RegisterEventListeners();
    PLUGIN_PRINT("Game Events", "Game events have been succesfully loaded.\n");
}

void RegisterEventListeners()
{
    if (!g_gameEventManager)
        return;

    FOR_EACH_VEC(g_GameEventListener, i)
    {
        if (!g_gameEventManager->FindListener(g_GameEventListener[i], g_GameEventListener[i]->GetName()))
            g_gameEventManager->AddListener(g_GameEventListener[i], g_GameEventListener[i]->GetName(), true);
    }
}

void UnregisterEventListeners()
{
    if (!g_gameEventManager)
        return;

    FOR_EACH_VEC(g_GameEventListener, i)
    {
        if (g_gameEventManager->FindListener(g_GameEventListener[i], g_GameEventListener[i]->GetName()))
            g_gameEventManager->RemoveListener(g_GameEventListener[i]);
    }

    g_GameEventListener.Purge();
}