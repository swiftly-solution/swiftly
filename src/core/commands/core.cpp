#include "commands.h"

void SwiftlyCommand(const CCommandContext& context, const CCommand& args)
{
    CPlayerSlot slot = context.GetPlayerSlot();
    if (args.ArgC() < 2)
    {
        ShowSwiftlyCommandHelp(slot);
        return;
    }

    std::string subcmd = args[1];
    if (subcmd == "credits")
        ShowSwiftlyCredits(slot);
    else if (subcmd == "cmds")
        ShowSwiftlyCommands(slot, V_StringToInt32(args[2], 1));
    else if (subcmd == "help")
        ShowSwiftlyCommandHelp(slot);
    else if (subcmd == "version")
        SwiftlyVersion(slot);
    else if (subcmd == "list")
        SwiftlyList(slot);
    else if (subcmd == "cvars")
        SwiftlyConvarsManager(slot, V_StringToInt32(args[2], 1));
    else if (subcmd == "translations")
        SwiftlyTranslationManager(slot, args[2]);
    else if (subcmd == "config")
        SwiftlyConfigurationManager(slot, args[2]);
    else if (subcmd == "exts")
        SwiftlyExtensionManager(slot, args[2]);
    else if (subcmd == "plugins")
        SwiftlyPluginManager(slot, args[2], args[3]);
    else if (subcmd == "resmon")
        SwiftlyResourceMonitorManager(slot, args[2], args[3]);
    else if (subcmd == "status")
        SwiftlyStatus(slot);
    else if (subcmd == "chat")
        SwiftlyChatManager(slot, args[2]);
    else
        ShowSwiftlyCommandHelp(slot);
}

CON_COMMAND_F(swiftly, "The main command for Swiftly.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND | FCVAR_SERVER_CAN_EXECUTE)
{
    SwiftlyCommand(context, args);
}

CON_COMMAND_F(sw, "The main command for Swiftly.", FCVAR_CLIENT_CAN_EXECUTE | FCVAR_LINKED_CONCOMMAND | FCVAR_SERVER_CAN_EXECUTE)
{
    SwiftlyCommand(context, args);
}