#include "commands.h"

#include <server/chat/chat.h>

void SwiftlyChatReload(CPlayerSlot slot)
{
    g_chatProcessor.LoadMessages();
    PrintToClientOrConsole(slot, "Chat Processor", "All chat messages has been succesfully reloaded.\n");
}

void SwiftlyChatManagerHelp(CPlayerSlot slot)
{
    PrintToClientOrConsole(slot, "Commands", "Swiftly Chat Menu\n");
    PrintToClientOrConsole(slot, "Commands", "Usage: sw chat <command>\n");
    PrintToClientOrConsole(slot, "Commands", " reload     - Reload chat message configurations.\n");
}

void SwiftlyChatManager(CPlayerSlot slot, const char* subcmd)
{
    if (slot.Get() != -1)
        return;

    std::string sbcmd = subcmd;
    if (sbcmd.size() == 0)
    {
        SwiftlyChatManagerHelp(slot);
        return;
    }

    if (sbcmd == "reload")
        SwiftlyChatReload(slot);
    else
        SwiftlyChatManagerHelp(slot);
}