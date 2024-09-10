#include "usermessages.h"
#include "../sdk/entity/CRecipientFilters.h"

SH_DECL_HOOK8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)

PluginEvent* umEvent = nullptr;

void UserMessages::Initialize()
{
    umEvent = new PluginEvent("core", nullptr, nullptr);
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);
}

void UserMessages::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);
    delete umEvent;
}

void UserMessages::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType)
{
    g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", encoders::msgpack::SerializeToString({ string_format("%p|%p|%p", pEvent, pData, clients), bufType == BUF_RELIABLE }), umEvent);
}