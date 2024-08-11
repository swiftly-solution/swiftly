#include "CallStack.h"
#include "RegisterCallStack.h"

RegisterCallStack::RegisterCallStack(std::string plugin_name, std::string stack_msg)
{
    this->plugin_name = plugin_name;
    this->id = g_callStack->RegisterPluginCallstack(plugin_name, stack_msg);
}
RegisterCallStack::~RegisterCallStack()
{
    g_callStack->UnregisterPluginCallstack(plugin_name, this->id);
}