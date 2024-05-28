#include <string>

#include <tier1/convar.h>

#include "../entrypoint.h"
#include "../common.h"
#include "../utils/utils.h"
#include "../player/PlayerManager.h"

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
                                   player->GetSlot().Get(), player->GetName(), "BOT\t", seconds_to_time(player->GetConnectedTime()).c_str(), "Active");
        else
            PrintToClientOrConsole(slot, "Status", "#%d\t%s\t%llu\t%s\t%s\n",
                                   player->GetSlot().Get(), player->GetName(), controller->m_steamID(), seconds_to_time(player->GetConnectedTime()).c_str(), "Active");
    }
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
    PrintToClientOrConsole(slot, "Commands", " version      - Display Swiftly version\n");
}

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