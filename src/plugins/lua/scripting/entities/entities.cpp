#include "../core.h"

LoadLuaScriptingComponent(
    entities,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .addFunction("FindEntitiesByClassname", UTIL_FindEntitiesByClassname)
            .addFunction("CreateEntityByName", CreateEntityByName);
    }
)