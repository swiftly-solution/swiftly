#ifndef _commands_h
#define _commands_h

#include "../player/Player.h"

class Command
{
public:
    Command(std::string pluginName, void *funcPtr) : m_pluginName(pluginName), m_funcPtr(funcPtr) {}
    void Exec(int slot, std::vector<std::string> args, bool silent);
    std::string GetPluginName() { return this->m_pluginName; }

private:
    void *m_funcPtr = nullptr;
    std::string m_pluginName;
};

#endif