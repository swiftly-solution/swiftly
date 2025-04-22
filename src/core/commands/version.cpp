#include "commands.h"

void SwiftlyVersion(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "Version", "Swiftly Version informations:\n");
    PrintToClientOrConsole(slot, "Version", " Swiftly Version: %s (%s)\n", g_Plugin.GetVersion(), std::string(GITHUB_SHA).substr(0, 7).c_str());
    PrintToClientOrConsole(slot, "Version", " Swiftly API Version: %d\n", g_Plugin.GetApiVersion());
    PrintToClientOrConsole(slot, "Version", " Swiftly C++ Version: %s\n", GetCppVersion());
    PrintToClientOrConsole(slot, "Version", " Compiled on: %s %s\n", __DATE__, __TIME__);
    PrintToClientOrConsole(slot, "Version", " Github Commit: https://github.com/swiftly-solution/swiftly/commit/%s\n", std::string(GITHUB_SHA).c_str());
    PrintToClientOrConsole(slot, "Version", " https://github.com/swiftly-solution \n");
}
