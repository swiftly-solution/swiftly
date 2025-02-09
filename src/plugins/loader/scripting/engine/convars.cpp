#include "../../core.h"

LoadScriptingComponent(
    convars,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginConvars>("ConVars")
            .addFunction("CreateFake", &PluginConvars::CreateFake)
            .addFunction("DeleteFake", &PluginConvars::DeleteFake)
            .addFunction("Get", &PluginConvars::GetConvarValue)
            .addFunction("GetType", &PluginConvars::GetConvarType)
            .addFunction("Set", &PluginConvars::SetConvar)
            .addFunction("Exists", &PluginConvars::Exists)
            .addFunction("ExistsFake", &PluginConvars::ExistsFake)
            .addFunction("AddFlags", &PluginConvars::AddFlags)
            .addFunction("RemoveFlags", &PluginConvars::RemoveFlags)
            .addFunction("GetFlags", &PluginConvars::GetFlags)
            .addFunction("HasFlags", &PluginConvars::HasFlags)
            .endClass()
            .addConstant("convar", new PluginConvars(FetchPluginName(state)));
    }
)