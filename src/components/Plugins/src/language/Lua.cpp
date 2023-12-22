#include "../../inc/Scripting.h"
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

auto printfunc = [](const char *msg) -> void
{
    if (!g_SMAPI)
        return;

    g_SMAPI->ConPrint((std::string(msg) + "\n").c_str());
};

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

    plugin->GetLuaState()->CreateFunction(printfunc, "print");
}