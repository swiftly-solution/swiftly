#include "NativeHooks.h"
#include "../common.h"
#include "../components/Plugins/inc/Scripting.h"
#include "../events/gameevents.h"
#include "../commands/CommandsManager.h"

FuncHook<decltype(Hook_Host_Say)> Host_Say(Hook_Host_Say, "Host_Say");

void __fastcall Hook_Host_Say(CBasePlayerController *controller, CCommand &args, bool teamonly, int unk1, const char *unk2)
{
    if (!controller)
        return;

    int handleCommands = g_commandsManager->HandleCommands(controller, args[1]);
    if (handleCommands == 2)
        return;

    if (!scripting_OnClientChat(controller, args[1], teamonly))
        return;

    Host_Say(controller, args, teamonly, unk1, unk2);

    IGameEvent *event = g_gameEventManager->CreateEvent("player_chat");
    if (event)
    {
        event->SetBool("teamonly", teamonly);
        event->SetInt("userid", controller->GetRefEHandle().GetEntryIndex());
        event->SetString("text", args[1]);
        g_gameEventManager->FireEvent(event, true);
    }
}

CUtlVector<FuncHookBase *> g_funcHooks;

bool InitializeHooks()
{
    g_funcHooks.PurgeAndDeleteElements();

    if (!Host_Say.Create())
        return false;
    Host_Say.Enable();
}