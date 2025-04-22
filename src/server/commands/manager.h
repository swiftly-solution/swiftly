#ifndef _server_commands_h
#define _server_commands_h

#include <map>
#include <string>
#include <vector>
#include <set>

#include "command.h"
#include <core/entrypoint.h>

std::string GenerateCommandDefaultPrefix();

class CommandsManager
{
private:
    std::map<std::string, Command *> commands;
    std::map<std::string, std::vector<std::string>> commandAliases;
    std::map<std::string, std::vector<std::string>> commandsByPlugin;

public:
    void Initialize();
    void Shutdown();

    int HandleCommand(int playerid, std::string text);

    Command* FetchCommand(std::string cmd_name);
    void RegisterCommand(std::string plugin_name, std::string cmd, Command *command, bool registerRaw = false);
    void UnregisterCommand(std::string cmd);

    std::vector<std::string> FetchCommandsByPlugin(std::string plugin_name);
    std::map<std::string, Command *> GetCommands();

    void DispatchConCommand(ConCommandRef cmd, const CCommandContext& ctx, const CCommand& args);
};

extern CommandsManager g_commandsManager;

#endif