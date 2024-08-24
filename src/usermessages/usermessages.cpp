#include "usermessages.h"
#include <map>

bool UserMessages_SendNetMessage(INetChannel* pNetChan, CNetMessage* pData, int a4)
{
    auto netmsg = pData->GetNetMessage();
    int playerid = FindClientByNetChannel(pNetChan);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    auto result = g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", encoders::msgpack::SerializeToString({ playerid, string_format("%p|%p|%p", netmsg, netmsg->GetNetMessageInfo(), pData), a4 == NetChannelBufType_t::BUF_RELIABLE }), event);
    delete event;

    return (result != EventResult::Stop);
}