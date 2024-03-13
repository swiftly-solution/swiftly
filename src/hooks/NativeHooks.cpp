#include "NativeHooks.h"
#include "../common.h"
#include "../components/Plugins/inc/Scripting.h"
#include "../events/gameevents.h"
#include "../commands/CommandsManager.h"
#include "../filter/ConsoleFilter.h"
#include "../addons/addons.h"
#include "../addons/clients.h"
#include "networkbasetypes.pb.h"
#include "networksystem/inetworkserializer.h"
#include "../sdk/entity/serversideclient.h"

FuncHook<decltype(Hook_LoggingSystem_LogDirect)> LoggingSystemt_LogDirect(Hook_LoggingSystem_LogDirect, "LoggingSystem_LogDirect");
FuncHook<decltype(Hook_LoggingSystem_Log)> LoggingSystemt_Log(Hook_LoggingSystem_Log, "LoggingSystem_Log");
FuncHook<decltype(Hook_Msg)> TMsg(Hook_Msg, "Msg");
FuncHook<decltype(Hook_Warning)> TWarning(Hook_Warning, "Warning");
FuncHook<decltype(Hook_LoggingSystem_LogAssert)> LoggingSystemt_LogAssert(Hook_LoggingSystem_LogAssert, "LoggingSystem_LogAssert");
FuncHook<decltype(Hook_ClientPrint)> TClientPrint(Hook_ClientPrint, "ClientPrint");
FuncHook<decltype(Hook_IsHearingClient)> TIsHearingClient(Hook_IsHearingClient, "IsHearingClient");
FuncHook<decltype(Hook_PrecacheResource)> TPrecacheResource(Hook_PrecacheResource, "PrecacheResource");
FuncHook<decltype(Hook_CGameRules_Constructor)> TCGameRules_Constructor(Hook_CGameRules_Constructor, "CGameRules_Constructor");
FuncHook<decltype(Hook_SendNetMessage)> TSendNetMessage(Hook_SendNetMessage, "SendNetMessage");
FuncHook<decltype(Hook_HostStateRequest)> THostStateRequest(Hook_HostStateRequest, "HostStateRequest");
FuncHook<decltype(Hook_CCSPlayerPawnBase_PostThink)> TCCSPlayerPawnBase_PostThink(Hook_CCSPlayerPawnBase_PostThink, "CCSPlayerPawnBase_PostThink");

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

void Hook_LoggingSystem_LogDirect(int channelId, int severity, const char *message, ...)
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

void Hook_Msg(const char *message, ...)
{
    CHECKLOGS()
    TMsg(buffer);
}

void Hook_Warning(const char *message, ...)
{
    CHECKLOGS()
    TWarning(buffer);
}

void Hook_ClientPrint(CBasePlayerController *controller, int destination, const char *message, const char *arg1, const char *arg2, const char *arg3, const char *arg4)
{
    bool ret = scripting_OnClientGameMessage(controller, destination, message);
    if (!ret)
        return;

    TClientPrint(controller, destination, message, arg1, arg2, arg3, arg4);
}

bool Hook_IsHearingClient(void *serverClient, int playerSlot)
{
    Player *player = g_playerManager->GetPlayer(playerSlot);
    if (player != nullptr)
        if (!scripting_ShouldHearVoice(player))
            return false;

    return TIsHearingClient(serverClient, playerSlot);
}

void Hook_PrecacheResource(const char *model_path, int64_t context)
{
    if (g_precacher->GetContext() == 0 && starts_with(std::string(model_path), "models/"))
    {
        g_precacher->SetContext(context);
        g_precacher->CacheModels();
    }

    TPrecacheResource(model_path, context);
}

void Hook_CGameRules_Constructor(CGameRules *pThis)
{
    g_pGameRules = (CCSGameRules *)pThis;
    TCGameRules_Constructor(pThis);
}

extern double g_flUniversalTime;

void Hook_SendNetMessage(INetChannel *pNetChan, INetworkSerializable *pNetMessage, void *pData, int a4)
{
    NetMessageInfo_t *info = pNetMessage->GetNetMessageInfo();

    if (info->m_MessageId != 7 || g_addons->GetStatus() == false || g_addons->GetAddons().size() == 0)
        return TSendNetMessage(pNetChan, pNetMessage, pData, a4);

    ClientJoinInfo_t *pPendingClient = GetPendingClient(pNetChan);

    if (pPendingClient)
    {
        CNETMsg_SignonState *pMsg = (CNETMsg_SignonState *)pData;
        pMsg->set_addons(g_addons->GetAddons()[pPendingClient->addon].c_str());
        pMsg->set_signon_state(SIGNONSTATE_CHANGELEVEL);
        pPendingClient->signon_timestamp = g_flUniversalTime;
    }

    TSendNetMessage(pNetChan, pNetMessage, pData, a4);
}

void *Hook_HostStateRequest(void *a1, void **pRequest)
{
    if (g_addons->GetStatus() == false || g_addons->GetAddons().size() == 0 || V_strnicmp((char *)pRequest[2], "changelevel", 11))
        return THostStateRequest(a1, pRequest);

    CUtlString *sAddonString = (CUtlString *)(pRequest + 11);

    if (!sAddonString->IsEmpty())
        sAddonString->Format("%s,%s", sAddonString->Get(), implode(g_addons->GetAddons(), ",").c_str());
    else
        sAddonString->Set(implode(g_addons->GetAddons(), ",").c_str());

    return THostStateRequest(a1, pRequest);
}

void scripting_OnPlayerPostThink(CPlayerSlot slot);

void Hook_CCSPlayerPawnBase_PostThink(CCSPlayerPawnBase *base)
{
    TCCSPlayerPawnBase_PostThink(base);

    scripting_OnPlayerPostThink(CPlayerSlot(base->GetEntityIndex().Get() - 1));
}

CUtlVector<FuncHookBase *> g_funcHooks;

bool InitializeHooks()
{
    g_funcHooks.PurgeAndDeleteElements();

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

    if (!TPrecacheResource.Create())
        return false;
    TPrecacheResource.Enable();

    if (!TCGameRules_Constructor.Create())
        return false;
    TCGameRules_Constructor.Enable();

    if (!TSendNetMessage.Create())
        return false;
    TSendNetMessage.Enable();

    if (!THostStateRequest.Create())
        return false;
    THostStateRequest.Enable();

    if (!TCCSPlayerPawnBase_PostThink.Create())
        return false;
    TCCSPlayerPawnBase_PostThink.Enable();

    return true;
}