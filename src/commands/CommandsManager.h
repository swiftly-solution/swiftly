#ifndef _commandsmanager_h
#define _commandsmanager_h

#include <map>
#include <string>
#include "Command.h"
#include <luacpp/luacpp.h>

class CBasePlayerController;

class CommandsManager
{
private:
    std::map<std::string, Command *> commands;
    std::map<std::string, std::vector<std::string>> commandsByPlugin;

public:
    std::map<std::string, luacpp::LuaFunction> commandsLuaReference;

    CommandsManager() {}
    ~CommandsManager() {}

    int HandleCommands(CBasePlayerController *controller, std::string text);
    Command *FetchCommand(std::string cmd);
    bool RegisterCommand(std::string plugin_name, std::string cmd, Command *command);
    bool UnregisterCommand(std::string cmd);
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

#endif