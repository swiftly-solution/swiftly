#include "CommandsManager.h"
#include "../hooks/GameEvents.h"
#include "../player/PlayerManager.h"
#include "../configuration/Configuration.h"

// @returns 1 - command is not silent
// @returns 2 - command is silent
// @returns -1 - invalid controller
// @returns 0 - is not command
int CommandsManager::HandleCommands(CBasePlayerController *controller, std::string text)
{
    CPlayerSlot *slot = &g_playerManager->GetSlotFromUserId(controller->GetRefEHandle().GetEntryIndex() - 1);
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
        std::vector<std::string> cmdString = explode(text, " ");
        std::string commandName = cmdString[0];
        cmdString.erase(cmdString.begin());
        commandName.erase(0, 1);

        Command *cmd = g_commandsManager->FetchCommand(commandName);
        if (cmd == nullptr)
            return 0;

        cmd->Exec(player, cmdString, isSilentCommand);
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

    return true;
}

bool CommandsManager::UnregisterCommand(std::string cmd)
{
    Command *command = this->FetchCommand(cmd);
    if (command == nullptr)
        return false;

    this->commandsByPlugin[command->m_pluginName].erase(std::find(this->commandsByPlugin[command->m_pluginName].begin(), this->commandsByPlugin[command->m_pluginName].end(), cmd));
    this->commands.erase(cmd);
    return true;
}