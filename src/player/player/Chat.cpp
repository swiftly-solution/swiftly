#include "Chat.h"
#include "../playermanager/PlayerManager.h"
#include "../../server/commands/CommandsManager.h"
#include "usermessages.pb.h"

SH_DECL_EXTERN8_void(IGameEventSystem, PostEventAbstract, SH_NOATTRIB, 0, CSplitScreenSlot, bool, int, const uint64*, INetworkMessageInternal*, const CNetMessage*, unsigned long, NetChannelBufType_t)
SH_DECL_EXTERN3_void(ICvar, DispatchConCommand, SH_NOATTRIB, 0, ConCommandHandle, const CCommandContext&, const CCommand&);

void PlayerChat::Initialize()
{
    SH_ADD_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &PlayerChat::PostEvent, false);
    SH_ADD_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &PlayerChat::DispatchConCommand, false);
}

void PlayerChat::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(IGameEventSystem, PostEventAbstract, g_pGameEventSystem, this, &PlayerChat::PostEvent, false);
    SH_REMOVE_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &PlayerChat::DispatchConCommand, false);
}

std::string textMessageReplacements = {
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
}

std::string formatPlayerMessage(Player* player, CCSPlayerController* controller, bool teamOnly, std::string text)
{
    for(auto it = textMessageReplacements.begin(); it != textMessageReplacements.end(); ++it)
        text = replace(text, it->first, it->second);

    std::vector<std::string> msg;
    if (teamOnly) msg.push_back(ProcessColor(string_format("{teamcolor}[%s]{default}", controller->m_iTeamNum() == CS_TEAM_CT ? "CT" : (controller->m_iTeamNum() == CS_TEAM_T ? "T" : "SPEC")), controller->m_iTeamNum()));
    if (player->tag.length() > 0) msg.push_back(ProcessColor(string_format("%s%s{default}", player->tagcolor.empty() ? "{default}" : player->tagcolor.c_str(), player->tag.c_str()), controller->m_iTeamNum()));
    msg.push_back(string_format("%s%s%s%s:", ProcessColor(player->namecolor, controller->m_iTeamNum()).c_str(), player->GetName(), ProcessColor("{default}", CS_TEAM_CT).c_str(), (teamOnly ? ProcessColor(" {green}@ %s3{default}", CS_TEAM_CT) : "").c_str()));
    msg.push_back(string_format("%s%s", ProcessColor(player->chatcolor, controller->m_iTeamNum()).c_str(), text.c_str()));

    return (" " + implode(msg, " "));
}

void PlayerChat::PostEvent(CSplitScreenSlot nSlot, bool bLocalOnly, int nClientCount, const uint64* clients, INetworkMessageInternal* pEvent, const CNetMessage* pData, unsigned long nSize, NetChannelBufType_t bufType)
{
    if(pEvent->GetNetMessageInfo()->m_MessageId == 118) {
        PluginUserMessage um(pEvent, (CNetMessage*)pData, (uint64*)clients);
        Player* player = g_playerManager->GetPlayer(um.GetInt32("entityindex") - 1);
        if(!player) return;

        CCSPlayerController* controller = player->GetPlayerController();
        if(!controller) return;

        um.SetString("messagename", formatPlayerMessage(player, controller, um.GetString("messagename").find("All") == std::string::npos, um.GetString("param2")).c_str());
    }
}

void PlayerChat::DispatchConCommand(ConCommandHandle cmd, const CCommandContext& ctx, const CCommand& args)
{
    CPlayerSlot slot = ctx.GetPlayerSlot();

    if (slot.Get() != -1)
    {
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