#include "CommandsManager.h"

CommandsManager::CommandsManager() {}
CommandsManager::~CommandsManager() {}

static void commandsCallback(const CCommandContext &context, const CCommand &args);
std::map<std::string, bool> conCommandCreated;

Command *CommandsManager::FetchCommand(std::string cmd)
{
    if (this->commands.find(cmd) == this->commands.end())
        return nullptr;

    return this->commands.at(cmd);
}

void CommandsManager::RegisterCommand(std::string plugin_name, std::string cmd, Command *command)
{
    if (this->commands.find(cmd) != this->commands.end())
        return;

    this->commands.insert({cmd, command});
    this->commandAliases.insert({cmd, {}});

    if (this->commandsByPlugin.find(plugin_name) == this->commandsByPlugin.end())
        this->commandsByPlugin.insert({plugin_name, {}});

    this->commandsByPlugin[plugin_name].push_back(cmd);

    if (conCommandCreated.find(cmd) == conCommandCreated.end())
    {
        conCommandCreated.insert({cmd, true});

        ConCommandRefAbstract commandRef;
        new ConCommand(&commandRef, ("sw_" + cmd).c_str(), commandsCallback, "Swiftly Command", (1 << 25) | (1 << 0) | (1 << 24));
    }
}

void CommandsManager::UnregisterCommand(std::string cmd)
{
    if (this->commands.find(cmd) == this->commands.end())
        return;

    Command *command = FetchCommand(cmd);
    std::string plugin = command->GetPluginName();

    delete command;
    this->commands.erase(cmd);

    std::vector<std::string> aliases = this->commandAliases.at(cmd);
    for (std::string alias : aliases)
        UnregisterCommand(alias);

    this->commandAliases.erase(cmd);

    auto cmdIterator = std::find(this->commandsByPlugin[plugin].begin(), this->commandsByPlugin[plugin].end(), cmd);
    if (cmdIterator != this->commandsByPlugin[plugin].end())
        this->commandsByPlugin[plugin].erase(cmdIterator);
}

static void commandsCallback(const CCommandContext &context, const CCommand &args)
{
    CCommand tokenizedArgs;
    tokenizedArgs.Tokenize(args.GetCommandString());

    std::string commandName = (tokenizedArgs[0] + 3);

    std::vector<std::string> argsplit;
    for (int i = 1; i < tokenizedArgs.ArgC(); i++)
        argsplit.push_back(tokenizedArgs[i]);

    if (g_commandsManager->FetchCommand(commandName) == nullptr)
        return;

    Command *command = g_commandsManager->FetchCommand(commandName);
    if (!command)
        return;

    command->Execute(context.GetPlayerSlot().Get(), argsplit, true);
}