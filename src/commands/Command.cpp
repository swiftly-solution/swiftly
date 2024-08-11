#include "Command.h"

#include "../crashreporter/CallStack.h"
#include "../plugins/PluginManager.h"

Command::~Command()
{
    Plugin* plugin = g_pluginManager->FetchPlugin(this->m_pluginName);
    if (!plugin)
        return;

    if (plugin->GetKind() == PluginKind_t::Lua)
    {
        delete this->m_funcPtr;
    }
}

void Command::Execute(int slot, std::vector<std::string> args, bool silent, std::string prefix)
{
    REGISTER_CALLSTACK(this->m_pluginName, string_format("Command::Execute(command_name=\"%s\",slot=%d,args=\"%s\",silent=%d,prefix=\"%s\")", this->m_commandName.c_str(), slot, implode(args, " ").c_str(), silent, prefix.c_str()));
    if (this->m_funcPtr == nullptr)
        return;

    Plugin* plugin = g_pluginManager->FetchPlugin(this->m_pluginName);
    if (!plugin)
        return;

    plugin->ExecuteCommand(this->m_funcPtr, this->m_commandName, slot, args, silent, prefix);
}

std::string Command::GetPluginName() { return this->m_pluginName; }