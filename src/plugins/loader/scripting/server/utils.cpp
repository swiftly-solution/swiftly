#include "../../core.h"
#include <functional>

std::string FetchPluginName(EContext* state);
void RegisterTimeout(int64_t delay, std::function<void()> cb);

#define FetchPluginByState(state) g_pluginManager->FetchPlugin(FetchPluginName(state))

void scripting_AddTimeout(int64_t delay, EValue callback, EContext* ctx)
{
    if (!callback.isFunction()) return;
    EValue* cb = new EValue(callback);

    RegisterTimeout(delay, [cb, ctx]() -> void {
        auto pl = FetchPluginByState(ctx);
        if (pl == nullptr) return;

        if (!cb->isFunction()) {
            delete cb;
            return;
        }

        try {
            cb->operator()();
        }
        catch (EException& e)
        {
            PRINTF("An error has occured while trying to execute the timeout callback: %s\n", e.what());
        }
        delete cb;
    });
}

LoadScriptingComponent(
    utils,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .addFunction("AddTimeout", scripting_AddTimeout)
            .addFunction("GetPluginPath", scripting_GetPluginPath)
            .addFunction("GetTime", GetTime)
            .addFunction("IsWindows", scripting_IsWindows)
            .addFunction("IsLinux", scripting_IsLinux)
            .addFunction("GetOS", scripting_GetOS)
            .addFunction("StateUpdate", scripting_StateUpdate)
            .addFunction("GetUserMessage", scripting_GetUserMessage)
            .addFunction("GetPluginState", scripting_GetPluginState)
            .addFunction("GetCCSGameRules", scripting_GetCCSGameRules)
            .addFunction("CreateTextTable", scripting_CreateTextTable)
            .addFunction("RegisterCallstack", RegisterCallstack)
            .addFunction("UnregisterCallstack", UnregisterCallstack);
    }
)