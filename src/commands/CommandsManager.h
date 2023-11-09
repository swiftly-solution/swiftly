#ifndef _commandsmanager_h
#define _commandsmanager_h

#include <map>
#include <string>
#include "Command.h"

class CBasePlayerController;

class CommandsManager
{
private:
    std::map<std::string, Command *> commands;

public:
    CommandsManager() {}
    ~CommandsManager() {}

    int HandleCommands(CBasePlayerController *controller, std::string text);
    Command *FetchCommand(std::string cmd);
    bool RegisterCommand(std::string cmd, Command *command);
    bool UnregisterCommand(std::string cmd);
};

extern CommandsManager *g_commandsManager;

#endif