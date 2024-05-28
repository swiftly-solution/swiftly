#ifndef _plugins_lua_luaplugin_h
#define _plugins_lua_luaplugin_h

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <LuaBridge/LuaBridge.h>
#include <LuaBridge/Array.h>
#include <LuaBridge/List.h>
#include <LuaBridge/Map.h>
#include <LuaBridge/Optional.h>
#include <LuaBridge/Pair.h>
#include <LuaBridge/UnorderedMap.h>
#include <LuaBridge/Vector.h>

#include "../Plugin.h"

class LuaPlugin : public Plugin
{
private:
    lua_State *state;

public:
    LuaPlugin(std::string plugin_name, PluginKind_t kind) : Plugin(plugin_name, kind) {}

    bool LoadScriptingEnvironment();
    void DestroyScriptingEnvironment();
    bool ExecuteStart();
    void ExecuteStop();
};

#endif