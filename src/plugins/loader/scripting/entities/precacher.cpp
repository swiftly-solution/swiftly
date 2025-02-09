#include "../../core.h"

LoadScriptingComponent(
    precacher,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginPrecacher>("Precacher")
            .addFunction("PrecacheModel", &PluginPrecacher::PrecacheModel)
            .addFunction("PrecacheSound", &PluginPrecacher::PrecacheSound)
            .addFunction("PrecacheItem", &PluginPrecacher::PrecacheItem)
            .endClass()
            .addConstant("precacher", new PluginPrecacher(FetchPluginName(state)));
    }
)