#include "../core.h"

int AddGlobalEvents(luabridge::LuaRef eventFunction, lua_State* L)
{
    if (!eventFunction.isFunction())
        return 0;

    Plugin* plugin = FetchPluginByState(L);
    if (!plugin)
        return 0;

    plugin->RegisterEventHandler(new luabridge::LuaRef(eventFunction));
    return 0;
}

int RegisterEventHandlerPlugin(std::string eventName, lua_State* L)
{
    Plugin* plugin = FetchPluginByState(L);
    if (!plugin)
        return 0;

    plugin->RegisterEventHandling(eventName);
    return 0;
}

std::vector<luabridge::LuaRef> TriggerEventInternal(std::string eventName, std::string eventPayload, lua_State* L)
{
    std::vector<luabridge::LuaRef> returnValues;

    PluginEvent event(FetchPluginName(L), nullptr, nullptr);

    returnValues.push_back(luabridge::LuaRef(L, (int)g_pluginManager->ExecuteEvent(FetchPluginName(L), eventName, eventPayload, &event)));
    returnValues.push_back(luabridge::LuaRef(L, event));

    return returnValues;
}

LoadLuaScriptingComponent(
    events,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .addFunction("AddGlobalEvents", AddGlobalEvents)
            .addFunction("RegisterEventHandlerPlugin", RegisterEventHandlerPlugin)
            .addFunction("TriggerEventInternal", TriggerEventInternal)

            .beginClass<PluginEvent>("Event")
            .addConstructor<void(*)(std::string, lua_State*)>()
            .addFunction("GetInvokingPlugin", &PluginEvent::GetInvokingPlugin)
            .addFunction("IsGameEvent", &PluginEvent::IsGameEvent)
            .addFunction("IsHook", &PluginEvent::IsHook)
            .addFunction("SetBool", &PluginEvent::SetBool)
            .addFunction("SetInt", &PluginEvent::SetInt)
            .addFunction("SetUint64", &PluginEvent::SetUint64)
            .addFunction("SetFloat", &PluginEvent::SetFloat)
            .addFunction("SetString", &PluginEvent::SetString)
            .addFunction("GetBool", &PluginEvent::GetBool)
            .addFunction("GetInt", &PluginEvent::GetInt)
            .addFunction("GetUint64", &PluginEvent::GetUint64)
            .addFunction("GetFloat", &PluginEvent::GetFloat)
            .addFunction("GetString", &PluginEvent::GetString)
            .addFunction("SetReturn", &PluginEvent::SetReturn)
            .addFunction("GetReturn", &PluginEvent::GetReturnValue)
            .addFunction("FireEvent", &PluginEvent::FireEvent)
            .addFunction("FireEventToClient", &PluginEvent::FireEventToClient)

            .addFunction("GetHookBool", &PluginEvent::GetHookBool)
            .addFunction("GetHookInt", &PluginEvent::GetHookInt)
            .addFunction("GetHookUint64", &PluginEvent::GetHookUint64)
            .addFunction("GetHookFloat", &PluginEvent::GetHookFloat)
            .addFunction("GetHookString", &PluginEvent::GetHookString)
            .addFunction("GetHookPointer", &PluginEvent::GetHookPointer)
            .addFunction("GetHookDouble", &PluginEvent::GetHookDouble)
            .addFunction("GetHookUInt", &PluginEvent::GetHookUInt)
            .addFunction("GetHookInt64", &PluginEvent::GetHookInt64)
            .addFunction("SetHookBool", &PluginEvent::SetHookBool)
            .addFunction("SetHookInt", &PluginEvent::SetHookInt)
            .addFunction("SetHookUint64", &PluginEvent::SetHookUint64)
            .addFunction("SetHookFloat", &PluginEvent::SetHookFloat)
            .addFunction("SetHookString", &PluginEvent::SetHookString)
            .addFunction("SetHookPointer", &PluginEvent::SetHookPointer)
            .addFunction("SetHookDouble", &PluginEvent::SetHookDouble)
            .addFunction("SetHookUInt", &PluginEvent::SetHookUInt)
            .addFunction("SetHookInt64", &PluginEvent::SetHookInt64)

            .addFunction("SetHookReturn", &PluginEvent::SetHookReturn)
            .addFunction("GetHookReturn", &PluginEvent::GetHookReturn)

            .endClass();
    }
)