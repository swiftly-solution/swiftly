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

    return (g_pGameRules->m_totalRoundsPlayed() == 0 || (g_pGameRules->m_bSwitchingTeamsAtRoundReset() && g_pGameRules->m_nOvertimePlaying() == 0) || g_pGameRules->m_bGameRestart());
}

SMM_API bool scripting_Server_IsMapValid(const char *map)
{
    if (map == nullptr)
        return false;

    return (engine->IsMapValid(map) == 1);
}