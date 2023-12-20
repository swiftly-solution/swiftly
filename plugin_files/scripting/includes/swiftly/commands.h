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
        void *commnads_RegisterCommand = FetchFunctionPtr(nullptr, "scripting_Commands_RegisterCommand");
        if (commnads_RegisterCommand)
            reinterpret_cast<Commands_RegisterCommand>(commnads_RegisterCommand)(m_pluginName.c_str(), name, func);
        else
            NOT_SUPPORTED("scripting_Commands_RegisterCommand");
    }

    void UnregisterCommand(const char *name)
    {
        void *commnads_UnregisterCommand = FetchFunctionPtr(nullptr, "scripting_Commands_UnregisterCommand");
        if (commnads_UnregisterCommand)
            reinterpret_cast<Commands_UnregisterCommand>(commnads_UnregisterCommand)(name);
        else
            NOT_SUPPORTED("scripting_Commands_UnregisterCommand");
    }
};

extern Commands *commands;

#endif