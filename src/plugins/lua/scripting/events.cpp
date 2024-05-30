#include "core.h"

int AddGlobalEvents(luabridge::LuaRef eventFunction, lua_State *L)
{
    if (!eventFunction.isFunction())
        return 0;

    Plugin *plugin = FetchPlugin(L);
    if (!plugin)
        return 0;

    plugin->RegisterEventHandler(new luabridge::LuaRef(eventFunction));
    return 0;
}

int RegisterEventHandlerPlugin(std::string eventName, lua_State *L)
{
    Plugin *plugin = FetchPlugin(L);
    if (!plugin)
        return 0;

    plugin->RegisterEventHandling(eventName);
    return 0;
}

luabridge::LuaRef TriggerEventInternal(std::string eventName, std::string eventPayload, lua_State *L)
{
    luabridge::LuaRef returnValue = luabridge::LuaRef::newTable(L);

    PluginEvent *event = new PluginEvent(FetchPluginName(L), nullptr, nullptr);

    returnValue.append((int)g_pluginManager->ExecuteEvent(FetchPluginName(L), eventName, eventPayload, event));
    returnValue.append(*event);

    return returnValue;
}

luabridge::LuaRef GetReturnValueInternal(PluginEvent *event, lua_State *L)
{
    return LuaSerializeData(event->GetReturnValue(), L);
}

void SetupLuaEvents(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .addFunction("AddGlobalEvents", AddGlobalEvents)
        .addFunction("RegisterEventHandlerPlugin", RegisterEventHandlerPlugin)
        .addFunction("TriggerEventInternal", TriggerEventInternal)

        .beginClass<PluginEvent>("Event")
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
        .addFunction("SetReturn", &PluginEvent::SetReturnLua)
        .addFunction("FireEvent", &PluginEvent::FireEvent)
        .addFunction("FireEventToClient", &PluginEvent::FireEventToClient)
        .addFunction("GetReturn", GetReturnValueInternal)
        .endClass();
}