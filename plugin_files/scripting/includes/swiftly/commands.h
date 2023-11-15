#ifndef _swiftly_commands_h
#define _swiftly_commands_h

#include "swiftly_memory.h"
#include "types.h"
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
        void *commnads_RegisterCommand = FetchFunctionPtr(nullptr, "scripting_Commands_RegisterCommand");
        if (commnads_RegisterCommand)
            reinterpret_cast<Commands_RegisterCommand>(commnads_RegisterCommand)(m_pluginName.c_str(), name, func);
    }

    void UnregisterCommand(const char *name)
    {
        void *commnads_UnregisterCommand = FetchFunctionPtr(nullptr, "scripting_Commands_UnregisterCommand");
        if (commnads_UnregisterCommand)
            reinterpret_cast<Commands_UnregisterCommand>(commnads_UnregisterCommand)(name);
    }
};

extern Commands *commands;

#endif