#ifndef _commands_h
#define _commands_h

#include "../player/Player.h"

class Command
{
private:
    void *m_funcPtr = nullptr;

public:
    std::string m_pluginName;
    Command(std::string pluginName, void *funcPtr) : m_pluginName(pluginName), m_funcPtr(funcPtr) {}
    void Exec(int slot, std::vector<std::string> args, bool silent);
};

#endif