#include "usermessages.h"
#include "../../sdk/entity/CRecipientFilters.h"
#include "../../sdk/entity/serversideclient.h"

#include "../../utils/memory.h"

SH_DECL_EXTERN8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)
SH_DECL_MANUALHOOK2(FilterMessage, 0, 0, 0, bool, const CNetMessage*, INetChannel*);

PluginEvent* umEvent = nullptr;
PluginEvent* userUmEvent = nullptr;

int hookID = -1;

void UserMessages::Initialize()
{
    umEvent = new PluginEvent("core", nullptr, nullptr);
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);

    userUmEvent = new PluginEvent("core", nullptr, nullptr);
    DynLibUtils::CModule eng = DetermineModuleByLibrary("engine2");
    void* serverSideClientVTable = FindVirtTable(&eng, "CServerSideClient", g_Offsets->GetOffset("INetworkMessageProcessingPreFilter"));

    hookID = SH_ADD_MANUALDVPHOOK(FilterMessage, serverSideClientVTable, SH_MEMBER(this, &UserMessages::FilterMessage), false);
}

bool UserMessages::FilterMessage(const CNetMessage* cMsg, INetChannel* netchan)
{
    auto client = META_IFACEPTR(CServerSideClient);
    if(!client) RETURN_META_VALUE(MRES_IGNORED, true);

    auto result = g_pluginManager->ExecuteEvent("core", "OnUserMessageReceive", encoders::msgpack::SerializeToString({ client->GetPlayerSlot().Get(), string_format("%p|%p|0x0", cMsg->GetNetMessage(), cMsg) }), userUmEvent);
    if(result != EventResult::Continue)
        RETURN_META_VALUE(MRES_SUPERCEDE, true);

    RETURN_META_VALUE(MRES_IGNORED, true);
}

void UserMessages::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);
    delete umEvent;

    SH_REMOVE_HOOK_ID(hookID);
    hookID = -1;
    delete userUmEvent;
}

void UserMessages::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType)
{
    if(g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", encoders::msgpack::SerializeToString({ string_format("%p|%p|%p", pEvent, pData, clients), bufType == BUF_RELIABLE }), umEvent) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);
}