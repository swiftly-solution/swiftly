#ifndef _plugins_plugin_h
#define _plugins_plugin_h

#include <string>
#include <vector>
#include <map>
#include <any>
#include <set>
#include <Embedder.h>
#include "../types/PluginKind.h"
#include "../types/PluginState.h"
#include "../types/EventResult.h"
#include "../engine/gameevents/gameevents.h"

std::any DeserializeData(EValue ref, EContext* state);
EValue SerializeData(std::any data, EContext* state);

template<class T>
struct Stack;

template<>
struct Stack<std::any>
{
    static void pushLua(EContext* ctx, std::any value)
    {
        SerializeData(value, ctx).pushLua();
    }

    static JSValue pushJS(EContext* ctx, std::any value)
    {
        return SerializeData(value, ctx).pushJS();
    }

    static std::any getLua(EContext* ctx, int ref)
    {
        return DeserializeData(EValue(ctx, ref), ctx);
    }

    static std::any getJS(EContext* ctx, JSValue value)
    {
        return DeserializeData(EValue(ctx, value), ctx);
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return true;
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return true;
    }
};

class PluginEvent;

class Plugin
{
private:
    std::string name;
    PluginKind_t kind;
    PluginState_t state = PluginState_t::Stopped;
    std::string loadError = "";
    EContext* ctx = nullptr;
    EValue* globalEventHandler = nullptr;
    std::set<std::string> eventHandlers;

public:
    Plugin(std::string m_name, PluginKind_t m_kind);
    ~Plugin();

    std::string GetName();
    PluginKind_t GetKind();

    PluginState_t GetPluginState();
    void SetPluginState(PluginState_t state);

    std::string GetLoadError();
    void SetLoadError(std::string error);

    bool LoadScriptingEnvironment();
    void DestroyScriptingEnvironment();
    bool ExecuteStart();
    bool ExecuteStop();

    void ExecuteCommand(void* functionPtr, std::string name, int slot, std::vector<std::string> args, bool silent, std::string prefix);

    void RegisterEventHandler(void* functionPtr);
    void RegisterEventHandling(std::string eventName);
    void UnregisterEventHandling(std::string eventName);

    // Returns the memory usage of the plugin in bytes
    int64_t GetMemoryUsage();

    std::string GetAuthor();
    std::string GetWebsite();
    std::string GetVersion();
    std::string GetPlName();

    EventResult TriggerEvent(std::string invokedBy, std::string eventName, std::string eventPayload, PluginEvent* event);

    EContext* GetContext() { return ctx; }
};

#endif