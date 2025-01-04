#include "CallStack.h"
#include "../../utils/utils.h"
#include <swiftly-ext/core.h>

uint64_t stackID = 0;

uint64_t CallStack::RegisterPluginCallstack(std::string plugin_name, std::string stackMsg)
{
    ++stackID;
    if (stackID % 2000000000 == 0)
        stackID = 1;

    callStacks[plugin_name].insert_or_assign(stackID, stackMsg);
    fprintf(stdout, "%s\n", stackMsg.c_str());
    return stackID;
}

void CallStack::UnregisterPluginCallstack(std::string plugin_name, uint64_t stackID)
{
    if (callStacks[plugin_name].find(stackID) == callStacks[plugin_name].end()) return;

    callStacks[plugin_name].erase(stackID);
}

std::unordered_map<uint64_t, std::string> CallStack::GetPluginCallstack(std::string plugin_name)
{
    return callStacks[plugin_name];
}

EXT_API uint64_t swiftly_RegisterCallstack(const char* plugin_name, const char* stackmsg)
{
    return g_callStack->RegisterPluginCallstack(plugin_name, stackmsg);
}

EXT_API void swiftly_UnregisterCallstack(const char* plugin_name, uint64_t stid)
{
    g_callStack->UnregisterPluginCallstack(plugin_name, stid);
}