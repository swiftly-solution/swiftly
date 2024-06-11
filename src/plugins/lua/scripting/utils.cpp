#include "core.h"

void SetupLuaUtils(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .addFunction("GetTime", GetTime)
        .addFunction("IsWindows", scripting_IsWindows)
        .addFunction("IsLinux", scripting_IsLinux)
        .addFunction("GetOS", scripting_GetOS);
}