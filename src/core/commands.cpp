#include <string>
#include <TextTable.h>

#include <tier1/convar.h>

#include "../entrypoint.h"
#include "../common.h"
#include "../addons/addons.h"
#include "../utils/utils.h"
#include "../player/PlayerManager.h"
#include "../filters/ConsoleFilter.h"
#include "../translations/Translations.h"
#include "../plugins/PluginManager.h"
#include "../resourcemonitor/ResourceMonitor.h"
#include "../commands/CommandsManager.h"

#ifndef GITHUB_SHA
#define GITHUB_SHA "LOCAL"
#endif

const char *GetCppVersion()
{
    if (__cplusplus == 202101L)
        return "C++23";
    else if (__cplusplus == 202002L)
        return "C++20";
    else if (__cplusplus == 201703L)
        return "C++17";
    else if (__cplusplus == 201402L)
        return "C++14";
    else if (__cplusplus == 201103L)
        return "C++11";
    else if (__cplusplus == 199711L)
        return "C++98";
    else
        return "Pre-standard C++";
}

std::string seconds_to_time(unsigned int number)
{
    return string_format("%02d:%02d:%02d", int(number / 3600), int((number % 3600) / 60), int((number % 3600) % 60));
}

template <typename... T>
void PrintToClientOrConsole(CPlayerSlot slot, std::string category, std::string message, T... args)
{
    if (slot.Get() == -1)
        PLUGIN_PRINTF(category, message, args...);
    else
        CLIENT_PRINTF(slot, category, message, args...);
}

void SwiftlyList(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "List", "Connected players: %02d/%02d\n", g_playerManager->GetPlayers(), engine->GetServerGlobals()->maxClients);
    uint16 idx = 0;
    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        CBasePlayerController *controller = player->GetController();
        if (!controller)
            continue;

        ++idx;
        PrintToClientOrConsole(slot, "List", "%d. %s%s (%llu)\n", idx, player->GetName(), player->IsFakeClient() ? " (BOT)" : "", controller->m_steamID());
    }
}

void SwiftlyStatus(CPlayerSlot slot, CCommandContext context)
{
    TextTable statusTable('-', '|', '+');

    statusTable.add(" playerid ");
    statusTable.add(" name ");
    statusTable.add(" steamid ");
    statusTable.add(" time ");
    statusTable.add(" state ");
    statusTable.endOfRow();

    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        CBasePlayerController *controller = player->GetController();
        if (!controller)
            continue;

        statusTable.add(string_format(" #%d ", player->GetSlot().Get()));
        statusTable.add(string_format(" %s ", player->GetName()));
        statusTable.add(string_format(" %s ", player->IsFakeClient() ? "BOT" : std::to_string(controller->m_steamID()).c_str()));
        statusTable.add(string_format(" %s ", seconds_to_time(player->GetConnectedTime()).c_str()));
        statusTable.add(string_format(" %s ", "Active"));
        statusTable.endOfRow();
    }

    auto PrintTT = [slot](std::string category, TextTable table) -> void
    {
        std::stringstream outputTable;
        outputTable << table;
        std::vector<std::string> rows = explode(outputTable.str(), "\n");
        for (int i = 0; i < rows.size() - 1; i++)
            PrintToClientOrConsole(slot, category, "%s\n", rows[i].c_str());
    };

    PrintTT("Status", statusTable);

    PrintToClientOrConsole(slot, "Status", "end of status\n");
}

void ShowSwiftlyCommands(CPlayerSlot slot, CCommandContext context, int page)
{
    std::map<std::string, Command *> cmds = g_commandsManager->GetCommands();
    PrintToClientOrConsole(slot, "Commands", "There are %d commands created by plugins.\n", cmds.size());
    PrintToClientOrConsole(slot, "Commands", "Below will be shown a list of all the commands:\n");

    if (page < 1)
        page = 1;
    else if (static_cast<unsigned int>(page) * 10 > cmds.size())
        page = int(floor(cmds.size() / 10));

    std::map<std::string, Command *>::iterator it = cmds.begin();
    for (int i = 0; i < (page - 1) * 10; i++)
        ++it;

    for (uint32 i = 0; i < 10; i++)
    {
        if (it == cmds.end())
            break;
        PrintToClientOrConsole(slot, "Commands", "sw_%s\n", it->first.c_str());
        ++it;
    }

    if (static_cast<unsigned int>(page) * 10 < cmds.size())
        PrintToClientOrConsole(slot, "Commands", "To see more please use swiftly cmds %d\n", page + 1);
}

void ShowSwiftlyCommandHelp(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Commands Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly <command> [args]\n");
    PrintToClientOrConsole(slot, "Commands", " credits      - List Swiftly credits\n");
    PrintToClientOrConsole(slot, "Commands", " help         - Show the help for Swiftly commands\n");
    PrintToClientOrConsole(slot, "Commands", " list         - Show the list of online players\n");
    PrintToClientOrConsole(slot, "Commands", " cmds         - List all console commands created by plugins\n");
    PrintToClientOrConsole(slot, "Commands", " status       - Show the status of the players\n");
    if (slot.Get() == -1)
    {
        PrintToClientOrConsole(slot, "Commands", " addons       - Addons Management Menu\n");
        PrintToClientOrConsole(slot, "Commands", " confilter    - Console Filtering Menu\n");
        PrintToClientOrConsole(slot, "Commands", " plugins      - Plugin Management Menu\n");
        PrintToClientOrConsole(slot, "Commands", " resmon       - Resource Monitor Menu\n");
        PrintToClientOrConsole(slot, "Commands", " translations - Translations Menu\n");
    }
    PrintToClientOrConsole(slot, "Commands", " version      - Display Swiftly version\n");
}

//////////////////////////////////////////////////////////////
/////////////////            Addons            //////////////
////////////////////////////////////////////////////////////

void SwiftlyAddonsManagerHelp(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Addons Management Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly addons <command>\n");
    PrintToClientOrConsole(slot, "Commands", " disable    - Disables the addons downloading.\n");
    PrintToClientOrConsole(slot, "Commands", " enable     - Enables the addons downloading.\n");
    PrintToClientOrConsole(slot, "Commands", " reload     - Reloads the addons from the configuration.\n");
    PrintToClientOrConsole(slot, "Commands", " status     - Shows the status of the addons downloading.\n");
}

void SwiftlyAddonsManagerReload(CPlayerSlot slot, CCommandContext context)
{
    g_addons.LoadAddons();
    PrintToClientOrConsole(slot, "Addons", "All addons has been succesfully reloaded.\n");
}

void SwiftlyAddonsManagerDisable(CPlayerSlot slot, CCommandContext context)
{
    if (!g_addons.GetStatus())
        return PrintToClientOrConsole(slot, "Addons", "Addons is already disabled.\n");

    g_addons.ToggleStatus();
    PrintToClientOrConsole(slot, "Addons", "Addons has been disabled.\n");
}

void SwiftlyAddonsManagerEnable(CPlayerSlot slot, CCommandContext context)
{
    if (g_addons.GetStatus())
        return PrintToClientOrConsole(slot, "Addons", "Addons is already enabled.\n");

    g_addons.ToggleStatus();
    PrintToClientOrConsole(slot, "Addons", "Addons has been enabled.\n");
}

void SwiftlyAddonsManagerStatus(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Addons", "Addons Status: %s.\n", g_addons.GetStatus() ? "Enabled" : "Disabled");
}

void SwiftlyAddonsManager(CPlayerSlot slot, CCommandContext context, const char *subcmd)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyAddonsManagerHelp(slot, context);
        return;
    }

    if (sbcmd == "reload")
        SwiftlyAddonsManagerReload(slot, context);
    else if (sbcmd == "disable")
        SwiftlyAddonsManagerDisable(slot, context);
    else if (sbcmd == "enable")
        SwiftlyAddonsManagerEnable(slot, context);
    else if (sbcmd == "status")
        SwiftlyAddonsManagerStatus(slot, context);
    else
        SwiftlyAddonsManagerHelp(slot, context);
}

//////////////////////////////////////////////////////////////
/////////////////        Console Filter        //////////////
////////////////////////////////////////////////////////////

void SwiftlyConFilterManagerHelp(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Console Filtering Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly confilter <command>\n");
    PrintToClientOrConsole(slot, "Commands", " disable    - Disables the console filtering.\n");
    PrintToClientOrConsole(slot, "Commands", " enable     - Enables the console filtering.\n");
    PrintToClientOrConsole(slot, "Commands", " reload     - Reloads the console filtering messages.\n");
    PrintToClientOrConsole(slot, "Commands", " stats      - Shows the console filter stats.\n");
}

void SwiftlyConFilterEnable(CPlayerSlot slot, CCommandContext context)
{
    if (g_conFilter->Status())
        return PrintToClientOrConsole(slot, "Console Filtering", "Console filtering is already enabled.\n");

    g_conFilter->Toggle();
    PrintToClientOrConsole(slot, "Console Filtering", "Console filtering has been enabled.\n");
}

void SwiftlyConFilterDisable(CPlayerSlot slot, CCommandContext context)
{
    if (!g_conFilter->Status())
        return PrintToClientOrConsole(slot, "Console Filtering", "Console filtering is already disabled.\n");

    g_conFilter->Toggle();
    PrintToClientOrConsole(slot, "Console Filtering", "Console filtering has been disabled.\n");
}

void SwiftlyConFilterStats(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Console Filtering", "Console Filtering status: %s.\n", g_conFilter->Status() ? "Enabled" : "Disabled");
    PrintToClientOrConsole(slot, "Console Filtering", "Below it will be shown the amount of messages filtered:\n");
    std::map<std::string, uint64> counters = g_conFilter->GetCounters();
    uint32 idx = 0;
    for (std::map<std::string, uint64>::iterator it = counters.begin(); it != counters.end(); ++it)
    {
        ++idx;
        PrintToClientOrConsole(slot, "Console Filtering", "%02d. %s -> %llu\n", idx, it->first.c_str(), it->second);
    }
}

void SwiftlyConFilterReload(CPlayerSlot slot, CCommandContext context)
{
    bool shouldRestart = g_conFilter->Status();

    if (g_conFilter->Status())
        g_conFilter->Toggle();

    g_conFilter->LoadFilters();
    PrintToClientOrConsole(slot, "Console Filtering", "Console Filtering messages have been succesfully reloaded.\n");

    if (shouldRestart)
        g_conFilter->Toggle();
}

void SwiftlyConFilterManager(CPlayerSlot slot, CCommandContext context, const char *subcmd)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyConFilterManagerHelp(slot, context);
        return;
    }

    if (sbcmd == "enable")
        SwiftlyConFilterEnable(slot, context);
    else if (sbcmd == "disable")
        SwiftlyConFilterDisable(slot, context);
    else if (sbcmd == "stats")
        SwiftlyConFilterStats(slot, context);
    else if (sbcmd == "reload")
        SwiftlyConFilterReload(slot, context);
    else
        SwiftlyConFilterManagerHelp(slot, context);
}

//////////////////////////////////////////////////////////////
/////////////////            Plugins           //////////////
////////////////////////////////////////////////////////////

void ShowSwiftlyPluginManagerHelp(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Plugin Management Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins <command> [plugin_name]\n");
    PrintToClientOrConsole(slot, "Commands", " info     - Shows informations about a plugin\n");
    PrintToClientOrConsole(slot, "Commands", " list     - Shows loaded plugins\n");
    PrintToClientOrConsole(slot, "Commands", " load     - Loads a plugin\n");
    PrintToClientOrConsole(slot, "Commands", " reload   - Reloads a plugin if it was loaded\n");
    PrintToClientOrConsole(slot, "Commands", " unload   - Unloads a plugin if it was loaded\n");
    PrintToClientOrConsole(slot, "Commands", " refresh  - Refreshes the plugin list.\n");
}

void SwiftlyPluginManagerList(CPlayerSlot slot, CCommandContext context)
{
    uint32 loadedPlugins = 0;
    auto plugins = g_pluginManager->GetPluginsList();
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin == nullptr)
            continue;
        if (plugin->GetPluginState() == PluginState_t::Stopped)
            continue;

        ++loadedPlugins;
    }

    if (loadedPlugins == 0)
        return PrintToClientOrConsole(slot, "Plugins List", "There are no plugins loaded.\n");

    PrintToClientOrConsole(slot, "Plugins List", "Showing below %02d plugins loaded:\n", loadedPlugins);
    uint32 showingIdx = 0;
    std::vector<std::string> errors;
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin == nullptr)
            continue;
        if (plugin->GetLoadError().size() > 0)
            errors.push_back(string_format("Plugin '%s': %s", plugin->GetName().c_str(), plugin->GetLoadError().c_str()));
        if (plugin->GetPluginState() == PluginState_t::Stopped)
            continue;

        ++showingIdx;

        auto website = plugin->GetWebsite();

        PrintToClientOrConsole(slot, "Plugins List", "%02d. \"%s\" (%s) by %s%s\n",
                               showingIdx,
                               plugin->GetPlName().c_str(),
                               plugin->GetVersion().c_str(),
                               plugin->GetAuthor().c_str(),
                               website == "" ? "" : string_format(" ( %s )", website.c_str()).c_str());
    }
    if (errors.size() && slot.Get() == -1)
    {
        PrintToClientOrConsole(slot, "Plugins List", "Plugin load errors:\n");
        for (const std::string err : errors)
            PrintToClientOrConsole(slot, "Plugins List", "%s\n", err.c_str());

        errors.clear();
    }
}

void SwiftlyPluginManagerInfo(CPlayerSlot slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins info <plugin_name>\n");

    if (!g_pluginManager->PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Info", "Invalid plugin name.\n");

    Plugin *plugin = g_pluginManager->FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return PrintToClientOrConsole(slot, "Plugin Info", "Plugin is not loaded.\n");

    std::string website = plugin->GetWebsite();

    PrintToClientOrConsole(slot, "Plugin Info", "Plugin File Name: %s\n", plugin->GetName().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Name: %s\n", plugin->GetPlName().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Author: %s\n", plugin->GetAuthor().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Version: %s\n", plugin->GetVersion().c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "URL: %s\n", website == "" ? "Not Present" : website.c_str());
    if (plugin->GetKind() == PluginKind_t::Lua)
    {
        LuaPlugin *plg = (LuaPlugin *)plugin;

        auto collectgarbage = luabridge::getGlobal(plg->GetState(), "collectgarbage");
        auto countResult = collectgarbage(std::string("count"));

        PrintToClientOrConsole(slot, "Plugin Info", "Memory Usage: %.4fMB\n", countResult.cast<double>() / 1024);
    }
}

void SwiftlyPluginManagerUnload(CPlayerSlot slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins unload <plugin_name>\n");

    if (!g_pluginManager->PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Unload", "Invalid plugin name.\n");

    Plugin *plugin = g_pluginManager->FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return PrintToClientOrConsole(slot, "Plugin Unload", "Plugin is not loaded.\n");

    g_pluginManager->StopPlugin(plugin_name);
    PrintToClientOrConsole(slot, "Plugin Unload", "Plugin '%s' has been unloaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerLoad(CPlayerSlot slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins load <plugin_name>\n");

    if (!g_pluginManager->PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Load", "Invalid plugin name.\n");

    Plugin *plugin = g_pluginManager->FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Started)
        return PrintToClientOrConsole(slot, "Plugin Load", "Plugin is already loaded.\n");

    g_pluginManager->LoadPlugin(plugin_name);
    g_pluginManager->StartPlugin(plugin_name);
    PrintToClientOrConsole(slot, "Plugin Load", "Plugin '%s' has been loaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerReload(CPlayerSlot slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins reload <plugin_name>\n");

    if (!g_pluginManager->PluginExists(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Reload", "Invalid plugin name.\n");

    Plugin *plugin = g_pluginManager->FetchPlugin(plugin_name);
    if (plugin->GetPluginState() == PluginState_t::Stopped)
        return PrintToClientOrConsole(slot, "Plugin Reload", "Plugin is not loaded.\n");

    g_pluginManager->StopPlugin(plugin_name);
    g_pluginManager->LoadPlugin(plugin_name);
    g_pluginManager->StartPlugin(plugin_name);
    PrintToClientOrConsole(slot, "Plugin Reload", "Plugin '%s' has been reloaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerRefresh(CPlayerSlot slot, CCommandContext context)
{
    auto oldPluginsAmount = g_pluginManager->GetPluginsList().size();
    g_pluginManager->LoadPlugins();
    auto newPluginsAmount = g_pluginManager->GetPluginsList().size();
    PrintToClientOrConsole(slot, "Plugin Refresh", "Plugins have been succesfully refreshed. (%d -> %d plugins)\n", oldPluginsAmount, newPluginsAmount);
}

void SwiftlyPluginManager(CPlayerSlot slot, CCommandContext context, const char *subcmd, const char *plugin_name)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        ShowSwiftlyPluginManagerHelp(slot, context);
        return;
    }

    if (sbcmd == "list")
        SwiftlyPluginManagerList(slot, context);
    else if (sbcmd == "info")
        SwiftlyPluginManagerInfo(slot, context, plugin_name);
    else if (sbcmd == "unload")
        SwiftlyPluginManagerUnload(slot, context, plugin_name);
    else if (sbcmd == "load")
        SwiftlyPluginManagerLoad(slot, context, plugin_name);
    else if (sbcmd == "reload")
        SwiftlyPluginManagerReload(slot, context, plugin_name);
    else if (sbcmd == "refresh")
        SwiftlyPluginManagerRefresh(slot, context);
    else
        ShowSwiftlyPluginManagerHelp(slot, context);
}

//////////////////////////////////////////////////////////////
/////////////////            Resmon            //////////////
////////////////////////////////////////////////////////////

void SwiftlyResourceMonitorManagerHelp(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Resource Monitor Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly resmon <command>\n");
    PrintToClientOrConsole(slot, "Commands", " enable          - Enabled the usage monitoring.\n");
    PrintToClientOrConsole(slot, "Commands", " disable         - Disables the usage monitoring.\n");
    PrintToClientOrConsole(slot, "Commands", " view            - Shows the usage monitored.\n");
    PrintToClientOrConsole(slot, "Commands", " viewplugin <ID> - Shows the usage monitored for a specific plugin.\n");
}

void SwiftlyResourceMonitorManagerEnable(CPlayerSlot slot, CCommandContext context)
{
    if (g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is already enabled.\n");

    g_ResourceMonitor->Enable();
    PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring has been enabled.\n");
}

void SwiftlyResourceMonitorManagerDisable(CPlayerSlot slot, CCommandContext context)
{
    if (!g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is already disabled.\n");

    g_ResourceMonitor->Disable();
    PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring has been disabled.\n");
}

void SwiftlyResourceMonitorManagerViewPlugin(CPlayerSlot slot, CCommandContext context, std::string plugin_id)
{
    if (!g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is not enabled.\n");

    if (!g_pluginManager->PluginExists(plugin_id) && plugin_id != "core")
        return PrintToClientOrConsole(slot, "Resource Monitor", "Invalid plugin ID.\n");

    auto PrintTable = [](TextTable tbl) -> void
    {
        std::stringstream outputTable;
        outputTable << tbl;
        std::vector<std::string> rows = explode(outputTable.str(), "\n");
        for (int i = 0; i < rows.size(); i++)
            PLUGIN_PRINTF("Resource Monitor", "%s\n", rows[i].c_str());
    };

    PrintToClientOrConsole(slot, "Resource Monitor", "Resource Monitor View Plugin\n");
    PrintToClientOrConsole(slot, "Resource Monitor", "ID: %s\n", plugin_id.c_str());
    PrintToClientOrConsole(slot, "Resource Monitor", " \n", plugin_id.c_str());

    PrintToClientOrConsole(slot, "Resource Monitor", "Plugin Usage View\n");

    TextTable usagesTable('-', '|', '+');

    usagesTable.add(" ID ");
    usagesTable.add(" Name ");
    usagesTable.add(" min/avg/max ");
    usagesTable.endOfRow();

    std::map<std::string, std::map<std::string, std::set<float>>> data = g_ResourceMonitor->GetResmonTimeTables();
    if (data.count(plugin_id) > 0)
    {
        std::map<std::string, std::set<float>> pluginData = data.at(plugin_id);
        uint64_t idx = 0;
        for (std::map<std::string, std::set<float>>::iterator it = pluginData.begin(); it != pluginData.end(); ++it)
        {
            ++idx;
            usagesTable.add(string_format(" %02d. ", idx));
            usagesTable.add(string_format(" %s ", it->first.c_str()));

            if (it->second.size() == 0)
                usagesTable.add(" 0.000ms / 0.000ms ");
            else
            {
                auto it2 = it->second.end();
                --it2;
                float max = *(it2);

                float avg = 0;
                uint64_t avgCount = 0;
                for (std::set<float>::iterator ii = it->second.begin(); ii != it->second.end(); ++ii)
                {
                    avg += *(ii);
                    ++avgCount;
                }

                usagesTable.add(string_format(" %.3fms / %.3fms ", (avg / avgCount), max));
            }
            usagesTable.endOfRow();
        }
    }

    PrintTable(usagesTable);
}

void SwiftlyResourceMonitorManagerView(CPlayerSlot slot, CCommandContext context)
{
    if (!g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is not enabled.\n");

    TextTable pluginsTable('-', '|', '+');

    pluginsTable.add(" ID ");
    pluginsTable.add(" Name ");
    pluginsTable.add(" Status ");
    pluginsTable.add(" Type ");
    pluginsTable.add(" Memory ");
    pluginsTable.add(" avg/max ");
    pluginsTable.endOfRow();

    auto PrintTable = [](TextTable tbl) -> void
    {
        std::stringstream outputTable;
        outputTable << tbl;
        std::vector<std::string> rows = explode(outputTable.str(), "\n");
        for (int i = 0; i < rows.size(); i++)
            PLUGIN_PRINTF("Resource Monitor", "%s\n", rows[i].c_str());
    };

    PLUGIN_PRINTF("Resource Monitor", "Plugin Resource Viewer\n");

    std::map<std::string, std::map<std::string, std::set<float>>> data = g_ResourceMonitor->GetResmonTimeTables();

    pluginsTable.add(" core ");
    pluginsTable.add(" [Swiftly] Core ");
    pluginsTable.add(" Loaded ");
    pluginsTable.add(" - ");
    pluginsTable.add(" - ");

    if (data.find("core") != data.end())
    {
        float max = 0;
        uint64_t maxCount = 0;
        float avg = 0;
        uint64_t avgCount = 0;

        std::map<std::string, std::set<float>> pluginData = data.at("core");
        for (std::map<std::string, std::set<float>>::iterator it = pluginData.begin(); it != pluginData.end(); ++it)
        {
            if (it->second.size() == 0)
                continue;

            auto maxend = it->second.end();
            --maxend;
            max += *(maxend);
            ++maxCount;

            for (std::set<float>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
            {
                avg += *(it2);
                ++avgCount;
            }
        }

        pluginsTable.add(string_format(" %.3fms / %.3fms ", (avg / avgCount), (max / maxCount)));
    }
    else
        pluginsTable.add(" 0.000ms / 0.000ms ");

    pluginsTable.endOfRow();

    for (Plugin *plugin : g_pluginManager->GetPluginsList())
    {
        std::string plugin_id = plugin->GetName();

        pluginsTable.add(" " + plugin_id + " ");
        std::string plugin_name = (plugin->GetPluginState() == PluginState_t::Started ? plugin->GetPlName() : "-");
        pluginsTable.add(string_format(" %s ", (plugin_name.size() > 24 ? (plugin_name.substr(0, 21) + "...") : plugin_name).c_str()));
        pluginsTable.add(std::string(" ") + (plugin->GetPluginState() == PluginState_t::Started ? "Loaded" : "Unloaded") + " ");
        pluginsTable.add(std::string(" ") + (plugin->GetKind() == PluginKind_t::Lua ? "Lua" : "None") + " ");
        if (plugin->GetKind() == PluginKind_t::Lua && plugin->GetPluginState() == PluginState_t::Started)
        {
            auto collectgarbage = luabridge::getGlobal(((LuaPlugin *)plugin)->GetState(), "collectgarbage");
            auto countResult = collectgarbage(std::string("count"));
            pluginsTable.add(string_format(" %.4f MB ", (countResult.cast<double>() / 1024)));
        }
        else
            pluginsTable.add(" - ");

        if (plugin->GetPluginState() == PluginState_t::Started && data.find(plugin->GetName()) != data.end())
        {

            float max = 0;
            uint64_t maxCount = 0;
            float avg = 0;
            uint64_t avgCount = 0;

            std::map<std::string, std::set<float>> pluginData = data.at(plugin->GetName());
            for (std::map<std::string, std::set<float>>::iterator it = pluginData.begin(); it != pluginData.end(); ++it)
            {
                if (it->second.size() == 0)
                    continue;

                auto maxend = it->second.end();
                --maxend;
                max += *(maxend);
                ++maxCount;

                for (std::set<float>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
                {
                    avg += *(it2);
                    ++avgCount;
                }
            }

            pluginsTable.add(string_format(" %.3fms / %.3fms ", (avg / avgCount), (max / maxCount)));
        }
        else
            pluginsTable.add(" 0.000ms / 0.000ms ");

        pluginsTable.endOfRow();
    }

    PrintTable(pluginsTable);
    PrintToClientOrConsole(slot, "Resource Monitor", "To view more detailed informations for each plugin, use: sw resmon viewplugin <ID>\n");
}

void SwiftlyResourceMonitorManager(CPlayerSlot slot, CCommandContext context, const char *subcmd, const char *subcmd2)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyResourceMonitorManagerHelp(slot, context);
        return;
    }

    if (sbcmd == "enable")
        SwiftlyResourceMonitorManagerEnable(slot, context);
    else if (sbcmd == "disable")
        SwiftlyResourceMonitorManagerDisable(slot, context);
    else if (sbcmd == "view")
        SwiftlyResourceMonitorManagerView(slot, context);
    else if (sbcmd == "viewplugin")
        SwiftlyResourceMonitorManagerViewPlugin(slot, context, (subcmd2 == nullptr ? "" : subcmd2));
    else
        SwiftlyResourceMonitorManagerHelp(slot, context);
}

//////////////////////////////////////////////////////////////
/////////////////         Translations         //////////////
////////////////////////////////////////////////////////////

void SwiftlyTranslationManagerHelp(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Console Filtering Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly translations <command>\n");
    PrintToClientOrConsole(slot, "Commands", " reload    - Reloads the translations.\n");
}

void SwiftlyTranslationReload(CPlayerSlot slot, CCommandContext context)
{
    g_translations->LoadTranslations();
    PrintToClientOrConsole(slot, "Translations", "All translations have been succesfully reloaded.\n");
}

void SwiftlyTranslationManager(CPlayerSlot slot, CCommandContext context, const char *subcmd)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyTranslationManagerHelp(slot, context);
        return;
    }

    if (sbcmd == "reload")
        SwiftlyTranslationReload(slot, context);
    else
        SwiftlyTranslationManagerHelp(slot, context);
}

//////////////////////////////////////////////////////////////
/////////////////            Version           //////////////
////////////////////////////////////////////////////////////

void SwiftlyVersion(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Version", "Swiftly Version informations:\n");
    PrintToClientOrConsole(slot, "Version", " Swiftly Version: %s (%s)\n", g_Plugin.GetVersion(), std::string(GITHUB_SHA).substr(0, 7).c_str());
    PrintToClientOrConsole(slot, "Version", " Swiftly API Version: %d\n", g_Plugin.GetApiVersion());
    PrintToClientOrConsole(slot, "Version", " Swiftly C++ Version: %s\n", GetCppVersion());
    PrintToClientOrConsole(slot, "Version", " Compiled on: %s %s\n", __DATE__, __TIME__);
    PrintToClientOrConsole(slot, "Version", " Github Commit: https://github.com/swiftly-solution/swiftly/commit/%s\n", std::string(GITHUB_SHA).c_str());
    PrintToClientOrConsole(slot, "Version", " https://github.com/swiftly-solution \n");
}

//////////////////////////////////////////////////////////////
/////////////////            Credits           //////////////
////////////////////////////////////////////////////////////

void ShowSwiftlyCredits(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly was developed by Swiftly Solutions.\n");
    PrintToClientOrConsole(slot, "Commands", "https://github.com/swiftly-solution \n");
}

void SwiftlyCommand(const CCommandContext &context, const CCommand &args)
{
    CPlayerSlot slot = context.GetPlayerSlot();
    if (args.ArgC() < 2)
    {
        ShowSwiftlyCommandHelp(slot, context);
        return;
    }

    std::string subcmd = args[1];
    if (subcmd == "credits")
        ShowSwiftlyCredits(slot, context);
    else if (subcmd == "cmds")
        ShowSwiftlyCommands(slot, context, args[2] == nullptr ? 1 : atoi(args[2]));
    else if (subcmd == "help")
        ShowSwiftlyCommandHelp(slot, context);
    else if (subcmd == "version")
        SwiftlyVersion(slot, context);
    else if (subcmd == "list")
        SwiftlyList(slot, context);
    else if (subcmd == "confilter")
        SwiftlyConFilterManager(slot, context, args[2]);
    else if (subcmd == "addons")
        SwiftlyAddonsManager(slot, context, args[2]);
    else if (subcmd == "translations")
        SwiftlyTranslationManager(slot, context, args[2]);
    else if (subcmd == "plugins")
        SwiftlyPluginManager(slot, context, args[2], args[3]);
    else if (subcmd == "resmon")
        SwiftlyResourceMonitorManager(slot, context, args[2], args[3]);
    else if (subcmd == "status")
        SwiftlyStatus(slot, context);
    else
        ShowSwiftlyCommandHelp(slot, context);
}

CON_COMMAND_F(swiftly, "The main command for Swiftly.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND | FCVAR_SERVER_CAN_EXECUTE)
{
    SwiftlyCommand(context, args);
}

CON_COMMAND_F(sw, "The main command for Swiftly.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND | FCVAR_SERVER_CAN_EXECUTE)
{
    SwiftlyCommand(context, args);
}