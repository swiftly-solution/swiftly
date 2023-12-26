#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

static const luaL_Reg lualibs[] = {
    {"_G", luaopen_base},
    {LUA_TABLIBNAME, luaopen_table},
    {LUA_STRLIBNAME, luaopen_string},
    {LUA_MATHLIBNAME, luaopen_math},
    {LUA_DBLIBNAME, luaopen_debug},
    {LUA_COLIBNAME, luaopen_coroutine},
    {LUA_UTF8LIBNAME, luaopen_utf8},
    {LUA_IOLIBNAME, luaopen_io},
    {LUA_OSLIBNAME, luaopen_os},
    {NULL, NULL},
};

void SetupLuaEnvironment(Plugin *plugin)
{
    const luaL_Reg *lib = lualibs;
    for (; lib->func; lib++)
    {
        luaL_requiref(plugin->GetLuaRawState(), lib->name, lib->func, 1);
        lua_pop(plugin->GetLuaRawState(), 1);
    }

    luacpp::LuaState *state = plugin->GetLuaState();

    state->CreateFunction([](const char *msg) -> void
                          { if (std::string(msg).size() == 0) {return;} scripting_Print((std::string(msg) + "\n").c_str()); },
                          "print");
    state->CreateFunction([plugin]() -> const char *
                          { return plugin->GetName().c_str(); },
                          "PluginName");

    PRINT("Scripting - Lua", "Core loaded.\n");

    SetupLuaConfiguration(state, plugin);
    SetupLuaGameEvents(state, plugin);
    SetupLuaLogger(state, plugin);
    SetupLuaPlayer(state, plugin);
    SetupLuaTranslation(state, plugin);
}