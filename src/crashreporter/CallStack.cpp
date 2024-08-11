#include "CallStack.h"
#include "../utils/utils.h"

std::string CallStack::RegisterPluginCallstack(std::string plugin_name, std::string stackMsg)
{
    std::string stackID = get_uuid();
    if (callStacks.find(plugin_name) == callStacks.end())
        callStacks.insert({ plugin_name, {} });

    while (callStacks[plugin_name].find(stackID) != callStacks[plugin_name].end())
        stackID = get_uuid();

    callStacks[plugin_name].insert({ stackID, stackMsg });

    return stackID;
}
void CallStack::UnregisterPluginCallstack(std::string plugin_name, std::string stackID)
{
    if (callStacks.find(plugin_name) == callStacks.end()) return;
    if (callStacks[plugin_name].find(stackID) == callStacks[plugin_name].end()) return;

    callStacks[plugin_name].erase(stackID);
}

std::unordered_map<std::string, std::string> CallStack::GetPluginCallstack(std::string plugin_name)
{
    if (callStacks.find(plugin_name) == callStacks.end()) return {};

    return callStacks[plugin_name];
}