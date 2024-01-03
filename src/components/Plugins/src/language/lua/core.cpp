#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

extern "C"
{
    LUALIB_API int luaopen_rapidjson(lua_State *L);
}

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
    {"json", luaopen_rapidjson},
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

    state->CreateFunction([plugin]() -> void
                          {
                                lua_State* st = plugin->GetLuaRawState();

                                int n = lua_gettop(st);

                                lua_getglobal(st, "tostring");

                                for(int i = 1; i <= n; i++) {
                                    lua_pushvalue(st, -1);
                                    lua_pushvalue(st,i);
                                    lua_call(st,1,1);

                                    size_t l = 0;
                                    const char* s = lua_tolstring(st, -1, &l);
                                    if(s == nullptr) {
                                        PRINTF("Runtime", "An error has occured while trying to call 'print'.\nError: 'tostring' must return a string to 'print'\n");
                                        break;
                                    }

                                    if(i > 1) scripting_Print("\t");
                                    scripting_Print(s);
                                    lua_pop(st,1);
                                } scripting_Print("\n"); },
                          "print");
    state->CreateFunction([plugin]() -> const char *
                          { return plugin->GetName().c_str(); },
                          "PluginName");

    PRINT("Scripting - Lua", "Core loaded.\n");

    SetupLuaCommands(state, plugin);
    SetupLuaConfiguration(state, plugin);
    SetupLuaGameEvents(state, plugin);
    SetupLuaLogger(state, plugin);
    SetupLuaPlayer(state, plugin);
    SetupLuaPrecacher(state, plugin);
    SetupLuaServer(state, plugin);
    SetupLuaTranslation(state, plugin);
}