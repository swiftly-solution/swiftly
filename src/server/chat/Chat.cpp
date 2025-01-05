#include "Chat.h"
#include "../../player/playermanager/PlayerManager.h"
#include "../../server/commands/CommandsManager.h"
#include "usermessages.pb.h"
#include "../../filesystem/files/Files.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <iostream>
#include <iomanip>
#include <ctime>

SH_DECL_EXTERN8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)
SH_DECL_EXTERN3_void(ICvar, DispatchConCommand, SH_NOATTRIB, 0, ConCommandHandle, const CCommandContext&, const CCommand&);


void ChatProcessor::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &ChatProcessor::PostEvent, false);
    SH_ADD_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &ChatProcessor::DispatchConCommand, false);
}

void ChatProcessor::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &ChatProcessor::PostEvent, false);
    SH_REMOVE_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &ChatProcessor::DispatchConCommand, false);
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

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << localTime->tm_hour << ":"
        << std::setw(2) << std::setfill('0') << localTime->tm_min;

    return oss.str();
}
std::string getCompTeammateColorString(CCSPlayerController* controller)
{
    switch (controller->m_iCompTeammateColor)
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

std::string formatPlayerMessage(Player* player, CCSPlayerController* controller, std::string placeholder, std::string message, bool isRadio = false)
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
        {"{NAME}", string_format("%s%s{default}", player->namecolor.empty() ? "{teamcolor}" : player->namecolor.c_str(), name.c_str())},
        {"{TAG}", string_format("%s%s{default}", player->tagcolor.empty() ? "{default}" : player->tagcolor.c_str(), player->tag.c_str())},
        {"{LOCATION}", isRadio ? "%s2" : "%s3"},
        {"{TIME}", getCurrentTime().c_str()},
        {"{COMP_COLOR}", getCompTeammateColorString(controller).c_str()},
        {"{MESSAGE}",  string_format("%s%s", player->chatcolor.c_str(), message.c_str())},
    };
    for (auto it = replacements.begin(); it != replacements.end(); ++it)
        placeholder = replace(placeholder, it->first, it->second);

    return ProcessColor(" " + placeholder, controller->m_iTeamNum());
}
void ChatProcessor::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType)
{
#ifndef _WIN32
    if (pEvent->GetNetMessageInfo()->m_MessageId == 118) {
        PluginUserMessage um(pEvent, (CNetMessage*)pData, (uint64*)clients);
        Player* player = g_playerManager->GetPlayer(um.GetInt32("entityindex") - 1);
        if (!player) return;

        CCSPlayerController* controller = player->GetPlayerController();
        if (!controller) return;

        std::string key = um.GetString("messagename");
        auto it = this->placeholders.find(key);
        if (it != this->placeholders.end()) {
            um.SetString("messagename", formatPlayerMessage(player, controller, it->second.c_str(), um.GetString("param2")).c_str());
        }
    }
    else if (pEvent->GetNetMessageInfo()->m_MessageId == 322) {
        PluginUserMessage um(pEvent, (CNetMessage*)pData, (uint64*)clients);
        Player* player = g_playerManager->GetPlayer(um.GetInt32("client"));
        if (!player) return;
        CCSPlayerController* controller = player->GetPlayerController();
        if (!controller) return;

        auto it = this->placeholders.find(um.GetRepeatedString("params", 2));
        if (it != this->placeholders.end()) {
            um.SetString("msg_name", formatPlayerMessage(player, controller, it->second.c_str(), um.GetRepeatedString("params", 2), true).c_str());
        }
    }
#endif
}

bool OnClientCommand(int playerid, std::string command);

void ChatProcessor::DispatchConCommand(ConCommandHandle cmd, const CCommandContext& ctx, const CCommand& args)
{
    CPlayerSlot slot = ctx.GetPlayerSlot();

    if (slot.Get() != -1)
    {
        if (!OnClientCommand(slot.Get(), args.GetCommandString()))
            RETURN_META(MRES_SUPERCEDE);

        std::string command = args.Arg(0);
        if (command == "say" || command == "say_team")
        {
            Player* player = g_playerManager->GetPlayer(slot);
            if (!player) return;

            CCSPlayerController* controller = player->GetPlayerController();
            bool teamonly = (command == "say_team");

            std::vector<std::string> textSplitted = explode(args.GetCommandString(), " ");
            textSplitted.erase(textSplitted.begin());

            std::string text = implode(textSplitted, " ");
            if (text.front() == '\'' || text.front() == '"') text.erase(text.begin());
            if (text.back() == '\'' || text.back() == '"') text.pop_back();

            if (strim(text).length() == 0) RETURN_META(MRES_SUPERCEDE);

            if (controller)
            {
                IGameEvent* pEvent = g_gameEventManager->CreateEvent("player_chat");

                if (pEvent)
                {
                    pEvent->SetBool("teamonly", teamonly);
                    pEvent->SetInt("userid", slot.Get());
                    pEvent->SetString("text", text.c_str());

                    g_gameEventManager->FireEvent(pEvent, true);
                    g_gameEventManager->FreeEvent(pEvent);
                }
            }

            int handleCommandReturn = g_commandsManager->HandleCommand(player, text);
            if (handleCommandReturn == 2 || !OnClientChat(slot.Get(), text, teamonly)) RETURN_META(MRES_SUPERCEDE);
        }
    }
}
