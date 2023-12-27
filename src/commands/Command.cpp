#include "Command.h"
#include "../common.h"
#include "../components/Plugins/inc/Plugin.h"

#include "CommandsManager.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

typedef void (*Command_Main)(int, const char **, uint32, bool);

void Command::Exec(int slot, std::vector<std::string> args, bool silent)
{
    if (this->m_funcPtr == nullptr)
        return;

    const char *toSendArgs[512] = {};
    for (uint32_t i = 0; i < args.size(); i++)
        toSendArgs[i] = args[i].c_str();

    if (g_commandsManager->commandsLuaReference.find(this->name) != g_commandsManager->commandsLuaReference.end())
    {
        if (ExistsPluginInMap(this->m_pluginName))
        {
            Plugin *plugin = FetchPluginFromMap(this->m_pluginName);
            if (plugin->IsPluginLoaded())
            {
                auto table = plugin->GetLuaState()->CreateTable();
                for (uint32_t i = 0; i < args.size(); i++)
                    table.SetString(i + 1, args[i].c_str());

                std::string errstr;
                if (!g_commandsManager->commandsLuaReference.at(name).Execute(nullptr, &errstr, slot, table, args.size(), silent))
                    PRINTF("Runtime", "An error has occured while calling command '%s'.\nError: %s\n", this->name.c_str(), errstr.c_str());
            }
        }
    }
    else
        reinterpret_cast<Command_Main>(this->m_funcPtr)(slot, reinterpret_cast<const char **>(toSendArgs), args.size(), silent);
}