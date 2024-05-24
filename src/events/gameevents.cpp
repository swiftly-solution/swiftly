#include "gameevents.h"
#include "../sdk/entity/CBasePlayerController.h"
#include "../sdk/entity/CBasePlayerPawn.h"

void RegisterEventListeners()
{
    if (!g_gameEventManager) {
        return;
    }

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
