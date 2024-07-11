#include "../scripting.h"
#include "../../../commands/CommandsManager.h"

PluginCommands::PluginCommands(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginCommands::RegisterCommand(std::string commandName, void *callback)
{
    if (g_commandsManager->FetchCommand(commandName))
        return;

    Command *command = new Command(this->plugin_name, callback, commandName);
    g_commandsManager->RegisterCommand(this->plugin_name, commandName, command);
}

void PluginCommands::UnregisterCommand(std::string commandName)
{
    g_commandsManager->UnregisterCommand(commandName);
}

void PluginCommands::RegisterAlias(std::string commandName, std::string aliasName)
{
    Command *command = g_commandsManager->FetchCommand(commandName);
    if (!command)
        return;

    g_commandsManager->RegisterCommand(command->GetPluginName(), aliasName, command);
}

void PluginCommands::UnregisterAlias(std::string aliasName)
{
    UnregisterCommand(aliasName);
}

void PluginCommands::RegisterCommandLua(std::string commandName, luabridge::LuaRef callback)
{
    if (!callback.isFunction())
        return;

    RegisterCommand(commandName, new luabridge::LuaRef(callback));
}