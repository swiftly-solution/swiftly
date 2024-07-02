/******************************************************************
 *
 * This feature is inspired from CounterStrikeSharp.
 * You can find the source code used by us in the following files:
 *
 * https://github.com/roflmuffin/CounterStrikeSharp/blob/a87bd25b48ff1407a71cfdce3222f5f55c8a2e0b/src/core/managers/voice_manager.h#L26
 * https://github.com/roflmuffin/CounterStrikeSharp/blob/a87bd25b48ff1407a71cfdce3222f5f55c8a2e0b/src/core/managers/voice_manager.cpp#L30
 *
 ******************************************************************/

#include "VoiceManager.h"
#include "../player/PlayerManager.h"
#include <module.h>

SH_DECL_HOOK3(IVEngineServer2, SetClientListening, SH_NOATTRIB, 0, bool, CPlayerSlot, CPlayerSlot, bool);

void VoiceManager::OnAllInitialized()
{
    SH_ADD_HOOK(IVEngineServer2, SetClientListening, engine, SH_MEMBER(this, &VoiceManager::SetClientListening), false);
}

void VoiceManager::OnShutdown()
{
    SH_REMOVE_HOOK(IVEngineServer2, SetClientListening, engine, SH_MEMBER(this, &VoiceManager::SetClientListening), false);
}

bool VoiceManager::SetClientListening(CPlayerSlot iReceiver, CPlayerSlot iSender, bool bListen)
{
    Player *receiver = g_playerManager->GetPlayer(iReceiver);
    if (!receiver)
        RETURN_META_VALUE(MRES_IGNORED, bListen);

    Player *sender = g_playerManager->GetPlayer(iSender);
    if (!sender)
        RETURN_META_VALUE(MRES_IGNORED, bListen);

    auto listenOverride = receiver->GetListen(iSender);
    auto senderFlags = sender->GetVoiceFlags();
    auto receiverFlags = receiver->GetVoiceFlags();

    if (receiver->m_selfMutes->Get(iSender.Get()))
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, false));
    }

    if (senderFlags & Speak_Muted)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, false));
    }

    if (senderFlags & Speak_Muted)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, false));
    }

    if (listenOverride == Listen_Mute)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, false));
    }
    else if (listenOverride == Listen_Hear)
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, true));
    }

    if ((senderFlags & Speak_All) || (receiverFlags & Speak_ListenAll))
    {
        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening, (iReceiver, iSender, true));
    }

    if ((senderFlags & Speak_Team) || (receiverFlags & Speak_ListenTeam))
    {
        auto senderController = sender->GetPlayerController();
        auto receiverController = receiver->GetPlayerController();
        if (!senderController || !receiverController)
            RETURN_META_VALUE(MRES_IGNORED, bListen);

        RETURN_META_VALUE_NEWPARAMS(MRES_IGNORED, bListen, &IVEngineServer2::SetClientListening,
                                    (iReceiver, iSender, senderController->m_iTeamNum() == receiverController->m_iTeamNum()));
    }

    RETURN_META_VALUE(MRES_IGNORED, bListen);
}

void VoiceManager::OnClientCommand(CPlayerSlot slot, const CCommand &args)
{
    Player *player = g_playerManager->GetPlayer(slot);
    if (!player)
        return;

    if (args.ArgC() > 1 && std::string(args.Arg(0)) == "vban")
    {
        uint32_t mask = 0;
        sscanf(args.Arg(1), "%x", &mask);
        player->m_selfMutes->SetDWord(0, mask);
    }
}