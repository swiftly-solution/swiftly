#include "../../../../common.h"
#include "../../../../commands/CommandsManager.h"

SMM_API void scripting_Commands_RegisterCommand(const char *name, void *funcPtr)
{
    Command *cmd = g_commandsManager->FetchCommand(name);
    if (cmd != nullptr)
    {
        PRINTF("Command Manager", "Command \"%s\" was already registered.\n", name);
        return;
    }

    Command *newcmd = new Command(funcPtr);
    g_commandsManager->RegisterCommand(name, newcmd);
}

SMM_API void scripting_Commands_UnregisterCommand(const char *name)
{
    Command *cmd = g_commandsManager->FetchCommand(name);
    if (cmd == nullptr)
    {
        PRINTF("Command Manager", "Command \"%s\" doesn't exists.\n", name);
        return;
    }

    g_commandsManager->UnregisterCommand(name);
}