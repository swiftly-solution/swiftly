#include "usermessages.h"
#include "../sdk/entity/CRecipientFilters.h"

SH_DECL_HOOK8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)

void UserMessages::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);
}

void UserMessages::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);
}

void UserMessages::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType)
{
    static void (IGameEventSystem:: * PostEventAbstract)(CSplitScreenSlot, bool, int, const uint64*,
        INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t) = &IGameEventSystem::PostEventAbstract;

    uint64 newClients = *const_cast<uint64*>(clients);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", encoders::msgpack::SerializeToString({ string_format("%p|%p|%p", pEvent, pData, &newClients), bufType == BUF_RELIABLE }), event);
    delete event;

    SH_CALL(g_pGameEventSystem, PostEventAbstract)
        (nSlot, bLocalOnly, nClientCount, &newClients, pEvent, pData, nSize, bufType);
    RETURN_META(MRES_SUPERCEDE);
}