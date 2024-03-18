#include "../inc/BasicComponent.h"
#include "../../../hooks/Hooks.h"
#include "../../../common.h"
#include "../../../player/PlayerManager.h"
#include "../../../translations/Translations.h"
#include "../../../database/DatabaseManager.h"
#include "../../../commands/CommandsManager.h"
#include "../../../filter/ConsoleFilter.h"
#include "../../Plugins/inc/Plugin.h"
#include "../../../files/Files.h"
#include "../../../http/HTTPManager.h"
#include "../../../addons/addons.h"
#include "../../Plugins/inc/plugins/CPPPlugin.h"
#include "../../Plugins/inc/plugins/LuaPlugin.h"
#include "../../../resourcemonitor/ResourceMonitor.h"

#include <TextTable.h>
#include <sstream>

#ifndef GITHUB_SHA
#define GITHUB_SHA "LOCAL"
#endif

typedef const char *(*GetPlugin)();
typedef double (*GetCount)();

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

void BasicComponent::LoadComponent()
{
}

std::string seconds_to_time(unsigned int number)
{
    return string_format("%02d:%02d:%02d", int(number / 3600), int((number % 3600) / 60), int((number % 3600) % 60));
}

CON_COMMAND_F(sw_status, "Shows the connection status to the server.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND | FCVAR_SERVER_CAN_EXECUTE)
{
    CPlayerSlot sl = context.GetPlayerSlot();
    CPlayerSlot *slot = &sl;

    PrintToClientOrConsole(slot, "Status", "playerid\tname\tsteamid\t\ttime\t\tstate\n");

    for (uint16 i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        CBasePlayerController *controller = player->GetController();
        if (!controller)
            continue;

        if (player->IsFakeClient())
            PrintToClientOrConsole(slot, "Status", "#%d\t%s\t%s\t%s\t%s\n",
                                   player->GetSlot()->Get(), player->GetName(), "BOT\t", seconds_to_time(player->GetConnectedTime()).c_str(), "Active");
        else
            PrintToClientOrConsole(slot, "Status", "#%d\t%s\t%llu\t%s\t%s\n",
                                   player->GetSlot()->Get(), player->GetName(), controller->m_steamID(), seconds_to_time(player->GetConnectedTime()).c_str(), "Active");
    }
    PrintToClientOrConsole(slot, "Status", "end of status\n");
}

CON_COMMAND_F(sw_list, "Shows the players connected on the server, including the number of those.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND | FCVAR_SERVER_CAN_EXECUTE)
{
    CPlayerSlot sl = context.GetPlayerSlot();
    CPlayerSlot *slot = &sl;

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

void ShowSwiftlyCommandHelp(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Commands Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly <command> [args]\n");
    PrintToClientOrConsole(slot, "Commands", " credits      - List Swiftly credits\n");
    PrintToClientOrConsole(slot, "Commands", " cmds         - List all console commands created by plugins\n");
    PrintToClientOrConsole(slot, "Commands", " help         - Show the help for Swiftly commands\n");
    if (slot->Get() == -1)
    {
        PrintToClientOrConsole(slot, "Commands", " addons       - Addons Management Menu\n");
        PrintToClientOrConsole(slot, "Commands", " confilter    - Console Filtering Menu\n");
        PrintToClientOrConsole(slot, "Commands", " plugins      - Plugin Management Menu\n");
        PrintToClientOrConsole(slot, "Commands", " translations - Translations Menu\n");
        PrintToClientOrConsole(slot, "Commands", " resmon       - Resource Monitor Menu\n");
    }
    PrintToClientOrConsole(slot, "Commands", " version      - Display Swiftly version\n");
}

void ShowSwiftlyCredits(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly was developed by Swiftly Solutions.\n");
    PrintToClientOrConsole(slot, "Commands", "https://github.com/swiftly-solution \n");
}

void ShowSwiftlyCommands(CPlayerSlot *slot, CCommandContext context, int page)
{
    PrintToClientOrConsole(slot, "Commands", "Below will be shown a list of all the commands which were created by plugins:\n");

    std::map<std::string, Command *> cmds = g_commandsManager->GetCommands();
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

void ShowSwiftlyPluginManagerHelp(CPlayerSlot *slot, CCommandContext context)
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

void SwiftlyPluginManagerList(CPlayerSlot *slot, CCommandContext context)
{
    uint32 loadedPlugins = 0;
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin == nullptr)
            continue;
        if (!plugin->IsPluginLoaded())
            continue;

        ++loadedPlugins;
    }

    if (loadedPlugins == 0)
        return PrintToClientOrConsole(slot, "Plugins List", "There are no plugins loaded.\n", loadedPlugins);

    PrintToClientOrConsole(slot, "Plugins List", "Showing below %02d plugins loaded:\n", loadedPlugins);
    uint32 showingIdx = 0;
    std::vector<std::string> errors;
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin == nullptr)
            continue;
        if (plugin->err.size() > 0)
            errors.push_back(string_format("Plugin '%s': %s", plugin->GetName().c_str(), plugin->err.c_str()));
        if (!plugin->IsPluginLoaded())
            continue;

        if (!plugin->FunctionExists("GetPluginAuthor") || !plugin->FunctionExists("GetPluginVersion") || !plugin->FunctionExists("GetPluginName") || !plugin->FunctionExists("GetPluginWebsite"))
            continue;

        ++showingIdx;

        std::string website = plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginWebsite");

        PrintToClientOrConsole(slot, "Plugins List", "%02d. \"%s\" (%s) by %s%s\n",
                               showingIdx,
                               plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginName"),
                               plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginVersion"),
                               plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginAuthor"),
                               website == "" ? "" : string_format(" ( %s )", website.c_str()).c_str());
    }
    if (errors.size() && slot->Get() == -1)
    {
        PrintToClientOrConsole(slot, "Plugins List", "Plugin load errors:\n");
        for (const std::string err : errors)
            PrintToClientOrConsole(slot, "Plugins List", "%s\n", err.c_str());

        errors.clear();
    }
}

void SwiftlyPluginManagerInfo(CPlayerSlot *slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins info <plugin_name>\n");

    if (!ExistsPluginInMap(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Info", "Invalid plugin name.\n");

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    if (!plugin->IsPluginLoaded())
        return PrintToClientOrConsole(slot, "Plugin Info", "Plugin is not loaded.\n");

    std::string website = plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginWebsite");

    PrintToClientOrConsole(slot, "Plugin Info", "Plugin File Name: %s\n", plugin->m_path.c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Name: %s\n", plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginName"));
    PrintToClientOrConsole(slot, "Plugin Info", "Author: %s\n", plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginAuthor"));
    PrintToClientOrConsole(slot, "Plugin Info", "Version: %s\n", plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginVersion"));
    PrintToClientOrConsole(slot, "Plugin Info", "URL: %s\n", website == "" ? "Not Present" : website.c_str());
    if (plugin->GetPluginType() == PluginType_t::PLUGIN_LUA)
    {
        LuaPlugin *plg = (LuaPlugin *)plugin;
        LuaFuncWrapper wrapper(plg->GetLuaState()->Get("collectgarbage"));
        wrapper.PrepForExec();
        luacpp::PushValues(wrapper.GetML(), "count");
        PrintToClientOrConsole(slot, "Plugin Info", "Memory Usage: %.4fMB\n", (wrapper.ExecuteWithReturn<double>("collectgarbage", 1) / 1024));
    }
}

void SwiftlyPluginManagerUnload(CPlayerSlot *slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins unload <plugin_name>\n");

    if (!ExistsPluginInMap(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Unload", "Invalid plugin name.\n");

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    if (!plugin->IsPluginLoaded())
        return PrintToClientOrConsole(slot, "Plugin Unload", "Plugin is not loaded.\n");

    plugin->StopPlugin();
    PrintToClientOrConsole(slot, "Plugin Unload", "Plugin '%s' has been unloaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerLoad(CPlayerSlot *slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins load <plugin_name>\n");

    if (!ExistsPluginInMap(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Load", "Invalid plugin name.\n");

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    if (plugin->IsPluginLoaded())
        return PrintToClientOrConsole(slot, "Plugin Load", "Plugin is already loaded.\n");

    plugin->LoadPlugin();
    plugin->StartPlugin();
    PrintToClientOrConsole(slot, "Plugin Load", "Plugin '%s' has been loaded.\n", plugin_name.c_str());
}

void SwiftlyPluginManagerReload(CPlayerSlot *slot, CCommandContext context, std::string plugin_name)
{
    if (plugin_name.size() == 0)
        return PrintToClientOrConsole(slot, "Commands", "Usage: swiftly plugins reload <plugin_name>\n");

    if (!ExistsPluginInMap(plugin_name))
        return PrintToClientOrConsole(slot, "Plugin Reload", "Invalid plugin name.\n");

    Plugin *plugin = FetchPluginFromMap(plugin_name);
    if (!plugin->IsPluginLoaded())
        return PrintToClientOrConsole(slot, "Plugin Reload", "Plugin is not loaded.\n");

    plugin->StopPlugin();
    plugin->LoadPlugin();
    plugin->StartPlugin();
    PrintToClientOrConsole(slot, "Plugin Reload", "Plugin '%s' has been reloaded.\n", plugin_name.c_str());
}

void LoadPlugin(std::string plugin_name)
{
    Plugin *plugin = nullptr;

    std::vector<std::string> files = Files::FetchFileNames("addons/swiftly/plugins/" + plugin_name);

    for (const std::string &file : files)
    {
        if (ends_with(file, WIN_LINUX(".dll", ".so")))
        {
            plugin = new CPPPlugin(file, plugin_name, PluginType_t::PLUGIN_CPP);
            break;
        }
        else if (ends_with(file, ".lua"))
        {
            plugin = new LuaPlugin(std::string(std::filesystem::current_path().string() + "/addons/swiftly/plugins/" + plugin_name), plugin_name, PluginType_t::PLUGIN_LUA);
            break;
        }
    }

    if (plugin)
        AddPluginInMap(plugin);
}

void SwiftlyPluginManagerRefresh(CPlayerSlot *slot, CCommandContext context)
{
    if (slot->Get() != -1)
        return;

    std::vector<std::string> pluginNames;

    std::vector<std::string> directories = Files::FetchDirectories("addons/swiftly/plugins");
    for (std::string directory : directories)
    {
        if (directory.find("disabled") != std::string::npos)
            continue;

        directory = replace(directory, "addons/swiftly/plugins", "");
        directory = replace(directory, WIN_LINUX("\\", "/"), "");

        pluginNames.push_back(directory);
    }

    uint32 newPlugins = 0;

    for (const std::string plugin_name : pluginNames)
    {
        if (!ExistsPluginInMap(plugin_name))
        {
            LoadPlugin(plugin_name);
            ++newPlugins;
        }
    }

    PrintToClientOrConsole(slot, "Plugin Refresh", "%02d plugins have been added.\n", newPlugins);
}

void SwiftlyPluginManager(CPlayerSlot *slot, CCommandContext context, const char *subcmd, const char *plugin_name)
{
    if (slot->Get() != -1)
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

void SwiftlyResourceMonitorManagerHelp(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Resource Monitor Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly resmon <command>\n");
    PrintToClientOrConsole(slot, "Commands", " enable          - Enabled the usage monitoring.\n");
    PrintToClientOrConsole(slot, "Commands", " disable         - Disables the usage monitoring.\n");
    PrintToClientOrConsole(slot, "Commands", " view            - Shows the usage monitored.\n");
    PrintToClientOrConsole(slot, "Commands", " viewplugin <ID> - Shows the usage monitored for a specific plugin.\n");
}

void SwiftlyTranslationManagerHelp(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Console Filtering Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly translations <command>\n");
    PrintToClientOrConsole(slot, "Commands", " reload    - Reloads the translations.\n");
}

void SwiftlyAddonsManagerHelp(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Addons Management Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly addons <command>\n");
    PrintToClientOrConsole(slot, "Commands", " disable    - Disables the addons downloading.\n");
    PrintToClientOrConsole(slot, "Commands", " enable     - Enables the addons downloading.\n");
    PrintToClientOrConsole(slot, "Commands", " reload     - Reloads the addons from the configuration.\n");
    PrintToClientOrConsole(slot, "Commands", " status     - Shows the status of the addons downloading.\n");
}

void SwiftlyConFilterManagerHelp(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Console Filtering Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly confilter <command>\n");
    PrintToClientOrConsole(slot, "Commands", " disable    - Disables the console filtering.\n");
    PrintToClientOrConsole(slot, "Commands", " enable     - Enables the console filtering.\n");
    PrintToClientOrConsole(slot, "Commands", " reload     - Reloads the console filtering messages.\n");
    PrintToClientOrConsole(slot, "Commands", " stats      - Shows the console filter stats.\n");
}

void SwiftlyTranslationReload(CPlayerSlot *slot, CCommandContext context)
{
    g_translations->LoadTranslations();
    PrintToClientOrConsole(slot, "Translations", "All translations have been succesfully reloaded.\n");
}

void SwiftlyAddonsManagerReload(CPlayerSlot *slot, CCommandContext context)
{
    g_addons->RegisterAddons();
    PrintToClientOrConsole(slot, "Addons", "All addons has been succesfully reloaded.\n");
}

void SwiftlyAddonsManagerDisable(CPlayerSlot *slot, CCommandContext context)
{
    if (!g_addons->GetStatus())
        return PrintToClientOrConsole(slot, "Addons", "Addons is already disabled.\n");

    g_addons->ToggleStatus();
    PrintToClientOrConsole(slot, "Addons", "Addons has been disabled.\n");
}

void SwiftlyAddonsManagerEnable(CPlayerSlot *slot, CCommandContext context)
{
    if (g_addons->GetStatus())
        return PrintToClientOrConsole(slot, "Addons", "Addons is already enabled.\n");

    g_addons->ToggleStatus();
    PrintToClientOrConsole(slot, "Addons", "Addons has been enabled.\n");
}

void SwiftlyAddonsManagerStatus(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Addons", "Addons Status: %s.\n", g_addons->GetStatus() ? "Enabled" : "Disabled");
}

void SwiftlyConFilterEnable(CPlayerSlot *slot, CCommandContext context)
{
    if (g_conFilter->Status())
        return PrintToClientOrConsole(slot, "Console Filtering", "Console filtering is already enabled.\n");

    g_conFilter->Toggle();
    PrintToClientOrConsole(slot, "Console Filtering", "Console filtering has been enabled.\n");
}

void SwiftlyConFilterDisable(CPlayerSlot *slot, CCommandContext context)
{
    if (!g_conFilter->Status())
        return PrintToClientOrConsole(slot, "Console Filtering", "Console filtering is already disabled.\n");

    g_conFilter->Toggle();
    PrintToClientOrConsole(slot, "Console Filtering", "Console filtering has been disabled.\n");
}

void SwiftlyResourceMonitorManagerEnable(CPlayerSlot *slot, CCommandContext context)
{
    if (g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is already enabled.\n");

    g_ResourceMonitor->Enable();
    PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring has been enabled.\n");
}

void SwiftlyResourceMonitorManagerDisable(CPlayerSlot *slot, CCommandContext context)
{
    if (!g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is already disabled.\n");

    g_ResourceMonitor->Disable();
    PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring has been disabled.\n");
}

void SwiftlyResourceMonitorManagerViewPlugin(CPlayerSlot *slot, CCommandContext context, std::string plugin_id)
{
    if (!g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is not enabled.\n");

    if (!ExistsPluginInMap(plugin_id) && plugin_id != "swiftly-core")
        return PrintToClientOrConsole(slot, "Resource Monitor", "Invalid plugin ID.\n");

    auto PrintTable = [](TextTable tbl) -> void
    {
        std::stringstream outputTable;
        outputTable << tbl;
        std::vector<std::string> rows = explode(outputTable.str(), "\n");
        for (int i = 0; i < rows.size(); i++)
            PRINTF("Resource Monitor", "%s\n", rows[i].c_str());
    };

    Plugin *plugin = FetchPluginFromMap(plugin_id);

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
                usagesTable.add(" 0.000ms / 0.000ms / 0.000ms ");
            else
            {
                float min = *(it->second.begin());
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

                usagesTable.add(string_format(" %.3fms / %.3fms / %.3fms ", min, (avg / avgCount), max));
            }
            usagesTable.endOfRow();
        }
    }

    PrintTable(usagesTable);
}

void SwiftlyResourceMonitorManagerView(CPlayerSlot *slot, CCommandContext context)
{
    if (!g_ResourceMonitor->IsEnabled())
        return PrintToClientOrConsole(slot, "Resource Monitor", "Resource monitoring is not enabled.\n");

    TextTable pluginsTable('-', '|', '+');

    pluginsTable.add(" ID ");
    pluginsTable.add(" Name ");
    pluginsTable.add(" Status ");
    pluginsTable.add(" Type ");
    pluginsTable.add(" Memory ");
    pluginsTable.add(" min/avg/max ");
    pluginsTable.endOfRow();

    auto PrintTable = [](TextTable tbl) -> void
    {
        std::stringstream outputTable;
        outputTable << tbl;
        std::vector<std::string> rows = explode(outputTable.str(), "\n");
        for (int i = 0; i < rows.size(); i++)
            PRINTF("Resource Monitor", "%s\n", rows[i].c_str());
    };

    PRINTF("Resource Monitor", "Plugin Resource Viewer\n");

    std::map<std::string, std::map<std::string, std::set<float>>> data = g_ResourceMonitor->GetResmonTimeTables();

    pluginsTable.add(" swiftly-core ");
    pluginsTable.add(" [Swiftly] Core ");
    pluginsTable.add(" Loaded ");
    pluginsTable.add(" - ");
    pluginsTable.add(" - ");

    if (data.find("swiftly-core") != data.end())
    {
        float min = 0;
        uint64_t minCount = 0;
        float max = 0;
        uint64_t maxCount = 0;
        float avg = 0;
        uint64_t avgCount = 0;

        std::map<std::string, std::set<float>> pluginData = data.at("swiftly-core");
        for (std::map<std::string, std::set<float>>::iterator it = pluginData.begin(); it != pluginData.end(); ++it)
        {
            if (it->second.size() == 0)
                continue;
            min += *(it->second.begin());
            ++minCount;

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

        pluginsTable.add(string_format(" %.3fms / %.3fms / %.3fms ", (min / minCount), (avg / avgCount), (max / maxCount)));
    }
    else
        pluginsTable.add(" 0.000ms / 0.000ms / 0.000ms ");

    pluginsTable.endOfRow();

    for (Plugin *plugin : plugins)
    {
        std::string plugin_id = plugin->GetName();

        pluginsTable.add(" " + plugin_id + " ");
        std::string plugin_name = (plugin->IsPluginLoaded() ? plugin->ExecuteFunctionWithReturn<const char *, GetPlugin>("GetPluginName") : "-");
        pluginsTable.add(string_format(" %s ", (plugin_name.size() > 24 ? (plugin_name.substr(0, 21) + "...") : plugin_name).c_str()));
        pluginsTable.add(std::string(" ") + (plugin->IsPluginLoaded() ? "Loaded" : "Unloaded") + " ");
        pluginsTable.add(std::string(" ") + (plugin->GetPluginType() == PluginType_t::PLUGIN_LUA ? "Lua" : "C++") + " ");
        if (plugin->GetPluginType() == PluginType_t::PLUGIN_LUA && plugin->IsPluginLoaded())
        {
            LuaPlugin *plg = (LuaPlugin *)plugin;
            LuaFuncWrapper wrapper(plg->GetLuaState()->Get("collectgarbage"));
            wrapper.PrepForExec();
            luacpp::PushValues(wrapper.GetML(), "count");
            pluginsTable.add(string_format(" %.3f MB ", (wrapper.ExecuteWithReturn<double>("collectgarbage", 1) / 1024)));
        }
        else
            pluginsTable.add(" - ");

        if (plugin->IsPluginLoaded() && data.find(plugin->GetName()) != data.end())
        {

            float min = 0;
            uint64_t minCount = 0;
            float max = 0;
            uint64_t maxCount = 0;
            float avg = 0;
            uint64_t avgCount = 0;

            std::map<std::string, std::set<float>> pluginData = data.at(plugin->GetName());
            for (std::map<std::string, std::set<float>>::iterator it = pluginData.begin(); it != pluginData.end(); ++it)
            {
                if (it->second.size() == 0)
                    continue;
                min += *(it->second.begin());
                ++minCount;

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

            pluginsTable.add(string_format(" %.3fms / %.3fms / %.3fms ", (min / minCount), (avg / avgCount), (max / maxCount)));
        }
        else
            pluginsTable.add(" 0.000ms / 0.000ms / 0.000ms ");

        pluginsTable.endOfRow();
    }

    PrintTable(pluginsTable);
    PrintToClientOrConsole(slot, "Resource Monitor", "To view more detailed informations for each plugin, use: sw resmon viewplugin <ID>\n");
}

void SwiftlyConFilterStats(CPlayerSlot *slot, CCommandContext context)
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

void SwiftlyConFilterReload(CPlayerSlot *slot, CCommandContext context)
{
    bool shouldRestart = g_conFilter->Status();

    if (g_conFilter->Status())
        g_conFilter->Toggle();

    g_conFilter->LoadFilters();
    PrintToClientOrConsole(slot, "Console Filtering", "Console Filtering messages have been succesfully reloaded.\n");

    if (shouldRestart)
        g_conFilter->Toggle();
}

void SwiftlyConFilterManager(CPlayerSlot *slot, CCommandContext context, const char *subcmd)
{
    if (slot->Get() != -1)
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

void SwiftlyTranslationManager(CPlayerSlot *slot, CCommandContext context, const char *subcmd)
{
    if (slot->Get() != -1)
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

void SwiftlyResourceMonitorManager(CPlayerSlot *slot, CCommandContext context, const char *subcmd, const char *subcmd2)
{
    if (slot->Get() != -1)
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

void SwiftlyAddonsManager(CPlayerSlot *slot, CCommandContext context, const char *subcmd)
{
    if (slot->Get() != -1)
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

void SwiftlyVersion(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Version", "Swiftly Version informations:\n");
    PrintToClientOrConsole(slot, "Version", " Swiftly Version: %s (%s)\n", g_Plugin.GetVersion(), std::string(GITHUB_SHA).substr(0, 7).c_str());
    PrintToClientOrConsole(slot, "Version", " Swiftly API Version: %d\n", g_Plugin.GetApiVersion());
    PrintToClientOrConsole(slot, "Version", " Swiftly C++ Version: %s\n", GetCppVersion());
    PrintToClientOrConsole(slot, "Version", " Compiled on: %s %s\n", __DATE__, __TIME__);
    PrintToClientOrConsole(slot, "Version", " Github Commit: https://github.com/swiftly-solution/swiftly/commit/%s\n", std::string(GITHUB_SHA).c_str());
    PrintToClientOrConsole(slot, "Version", " https://github.com/swiftly-solution \n");
}

void SwiftlyCommand(const CCommandContext &context, const CCommand &args)
{
    CPlayerSlot sl = context.GetPlayerSlot();
    CPlayerSlot *slot = &sl;
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
    else if (subcmd == "plugins")
        SwiftlyPluginManager(slot, context, args[2], args[3]);
    else if (subcmd == "confilter")
        SwiftlyConFilterManager(slot, context, args[2]);
    else if (subcmd == "addons")
        SwiftlyAddonsManager(slot, context, args[2]);
    else if (subcmd == "version")
        SwiftlyVersion(slot, context);
    else if (subcmd == "translations")
        SwiftlyTranslationManager(slot, context, args[2]);
    else if (subcmd == "resmon")
        SwiftlyResourceMonitorManager(slot, context, args[2], args[3]);
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