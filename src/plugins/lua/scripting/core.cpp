#include "core.h"

int customPrint(lua_State *state)
{
    g_SMAPI->ConPrintf("[Swiftly] [%16s] ", ("plugin:" + luabridge::getGlobal(state, "plugin_name").tostring()).c_str());

    int n = lua_gettop(state);

    lua_getglobal(state, "tostring");

    for (int i = 1; i <= n; i++)
    {
        lua_pushvalue(state, -1);
        lua_pushvalue(state, i);
        lua_call(state, 1, 1);

        size_t l = 0;
        const char *s = lua_tolstring(state, -1, &l);
        if (s == nullptr)
        {
            PRINT("An error has occured while trying to call 'print'.\nError: 'tostring' must return a string to 'print'\n");
            break;
        }

        if (i > 1)
            g_SMAPI->ConPrint("\t");

        g_SMAPI->ConPrint(s);
        lua_pop(state, 1);
    }
    g_SMAPI->ConPrint("\n");
    return 0;
}

void SetupLuaEnvironment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .addCFunction("print", &customPrint)
        .addFunction("GetCurrentPluginName", +[](lua_State *L) -> std::string
                     { return FetchPluginName(L); });

    luabridge::setGlobal(state, plugin->GetName(), "plugin_name");

    SetupLuaLogs(plugin, state);
    SetupLuaTypes(plugin, state);
    SetupLuaTranslations(plugin, state);
    SetupLuaConfiguration(plugin, state);
    SetupLuaFiles(plugin, state);
    SetupLuaPrecacher(plugin, state);
    SetupLuaCommands(plugin, state);
    SetupLuaPlayerManager(plugin, state);
    SetupLuaEvents(plugin, state);
    SetupLuaHTTP(plugin, state);
}