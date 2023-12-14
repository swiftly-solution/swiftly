#include "../../../../common.h"

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
    const char *mapname = engine->GetServerGlobals()->mapname.ToCStr();

    char *res = new char[strlen(mapname) + 1];
    strcpy(res, mapname);
    return res;
}

SMM_API bool scripting_Server_IsMapValid(const char *map)
{
    if (map == nullptr)
        return false;

    return (engine->IsMapValid(map) == 1);
}