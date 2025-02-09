#include "../../core.h"

LoadScriptingComponent(
    hooks,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginHooks>("Hooks")
            .addFunction("Add", &PluginHooks::AddHook)
            .addFunction("AddEntityOutputHook", &PluginHooks::AddEntityOutputHook)
            .addFunction("Call", &PluginHooks::CallHook)
            .endClass()
            .addConstant("hooks", new PluginHooks(FetchPluginName(state)));
    }
)