#ifndef _swiftly_commands_h
#define _swiftly_commands_h

#include "swiftly_memory.h"
#include "types.h"
#include "swiftly_utils.h"
#include "swiftly.h"
#include <vector>
#include <map>

class Commands
{
private:
    std::map<std::string, void *> cmds;
    std::string m_pluginName;

public:
    Commands(std::string pluginName) : m_pluginName(pluginName) {}
    void Register(const char *name, void *func)
    {
        REGISTER_METHOD_VOID(scripting_Commands_RegisterCommand, name, func);
    }

    void UnregisterCommand(const char *name)
    {
        REGISTER_METHOD_VOID(scripting_Commands_UnregisterCommand, name);
    }
};

extern Commands *commands;

#endif