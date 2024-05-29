#include "Command.h"

#include "../plugins/PluginManager.h"

void Command::Execute(int slot, std::vector<std::string> args, bool silent)
{
    if (this->m_funcPtr == nullptr)
        return;

    Plugin *plugin = g_pluginManager->FetchPlugin(this->m_pluginName);
    if (!plugin)
        return;

    plugin->ExecuteCommand(this->m_funcPtr, this->m_commandName, slot, args, silent);
}

std::string Command::GetPluginName() { return this->m_pluginName; }