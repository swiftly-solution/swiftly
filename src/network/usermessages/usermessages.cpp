#include "usermessages.h"
#include "usermessage.h"

#include <sdk/components/CServerSideClient.h>
#include <memory/gamedata/gamedata.h>
#include <utils/memory.h>
#include <plugins/manager.h>

#include <dynlibutils/module.h>

DynLibUtils::CModule DetermineModuleByLibrary(std::string library);

SH_DECL_EXTERN8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)
SH_DECL_MANUALHOOK2(FilterMessage, 0, 0, 0, bool, const CNetMessage*, INetChannel*);

int hookID = -1;

void UserMessages::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);

#ifndef _WIN32
    DynLibUtils::CModule eng = DetermineModuleByLibrary("engine2");
    void* serverSideClientVTable = FindVirtTable(&eng, "CServerSideClient", g_GameData.GetOffset("INetworkMessageProcessingPreFilter"));

    hookID = SH_ADD_MANUALDVPHOOK(FilterMessage, serverSideClientVTable, SH_MEMBER(this, &UserMessages::FilterMessage), false);
#endif
}

bool UserMessages::FilterMessage(const CNetMessage* cMsg, INetChannel* netchan)
{
    auto client = META_IFACEPTR(CServerSideClient);
    if (!client) RETURN_META_VALUE(MRES_IGNORED, true);
    if (!cMsg) RETURN_META_VALUE(MRES_IGNORED, true);

    UserMessage um(cMsg->GetNetMessage(), const_cast<CNetMessage*>(cMsg), (uint64_t*)0);
    ClassData* umobj = new ClassData({ { "um_ptr", &um } }, "UserMessage", nullptr);
    auto result = g_pluginManager.ExecuteEvent("core", "OnUserMessageReceive", { client->GetPlayerSlot().Get(), umobj }, {});
    delete umobj;
    if (result != EventResult::Continue)
        RETURN_META_VALUE(MRES_SUPERCEDE, true);

    RETURN_META_VALUE(MRES_IGNORED, true);
}

void UserMessages::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);

#ifndef _WIN32
    SH_REMOVE_HOOK_ID(hookID);
    hookID = -1;
#endif
}

void UserMessages::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType)
{
    UserMessage um(pEvent, const_cast<CNetMessage*>(pData), (uint64_t*)(const_cast<uint64*>(clients)));
    ClassData* umobj = new ClassData({ { "um_ptr", &um } }, "UserMessage", nullptr);

    if (g_pluginManager.ExecuteEvent("core", "OnUserMessageSend", { umobj, bufType == BUF_RELIABLE }, {}) == EventResult::Stop) {
        delete umobj;
        RETURN_META(MRES_SUPERCEDE);
    }

    delete umobj;
}