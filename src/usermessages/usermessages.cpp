#include "usermessages.h"
#include <msgpack.hpp>
#include <map>

std::map<std::string, PluginUserMessage*> scriptingUserMessages;

PluginUserMessage* FetchUserMessage(std::string uuid)
{
    if (!ExistsUserMessage(uuid)) return nullptr;
    return scriptingUserMessages.at(uuid);
}

bool ExistsUserMessage(std::string uuid)
{
    return (scriptingUserMessages.find(uuid) != scriptingUserMessages.end());
}

void EraseUserMessage(std::string uuid)
{
    if (!ExistsUserMessage(uuid)) return;
    scriptingUserMessages.erase(uuid);
}

std::string InsertUserMessage(PluginUserMessage* um)
{
    std::string uuid = get_uuid();
    if (ExistsUserMessage(uuid)) EraseUserMessage(uuid);
    scriptingUserMessages.insert({ uuid, um });

    return uuid;
}

bool UserMessages_SendNetMessage(INetChannel* pNetChan, CNetMessage* pData, int a4)
{
    auto netmsg = pData->GetNetMessage();
    int playerid = FindClientByNetChannel(pNetChan);

    PluginUserMessage* um = new PluginUserMessage(netmsg, netmsg->GetNetMessageInfo(), pData);
    std::string uuid = InsertUserMessage(um);

    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(playerid));
    eventData.push_back(msgpack::object(uuid.c_str()));
    eventData.push_back(msgpack::object(a4 == NetChannelBufType_t::BUF_RELIABLE));

    msgpack::pack(ss, eventData);

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    auto result = g_pluginManager->ExecuteEvent("core", "OnUserMessageSend", ss.str(), event);
    delete event;

    EraseUserMessage(uuid);
    delete um;

    return (result != EventResult::Stop);
}