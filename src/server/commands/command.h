#ifndef _server_commands_command_h
#define _server_commands_command_h

#include <embedder/src/Embedder.h>
#include <vector>
#include <string>

class Command
{
private:
    EValue* m_funcPtr;
    std::string m_pluginName;
    std::string m_commandName;
public:
    Command(std::string plugin_name, EValue* functionPtr, std::string name);
    ~Command();

    void Execute(int slot, std::vector<std::string> args, bool silent, std::string prefix);
    std::string GetPluginName();
};

#endif