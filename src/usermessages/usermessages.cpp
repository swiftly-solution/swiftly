#include "usermessages.h"
#include <map>

bool UserMessages_SendNetMessage(INetChannel* pNetChan, CNetMessage* pData, NetChannelBufType_t bufType)
{
    auto netmsg = pData->GetNetMessage();
    int playerid = FindClientByNetChannel(pNetChan);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    auto result = g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", encoders::msgpack::SerializeToString({ playerid, string_format("%p", netmsg), bufType == BUF_RELIABLE }), event);
    delete event;

    return (result != EventResult::Stop);
}