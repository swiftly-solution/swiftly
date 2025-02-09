#include "../../core.h"

LoadScriptingComponent(
    commands,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .beginClass<PluginCommands>("Commands")
            .addFunction("Register", &PluginCommands::RegisterCommand)
            .addFunction("Unregister", &PluginCommands::UnregisterCommand)
            .addFunction("RegisterRawAlias", &PluginCommands::RegisterRawAlias)
            .addFunction("RegisterAlias", &PluginCommands::RegisterAlias)
            .addFunction("UnregisterAlias", &PluginCommands::UnregisterAlias)
            .addFunction("GetAllCommands", &PluginCommands::GetAllCommands)
            .addFunction("GetCommands", &PluginCommands::GetCommands)
            .endClass()
            .addConstant("commands", new PluginCommands(FetchPluginName(state)));
    }
)