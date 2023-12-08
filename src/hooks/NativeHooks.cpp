#include "NativeHooks.h"
#include "../common.h"
#include "../components/Plugins/inc/Scripting.h"
#include "../events/gameevents.h"
#include "../commands/CommandsManager.h"
#include "../filter/ConsoleFilter.h"

FuncHook<decltype(Hook_Host_Say)> Host_Say(Hook_Host_Say, "Host_Say");
FuncHook<decltype(Hook_LoggingSystem_LogDirect)> LoggingSystemt_LogDirect(Hook_LoggingSystem_LogDirect, "LoggingSystem_LogDirect");
FuncHook<decltype(Hook_LoggingSystem_Log)> LoggingSystemt_Log(Hook_LoggingSystem_Log, "LoggingSystem_Log");
FuncHook<decltype(Hook_Msg)> TMsg(Hook_Msg, "Msg");
FuncHook<decltype(Hook_Warning)> TWarning(Hook_Warning, "Warning");
FuncHook<decltype(Hook_LoggingSystem_LogAssert)> LoggingSystemt_LogAssert(Hook_LoggingSystem_LogAssert, "LoggingSystem_LogAssert");
FuncHook<decltype(Hook_ClientPrint)> TClientPrint(Hook_ClientPrint, "ClientPrint");
FuncHook<decltype(Hook_IsHearingClient)> TIsHearingClient(Hook_IsHearingClient, "IsHearingClient");

#define CHECKLOGS()                                                \
    va_list args;                                                  \
    char buffer[4096];                                             \
    va_start(args, message);                                       \
                                                                   \
    size_t len = vsnprintf(buffer, sizeof(buffer), message, args); \
    if (len >= sizeof(buffer))                                     \
    {                                                              \
        len = sizeof(buffer) - 1;                                  \
        buffer[len] = '\0';                                        \
    }                                                              \
    va_end(args);                                                  \
    if (g_conFilter->Status())                                     \
        if (g_conFilter->NeedFiltering(buffer))                    \
            return;

void FASTCALL Hook_Host_Say(CBasePlayerController *controller, CCommand &args, bool teamonly, int unk1, const char *unk2)
{
    if (!controller)
        return;

    if (strlen(args[1]) == 0)
        return;

    int handleCommands = g_commandsManager->HandleCommands(controller, args[1]);
    if (handleCommands == 2)
        return;

    if (!scripting_OnClientChat(controller, args[1], teamonly))
        return;

    Host_Say(controller, args, teamonly, unk1, unk2);
}

void FASTCALL Hook_LoggingSystem_LogDirect(int channelId, int severity, const char *message, ...)
{
    CHECKLOGS();
    LoggingSystemt_LogDirect(channelId, severity, buffer);
}

void Hook_LoggingSystem_Log(int channelId, int severity, const char *message, ...)
{
    CHECKLOGS();
    LoggingSystemt_Log(channelId, severity, buffer);
}

void Hook_LoggingSystem_LogAssert(const char *message, ...)
{
    CHECKLOGS();
    LoggingSystemt_LogAssert(buffer);
}

void FASTCALL Hook_Msg(const char *message, ...)
{
    CHECKLOGS()
    TMsg(buffer);
}

void FASTCALL Hook_Warning(const char *message, ...)
{
    CHECKLOGS()
    TWarning(buffer);
}

void FASTCALL Hook_ClientPrint(CBasePlayerController *controller, int destination, const char *message, const char *arg1, const char *arg2, const char *arg3, const char *arg4)
{
    if (!scripting_OnClientGameMessage(controller, destination, message))
        return;

    TClientPrint(controller, destination, message, arg1, arg2, arg3, arg4);
}

bool FASTCALL Hook_IsHearingClient(void *serverClient, int playerSlot)
{
    Player *player = g_playerManager->GetPlayer(playerSlot);
    if (player != nullptr)
        if (!scripting_ShouldHearVoice(player))
            return false;

    return TIsHearingClient(serverClient, playerSlot);
}

CUtlVector<FuncHookBase *> g_funcHooks;

bool InitializeHooks()
{
    g_funcHooks.PurgeAndDeleteElements();

    if (!Host_Say.Create())
        return false;
    Host_Say.Enable();

    if (!LoggingSystemt_LogDirect.Create())
        return false;
    LoggingSystemt_LogDirect.Enable();

    if (!LoggingSystemt_Log.Create())
        return false;
    LoggingSystemt_Log.Enable();

    if (!LoggingSystemt_LogAssert.Create())
        return false;
    LoggingSystemt_LogAssert.Enable();

    if (!TMsg.Create())
        return false;
    TMsg.Enable();

    if (!TWarning.Create())
        return false;
    TWarning.Enable();

    if (!TClientPrint.Create())
        return false;
    TClientPrint.Enable();

    if (!TIsHearingClient.Create())
        return false;
    TIsHearingClient.Enable();

    return true;
}