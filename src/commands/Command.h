#pragma once

#include <string>
#include <vector>

class Command
{
public:
    Command(std::string plugin_name, void *functionPtr, std::string name)
    {
        this->m_funcPtr = functionPtr;
        this->m_pluginName = plugin_name;
        this->m_commandName = name;
    }

    ~Command();

    void Execute(int slot, std::vector<std::string> args, bool silent);
    std::string GetPluginName();

private:
    void *m_funcPtr = nullptr;
    std::string m_pluginName;
    std::string m_commandName;
};