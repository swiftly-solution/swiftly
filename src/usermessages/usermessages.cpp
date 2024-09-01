#include "usermessages.h"
#include "../sdk/entity/CRecipientFilters.h"

SH_DECL_HOOK6_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, IRecipientFilter*, INetworkMessageInternal*, const CNetMessage*, unsigned long)

void UserMessages::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);
}

void UserMessages::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &UserMessages::PostEvent, false);
}

void UserMessages::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, IRecipientFilter* filter, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize)
{
    CRecipientFilter* flt = (CRecipientFilter*)filter;
    std::vector<CPlayerSlot> players;
    for (int i = 0; i < flt->GetRecipientCount(); i++)
        players.push_back(flt->GetRecipientIndex(i));

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);

    for (auto player : players)
    {
        auto result = g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", encoders::msgpack::SerializeToString({ player.Get(), string_format("%p", pEvent), filter->GetNetworkBufType() == BUF_RELIABLE }), event);
        if (result == EventResult::Stop)
            flt->RemoveRecipient(player);
    }

    delete event;
}