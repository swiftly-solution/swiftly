#include "command.h"

#include <utils/common.h>
#include <plugins/manager.h>
#include <tools/crashreporter/callstack.h>
#include <tools/resourcemonitor/monitor.h>
#include <utils/utils.h>

Command::Command(std::string plugin_name, EValue* functionPtr, std::string name)
{
    m_funcPtr = functionPtr;
    m_pluginName = plugin_name;
    m_commandName = name;
}

Command::~Command()
{
    auto plugin = g_pluginManager.FetchPlugin(m_pluginName);
    if (!plugin) return;

    delete m_funcPtr;
}

void Command::Execute(int slot, std::vector<std::string> args, bool silent, std::string prefix)
{
    if (!m_funcPtr) return;

    if (!m_funcPtr->isFunction()) return;

    uint64_t stackid = g_callStack.RegisterPluginCallstack(m_pluginName, string_format("Command::Execute(command_name=\"%s\",slot=%d,args=\"%s\",silent=%d,prefix=\"%s\")", m_commandName.c_str(), slot, implode(args, " ").c_str(), silent, prefix.c_str()));
    std::string cmdResmon = "command:" + m_commandName;
    g_ResourceMonitor.StartTime(m_pluginName, cmdResmon);

    try {
        EValue command = *m_funcPtr;
        int argc = args.size();
        command(slot, args, argc, silent, prefix);
    }
    catch (EException& e) {
        PRINTF("An error has occured while executing command '%s'.\n", m_commandName.c_str());
        PRINTF("%s\n", e.what());
    }
    g_ResourceMonitor.StopTime(m_pluginName, cmdResmon);
    g_callStack.UnregisterPluginCallstack(m_pluginName, stackid);
}

std::string Command::GetPluginName()
{
    return m_pluginName;
}