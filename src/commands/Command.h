#ifndef _commands_h
#define _commands_h

#include "../player/Player.h"

class Command
{
public:
    Command(std::string pluginName, void *funcPtr, std::string name)
    {
        this->m_pluginName = pluginName;
        this->m_funcPtr = funcPtr;
        this->name = name;
    }
    void Exec(int slot, std::vector<std::string> args, bool silent);
    std::string GetPluginName() { return this->m_pluginName; }

private:
    void *m_funcPtr = nullptr;
    std::string m_pluginName;
    std::string name;
};

#endif