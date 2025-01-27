#include "CommandsManager.h"

#include "../configuration/Configuration.h"

CommandsManager::CommandsManager() {}
CommandsManager::~CommandsManager() {}

static void commandsCallback(const CCommandContext& context, const CCommand& args);
std::set<std::string> conCommandCreated;

std::set<std::string> commandPrefixes;
std::set<std::string> silentCommandPrefixes;

// @returns 1 - command is not silent
// @returns 2 - command is silent
// @returns -1 - invalid controller
// @returns 0 - is not command
int CommandsManager::HandleCommand(Player* player, std::string text)
{
    if (text == "" || text.size() == 0)
        return -1;

    if (player == nullptr)
        return -1;

    if (commandPrefixes.size() == 0) commandPrefixes = explodeToSet(g_Config->FetchValue<std::string>("core.commandPrefixes"), " ");
    if (silentCommandPrefixes.size() == 0) silentCommandPrefixes = explodeToSet(g_Config->FetchValue<std::string>("core.commandSilentPrefixes"), " ");

    bool isCommand = false;
    bool isSilentCommand = false;
    std::string selectedPrefix = "";

    for(auto it = commandPrefixes.begin(); it != commandPrefixes.end(); ++it) {
        std::string prefix = *it;
        auto strPrefix = text.substr(0, prefix.size());

        if(prefix == strPrefix) {
            isCommand = true;
            selectedPrefix = prefix;
            break;
        }
    }

    if(!isCommand) {
        for(auto it = silentCommandPrefixes.begin(); it != silentCommandPrefixes.end(); ++it) {
            std::string prefix = *it;
            auto strPrefix = text.substr(0, prefix.size());
    
            if(prefix == strPrefix) {
                isSilentCommand = true;
                selectedPrefix = prefix;
                break;
            }
        }
    }

    if (isCommand || isSilentCommand)
    {
        CCommand tokenizedArgs;
        tokenizedArgs.Tokenize(text.c_str());

        std::vector<std::string> cmdString = TokenizeCommand(text);
        cmdString.erase(cmdString.begin());

        if (tokenizedArgs.ArgC() < 1)
            return 0;

        std::string commandName = tokenizedArgs[0];
        if (commandName.size() < 1)
            return 0;

        commandName.erase(0, 1);

        Command* cmd = g_commandsManager->FetchCommand(commandName);
        if (cmd == nullptr)
            return 0;

        try {
            cmd->Execute(player->GetSlot().Get(), cmdString, isSilentCommand, selectedPrefix);
        }
        catch (std::exception& e) {
            PLUGIN_PRINTF("Commands Manager", "An error has occured while trying to execute command '%s'.\n", commandName.c_str());
            PLUGIN_PRINTF("Commands Manager", "%s\n", e.what());
        }
    }

    if (isCommand)
        return 1;
    else if (isSilentCommand)
        return 2;
    else
        return 0;
}

Command* CommandsManager::FetchCommand(std::string cmd)
{
    if (this->commands.find(cmd) == this->commands.end()) return nullptr;

    return this->commands[cmd];
}

void CommandsManager::RegisterCommand(std::string plugin_name, std::string cmd, Command* command, bool registerRaw)
{
    if (!registerRaw)
    {
        if (this->commands.find(cmd) != this->commands.end())
            return;

        this->commands.insert({ cmd, command });
        this->commandAliases.insert({ cmd, {} });

        if (this->commandsByPlugin.find(plugin_name) == this->commandsByPlugin.end())
            this->commandsByPlugin.insert({ plugin_name, {} });

        this->commandsByPlugin[plugin_name].push_back(cmd);
    }

    if (!registerRaw)
        cmd = "sw_" + cmd;

    if (conCommandCreated.find(cmd) == conCommandCreated.end())
    {
        conCommandCreated.insert(cmd);

        ConCommandRefAbstract commandRef;
        new ConCommand(&commandRef, cmd.c_str(), commandsCallback, "Swiftly Command", (1 << 25) | (1 << 0) | (1 << 24));
    }
}

void CommandsManager::UnregisterCommand(std::string cmd)
{
    if (this->commands.find(cmd) == this->commands.end())
        return;

    Command* command = FetchCommand(cmd);
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

static void commandsCallback(const CCommandContext& context, const CCommand& args)
{
    CCommand tokenizedArgs;
    tokenizedArgs.Tokenize(args.GetCommandString());

    std::string commandName = (starts_with(tokenizedArgs[0], "sw_") ? (tokenizedArgs[0] + 3) : tokenizedArgs[0]);

    std::vector<std::string> argsplit = TokenizeCommand(args.GetCommandString());
    argsplit.erase(argsplit.begin());

    if (g_commandsManager->FetchCommand(commandName) == nullptr)
        return;

    Command* command = g_commandsManager->FetchCommand(commandName);
    if (!command)
        return;

    command->Execute(context.GetPlayerSlot().Get(), argsplit, true, "sw_");
}