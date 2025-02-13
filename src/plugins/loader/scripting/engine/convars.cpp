#include "../../core.h"

LoadScriptingComponent(
    convars,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginConvars>("ConVars", state)
            .addConstructor<std::string>()
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
            .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("convar = ConVars(GetCurrentPluginName())");
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.convar = ConVars(GetCurrentPluginName())");
    }
)