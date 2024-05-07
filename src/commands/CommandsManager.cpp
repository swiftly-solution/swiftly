#include "CommandsManager.h"
#include "../player/PlayerManager.h"
#include "../configuration/Configuration.h"

std::map<std::string, bool> existed;

// @returns 1 - command is not silent
// @returns 2 - command is silent
// @returns -1 - invalid controller
// @returns 0 - is not command
int CommandsManager::HandleCommands(CBasePlayerController *controller, std::string text)
{
    if (text == "" || text.size() == 0)
        return -1;

    CPlayerSlot sl = g_playerManager->GetSlotFromUserId(controller->GetRefEHandle().GetEntryIndex() - 1);
    CPlayerSlot *slot = &sl;
    if (slot == nullptr)
        return -1;
    Player *player = g_playerManager->GetPlayer(slot);
    if (player == nullptr)
        return -1;

    std::vector<std::string> commandPrefixes = explode(g_Config->FetchValue<std::string>("core.commandPrefixes"), " ");
    std::vector<std::string> silentCommandPrefixes = explode(g_Config->FetchValue<std::string>("core.silentCommandPrefixes"), " ");
    bool isCommand = (std::find(commandPrefixes.begin(), commandPrefixes.end(), std::string(1, text.at(0))) != commandPrefixes.end());
    bool isSilentCommand = (std::find(silentCommandPrefixes.begin(), silentCommandPrefixes.end(), std::string(1, text.at(0))) != silentCommandPrefixes.end());
    if (isCommand || isSilentCommand)
    {
        CCommand tokenizedArgs;
        tokenizedArgs.Tokenize(text.c_str());

        std::vector<std::string> cmdString;
        for (int i = 1; i < tokenizedArgs.ArgC(); i++)
            cmdString.push_back(tokenizedArgs[i]);

        std::string commandName = tokenizedArgs[0];
        commandName.erase(0, 1);

        Command *cmd = g_commandsManager->FetchCommand(commandName);
        if (cmd == nullptr)
            return 0;

        cmd->Exec(player->GetSlot()->Get(), cmdString, isSilentCommand);
    }

    if (isCommand)
        return 1;
    else if (isSilentCommand)
        return 2;
    else
        return 0;
}

Command *CommandsManager::FetchCommand(std::string cmd)
{
    if (this->commands.find(cmd) == this->commands.end())
        return nullptr;

    return this->commands.at(cmd);
}

static void commandsCallback(const CCommandContext &context, const CCommand &args);

bool CommandsManager::RegisterCommand(std::string plugin_name, std::string cmd, Command *command)
{
    if (this->FetchCommand(cmd) != nullptr)
        return false;

    this->commands.insert(std::make_pair(cmd, command));

    if (this->commandsByPlugin.find(plugin_name) == this->commandsByPlugin.end())
    {
        std::vector<std::string> cmds;
        cmds.push_back(cmd);
        this->commandsByPlugin.insert(std::make_pair(plugin_name, cmds));
    }
    else
        this->commandsByPlugin[plugin_name].push_back(cmd);

    if (existed.find(cmd) == existed.end())
    {
        ConCommandRefAbstract commandRef;
        auto conCommand = new ConCommand(&commandRef, ("sw_" + cmd).c_str(), commandsCallback, "The main command for Swiftly.", (1 << 25) | (1 << 0) | (1 << 24));

        existed.insert(std::make_pair(cmd, true));
    }

    return true;
}

static void commandsCallback(const CCommandContext &context, const CCommand &args)
{
    CCommand tokenizedArgs;
    tokenizedArgs.Tokenize(args.GetCommandString());

    std::string cmdName = (tokenizedArgs[0] + 3);
    std::vector<std::string> argsplit;
    for (int i = 1; i < tokenizedArgs.ArgC(); i++)
        argsplit.push_back(tokenizedArgs[i]);

    if (g_commandsManager->FetchCommand(cmdName) == nullptr)
        return;

    Command *cmd = g_commandsManager->FetchCommand(cmdName);
    if (cmd == nullptr)
        return;

    cmd->Exec(context.GetPlayerSlot().Get(), argsplit, true);
}

bool CommandsManager::UnregisterCommand(std::string cmd)
{
    Command *command = this->FetchCommand(cmd);
    if (command == nullptr)
        return false;

    this->commandsByPlugin[command->GetPluginName()].erase(std::find(this->commandsByPlugin[command->GetPluginName()].begin(), this->commandsByPlugin[command->GetPluginName()].end(), cmd));
    delete command;
    this->commands.erase(cmd);
    if (this->commandsLuaReference.find(cmd) != this->commandsLuaReference.end())
        this->commandsLuaReference.erase(cmd);
    return true;
}