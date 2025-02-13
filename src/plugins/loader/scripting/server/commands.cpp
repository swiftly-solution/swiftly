#include "../../core.h"

LoadScriptingComponent(
    commands,
    [](Plugin* plugin, EContext* state)
    {
        BeginClass<PluginCommands>("Commands", state)
            .addConstructor<std::string>()
            .addFunction("Register", &PluginCommands::RegisterCommand)
            .addFunction("Unregister", &PluginCommands::UnregisterCommand)
            .addFunction("RegisterRawAlias", &PluginCommands::RegisterRawAlias)
            .addFunction("RegisterAlias", &PluginCommands::RegisterAlias)
            .addFunction("UnregisterAlias", &PluginCommands::UnregisterAlias)
            .addFunction("GetAllCommands", &PluginCommands::GetAllCommands)
            .addFunction("GetCommands", &PluginCommands::GetCommands)
        .endClass();

        if(state->GetKind() == ContextKinds::Lua) state->RunCode("commands = Commands(GetCurrentPluginName())");  
        else if(state->GetKind() == ContextKinds::JavaScript) state->RunCode("globalThis.commands = Commands(GetCurrentPluginName())");
    }
)