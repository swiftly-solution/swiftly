#include "../inc/BasicComponent.h"
#include "../../../hooks/Hooks.h"
#include "../../../common.h"
#include "../../../player/PlayerManager.h"
#include "../../../database/DatabaseManager.h"
#include "../../../commands/CommandsManager.h"
#include "../../../filter/ConsoleFilter.h"
#include "../../Plugins/inc/Plugin.h"
#include "../../../files/Files.h"

typedef const char *(*GetPlugin)();

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

CON_COMMAND_F(sw_status, "Shows the connection status to the server.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
{
    CPlayerSlot sl = context.GetPlayerSlot();
    CPlayerSlot *slot = &sl;

    PrintToClientOrConsole(slot, "Commands - Status", "userid\tname\tsteamid\t\ttime\t\tstate\n");

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
                                   i + 1, controller->m_iszPlayerName(), "BOT\t", seconds_to_time(player->GetConnectedTime()).c_str(), player->GetEHandlerIdx() == -1 ? "Initializing" : "Active");
        else
            PrintToClientOrConsole(slot, "Status", "#%d\t%s\t%llu\t%s\t%s\n",
                                   i + 1, controller->m_iszPlayerName(), controller->m_steamID(), seconds_to_time(player->GetConnectedTime()).c_str(), player->GetEHandlerIdx() == -1 ? "Initializing" : "Active");
    }
    PrintToClientOrConsole(slot, "Status", "end of status\n");
}

CON_COMMAND_F(sw_list, "Shows the players connected on the server, including the number of those.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
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
        PrintToClientOrConsole(slot, "List", "%d. %s%s (%llu)\n", idx, controller->m_iszPlayerName(), player->IsFakeClient() ? " (BOT)" : "", controller->m_steamID());
    }
}

void ShowSwiftlyCommandHelp(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Commands Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly <command> [args]\n");
    PrintToClientOrConsole(slot, "Commands", " credits   - List Swiftly credits\n");
    PrintToClientOrConsole(slot, "Commands", " cmds      - List all console commands created by plugins\n");
    PrintToClientOrConsole(slot, "Commands", " help      - Show the help for Swiftly commands\n");
    if (slot->Get() == -1)
    {
        PrintToClientOrConsole(slot, "Commands", " confilter - Console Filtering Menu\n");
        PrintToClientOrConsole(slot, "Commands", " plugins   - Plugin Management Menu\n");
    }
    PrintToClientOrConsole(slot, "Commands", " version   - Display Swiftly version\n");
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
    for (uint32 i = 0; i < plugins.size(); i++)
    {
        Plugin *plugin = plugins[i];
        if (plugin == nullptr)
            continue;
        if (!plugin->IsPluginLoaded())
            continue;

        void *GetPluginAuthor = plugin->FetchFunction("GetPluginAuthor");
        void *GetPluginVersion = plugin->FetchFunction("GetPluginVersion");
        void *GetPluginName = plugin->FetchFunction("GetPluginName");
        void *GetPluginWebsite = plugin->FetchFunction("GetPluginWebsite");
        if (GetPluginAuthor == nullptr || GetPluginVersion == nullptr || GetPluginName == nullptr || GetPluginWebsite == nullptr)
            continue;

        ++showingIdx;

        std::string website = reinterpret_cast<GetPlugin>(GetPluginWebsite)();

        PrintToClientOrConsole(slot, "Plugins List", "%02d. \"%s\" (%s) by %s%s\n",
                               showingIdx,
                               reinterpret_cast<GetPlugin>(GetPluginName)(),
                               reinterpret_cast<GetPlugin>(GetPluginVersion)(),
                               reinterpret_cast<GetPlugin>(GetPluginAuthor)(),
                               website == "" ? "" : string_format(" ( %s )", website.c_str()).c_str());
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

    void *GetPluginAuthor = plugin->FetchFunction("GetPluginAuthor");
    void *GetPluginVersion = plugin->FetchFunction("GetPluginVersion");
    void *GetPluginName = plugin->FetchFunction("GetPluginName");
    void *GetPluginWebsite = plugin->FetchFunction("GetPluginWebsite");

    std::string website = reinterpret_cast<GetPlugin>(GetPluginWebsite)();

    PrintToClientOrConsole(slot, "Plugin Info", "Plugin File Name: %s\n", (plugin->GetName() + WIN_LINUX(".dll", ".so")).c_str());
    PrintToClientOrConsole(slot, "Plugin Info", "Name: %s\n", reinterpret_cast<GetPlugin>(GetPluginName)());
    PrintToClientOrConsole(slot, "Plugin Info", "Author: %s\n", reinterpret_cast<GetPlugin>(GetPluginAuthor)());
    PrintToClientOrConsole(slot, "Plugin Info", "Version: %s\n", reinterpret_cast<GetPlugin>(GetPluginVersion)());
    PrintToClientOrConsole(slot, "Plugin Info", "URL: %s\n", website == "" ? "Not Present" : website.c_str());
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

void SwiftlyPluginManagerRefresh(CPlayerSlot *slot, CCommandContext context)
{
    if (slot->Get() != -1)
        return;

    std::vector<std::string> pluginNames;

    std::vector<std::string> files = Files::FetchFileNames("addons/swiftly/plugins");
    for (const std::string &file : files)
    {
        if (!ends_with(file, WIN_LINUX(".dll", ".so")))
            continue;
        if (starts_with(file, WIN_LINUX("disabled\\", "disabled/")))
            continue;

        pluginNames.push_back(file);
    }

    uint32 newPlugins = 0;

    for (const std::string plugin_name : pluginNames)
    {
        Plugin *plugin = new Plugin(plugin_name);
        if (!ExistsPluginInMap(plugin_name))
        {
            AddPluginInMap(plugin);
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

void SwiftlyConFilterManagerHelp(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Console Filtering Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly confilter <command>\n");
    PrintToClientOrConsole(slot, "Commands", " disable    - Disables the console filtering.\n");
    PrintToClientOrConsole(slot, "Commands", " enable     - Enables the console filtering.\n");
    PrintToClientOrConsole(slot, "Commands", " reload     - Reloads the console filtering messages.\n");
    PrintToClientOrConsole(slot, "Commands", " stats      - Shows the console filter stats.\n");
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

void SwiftlyVersion(CPlayerSlot *slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Version", "Swiftly Version informations:\n");
    PrintToClientOrConsole(slot, "Version", " Swiftly Version: %s\n", g_Plugin.GetVersion());
    PrintToClientOrConsole(slot, "Version", " Swiftly API Version: %d\n", g_Plugin.GetApiVersion());
    PrintToClientOrConsole(slot, "Version", " Swiftly C++ Version: %s\n", GetCppVersion());
    PrintToClientOrConsole(slot, "Version", " Compiled on: %s %s\n", __DATE__, __TIME__);
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
    else if (subcmd == "version")
        SwiftlyVersion(slot, context);
    else
        ShowSwiftlyCommandHelp(slot, context);
}

CON_COMMAND_F(swiftly, "The main command for Swiftly.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
{
    SwiftlyCommand(context, args);
}
CON_COMMAND_F(sw, "The main command for Swiftly.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND)
{
    SwiftlyCommand(context, args);
}