#include "commands.h"

void ShowSwiftlyCommandHelp(CPlayerSlot slot)
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
        PrintToClientOrConsole(slot, "Commands", " cvars        - List all convars created by plugins\n");
        PrintToClientOrConsole(slot, "Commands", " config       - Configuration Management Menu\n");
        PrintToClientOrConsole(slot, "Commands", " exts         - Extension Management Menu\n");
        PrintToClientOrConsole(slot, "Commands", " plugins      - Plugin Management Menu\n");
        PrintToClientOrConsole(slot, "Commands", " resmon       - Resource Monitor Menu\n");
        PrintToClientOrConsole(slot, "Commands", " translations - Translations Menu\n");
        PrintToClientOrConsole(slot, "Commands", " chat         - Chat Menu\n");
    }
    PrintToClientOrConsole(slot, "Commands", " version      - Display Swiftly version\n");
}