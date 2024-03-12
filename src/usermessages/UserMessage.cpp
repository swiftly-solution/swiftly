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
    if (this->msgid == 0)
        this->msgBuffer = new CNETMsg_NOP;
    else if (this->msgid == 1)
        this->msgBuffer = new CNETMsg_Disconnect;
    else if (this->msgid == 3)
        this->msgBuffer = new CNETMsg_SplitScreenUser;
    else if (this->msgid == 4)
        this->msgBuffer = new CNETMsg_Tick;
    else if (this->msgid == 5)
        this->msgBuffer = new CNETMsg_StringCmd;
    else if (this->msgid == 6)
        this->msgBuffer = new CNETMsg_SetConVar;
    else if (this->msgid == 7)
        this->msgBuffer = new CNETMsg_SignonState;
    else if (this->msgid == 8)
        this->msgBuffer = new CNETMsg_SpawnGroup_Load;
    else if (this->msgid == 9)
        this->msgBuffer = new CNETMsg_SpawnGroup_ManifestUpdate;
    else if (this->msgid == 11)
        this->msgBuffer = new CNETMsg_SpawnGroup_SetCreationTick;
    else if (this->msgid == 12)
        this->msgBuffer = new CNETMsg_SpawnGroup_Unload;
    else if (this->msgid == 13)
        this->msgBuffer = new CNETMsg_SpawnGroup_LoadCompleted;
    else if (this->msgid == 15)
        this->msgBuffer = new CNETMsg_DebugOverlay;
    else if (this->msgid == 16)
        this->msgBuffer = new CBidirMsg_RebroadcastGameEvent;
    else if (this->msgid == 17)
        this->msgBuffer = new CBidirMsg_RebroadcastSource;
    else if (this->msgid == 20)
        this->msgBuffer = new CCLCMsg_ClientInfo;
    else if (this->msgid == 21)
        this->msgBuffer = new CCLCMsg_Move;
    else if (this->msgid == 22)
        this->msgBuffer = new CCLCMsg_VoiceData;
    else if (this->msgid == 23)
        this->msgBuffer = new CCLCMsg_BaselineAck;
    else if (this->msgid == 25)
        this->msgBuffer = new CCLCMsg_RespondCvarValue;
    else if (this->msgid == 26)
        this->msgBuffer = new CCLCMsg_FileCRCCheck;
    else if (this->msgid == 27)
        this->msgBuffer = new CCLCMsg_LoadingProgress;
    else if (this->msgid == 28)
        this->msgBuffer = new CCLCMsg_SplitPlayerConnect;
    else if (this->msgid == 30)
        this->msgBuffer = new CCLCMsg_SplitPlayerDisconnect;
    else if (this->msgid == 31)
        this->msgBuffer = new CCLCMsg_ServerStatus;
    else if (this->msgid == 33)
        this->msgBuffer = new CCLCMsg_RequestPause;
    else if (this->msgid == 34)
        this->msgBuffer = new CCLCMsg_CmdKeyValues;
    else if (this->msgid == 35)
        this->msgBuffer = new CCLCMsg_RconServerDetails;
    else if (this->msgid == 36)
        this->msgBuffer = new CCLCMsg_HltvReplay;
    else if (this->msgid == 40)
        this->msgBuffer = new CSVCMsg_ServerInfo;
    else if (this->msgid == 41)
        this->msgBuffer = new CSVCMsg_FlattenedSerializer;
    else if (this->msgid == 42)
        this->msgBuffer = new CSVCMsg_ClassInfo;
    else if (this->msgid == 43)
        this->msgBuffer = new CSVCMsg_SetPause;
    else if (this->msgid == 44)
        this->msgBuffer = new CSVCMsg_CreateStringTable;
    else if (this->msgid == 45)
        this->msgBuffer = new CSVCMsg_UpdateStringTable;
    else if (this->msgid == 46)
        this->msgBuffer = new CSVCMsg_VoiceInit;
    else if (this->msgid == 47)
        this->msgBuffer = new CSVCMsg_VoiceData;
    else if (this->msgid == 48)
        this->msgBuffer = new CSVCMsg_Print;
    else if (this->msgid == 49)
        this->msgBuffer = new CSVCMsg_Sounds;
    else if (this->msgid == 50)
        this->msgBuffer = new CSVCMsg_SetView;
    else if (this->msgid == 51)
        this->msgBuffer = new CSVCMsg_ClearAllStringTables;
    else if (this->msgid == 52)
        this->msgBuffer = new CSVCMsg_CmdKeyValues;
    else if (this->msgid == 54)
        this->msgBuffer = new CSVCMsg_SplitScreen;
    else if (this->msgid == 55)
        this->msgBuffer = new CSVCMsg_PacketEntities;
    else if (this->msgid == 56)
        this->msgBuffer = new CSVCMsg_Prefetch;
    else if (this->msgid == 57)
        this->msgBuffer = new CSVCMsg_Menu;
    else if (this->msgid == 58)
        this->msgBuffer = new CSVCMsg_GetCvarValue;
    else if (this->msgid == 59)
        this->msgBuffer = new CSVCMsg_StopSound;
    else if (this->msgid == 60)
        this->msgBuffer = new CSVCMsg_PeerList;
    else if (this->msgid == 61)
        this->msgBuffer = new CSVCMsg_PacketReliable;
    else if (this->msgid == 62)
        this->msgBuffer = new CSVCMsg_HLTVStatus;
    else if (this->msgid == 63)
        this->msgBuffer = new CSVCMsg_ServerSteamID;
    else if (this->msgid == 70)
        this->msgBuffer = new CSVCMsg_FullFrameSplit;
    else if (this->msgid == 71)
        this->msgBuffer = new CSVCMsg_RconServerDetails;
    else if (this->msgid == 72)
        this->msgBuffer = new CSVCMsg_UserMessage;
    else if (this->msgid == 74)
        this->msgBuffer = new CSVCMsg_HltvReplay;
    else if (this->msgid == 75)
        this->msgBuffer = new CCLCMsg_HltvFixupOperatorTick;
    else if (this->msgid == 101)
        this->msgBuffer = new CCSUsrMsg_AchievementEvent;
    else if (this->msgid == 102)
        this->msgBuffer = new CUserMessageCloseCaption;
    else if (this->msgid == 103)
        this->msgBuffer = new CCSUsrMsg_CloseCaptionDirect;
    else if (this->msgid == 104)
        this->msgBuffer = new CCSUsrMsg_CurrentTimescale;
    else if (this->msgid == 105)
        this->msgBuffer = new CUserMessageDesiredTimescale;
    else if (this->msgid == 106)
        this->msgBuffer = new CUserMessageFade;
    else if (this->msgid == 110)
        this->msgBuffer = new CUserMessageHudMsg;
    else if (this->msgid == 111)
        this->msgBuffer = new CUserMessageHudText;
    else if (this->msgid == 113)
        this->msgBuffer = new CUserMessageColoredText;
    else if (this->msgid == 114)
        this->msgBuffer = new CUserMessageRequestState;
    else if (this->msgid == 115)
        this->msgBuffer = new CUserMessageResetHUD;
    else if (this->msgid == 116)
        this->msgBuffer = new CUserMessageRumble;
    else if (this->msgid == 117)
        this->msgBuffer = new CUserMessageSayText;
    else if (this->msgid == 118)
        this->msgBuffer = new CUserMessageSayText2;
    else if (this->msgid == 119)
        this->msgBuffer = new CUserMessageSayTextChannel;
    else if (this->msgid == 120)
        this->msgBuffer = new CUserMessageShake;
    else if (this->msgid == 121)
        this->msgBuffer = new CUserMessageShakeDir;
    else if (this->msgid == 122)
        this->msgBuffer = new CUserMessageWaterShake;
    else if (this->msgid == 124)
        this->msgBuffer = new CUserMessageTextMsg;
    else if (this->msgid == 125)
        this->msgBuffer = new CUserMessageScreenTilt;
    else if (this->msgid == 128)
        this->msgBuffer = new CUserMessageVoiceMask;
    else if (this->msgid == 130)
        this->msgBuffer = new CUserMessageSendAudio;
    else if (this->msgid == 131)
        this->msgBuffer = new CUserMessageItemPickup;
    else if (this->msgid == 132)
        this->msgBuffer = new CUserMessageAmmoDenied;
    else if (this->msgid == 134)
        this->msgBuffer = new CUserMessageShowMenu;
    else if (this->msgid == 135)
        this->msgBuffer = new CUserMessageCreditsMsg;
    else if (this->msgid == 137)
        this->msgBuffer = new CEntityMessageScreenOverlay;
    else if (this->msgid == 138)
        this->msgBuffer = new CEntityMessageRemoveAllDecals;
    else if (this->msgid == 139)
        this->msgBuffer = new CEntityMessagePropagateForce;
    else if (this->msgid == 140)
        this->msgBuffer = new CEntityMessageDoSpark;
    else if (this->msgid == 142)
        this->msgBuffer = new CUserMessageCloseCaptionPlaceholder;
    else if (this->msgid == 143)
        this->msgBuffer = new CUserMessageCameraTransition;
    else if (this->msgid == 144)
        this->msgBuffer = new CUserMessageAudioParameter;
    else if (this->msgid == 145)
        this->msgBuffer = new CUserMsg_ParticleManager;
    else if (this->msgid == 146)
        this->msgBuffer = new CUserMsg_HudError;
    else if (this->msgid == 148)
        this->msgBuffer = new CUserMsg_CustomGameEvent;
    else if (this->msgid == 150)
        this->msgBuffer = new CUserMessageHapticsManagerPulse;
    else if (this->msgid == 151)
        this->msgBuffer = new CUserMessageHapticsManagerEffect;
    else if (this->msgid == 152)
        this->msgBuffer = new CUserMessageCommandQueueState;
    else if (this->msgid == 153)
        this->msgBuffer = new CUserMessageUpdateCssClasses;
    else if (this->msgid == 154)
        this->msgBuffer = new CUserMessageServerFrameTime;
    else if (this->msgid == 155)
        this->msgBuffer = new CUserMessageLagCompensationError;
    else if (this->msgid == 156)
        this->msgBuffer = new CUserMessageRequestDllStatus;
    else if (this->msgid == 157)
        this->msgBuffer = new CUserMessageRequestUtilAction;
    else if (this->msgid == 160)
        this->msgBuffer = new CUserMessageRequestInventory;
    else if (this->msgid == 162)
        this->msgBuffer = new CUserMessageRequestDiagnostic;
    else if (this->msgid == 205)
        this->msgBuffer = new CMsgSource1LegacyGameEventList;
    else if (this->msgid == 206)
        this->msgBuffer = new CMsgSource1LegacyListenEvents;
    else if (this->msgid == 207)
        this->msgBuffer = new CMsgSource1LegacyGameEvent;
    else if (this->msgid == 208)
        this->msgBuffer = new CMsgSosStartSoundEvent;
    else if (this->msgid == 209)
        this->msgBuffer = new CMsgSosStopSoundEvent;
    else if (this->msgid == 210)
        this->msgBuffer = new CMsgSosSetSoundEventParams;
    else if (this->msgid == 211)
        this->msgBuffer = new CMsgSosSetLibraryStackFields;
    else if (this->msgid == 212)
        this->msgBuffer = new CMsgSosStopSoundEventHash;
    else if (this->msgid == 280)
        this->msgBuffer = new CClientMsg_CustomGameEvent;
    else if (this->msgid == 281)
        this->msgBuffer = new CClientMsg_CustomGameEventBounce;
    else if (this->msgid == 282)
        this->msgBuffer = new CClientMsg_ClientUIEvent;
    else if (this->msgid == 301)
        this->msgBuffer = new CCSUsrMsg_VGUIMenu;
    else if (this->msgid == 317)
        this->msgBuffer = new CCSUsrMsg_SendAudio;
    else if (this->msgid == 318)
        this->msgBuffer = new CCSUsrMsg_RawAudio;
    else if (this->msgid == 321)
        this->msgBuffer = new CCSUsrMsg_Damage;
    else if (this->msgid == 322)
        this->msgBuffer = new CCSUsrMsg_RadioText;
    else if (this->msgid == 323)
        this->msgBuffer = new CCSUsrMsg_HintText;
    else if (this->msgid == 324)
        this->msgBuffer = new CCSUsrMsg_KeyHintText;
    else if (this->msgid == 325)
        this->msgBuffer = new CCSUsrMsg_ProcessSpottedEntityUpdate;
    else if (this->msgid == 327)
        this->msgBuffer = new CCSUsrMsg_AdjustMoney;
    else if (this->msgid == 330)
        this->msgBuffer = new CCSUsrMsg_KillCam;
    else if (this->msgid == 334)
        this->msgBuffer = new CCSUsrMsg_MatchEndConditions;
    else if (this->msgid == 335)
        this->msgBuffer = new CCSUsrMsg_DisconnectToLobby;
    else if (this->msgid == 336)
        this->msgBuffer = new CCSUsrMsg_PlayerStatsUpdate;
    else if (this->msgid == 338)
        this->msgBuffer = new CCSUsrMsg_WarmupHasEnded;
    else if (this->msgid == 345)
        this->msgBuffer = new CCSUsrMsg_CallVoteFailed;
    else if (this->msgid == 346)
        this->msgBuffer = new CCSUsrMsg_VoteStart;
    else if (this->msgid == 347)
        this->msgBuffer = new CCSUsrMsg_VotePass;
    else if (this->msgid == 348)
        this->msgBuffer = new CCSUsrMsg_VoteFailed;
    else if (this->msgid == 349)
        this->msgBuffer = new CCSUsrMsg_VoteSetup;
    else if (this->msgid == 350)
        this->msgBuffer = new CCSUsrMsg_ServerRankRevealAll;
    else if (this->msgid == 351)
        this->msgBuffer = new CCSUsrMsg_SendLastKillerDamageToClient;
    else if (this->msgid == 352)
        this->msgBuffer = new CCSUsrMsg_ServerRankUpdate;
    else if (this->msgid == 360)
        this->msgBuffer = new CCSUsrMsg_GlowPropTurnOff;
    else if (this->msgid == 361)
        this->msgBuffer = new CCSUsrMsg_SendPlayerItemDrops;
    else if (this->msgid == 362)
        this->msgBuffer = new CCSUsrMsg_RoundBackupFilenames;
    else if (this->msgid == 363)
        this->msgBuffer = new CCSUsrMsg_SendPlayerItemFound;
    else if (this->msgid == 364)
        this->msgBuffer = new CCSUsrMsg_ReportHit;
    else if (this->msgid == 365)
        this->msgBuffer = new CCSUsrMsg_XpUpdate;
    else if (this->msgid == 366)
        this->msgBuffer = new CCSUsrMsg_QuestProgress;
    else if (this->msgid == 367)
        this->msgBuffer = new CCSUsrMsg_ScoreLeaderboardData;
    else if (this->msgid == 368)
        this->msgBuffer = new CCSUsrMsg_PlayerDecalDigitalSignature;
    else if (this->msgid == 369)
        this->msgBuffer = new CCSUsrMsg_WeaponSound;
    else if (this->msgid == 370)
        this->msgBuffer = new CCSUsrMsg_UpdateScreenHealthBar;
    else if (this->msgid == 371)
        this->msgBuffer = new CCSUsrMsg_EntityOutlineHighlight;
    else if (this->msgid == 372)
        this->msgBuffer = new CCSUsrMsg_SSUI;
    else if (this->msgid == 373)
        this->msgBuffer = new CCSUsrMsg_SurvivalStats;
    else if (this->msgid == 374)
        this->msgBuffer = new CCSUsrMsg_DisconnectToLobby;
    else if (this->msgid == 375)
        this->msgBuffer = new CCSUsrMsg_EndOfMatchAllPlayersData;
    else if (this->msgid == 376)
        this->msgBuffer = new CCSUsrMsg_PostRoundDamageReport;
    else if (this->msgid == 379)
        this->msgBuffer = new CCSUsrMsg_RoundEndReportData;
    else if (this->msgid == 380)
        this->msgBuffer = new CCSUsrMsg_CurrentRoundOdds;
    else if (this->msgid == 381)
        this->msgBuffer = new CCSUsrMsg_DeepStats;
    else if (this->msgid == 383)
        this->msgBuffer = new CCSUsrMsg_ShootInfo;
    else if (this->msgid == 400)
        this->msgBuffer = new CMsgTEEffectDispatch;
    else if (this->msgid == 401)
        this->msgBuffer = new CMsgTEArmorRicochet;
    else if (this->msgid == 402)
        this->msgBuffer = new CMsgTEBeamEntPoint;
    else if (this->msgid == 403)
        this->msgBuffer = new CMsgTEBeamEnts;
    else if (this->msgid == 404)
        this->msgBuffer = new CMsgTEBeamPoints;
    else if (this->msgid == 405)
        this->msgBuffer = new CMsgTEBeamRing;
    else if (this->msgid == 407)
        this->msgBuffer = new CMsgTEBSPDecal;
    else if (this->msgid == 408)
        this->msgBuffer = new CMsgTEBubbles;
    else if (this->msgid == 409)
        this->msgBuffer = new CMsgTEBubbleTrail;
    else if (this->msgid == 410)
        this->msgBuffer = new CMsgTEDecal;
    else if (this->msgid == 411)
        this->msgBuffer = new CMsgTEWorldDecal;
    else if (this->msgid == 412)
        this->msgBuffer = new CMsgTEEnergySplash;
    else if (this->msgid == 413)
        this->msgBuffer = new CMsgTEFizz;
    else if (this->msgid == 415)
        this->msgBuffer = new CMsgTEGlowSprite;
    else if (this->msgid == 416)
        this->msgBuffer = new CMsgTEImpact;
    else if (this->msgid == 417)
        this->msgBuffer = new CMsgTEMuzzleFlash;
    else if (this->msgid == 418)
        this->msgBuffer = new CMsgTEBloodStream;
    else if (this->msgid == 419)
        this->msgBuffer = new CMsgTEExplosion;
    else if (this->msgid == 420)
        this->msgBuffer = new CMsgTEDust;
    else if (this->msgid == 421)
        this->msgBuffer = new CMsgTELargeFunnel;
    else if (this->msgid == 422)
        this->msgBuffer = new CMsgTESparks;
    else if (this->msgid == 423)
        this->msgBuffer = new CMsgTEPhysicsProp;
    else if (this->msgid == 424)
        this->msgBuffer = new CMsgTEPlayerDecal;
    else if (this->msgid == 425)
        this->msgBuffer = new CMsgTEProjectedDecal;
    else if (this->msgid == 426)
        this->msgBuffer = new CMsgTESmoke;
    else if (this->msgid == 452)
        this->msgBuffer = new CMsgTEFireBullets;
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