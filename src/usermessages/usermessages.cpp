#include "usermessages.h"
#include <msgpack.hpp>
#include <map>

bool UserMessages_SendNetMessage(INetChannel* pNetChan, CNetMessage* pData, int a4)
{
    auto netmsg = pData->GetNetMessage();
    int playerid = FindClientByNetChannel(pNetChan);

    PluginUserMessage um(netmsg, netmsg->GetNetMessageInfo(), pData);

    std::string uuid = get_uuid();
    if (scriptingUserMessages.find(uuid) != scriptingUserMessages.end()) scriptingUserMessages.erase(uuid);
    scriptingUserMessages.insert({ uuid, um });

    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(playerid));
    eventData.push_back(msgpack::object(uuid.c_str()));
    eventData.push_back(msgpack::object(a4 == NetChannelBufType_t::BUF_RELIABLE));

    msgpack::pack(ss, eventData);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    auto result = g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", ss.str(), event);
    delete event;

    scriptingUserMessages.erase(uuid);

    return (result != EventResult::Stop);
}