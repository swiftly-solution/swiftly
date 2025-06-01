#include "commands.h"
#include <server/configuration/configuration.h>

void SwiftlyConfigurationManagerHelp(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Configuration Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: sw config <command>\n");
    PrintToClientOrConsole(slot, "Commands", " reload     - Reloads all the plugin configurations.\n");
}

void SwiftlyConfigurationReload(CPlayerSlot slot)
{
    g_Config.ClearPluginConfig();
    g_Config.LoadPluginConfigurations();
    PrintToClientOrConsole(slot, "Configuration", "You've succesfully reloaded all the configurations for plugins.\n");
}

void SwiftlyConfigurationManager(CPlayerSlot slot, const char* subcmd)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyConfigurationManagerHelp(slot);
        return;
    }

    if (sbcmd == "reload")
        SwiftlyConfigurationReload(slot);
    else
        SwiftlyConfigurationManagerHelp(slot);
}