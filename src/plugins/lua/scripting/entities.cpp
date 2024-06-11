#include "core.h"

void SetupLuaEntities(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .addFunction("FindEntitiesByClassname", UTIL_FindEntitiesByClassname);
}