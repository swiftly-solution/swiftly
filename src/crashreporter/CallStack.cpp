#include "CallStack.h"
#include "../utils/utils.h"

uint64_t stackID = 0;

uint64_t CallStack::RegisterPluginCallstack(std::string plugin_name, std::string stackMsg)
{
    if (callStacks.find(plugin_name) == callStacks.end())
        callStacks.insert({ plugin_name, {} });

    ++stackID;
    if (stackID % 2000000000 == 0)
        stackID = 0;

    callStacks[plugin_name].insert_or_assign(stackID, stackMsg);
    return stackID;
}

void CallStack::UnregisterPluginCallstack(std::string plugin_name, uint64_t stackID)
{
    if (callStacks.find(plugin_name) == callStacks.end()) return;
    if (callStacks[plugin_name].find(stackID) == callStacks[plugin_name].end()) return;

    callStacks[plugin_name].erase(stackID);
}

std::unordered_map<uint64_t, std::string> CallStack::GetPluginCallstack(std::string plugin_name)
{
    if (callStacks.find(plugin_name) == callStacks.end()) return {};

    return callStacks[plugin_name];
}