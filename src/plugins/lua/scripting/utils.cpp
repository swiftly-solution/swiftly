#include "core.h"

void SetupLuaUtils(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .addFunction("GetTime", GetTime);
}