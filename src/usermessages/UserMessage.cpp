#include "UserMessage.h"

#ifdef GetMessage
#undef GetMessage
#endif

#define GETCHECK_FIELD()                                                                                              \
    const google::protobuf::FieldDescriptor *field = this->msgBuffer->GetDescriptor()->FindFieldByName(pszFieldName); \
    if (!field)                                                                                                       \
    {                                                                                                                 \
        return false;                                                                                                 \
    }

#define CHECK_FIELD_NOT_REPEATED()                                           \
    if (field->label() == google::protobuf::FieldDescriptor::LABEL_REPEATED) \
    {                                                                        \
        return false;                                                        \
    }

#define CHECK_FIELD_TYPE(type)                                                  \
    if (field->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_##type) \
    {                                                                           \
        return false;                                                           \
    }

#define CHECK_FIELD_TYPE2(type1, type2)                                                                                                     \
    google::protobuf::FieldDescriptor::CppType fieldType = field->cpp_type();                                                               \
    if (fieldType != google::protobuf::FieldDescriptor::CPPTYPE_##type1 && fieldType != google::protobuf::FieldDescriptor::CPPTYPE_##type2) \
    {                                                                                                                                       \
        return false;                                                                                                                       \
    }

#define CHECK_FIELD_REPEATED()                                               \
    if (field->label() != google::protobuf::FieldDescriptor::LABEL_REPEATED) \
    {                                                                        \
        return false;                                                        \
    }

#define CHECK_REPEATED_ELEMENT(idx)                                                       \
    int elemCount = this->msgBuffer->GetReflection()->FieldSize(*this->msgBuffer, field); \
    if (elemCount == 0 || idx >= elemCount || idx < 0)                                    \
    {                                                                                     \
        return false;                                                                     \
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

bool UserMessage::HasField(const char *pszFieldName)
{
    if (!this->msgBuffer)
        return false;

    GETCHECK_FIELD()
    CHECK_FIELD_NOT_REPEATED()
    return this->msgBuffer->GetReflection()->HasField(*this->msgBuffer, field);
}

bool UserMessage::GetInt32(const char *pszFieldName, int32 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT32);
    CHECK_FIELD_NOT_REPEATED();

    *out = this->msgBuffer->GetReflection()->GetInt32(*this->msgBuffer, field);
    return true;
}

bool UserMessage::SetInt32(const char *pszFieldName, int32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT32);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetInt32(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedInt32(const char *pszFieldName, int index, int32 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    *out = this->msgBuffer->GetReflection()->GetRepeatedInt32(*this->msgBuffer, field, index);
    return true;
}

bool UserMessage::SetRepeatedInt32(const char *pszFieldName, int index, int32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedInt32(this->msgBuffer, field, index, value);
    return true;
}

bool UserMessage::AddInt32(const char *pszFieldName, int32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT32);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddInt32(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetInt64(const char *pszFieldName, int64 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT64);
    CHECK_FIELD_NOT_REPEATED();

    *out = this->msgBuffer->GetReflection()->GetInt64(*this->msgBuffer, field);
    return true;
}

bool UserMessage::SetInt64(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT64);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetInt64(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedInt64(const char *pszFieldName, int index, int64 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    *out = this->msgBuffer->GetReflection()->GetRepeatedInt64(*this->msgBuffer, field, index);
    return true;
}

bool UserMessage::SetRepeatedInt64(const char *pszFieldName, int index, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedInt64(this->msgBuffer, field, index, value);
    return true;
}

bool UserMessage::AddInt64(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(INT64);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddInt64(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetUInt32(const char *pszFieldName, uint32 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT32);
    CHECK_FIELD_NOT_REPEATED();

    *out = this->msgBuffer->GetReflection()->GetUInt32(*this->msgBuffer, field);
    return true;
}

bool UserMessage::SetUInt32(const char *pszFieldName, uint32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT32);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetUInt32(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedUInt32(const char *pszFieldName, int index, uint32 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    *out = this->msgBuffer->GetReflection()->GetRepeatedUInt32(*this->msgBuffer, field, index);
    return true;
}

bool UserMessage::SetRepeatedUInt32(const char *pszFieldName, int index, uint32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT32);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedUInt32(this->msgBuffer, field, index, value);
    return true;
}

bool UserMessage::AddUInt32(const char *pszFieldName, uint32 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT32);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddUInt32(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetUInt64(const char *pszFieldName, uint64 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT64);
    CHECK_FIELD_NOT_REPEATED();

    *out = this->msgBuffer->GetReflection()->GetUInt64(*this->msgBuffer, field);
    return true;
}

bool UserMessage::SetUInt64(const char *pszFieldName, uint64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT64);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetUInt64(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedUInt64(const char *pszFieldName, int index, uint64 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    *out = this->msgBuffer->GetReflection()->GetRepeatedUInt64(*this->msgBuffer, field, index);
    return true;
}

bool UserMessage::SetRepeatedUInt64(const char *pszFieldName, int index, uint64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedUInt64(this->msgBuffer, field, index, value);
    return true;
}

bool UserMessage::AddUInt64(const char *pszFieldName, uint64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(UINT64);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddUInt32(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetInt64OrUnsigned(const char *pszFieldName, int64 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(INT64, UINT64);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
        *out = (int64)this->msgBuffer->GetReflection()->GetUInt64(*this->msgBuffer, field);
    else
        *out = this->msgBuffer->GetReflection()->GetInt64(*this->msgBuffer, field);

    return true;
}

bool UserMessage::SetInt64OrUnsigned(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(INT64, UINT64);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->SetUInt64(this->msgBuffer, field, (uint64)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->SetInt64(this->msgBuffer, field, value);
    }

    return true;
}

bool UserMessage::GetRepeatedInt64OrUnsigned(const char *pszFieldName, int index, int64 *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(INT64, UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
        *out = (int64)this->msgBuffer->GetReflection()->GetRepeatedUInt64(*this->msgBuffer, field, index);
    else
        *out = this->msgBuffer->GetReflection()->GetRepeatedInt64(*this->msgBuffer, field, index);

    return true;
}

bool UserMessage::SetRepeatedInt64OrUnsigned(const char *pszFieldName, int index, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(INT64, UINT64);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->SetRepeatedUInt64(this->msgBuffer, field, index, (uint64)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->SetRepeatedInt64(this->msgBuffer, field, index, value);
    }

    return true;
}

bool UserMessage::AddInt64OrUnsigned(const char *pszFieldName, int64 value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(INT64, UINT64);
    CHECK_FIELD_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_UINT64)
    {
        this->msgBuffer->GetReflection()->AddUInt64(this->msgBuffer, field, (uint64)value);
    }
    else
    {
        this->msgBuffer->GetReflection()->AddInt64(this->msgBuffer, field, value);
    }

    return true;
}

bool UserMessage::GetBool(const char *pszFieldName, bool *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(BOOL);
    CHECK_FIELD_NOT_REPEATED();

    *out = this->msgBuffer->GetReflection()->GetBool(*this->msgBuffer, field);
    return true;
}

bool UserMessage::SetBool(const char *pszFieldName, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(BOOL);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetBool(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedBool(const char *pszFieldName, int index, bool *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(BOOL);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    *out = this->msgBuffer->GetReflection()->GetRepeatedBool(*this->msgBuffer, field, index);
    return true;
}

bool UserMessage::SetRepeatedBool(const char *pszFieldName, int index, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(BOOL);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedBool(this->msgBuffer, field, index, value);
    return true;
}

bool UserMessage::AddBool(const char *pszFieldName, bool value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(BOOL);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddBool(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetFloat(const char *pszFieldName, float *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(FLOAT);
    CHECK_FIELD_NOT_REPEATED();

    *out = this->msgBuffer->GetReflection()->GetFloat(*this->msgBuffer, field);
    return true;
}

bool UserMessage::SetFloat(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(FLOAT);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetFloat(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedFloat(const char *pszFieldName, int index, float *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(FLOAT);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    *out = this->msgBuffer->GetReflection()->GetRepeatedFloat(*this->msgBuffer, field, index);
    return true;
}

bool UserMessage::SetRepeatedFloat(const char *pszFieldName, int index, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(FLOAT);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedFloat(this->msgBuffer, field, index, value);
    return true;
}

bool UserMessage::AddFloat(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(FLOAT);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddFloat(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetDouble(const char *pszFieldName, double *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    *out = this->msgBuffer->GetReflection()->GetDouble(*this->msgBuffer, field);
    return true;
}

bool UserMessage::SetDouble(const char *pszFieldName, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetDouble(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedDouble(const char *pszFieldName, int index, double *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(DOUBLE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    *out = this->msgBuffer->GetReflection()->GetRepeatedDouble(*this->msgBuffer, field, index);
    return true;
}

bool UserMessage::SetRepeatedDouble(const char *pszFieldName, int index, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(DOUBLE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedDouble(this->msgBuffer, field, index, value);
    return true;
}

bool UserMessage::AddDouble(const char *pszFieldName, double value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(DOUBLE);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddDouble(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetFloatOrDouble(const char *pszFieldName, float *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        *out = (float)this->msgBuffer->GetReflection()->GetDouble(*this->msgBuffer, field);
    else
        *out = this->msgBuffer->GetReflection()->GetFloat(*this->msgBuffer, field);

    return true;
}

bool UserMessage::SetFloatOrDouble(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE);
    CHECK_FIELD_NOT_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->SetDouble(this->msgBuffer, field, (double)value);
    else
        this->msgBuffer->GetReflection()->SetFloat(this->msgBuffer, field, value);

    return true;
}

bool UserMessage::GetRepeatedFloatOrDouble(const char *pszFieldName, int index, float *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        *out = (float)this->msgBuffer->GetReflection()->GetRepeatedDouble(*this->msgBuffer, field, index);
    else
        *out = this->msgBuffer->GetReflection()->GetRepeatedFloat(*this->msgBuffer, field, index);

    return true;
}

bool UserMessage::SetRepeatedFloatOrDouble(const char *pszFieldName, int index, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->SetRepeatedDouble(this->msgBuffer, field, index, (double)value);
    else
        this->msgBuffer->GetReflection()->SetRepeatedFloat(this->msgBuffer, field, index, value);

    return true;
}

bool UserMessage::AddFloatOrDouble(const char *pszFieldName, float value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE2(FLOAT, DOUBLE);
    CHECK_FIELD_REPEATED();

    if (fieldType == google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE)
        this->msgBuffer->GetReflection()->AddDouble(this->msgBuffer, field, (double)value);
    else
        this->msgBuffer->GetReflection()->AddFloat(this->msgBuffer, field, value);

    return true;
}

bool UserMessage::GetString(const char *pszFieldName, char *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(STRING);
    CHECK_FIELD_NOT_REPEATED();

    strcpy(out, this->msgBuffer->GetReflection()->GetString(*this->msgBuffer, field).c_str());

    return true;
}

bool UserMessage::SetString(const char *pszFieldName, const char *value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(STRING);
    CHECK_FIELD_NOT_REPEATED();

    this->msgBuffer->GetReflection()->SetString(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetRepeatedString(const char *pszFieldName, int index, char *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(STRING);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    std::string scratch;
    strcpy(out, this->msgBuffer->GetReflection()->GetRepeatedStringReference(*this->msgBuffer, field, index, &scratch).c_str());

    return true;
}

bool UserMessage::SetRepeatedString(const char *pszFieldName, int index, const char *value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(STRING);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    this->msgBuffer->GetReflection()->SetRepeatedString(this->msgBuffer, field, index, value);

    return true;
}

bool UserMessage::AddString(const char *pszFieldName, const char *value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(STRING);
    CHECK_FIELD_REPEATED();

    this->msgBuffer->GetReflection()->AddString(this->msgBuffer, field, value);
    return true;
}

bool UserMessage::GetColor(const char *pszFieldName, Color *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    const CMsgRGBA *msgRGBA = (const CMsgRGBA *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    out->SetColor(
        msgRGBA->r(),
        msgRGBA->g(),
        msgRGBA->b(),
        msgRGBA->a());

    return true;
}

bool UserMessage::SetColor(const char *pszFieldName, const Color &value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgRGBA *msgRGBA = (CMsgRGBA *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());

    return true;
}

bool UserMessage::GetRepeatedColor(const char *pszFieldName, int index, Color *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    const CMsgRGBA &msgRGBA = (const CMsgRGBA &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    out->SetColor(
        msgRGBA.r(),
        msgRGBA.g(),
        msgRGBA.b(),
        msgRGBA.a());

    return true;
}

bool UserMessage::SetRepeatedColor(const char *pszFieldName, int index, const Color &value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    CMsgRGBA *msgRGBA = (CMsgRGBA *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());

    return true;
}

bool UserMessage::AddColor(const char *pszFieldName, const Color &value)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgRGBA *msgRGBA = (CMsgRGBA *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgRGBA->set_r(value.r());
    msgRGBA->set_g(value.g());
    msgRGBA->set_b(value.b());
    msgRGBA->set_a(value.a());

    return true;
}

bool UserMessage::GetVector2D(const char *pszFieldName, Vector2D *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    const CMsgVector2D *msgVec2d = (const CMsgVector2D *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    out->Init(
        msgVec2d->x(),
        msgVec2d->y());

    return true;
}

bool UserMessage::SetVector2D(const char *pszFieldName, Vector2D &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgVector2D *msgVec2d = (CMsgVector2D *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);

    return true;
}

bool UserMessage::GetRepeatedVector2D(const char *pszFieldName, int index, Vector2D *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    const CMsgVector2D &msgVec2d = (const CMsgVector2D &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    out->Init(
        msgVec2d.x(),
        msgVec2d.y());

    return true;
}

bool UserMessage::SetRepeatedVector2D(const char *pszFieldName, int index, Vector2D &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    CMsgVector2D *msgVec2d = (CMsgVector2D *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);

    return true;
}

bool UserMessage::AddVector2D(const char *pszFieldName, Vector2D &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgVector2D *msgVec2d = (CMsgVector2D *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgVec2d->set_x(vec.x);
    msgVec2d->set_y(vec.y);

    return true;
}

bool UserMessage::GetVector(const char *pszFieldName, Vector *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    const CMsgVector *msgVec = (const CMsgVector *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    out->Init(
        msgVec->x(),
        msgVec->y(),
        msgVec->z());

    return true;
}

bool UserMessage::SetVector(const char *pszFieldName, Vector &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgVector *msgVec = (CMsgVector *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);

    return true;
}

bool UserMessage::GetRepeatedVector(const char *pszFieldName, int index, Vector *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    const CMsgVector &msgVec = (const CMsgVector &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    out->Init(
        msgVec.x(),
        msgVec.y(),
        msgVec.z());

    return true;
}

bool UserMessage::SetRepeatedVector(const char *pszFieldName, int index, Vector &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    CMsgVector *msgVec = (CMsgVector *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);

    return true;
}

bool UserMessage::AddVector(const char *pszFieldName, Vector &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgVector *msgVec = (CMsgVector *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgVec->set_x(vec.x);
    msgVec->set_y(vec.y);
    msgVec->set_z(vec.z);

    return true;
}

bool UserMessage::GetQAngle(const char *pszFieldName, QAngle *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    const CMsgQAngle *msgAng = (const CMsgQAngle *)&this->msgBuffer->GetReflection()->GetMessage(*this->msgBuffer, field);
    out->Init(
        msgAng->x(),
        msgAng->y(),
        msgAng->z());

    return true;
}

bool UserMessage::SetQAngle(const char *pszFieldName, QAngle &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_NOT_REPEATED();

    CMsgQAngle *msgAng = (CMsgQAngle *)this->msgBuffer->GetReflection()->MutableMessage(this->msgBuffer, field);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);

    return true;
}

bool UserMessage::GetRepeatedQAngle(const char *pszFieldName, int index, QAngle *out)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    const CMsgQAngle &msgAng = (const CMsgQAngle &)this->msgBuffer->GetReflection()->GetRepeatedMessage(*this->msgBuffer, field, index);
    out->Init(
        msgAng.x(),
        msgAng.y(),
        msgAng.z());

    return true;
}

bool UserMessage::SetRepeatedQAngle(const char *pszFieldName, int index, QAngle &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    CMsgQAngle *msgAng = (CMsgQAngle *)this->msgBuffer->GetReflection()->MutableRepeatedMessage(this->msgBuffer, field, index);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);

    return true;
}

bool UserMessage::AddQAngle(const char *pszFieldName, QAngle &vec)
{
    GETCHECK_FIELD();
    CHECK_FIELD_TYPE(MESSAGE);
    CHECK_FIELD_REPEATED();

    CMsgQAngle *msgAng = (CMsgQAngle *)this->msgBuffer->GetReflection()->AddMessage(this->msgBuffer, field);
    msgAng->set_x(vec.x);
    msgAng->set_y(vec.y);
    msgAng->set_z(vec.z);

    return true;
}

int UserMessage::GetRepeatedFieldCount(const char *pszFieldName)
{
    const google::protobuf::FieldDescriptor *field = this->msgBuffer->GetDescriptor()->FindFieldByName(pszFieldName);
    if (!field)
        return -1;

    if (field->label() != google::protobuf::FieldDescriptor::LABEL_REPEATED)
        return -1;

    return this->msgBuffer->GetReflection()->FieldSize(*this->msgBuffer, field);
}

bool UserMessage::RemoveRepeatedFieldValue(const char *pszFieldName, int index)
{
    GETCHECK_FIELD();
    CHECK_FIELD_REPEATED();
    CHECK_REPEATED_ELEMENT(index);

    const google::protobuf::Reflection *pReflection = this->msgBuffer->GetReflection();
    for (int i = index; i < elemCount - 1; ++i)
    {
        pReflection->SwapElements(this->msgBuffer, field, i, i + 1);
    }

    pReflection->RemoveLast(this->msgBuffer, field);

    return true;
}