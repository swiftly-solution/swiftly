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
#include <set>

luabridge::LuaRef LuaSerializeData(std::any data, lua_State* state);
std::any LuaDeserializeData(luabridge::LuaRef ref, lua_State* state);

namespace luabridge {

    /// Lua stack traits for C++ types.
    ///
    /// @tparam T A C++ type.
    ///
    template<class T>
    struct Stack;

    template<>
    struct Stack<std::any>
    {
        static void push(lua_State* L, std::any v) { LuaSerializeData(v, L).push(L); }

        static std::any get(lua_State* L, int index) { return LuaDeserializeData(LuaRef::fromStack(L, index), L); }
    };
}


class PluginEvent;

class LuaPlugin : public Plugin
{
private:
    lua_State* state;
    luabridge::LuaRef* globalEventHandler;
    std::set<std::string> eventHandlers;

public:
    LuaPlugin(std::string plugin_name, PluginKind_t kind) : Plugin(plugin_name, kind) {}

    bool LoadScriptingEnvironment();
    void DestroyScriptingEnvironment();
    bool ExecuteStart();
    void ExecuteStop();

    void ExecuteCommand(void* functionPtr, std::string name, int slot, std::vector<std::string> args, bool silent, std::string prefix);

    void RegisterEventHandler(void* functionPtr);
    void RegisterEventHandling(std::string eventName);
    void UnregisterEventHandling(std::string eventName);
    EventResult PluginTriggerEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent* event);

    std::string GetAuthor();
    std::string GetWebsite();
    std::string GetVersion();
    std::string GetPlName();

    lua_State* GetState() { return this->state; }
};

luabridge::LuaRef LuaSerializeData(std::any data, lua_State* state);

#endif