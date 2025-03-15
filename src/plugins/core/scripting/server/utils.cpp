#include "../../scripting.h"
#include "../../../PluginManager.h"
#include "../../../../network/usermessages/usermessages.h"
#include "../../../../utils/utils.h"

#include <list>
#include <functional>

std::list<std::pair<int64_t, std::function<void()>>> timeoutsArray;

bool scripting_IsWindows()
{
    return WIN_LINUX(true, false);
}

bool scripting_IsLinux()
{
    return WIN_LINUX(false, true);
}

std::string scripting_GetOS()
{
    return WIN_LINUX("Windows", "Linux");
}

SDKBaseClass scripting_GetCCSGameRules()
{
    SDKBaseClass val(gameRules, "CCSGameRules");
    return val;
}

std::string scripting_GetPluginPath(std::string plugin_name)
{
    Plugin* plugin = g_pluginManager->FetchPlugin(plugin_name);
    if (!plugin) return "";

    return string_format("%s/%s", g_pluginManager->GetPluginBasePath(plugin_name).c_str(), plugin->GetName().c_str());
}

PluginUserMessage scripting_GetUserMessage(std::string str)
{
    auto exploded = explode(str, "|");
    if (exploded.size() == 1) {
        google::protobuf::Message* msg = (google::protobuf::Message*)(strtol(exploded[0].c_str(), nullptr, 16));
        return PluginUserMessage(msg);
    }
    else if (exploded.size() == 3) {
        INetworkMessageInternal* msg = (INetworkMessageInternal*)(strtol(exploded[0].c_str(), nullptr, 16));
        CNetMessage* netmsg = (CNetMessage*)(strtol(exploded[1].c_str(), nullptr, 16));
        uint64* clients = (uint64*)(strtol(exploded[2].c_str(), nullptr, 16));
        return PluginUserMessage(msg, netmsg, clients);
    }
    else return PluginUserMessage("");
}

std::string scripting_CreateTextTable(std::vector<std::vector<std::string>> data)
{
    TextTable tbl('-', '|', '+');

    for (auto vec : data) {
        for (std::string str : vec) {
            tbl.add(" " + str + " ");
        }

        tbl.endOfRow();
    }

    std::stringstream outputTable;
    outputTable << tbl;
    return outputTable.str();
}

int scripting_GetPluginState(std::string plugin_name)
{
    if (!g_pluginManager->PluginExists(plugin_name)) return (int)PluginState_t::Stopped;
    Plugin* plugin = g_pluginManager->FetchPlugin(plugin_name);
    if (!plugin) return (int)PluginState_t::Stopped;

    return (int)plugin->GetPluginState();
}

void RegisterTimeout(int64_t delay, std::function<void()> cb)
{
    timeoutsArray.push_back({ GetTime() + delay, cb });
}

void ProcessTimeouts(uint64_t t)
{
    std::list<std::list<std::pair<int64_t, std::function<void()>>>::iterator> queueRemoveTimeouts;

    for (auto it = timeoutsArray.begin(); it != timeoutsArray.end(); ++it) {
        if (it->first <= t) {
            queueRemoveTimeouts.push_back(it);
            it->second();
        }
    }

    for (auto it = queueRemoveTimeouts.rbegin(); it != queueRemoveTimeouts.rend(); ++it)
        timeoutsArray.erase(*it);
}

uint64_t RegisterCallstack(std::string plugin_name, std::string stackmsg)
{
    return g_callStack->RegisterPluginCallstack(plugin_name, stackmsg);
}

void UnregisterCallstack(std::string plugin_name, uint64_t stackid)
{
    g_callStack->UnregisterPluginCallstack(plugin_name, stackid);
}