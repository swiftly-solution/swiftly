#include "../../../../common.h"
#include "sdk/entity/CGameRules.h"

SMM_API void scripting_Server_ExecuteCommand(const char *str)
{
    if (str == nullptr)
        return;

    engine->ServerCommand(str);
}

SMM_API uint16 scripting_Server_GetMaxPlayers()
{
    return engine->GetServerGlobals()->maxClients;
}

SMM_API const char *scripting_Server_GetMapName()
{
    if (!engine->GetServerGlobals())
        return "unknown_map";

    const char *mapname = engine->GetServerGlobals()->mapname.ToCStr();

    char *res = new char[strlen(mapname) + 1];
    strcpy(res, mapname);
    return res;
}

SMM_API bool scripting_Server_IsPistolRound()
{
    if (g_pGameRules == nullptr)
        return false;

    return (g_pGameRules->m_totalRoundsPlayed() == 0 || g_pGameRules->m_nRoundsPlayedThisPhase() == 0 || (g_pGameRules->m_bSwitchingTeamsAtRoundReset() && g_pGameRules->m_nOvertimePlaying() == 0) || g_pGameRules->m_bGameRestart());
}

SMM_API int scripting_server_GetTotalRounds()
{
    if (g_pGameRules == nullptr)
        return 0;

    return (g_pGameRules->m_totalRoundsPlayed());
}

SMM_API bool scripting_Server_IsMapValid(const char *map)
{
    if (map == nullptr)
        return false;

    return (engine->IsMapValid(map) == 1);
}

SMM_API float scripting_Server_GetCurrentTime()
{
    CGlobalVars *vars = GetGameGlobals();
    if (!vars)
        return 0.0f;

    return vars->curtime;
}

SMM_API int scripting_Server_GetTickCount()
{
    CGlobalVars *vars = GetGameGlobals();
    if (!vars)
        return 0;

    return vars->tickcount;
}

SMM_API void scripting_Server_SetQueuedMatchmaking(bool status)
{
    if (!g_pGameRules)
        return;

    g_pGameRules->m_bIsQueuedMatchmaking = status;
}

SMM_API bool scripting_Server_GetQueuedMatchmaking()
{
    if (!g_pGameRules)
        return false;

    return g_pGameRules->m_bIsQueuedMatchmaking();
}

SMM_API int scripting_Server_SetQueuedMatchmakingMode(int status)
{
    if (!g_pGameRules)
        return;

    g_pGameRules->m_nQueuedMatchmakingMode = status;
}
