#pragma once

#include <map>
#include <string>
#include <vector>
#include <algorithm>

#include "Command.h"
#include "../entrypoint.h"
#include "../player/Player.h"

class CommandsManager
{
private:
    std::map<std::string, Command *> commands;
    std::map<std::string, std::vector<std::string>> commandAliases;
    std::map<std::string, std::vector<std::string>> commandsByPlugin;

public:
    CommandsManager();
    ~CommandsManager();

    int HandleCommand(Player *player, std::string text);

    Command *FetchCommand(std::string cmd);
    void RegisterCommand(std::string plugin_name, std::string cmd, Command *command);
    void UnregisterCommand(std::string cmd);

    std::vector<std::string> FetchCommandsByPlugin(std::string plugin_name)
    {
        if (this->commandsByPlugin.find(plugin_name) == this->commandsByPlugin.end())
            return {};
        return this->commandsByPlugin.at(plugin_name);
    }

    std::map<std::string, Command *> GetCommands()
    {
        return this->commands;
    };
};

extern CommandsManager *g_commandsManager;