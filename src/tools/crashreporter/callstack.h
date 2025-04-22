#ifndef _tools_crashreporter_callstack_h
#define _tools_crashreporter_callstack_h

#include <map>
#include <string>
#include <unordered_map>

class CallStackManager
{
private:
    std::map<std::string, std::unordered_map<uint64_t, std::string>> callStacks;
public:
    uint64_t RegisterPluginCallstack(std::string plugin_name, std::string stackMsg);
    void UnregisterPluginCallstack(std::string plugin_name, uint64_t stackID);

    std::unordered_map<uint64_t, std::string> GetPluginCallstack(std::string plugin_name);
};

extern CallStackManager g_callStack;

#endif