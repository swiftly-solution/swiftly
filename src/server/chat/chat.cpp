#include "chat.h"

#include <iomanip>
#include <ctime>

#include <network/usermessages/usermessage.h>
#include <filesystem/files/files.h>
#include <utils/common.h>
#include <utils/utils.h>
#include <rapidjson/json.hpp>
#include <sdk/schema.h>
#include <server/player/manager.h>

extern std::map<std::string, std::string> colors;

SH_DECL_EXTERN8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)

void ChatProcessor::Initialize()
{
#ifndef _WIN32
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &ChatProcessor::PostEvent, false);
#endif
}

void ChatProcessor::Shutdown()
{
#ifndef _WIN32
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &ChatProcessor::PostEvent, false);
#endif
}

void ChatError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Chat Processor", "%s\n", text.c_str());
}

void ChatProcessor::LoadMessages()
{
    this->placeholders.clear();
    rapidjson::Document chatFile;

    chatFile.Parse(Files::Read("addons/swiftly/configs/chat.json").c_str());
    if (chatFile.HasParseError())
        return ChatError(string_format("A parsing error has been detected.\nError (offset %u): %s\n", (unsigned)chatFile.GetErrorOffset(), GetParseError_En(chatFile.GetParseError())));

    if (chatFile.IsArray())
        return ChatError("Chat file cannot be an array.");

    for (auto it = chatFile.MemberBegin(); it != chatFile.MemberEnd(); ++it)
    {
        std::string key = it->name.GetString();
        if (!it->value.IsString())
        {
            ChatError(string_format("The field \"%s\" is not a string.", key.c_str()));
            continue;
        }
        std::string value = it->value.GetString();
        if (value.empty())
        {
            continue;
        }
        this->placeholders[key] = value;
    }
}

std::map<std::string, std::string> textMessageReplacements = {
    { "\n", "\u2029" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
    { "", "" },
};

std::string getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    return string_format("%02d:%02d", localTime->tm_hour, localTime->tm_min);
}
std::string getCompTeammateColorString(void* controller)
{
    switch (schema::GetProp<int>(controller, "CCSPlayerController", "m_iCompTeammateColor"))
    {
    case -2:
        return "{GREY}";
        break;
        // case -1: // IN MY CASE WAS YELLOW PROBABLY IS RANDOMLY?
        //     return "{YELLOW}";
        //     break;
    case 0:
        return "{BLUE}";
        break;
    case 1:
        return "{GREEN}";
        break;
    case 2:
        return "{YELLOW}";
        break;
    case 3:
        return "{ORANGE}";
        break;
    case 4:
        return "{PURPLE}";
        break;
    case 5:
        return "{RED}";
        break;
    default:
        return "{DEFAULT}";
        break;
    }
}

std::string formatPlayerMessage(Player* player, void* controller, std::string placeholder, std::string message, bool isRadio = false)
{
    for (auto it = textMessageReplacements.begin(); it != textMessageReplacements.end(); ++it)
        message = replace(message, it->first, it->second);

    std::string name = player->GetName();

    for (auto it = colors.begin(); it != colors.end(); ++it)
    {
        message = replace(message, it->first, "");
        message = replace(message, str_tolower(it->first), "");
        name = replace(name, it->first, "");
        name = replace(name, str_tolower(it->first), "");
    }

    std::map<std::string, std::string> replacements = {
        {"{NAME}", string_format("%s%s{default}", std::any_cast<std::string>(player->GetInternalVar("namecolor")).empty() ? "{teamcolor}" : std::any_cast<std::string>(player->GetInternalVar("namecolor")).c_str(), name.c_str())},
        {"{TAG}", string_format("%s%s{default}", std::any_cast<std::string>(player->GetInternalVar("tagcolor")).empty() ? "{default}" : std::any_cast<std::string>(player->GetInternalVar("tagcolor")).c_str(), std::any_cast<std::string>(player->GetInternalVar("tag")).c_str())},
        {"{LOCATION}", isRadio ? "%s2" : "%s3"},
        {"{TIME}", getCurrentTime().c_str()},
        {"{COMP_COLOR}", getCompTeammateColorString(controller).c_str()},
        {"{MESSAGE}",  string_format("%s%s", std::any_cast<std::string>(player->GetInternalVar("chatcolor")).c_str(), message.c_str())},
    };
    for (auto it = replacements.begin(); it != replacements.end(); ++it)
        placeholder = replace(placeholder, it->first, it->second);

    return ProcessColor(" " + placeholder, schema::GetProp<int>(controller, "CBaseEntity", "m_iTeamNum"));
}

#ifndef _WIN32
void ChatProcessor::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType)
{
    if (pEvent->GetNetMessageInfo()->m_MessageId == 118) {
        UserMessage um(pEvent, (CNetMessage*)pData, (uint64_t*)clients);
        Player* player = g_playerManager.GetPlayer(um.GetInt32("entityindex") - 1);
        if (!player) return;

        void* controller = player->GetController();
        if (!controller) return;

        std::string key = um.GetString("messagename");
        auto it = this->placeholders.find(key);
        if (it != this->placeholders.end()) {
            um.SetString("messagename", formatPlayerMessage(player, controller, it->second.c_str(), um.GetString("param2")).c_str());
        }
    }
    else if (pEvent->GetNetMessageInfo()->m_MessageId == 322) {
        UserMessage um(pEvent, (CNetMessage*)pData, (uint64_t*)clients);
        Player* player = g_playerManager.GetPlayer(um.GetInt32("client"));
        if (!player) return;

        void* controller = player->GetController();
        if (!controller) return;

        auto it = this->placeholders.find(um.GetRepeatedString("params", 2));
        if (it != this->placeholders.end()) {
            um.SetString("msg_name", formatPlayerMessage(player, controller, it->second.c_str(), um.GetRepeatedString("params", 2), true).c_str());
        }
    }
}
#endif