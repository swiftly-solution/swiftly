#include <string>
#include <TextTable.h>

#include <tier1/convar.h>

#include "../entrypoint.h"
#include "../common.h"
#include "../utils/utils.h"
#include "../player/PlayerManager.h"
#include "../filters/ConsoleFilter.h"

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

    PrintTextTable("Status", statusTable);

    PrintToClientOrConsole(slot, "Status", "end of status\n");
}

void ShowSwiftlyCommandHelp(CPlayerSlot slot, CCommandContext context)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Commands Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: swiftly <command> [args]\n");
    PrintToClientOrConsole(slot, "Commands", " credits      - List Swiftly credits\n");
    PrintToClientOrConsole(slot, "Commands", " help         - Show the help for Swiftly commands\n");
    PrintToClientOrConsole(slot, "Commands", " list         - Show the list of online players\n");
    PrintToClientOrConsole(slot, "Commands", " status       - Show the status of the players\n");
    if (slot.Get() == -1)
    {
        PrintToClientOrConsole(slot, "Commands", " confilter    - Console Filtering Menu\n");
    }
    PrintToClientOrConsole(slot, "Commands", " version      - Display Swiftly version\n");
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
    else if (subcmd == "help")
        ShowSwiftlyCommandHelp(slot, context);
    else if (subcmd == "version")
        SwiftlyVersion(slot, context);
    else if (subcmd == "list")
        SwiftlyList(slot, context);
    else if (subcmd == "confilter")
        SwiftlyConFilterManager(slot, context, args[2]);
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