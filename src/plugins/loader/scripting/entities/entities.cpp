#include "../../core.h"

LoadScriptingComponent(
    entities,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .addFunction("FindEntitiesByClassname", UTIL_FindEntitiesByClassname)
            .addFunction("CreateEntityByName", CreateEntityByName);
    }
)