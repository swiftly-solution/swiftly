#include "../../core.h"

LoadScriptingComponent(
    precacher,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginPrecacher>("Precacher", state)
            .addConstructor<std::string>()
            .addFunction("PrecacheModel", &PluginPrecacher::PrecacheModel)
            .addFunction("PrecacheSound", &PluginPrecacher::PrecacheSound)
            .addFunction("PrecacheItem", &PluginPrecacher::PrecacheItem)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("precacher = Precacher(GetCurrentPluginName())");
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.precacher = Precacher(GetCurrentPluginName())");
    }
)