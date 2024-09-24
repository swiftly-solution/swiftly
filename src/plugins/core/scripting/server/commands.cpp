#include "../../scripting.h"
#include "../../../../server/commands/CommandsManager.h"

PluginCommands::PluginCommands(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginCommands::RegisterCommand(std::string commandName, void* callback)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginCommands::RegisterCommand(commandName=\"%s\",callback=%p)", commandName.c_str(), (void*)callback));

    if (g_commandsManager->FetchCommand(commandName))
        return;

    Command* command = new Command(this->plugin_name, callback, commandName);
    g_commandsManager->RegisterCommand(this->plugin_name, commandName, command);
}

void PluginCommands::UnregisterCommand(std::string commandName)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginCommands::UnregisterCommand(commandName=\"%s\")", commandName.c_str()));
    g_commandsManager->UnregisterCommand(commandName);
}

void PluginCommands::RegisterAlias(std::string commandName, std::string aliasName)
{

    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginCommands::RegisterAlias(commandName=\"%s\",aliasName=\"%s\")", commandName.c_str(), aliasName.c_str()));

    Command* command = g_commandsManager->FetchCommand(commandName);
    if (!command)
        return;

    g_commandsManager->RegisterCommand(command->GetPluginName(), aliasName, command);
}

void PluginCommands::RegisterRawAlias(std::string commandName, std::string aliasName)
{

    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginCommands::RegisterRawAlias(commandName=\"%s\",aliasName=\"%s\")", commandName.c_str(), aliasName.c_str()));

    Command* command = g_commandsManager->FetchCommand(commandName);
    if (!command)
        return;

    g_commandsManager->RegisterCommand(command->GetPluginName(), aliasName, command, true);
}

void PluginCommands::UnregisterAlias(std::string aliasName)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginCommands::RegisterRawAlias(aliasName=\"%s\")", aliasName.c_str()));

    UnregisterCommand(aliasName);
}

void PluginCommands::RegisterCommandLua(std::string commandName, luabridge::LuaRef callback)
{
    if (!callback.isFunction())
        return;

    RegisterCommand(commandName, new luabridge::LuaRef(callback));
}

/*
    std::map<std::string, Command *> GetCommands()
    {
        return this->commands;
    };
*/

std::vector<std::string> PluginCommands::GetAllCommands()
{
    std::vector<std::string> cmdsList;

    auto cmds = g_commandsManager->GetCommands();
    for(auto it = cmds.begin(); it != cmds.end(); ++it)
        cmdsList.push_back(it->first);

    return cmdsList;
}

std::vector<std::string> PluginCommands::GetCommands()
{
    return g_commandsManager->FetchCommandsByPlugin(this->plugin_name);
}