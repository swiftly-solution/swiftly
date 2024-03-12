#include "UserMessage.h"

#define GETCHECK_FIELD()                                                                                             \
    const google::protobuf::FieldDescriptor *field = msgBuffer->GetDescriptor()->FindFieldByName(fieldName.c_str()); \
    if (!field)                                                                                                      \
    {                                                                                                                \
        return false;                                                                                                \
    }

#define CHECK_FIELD_NOT_REPEATED()                                           \
    if (field->label() == google::protobuf::FieldDescriptor::LABEL_REPEATED) \
    {                                                                        \
        return false;                                                        \
    }

UserMessage::UserMessage(std::string msgname)
{
    this->msgid = INVALID_MESSAGE_ID;

    INetworkSerializable *msg = g_pNetworkMessages->FindNetworkMessagePartial(msgname.c_str());
    if (!msg)
        return;

    NetMessageInfo_t *msginfo = msg->GetNetMessageInfo();
    if (!msginfo)
        return;

    this->msgid = msginfo->m_MessageId;
    switch (this->msgid)
    {
    case 0:
        this->msgBuffer = new CNETMsg_NOP;
        break;
    case 1:
        this->msgBuffer = new CNETMsg_Disconnect;
        break;
    case 3:
        this->msgBuffer = new CNETMsg_SplitScreenUser;
        break;
    case 4:
        this->msgBuffer = new CNETMsg_Tick;
        break;
    case 5:
        this->msgBuffer = new CNETMsg_StringCmd;
        break;
    case 6:
        this->msgBuffer = new CNETMsg_SetConVar;
        break;
    case 7:
        this->msgBuffer = new CNETMsg_SignonState;
        break;
    case 8:
        this->msgBuffer = new CNETMsg_SpawnGroup_Load;
        break;
    case 9:
        this->msgBuffer = new CNETMsg_SpawnGroup_ManifestUpdate;
        break;
    case 11:
        this->msgBuffer = new CNETMsg_SpawnGroup_SetCreationTick;
        break;
    case 12:
        this->msgBuffer = new CNETMsg_SpawnGroup_Unload;
        break;
    case 13:
        this->msgBuffer = new CNETMsg_SpawnGroup_LoadCompleted;
        break;
    case 15:
        this->msgBuffer = new CNETMsg_DebugOverlay;
        break;
    case 16:
        this->msgBuffer = new CBidirMsg_RebroadcastGameEvent;
        break;
    case 17:
        this->msgBuffer = new CBidirMsg_RebroadcastSource;
        break;
    case 20:
        this->msgBuffer = new CCLCMsg_ClientInfo;
        break;
    case 21:
        this->msgBuffer = new CCLCMsg_Move;
        break;
    case 22:
        this->msgBuffer = new CCLCMsg_VoiceData;
        break;
    case 23:
        this->msgBuffer = new CCLCMsg_BaselineAck;
        break;
    case 25:
        this->msgBuffer = new CCLCMsg_RespondCvarValue;
        break;
    case 26:
        this->msgBuffer = new CCLCMsg_FileCRCCheck;
        break;
    case 27:
        this->msgBuffer = new CCLCMsg_LoadingProgress;
        break;
    case 28:
        this->msgBuffer = new CCLCMsg_SplitPlayerConnect;
        break;
    case 30:
        this->msgBuffer = new CCLCMsg_SplitPlayerDisconnect;
        break;
    case 31:
        this->msgBuffer = new CCLCMsg_ServerStatus;
        break;
    case 33:
        this->msgBuffer = new CCLCMsg_RequestPause;
        break;
    case 34:
        this->msgBuffer = new CCLCMsg_CmdKeyValues;
        break;
    case 35:
        this->msgBuffer = new CCLCMsg_RconServerDetails;
        break;
    case 36:
        this->msgBuffer = new CCLCMsg_HltvReplay;
        break;
    case 40:
        this->msgBuffer = new CSVCMsg_ServerInfo;
        break;
    case 41:
        this->msgBuffer = new CSVCMsg_FlattenedSerializer;
        break;
    case 42:
        this->msgBuffer = new CSVCMsg_ClassInfo;
        break;
    case 43:
        this->msgBuffer = new CSVCMsg_SetPause;
        break;
    case 44:
        this->msgBuffer = new CSVCMsg_CreateStringTable;
        break;
    case 45:
        this->msgBuffer = new CSVCMsg_UpdateStringTable;
        break;
    case 46:
        this->msgBuffer = new CSVCMsg_VoiceInit;
        break;
    case 47:
        this->msgBuffer = new CSVCMsg_VoiceData;
        break;
    case 48:
        this->msgBuffer = new CSVCMsg_Print;
        break;
    case 49:
        this->msgBuffer = new CSVCMsg_Sounds;
        break;
    case 50:
        this->msgBuffer = new CSVCMsg_SetView;
        break;
    case 51:
        this->msgBuffer = new CSVCMsg_ClearAllStringTables;
        break;
    case 52:
        this->msgBuffer = new CSVCMsg_CmdKeyValues;
        break;
    case 54:
        this->msgBuffer = new CSVCMsg_SplitScreen;
        break;
    case 55:
        this->msgBuffer = new CSVCMsg_PacketEntities;
        break;
    case 56:
        this->msgBuffer = new CSVCMsg_Prefetch;
        break;
    case 57:
        this->msgBuffer = new CSVCMsg_Menu;
        break;
    case 58:
        this->msgBuffer = new CSVCMsg_GetCvarValue;
        break;
    case 59:
        this->msgBuffer = new CSVCMsg_StopSound;
        break;
    case 60:
        this->msgBuffer = new CSVCMsg_PeerList;
        break;
    case 61:
        this->msgBuffer = new CSVCMsg_PacketReliable;
        break;
    case 62:
        this->msgBuffer = new CSVCMsg_HLTVStatus;
        break;
    case 63:
        this->msgBuffer = new CSVCMsg_ServerSteamID;
        break;
    case 70:
        this->msgBuffer = new CSVCMsg_FullFrameSplit;
        break;
    case 71:
        this->msgBuffer = new CSVCMsg_RconServerDetails;
        break;
    case 72:
        this->msgBuffer = new CSVCMsg_UserMessage;
        break;
    case 74:
        this->msgBuffer = new CSVCMsg_HltvReplay;
        break;
    case 75:
        this->msgBuffer = new CCLCMsg_HltvFixupOperatorTick;
        break;
    case 101:
        this->msgBuffer = new CCSUsrMsg_AchievementEvent;
        break;
    case 102:
        this->msgBuffer = new CUserMessageCloseCaption;
        break;
    case 103:
        this->msgBuffer = new CCSUsrMsg_CloseCaptionDirect;
        break;
    case 104:
        this->msgBuffer = new CCSUsrMsg_CurrentTimescale;
        break;
    case 105:
        this->msgBuffer = new CUserMessageDesiredTimescale;
        break;
    case 106:
        this->msgBuffer = new CUserMessageFade;
        break;
    case 110:
        this->msgBuffer = new CUserMessageHudMsg;
        break;
    case 111:
        this->msgBuffer = new CUserMessageHudText;
        break;
    case 113:
        this->msgBuffer = new CUserMessageColoredText;
        break;
    case 114:
        this->msgBuffer = new CUserMessageRequestState;
        break;
    case 115:
        this->msgBuffer = new CUserMessageResetHUD;
        break;
    case 116:
        this->msgBuffer = new CUserMessageRumble;
        break;
    case 117:
        this->msgBuffer = new CUserMessageSayText;
        break;
    case 118:
        this->msgBuffer = new CUserMessageSayText2;
        break;
    case 119:
        this->msgBuffer = new CUserMessageSayTextChannel;
        break;
    case 120:
        this->msgBuffer = new CUserMessageShake;
        break;
    case 121:
        this->msgBuffer = new CUserMessageShakeDir;
        break;
    case 122:
        this->msgBuffer = new CUserMessageWaterShake;
        break;
    case 124:
        this->msgBuffer = new CUserMessageTextMsg;
        break;
    case 125:
        this->msgBuffer = new CUserMessageScreenTilt;
        break;
    case 128:
        this->msgBuffer = new CUserMessageVoiceMask;
        break;
    case 130:
        this->msgBuffer = new CUserMessageSendAudio;
        break;
    case 131:
        this->msgBuffer = new CUserMessageItemPickup;
        break;
    case 132:
        this->msgBuffer = new CUserMessageAmmoDenied;
        break;
    case 134:
        this->msgBuffer = new CUserMessageShowMenu;
        break;
    case 135:
        this->msgBuffer = new CUserMessageCreditsMsg;
        break;
    case 137:
        this->msgBuffer = new CEntityMessageScreenOverlay;
        break;
    case 138:
        this->msgBuffer = new CEntityMessageRemoveAllDecals;
        break;
    case 139:
        this->msgBuffer = new CEntityMessagePropagateForce;
        break;
    case 140:
        this->msgBuffer = new CEntityMessageDoSpark;
        break;
    case 142:
        this->msgBuffer = new CUserMessageCloseCaptionPlaceholder;
        break;
    case 143:
        this->msgBuffer = new CUserMessageCameraTransition;
        break;
    case 144:
        this->msgBuffer = new CUserMessageAudioParameter;
        break;
    case 145:
        this->msgBuffer = new CUserMsg_ParticleManager;
        break;
    case 146:
        this->msgBuffer = new CUserMsg_HudError;
        break;
    case 148:
        this->msgBuffer = new CUserMsg_CustomGameEvent;
        break;
    case 150:
        this->msgBuffer = new CUserMessageHapticsManagerPulse;
        break;
    case 151:
        this->msgBuffer = new CUserMessageHapticsManagerEffect;
        break;
    case 152:
        this->msgBuffer = new CUserMessageCommandQueueState;
        break;
    case 153:
        this->msgBuffer = new CUserMessageUpdateCssClasses;
        break;
    case 154:
        this->msgBuffer = new CUserMessageServerFrameTime;
        break;
    case 155:
        this->msgBuffer = new CUserMessageLagCompensationError;
        break;
    case 156:
        this->msgBuffer = new CUserMessageRequestDllStatus;
        break;
    case 157:
        this->msgBuffer = new CUserMessageRequestUtilAction;
        break;
    case 160:
        this->msgBuffer = new CUserMessageRequestInventory;
        break;
    case 162:
        this->msgBuffer = new CUserMessageRequestDiagnostic;
        break;
    case 205:
        this->msgBuffer = new CMsgSource1LegacyGameEventList;
        break;
    case 206:
        this->msgBuffer = new CMsgSource1LegacyListenEvents;
        break;
    case 207:
        this->msgBuffer = new CMsgSource1LegacyGameEvent;
        break;
    case 208:
        this->msgBuffer = new CMsgSosStartSoundEvent;
        break;
    case 209:
        this->msgBuffer = new CMsgSosStopSoundEvent;
        break;
    case 210:
        this->msgBuffer = new CMsgSosSetSoundEventParams;
        break;
    case 211:
        this->msgBuffer = new CMsgSosSetLibraryStackFields;
        break;
    case 212:
        this->msgBuffer = new CMsgSosStopSoundEventHash;
        break;
    case 280:
        this->msgBuffer = new CClientMsg_CustomGameEvent;
        break;
    case 281:
        this->msgBuffer = new CClientMsg_CustomGameEventBounce;
        break;
    case 282:
        this->msgBuffer = new CClientMsg_ClientUIEvent;
        break;
    case 301:
        this->msgBuffer = new CCSUsrMsg_VGUIMenu;
        break;
    case 317:
        this->msgBuffer = new CCSUsrMsg_SendAudio;
        break;
    case 318:
        this->msgBuffer = new CCSUsrMsg_RawAudio;
        break;
    case 321:
        this->msgBuffer = new CCSUsrMsg_Damage;
        break;
    case 322:
        this->msgBuffer = new CCSUsrMsg_RadioText;
        break;
    case 323:
        this->msgBuffer = new CCSUsrMsg_HintText;
        break;
    case 324:
        this->msgBuffer = new CCSUsrMsg_KeyHintText;
        break;
    case 325:
        this->msgBuffer = new CCSUsrMsg_ProcessSpottedEntityUpdate;
        break;
    case 327:
        this->msgBuffer = new CCSUsrMsg_AdjustMoney;
        break;
    case 330:
        this->msgBuffer = new CCSUsrMsg_KillCam;
        break;
    case 334:
        this->msgBuffer = new CCSUsrMsg_MatchEndConditions;
        break;
    case 335:
        this->msgBuffer = new CCSUsrMsg_DisconnectToLobby;
        break;
    case 336:
        this->msgBuffer = new CCSUsrMsg_PlayerStatsUpdate;
        break;
    case 338:
        this->msgBuffer = new CCSUsrMsg_WarmupHasEnded;
        break;
    case 345:
        this->msgBuffer = new CCSUsrMsg_CallVoteFailed;
        break;
    case 346:
        this->msgBuffer = new CCSUsrMsg_VoteStart;
        break;
    case 347:
        this->msgBuffer = new CCSUsrMsg_VotePass;
        break;
    case 348:
        this->msgBuffer = new CCSUsrMsg_VoteFailed;
        break;
    case 349:
        this->msgBuffer = new CCSUsrMsg_VoteSetup;
        break;
    case 350:
        this->msgBuffer = new CCSUsrMsg_ServerRankRevealAll;
        break;
    case 351:
        this->msgBuffer = new CCSUsrMsg_SendLastKillerDamageToClient;
        break;
    case 352:
        this->msgBuffer = new CCSUsrMsg_ServerRankUpdate;
        break;
    case 360:
        this->msgBuffer = new CCSUsrMsg_GlowPropTurnOff;
        break;
    case 361:
        this->msgBuffer = new CCSUsrMsg_SendPlayerItemDrops;
        break;
    case 362:
        this->msgBuffer = new CCSUsrMsg_RoundBackupFilenames;
        break;
    case 363:
        this->msgBuffer = new CCSUsrMsg_SendPlayerItemFound;
        break;
    case 364:
        this->msgBuffer = new CCSUsrMsg_ReportHit;
        break;
    case 365:
        this->msgBuffer = new CCSUsrMsg_XpUpdate;
        break;
    case 366:
        this->msgBuffer = new CCSUsrMsg_QuestProgress;
        break;
    case 367:
        this->msgBuffer = new CCSUsrMsg_ScoreLeaderboardData;
        break;
    case 368:
        this->msgBuffer = new CCSUsrMsg_PlayerDecalDigitalSignature;
        break;
    case 369:
        this->msgBuffer = new CCSUsrMsg_WeaponSound;
        break;
    case 370:
        this->msgBuffer = new CCSUsrMsg_UpdateScreenHealthBar;
        break;
    case 371:
        this->msgBuffer = new CCSUsrMsg_EntityOutlineHighlight;
        break;
    case 372:
        this->msgBuffer = new CCSUsrMsg_SSUI;
        break;
    case 373:
        this->msgBuffer = new CCSUsrMsg_SurvivalStats;
        break;
    case 374:
        this->msgBuffer = new CCSUsrMsg_DisconnectToLobby;
        break;
    case 375:
        this->msgBuffer = new CCSUsrMsg_EndOfMatchAllPlayersData;
        break;
    case 376:
        this->msgBuffer = new CCSUsrMsg_PostRoundDamageReport;
        break;
    case 379:
        this->msgBuffer = new CCSUsrMsg_RoundEndReportData;
        break;
    case 380:
        this->msgBuffer = new CCSUsrMsg_CurrentRoundOdds;
        break;
    case 381:
        this->msgBuffer = new CCSUsrMsg_DeepStats;
        break;
    case 383:
        this->msgBuffer = new CCSUsrMsg_ShootInfo;
        break;
    case 400:
        this->msgBuffer = new CMsgTEEffectDispatch;
        break;
    case 401:
        this->msgBuffer = new CMsgTEArmorRicochet;
        break;
    case 402:
        this->msgBuffer = new CMsgTEBeamEntPoint;
        break;
    case 403:
        this->msgBuffer = new CMsgTEBeamEnts;
        break;
    case 404:
        this->msgBuffer = new CMsgTEBeamPoints;
        break;
    case 405:
        this->msgBuffer = new CMsgTEBeamRing;
        break;
    case 407:
        this->msgBuffer = new CMsgTEBSPDecal;
        break;
    case 408:
        this->msgBuffer = new CMsgTEBubbles;
        break;
    case 409:
        this->msgBuffer = new CMsgTEBubbleTrail;
        break;
    case 410:
        this->msgBuffer = new CMsgTEDecal;
        break;
    case 411:
        this->msgBuffer = new CMsgTEWorldDecal;
        break;
    case 412:
        this->msgBuffer = new CMsgTEEnergySplash;
        break;
    case 413:
        this->msgBuffer = new CMsgTEFizz;
        break;
    case 415:
        this->msgBuffer = new CMsgTEGlowSprite;
        break;
    case 416:
        this->msgBuffer = new CMsgTEImpact;
        break;
    case 417:
        this->msgBuffer = new CMsgTEMuzzleFlash;
        break;
    case 418:
        this->msgBuffer = new CMsgTEBloodStream;
        break;
    case 419:
        this->msgBuffer = new CMsgTEExplosion;
        break;
    case 420:
        this->msgBuffer = new CMsgTEDust;
        break;
    case 421:
        this->msgBuffer = new CMsgTELargeFunnel;
        break;
    case 422:
        this->msgBuffer = new CMsgTESparks;
        break;
    case 423:
        this->msgBuffer = new CMsgTEPhysicsProp;
        break;
    case 424:
        this->msgBuffer = new CMsgTEPlayerDecal;
        break;
    case 425:
        this->msgBuffer = new CMsgTEProjectedDecal;
        break;
    case 426:
        this->msgBuffer = new CMsgTESmoke;
        break;
    case 452:
        this->msgBuffer = new CMsgTEFireBullets;
        break;
    }
    this->msgSerializable = msg;
}

std::string UserMessage::GetMessageName()
{
    if (this->msgid == INVALID_MESSAGE_ID)
        return "";

    if (!this->msgSerializable)
        return "";

    return this->msgSerializable->GetUnscopedName();
}

int UserMessage::GetMessageID()
{
    return this->msgid;
}

bool UserMessage::HasField(std::string fieldName)
{
    if (!this->msgBuffer)
        return false;

    GETCHECK_FIELD()
    CHECK_FIELD_NOT_REPEATED()
    return this->msgBuffer->GetReflection()->HasField(*this->msgBuffer, field);
}