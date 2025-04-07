#include "../../core.h"

void AddGlobalEvents(EValue eventFunction, EContext* L)
{
    if (!eventFunction.isFunction())
        return;

    Plugin* plugin = FetchPluginByState(L);
    if (!plugin)
        return;

    plugin->RegisterEventHandler(new EValue(eventFunction));
}

void RegisterEventHandlerPlugin(std::string eventName, EContext* L)
{
    Plugin* plugin = FetchPluginByState(L);
    if (!plugin)
        return;

    plugin->RegisterEventHandling(eventName);
}

void RemoveEventHandlerPlugin(std::string eventName, EContext* L)
{
    Plugin* plugin = FetchPluginByState(L);
    if (!plugin)
        return;

    plugin->UnregisterEventHandling(eventName);
}

std::vector<std::any> TriggerEventInternal(std::string eventName, EValue eventPayload, EContext* L)
{
    std::vector<std::any> returnValues;

    PluginEvent event(FetchPluginName(L), nullptr, nullptr);

    std::string payload = "";
    size_t len;

    if (L->GetKind() == ContextKinds::JavaScript) payload = (const char*)JS_GetUint8Array((JSContext*)L->GetState(), &len, eventPayload.pushJS());
    else payload = eventPayload.cast<std::string>();

    returnValues.push_back((int)g_pluginManager->ExecuteEvent(FetchPluginName(L), eventName, payload, &event));
    returnValues.push_back(event);

    return returnValues;
}

void LoadEvent(Plugin* plugin, EContext* state)
{
    GetGlobalNamespace(state)
        .addFunction("AddGlobalEvents", AddGlobalEvents)
        .addFunction("RegisterEventHandlerPlugin", RegisterEventHandlerPlugin)
        .addFunction("RemoveEventHandlerPlugin", RemoveEventHandlerPlugin)
        .addFunction("TriggerEventInternal", TriggerEventInternal);

    BeginClass<PluginEvent>(state->GetKind() == ContextKinds::JavaScript ? "PEvent" : "Event", state)
        .addConstructor<std::string, EContext*>()
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

        .addFunction("SetNoBroadcast", &PluginEvent::SetNoBroadcast)
        .addFunction("GetNoBroadcast", &PluginEvent::GetNoBroadcast)

        .endClass();
}

LoadScriptingComponent(
    events,
    LoadEvent
)