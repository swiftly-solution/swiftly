#include "../../core.h"

LoadScriptingComponent(
    hooks,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginHooks>("Hooks", state)
            .addConstructor<std::string>()
            .addFunction("Add", &PluginHooks::AddHook)
            .addFunction("AddEntityOutputHook", &PluginHooks::AddEntityOutputHook)
            .addFunction("Call", &PluginHooks::CallHook)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("hooks = Hooks(GetCurrentPluginName())");
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.hooks = Hooks(GetCurrentPluginName())");
    }
)