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
    std::map<std::string, std::unordered_map<uint64_t, std::string>> callStacks;
public:
    uint64_t RegisterPluginCallstack(std::string plugin_name, std::string stackMsg);
    void UnregisterPluginCallstack(std::string plugin_name, uint64_t stackID);

    std::unordered_map<uint64_t, std::string> GetPluginCallstack(std::string plugin_name);
};

extern CallStack* g_callStack;

#endif