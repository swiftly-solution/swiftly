#ifndef _callstack_h
#define _callstack_h

#include <string>
#include <map>
#include <unordered_map>
#include "RegisterCallStack.h"

#define REGISTER_CALLSTACK(plugin_name, stack_str) RegisterCallStack OUIERGBNHI9U43HBG98734VHBW9(plugin_name, stack_str)

class CallStack
{
private:
    std::map<std::string, std::unordered_map<std::string, std::string>> callStacks;
public:
    CallStack() = default;

    std::string RegisterPluginCallstack(std::string plugin_name, std::string stackMsg);
    void UnregisterPluginCallstack(std::string plugin_name, std::string stackID);

    std::unordered_map<std::string, std::string> GetPluginCallstack(std::string plugin_name);
};

extern CallStack* g_callStack;

#endif