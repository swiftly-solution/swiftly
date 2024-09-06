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

    uint64 oldClients = *clients;
    uint64 newClients = 0;

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    for (uint64 i = 0; i < 64; i++)
        if (oldClients & ((uint64)1 << i))
            if (g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", encoders::msgpack::SerializeToString({ i, string_format("%p|%p", pEvent, pData), bufType == BUF_RELIABLE }), event) != EventResult::Stop)
                newClients |= ((uint64)1 << i);

    delete event;

    SH_CALL(g_pGameEventSystem, PostEventAbstract)
        (nSlot, bLocalOnly, nClientCount, &newClients, pEvent, pData, nSize, bufType);
    RETURN_META(MRES_SUPERCEDE);
}