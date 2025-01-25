#include "commands.h"

void ShowSwiftlyCommands(CPlayerSlot slot, int page)
{
    std::map<std::string, Command*> cmds = g_commandsManager->GetCommands();
    PrintToClientOrConsole(slot, "Commands", "There are %d commands created by plugins.\n", cmds.size());
    PrintToClientOrConsole(slot, "Commands", "Below will be shown a list of all the commands:\n");

    if (page < 1)
        page = 1;
    else if (static_cast<unsigned int>(page) * 10 > cmds.size())
        page = int(ceil(double(cmds.size()) / 10.0));

    std::map<std::string, Command*>::iterator it = cmds.begin();
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