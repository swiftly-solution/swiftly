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

#include <any>

class PluginEvent;

class LuaPlugin : public Plugin
{
private:
    lua_State *state;
    luabridge::LuaRef *globalEventHandler;
    std::map<std::string, bool> eventHandlers;

public:
    LuaPlugin(std::string plugin_name, PluginKind_t kind) : Plugin(plugin_name, kind) {}

    bool LoadScriptingEnvironment();
    void DestroyScriptingEnvironment();
    bool ExecuteStart();
    void ExecuteStop();

    void ExecuteCommand(void *functionPtr, std::string name, int slot, std::vector<std::string> args, bool silent);

    void RegisterEventHandler(void *functionPtr);
    void RegisterEventHandling(std::string eventName);
    EventResult TriggerEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent *event);
};

luabridge::LuaRef LuaSerializeData(std::any data, lua_State *state);

#endif