#include "../core.h"

LoadLuaScriptingComponent(
    utils,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .addFunction("GetPluginPath", scripting_GetPluginPath)
            .addFunction("GetTime", GetTime)
            .addFunction("IsWindows", scripting_IsWindows)
            .addFunction("IsLinux", scripting_IsLinux)
            .addFunction("GetOS", scripting_GetOS)
            .addFunction("StateUpdate", scripting_StateUpdate)
            .addFunction("GetUserMessage", scripting_GetUserMessage)
            .addFunction("GetPluginState", scripting_GetPluginState)
            .addFunction("GetCCSGameRules", scripting_GetCCSGameRules)
            .addFunction("CreateTextTable", scripting_CreateTextTable);
    }
)