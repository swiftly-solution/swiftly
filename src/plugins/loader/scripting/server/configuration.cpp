#include "../../core.h"

LoadScriptingComponent(
    configuration,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginConfiguration>("Configuration")
            .addFunction("Exists", &PluginConfiguration::Exists)
            .addFunction("Reload", &PluginConfiguration::Reload)
            .addFunction("FetchArraySize", &PluginConfiguration::FetchArraySize)
            .addFunction("Fetch", &PluginConfiguration::Fetch)
            .addFunction("Create", &PluginConfiguration::Create)
            .endClass()
            .addConstant("config", new PluginConfiguration(FetchPluginName(state)));
    }
)