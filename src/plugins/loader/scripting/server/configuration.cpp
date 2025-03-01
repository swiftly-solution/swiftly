#include "../../core.h"

LoadScriptingComponent(
    configuration,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginConfiguration>("Configuration", state)
            .addConstructor<std::string>()
            .addFunction("Exists", &PluginConfiguration::Exists)
            .addFunction("Reload", &PluginConfiguration::Reload)
            .addFunction("FetchArraySize", &PluginConfiguration::FetchArraySize)
            .addFunction("Fetch", &PluginConfiguration::Fetch)
            .addFunction("Create", &PluginConfiguration::Create)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("config = Configuration(GetCurrentPluginName())");  
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.config = Configuration(GetCurrentPluginName())");
    }
)