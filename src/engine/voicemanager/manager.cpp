#include "manager.h"

#include <memory/hooks/functions.h>
#include <server/player/manager.h>
#include <sdk/schema.h>

enum ListenOverride
{
    Listen_Default = 0,
    Listen_Mute,
    Listen_Hear
};

enum VoiceFlagValue
{
    Speak_Normal = 0,
    Speak_Muted = 1 << 0,
    Speak_All = 1 << 1,
    Speak_ListenAll = 1 << 2,
    Speak_Team = 1 << 3,
    Speak_ListenTeam = 1 << 4,
};

SH_DECL_EXTERN3(IVEngineServer2, SetClientListening, SH_NOATTRIB, 0, bool, CPlayerSlot, CPlayerSlot, bool);
SH_DECL_EXTERN2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, CPlayerSlot, const CCommand&);

void VoiceManager::OnAllInitialized()
{
    SH_ADD_HOOK(IVEngineServer2, SetClientListening, engine, SH_MEMBER(this, &VoiceManager::SetClientListening), false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &VoiceManager::OnClientCommand, false);
}

void VoiceManager::OnShutdown()
{
    SH_REMOVE_HOOK(IVEngineServer2, SetClientListening, engine, SH_MEMBER(this, &VoiceManager::SetClientListening), false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientCommand, gameclients, this, &VoiceManager::OnClientCommand, false);
}

bool VoiceManager::SetClientListening(CPlayerSlot iReceiver, CPlayerSlot iSender, bool bListen)
{
    Player* receiver = g_playerManager.GetPlayer(iReceiver);
    if (!receiver)
        RETURN_META_VALUE(MRES_IGNORED, bListen);

    Player* sender = g_playerManager.GetPlayer(iSender);
    if (!sender)
        RETURN_META_VALUE(MRES_IGNORED, bListen);

    auto listenOverride = receiver->GetListen(iSender);
    auto senderFlags = sender->GetVoiceFlags();
    auto receiverFlags = receiver->GetVoiceFlags();

    if (receiver->m_selfMutes->Get(iSender.Get()))
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, false));
    }

    if (senderFlags & VoiceFlagValue::Speak_Muted)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, false));
    }

    if (listenOverride == ListenOverride::Listen_Mute)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, false));
    }
    else if (listenOverride == ListenOverride::Listen_Hear)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, true));
    }

    if ((senderFlags & VoiceFlagValue::Speak_All) || (receiverFlags & VoiceFlagValue::Speak_ListenAll))
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, true));
    }

    if ((senderFlags & VoiceFlagValue::Speak_Team) || (receiverFlags & VoiceFlagValue::Speak_ListenTeam))
    {
        auto senderController = sender->GetController();
        auto receiverController = receiver->GetController();
        if (!senderController || !receiverController)
            RETURN_META_VALUE(MRES_IGNORED, bListen);

        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening,
            (iReceiver, iSender, schema::GetProp<int>(senderController, "CBaseEntity", "m_iTeamNum") == schema::GetProp<int>(receiverController, "CBaseEntity", "m_iTeamNum")));
    }

    RETURN_META_VALUE(MRES_IGNORED, bListen);
}

void VoiceManager::OnClientCommand(CPlayerSlot slot, const CCommand& args)
{
    Player* player = g_playerManager.GetPlayer(slot);
    if (!player)
        return;

    if (args.ArgC() > 1 && std::string(args.Arg(0)) == "vban")
    {
        uint32_t mask = 0;
        sscanf(args.Arg(1), "%x", &mask);
        player->m_selfMutes->SetDWord(0, mask);
    }
}