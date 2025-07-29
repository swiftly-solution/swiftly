namespace SwiftlyS2.API.Scripting
{
    public enum CollisionGroup
    {
        COLLISION_GROUP_ALWAYS = 0,
        COLLISION_GROUP_NONPHYSICAL = 1,
        COLLISION_GROUP_TRIGGER = 2,
        COLLISION_GROUP_CONDITIONALLY_SOLID = 3,
        COLLISION_GROUP_FIRST_USER = 4,
        COLLISION_GROUPS_MAX_ALLOWED = 64,
        COLLISION_GROUP_DEFAULT = 4,
        COLLISION_GROUP_DEBRIS = 5,
        COLLISION_GROUP_INTERACTIVE_DEBRIS = 6,
        COLLISION_GROUP_INTERACTIVE = 7,
        COLLISION_GROUP_PLAYER = 8,
        COLLISION_GROUP_BREAKABLE_GLASS = 9,
        COLLISION_GROUP_VEHICLE = 10,
        COLLISION_GROUP_PLAYER_MOVEMENT = 11,
        COLLISION_GROUP_NPC = 12,
        COLLISION_GROUP_IN_VEHICLE = 13,
        COLLISION_GROUP_WEAPON = 14,
        COLLISION_GROUP_VEHICLE_CLIP = 15,
        COLLISION_GROUP_PROJECTILE = 16,
        COLLISION_GROUP_DOOR_BLOCKER = 17,
        COLLISION_GROUP_PASSABLE_DOOR = 18,
        COLLISION_GROUP_DISSOLVING = 19,
        COLLISION_GROUP_PUSHAWAY = 20,
        COLLISION_GROUP_NPC_ACTOR = 21,
        COLLISION_GROUP_NPC_SCRIPTED = 22,
        COLLISION_GROUP_PZ_CLIP = 23,
        COLLISION_GROUP_PROPS = 24,
        LAST_SHARED_COLLISION_GROUP = 25    
    }
    public enum ConvarFlags
    {
        FCVAR_NONE = 0,
        FCVAR_LINKED_CONCOMMAND = 1<<0,
        FCVAR_DEVELOPMENTONLY = 1<<1,
        FCVAR_GAMEDLL = 1<<2,
        FCVAR_CLIENTDLL = 1<<3,
        FCVAR_HIDDEN = 1<<4,
        FCVAR_PROTECTED = 1<<5,
        FCVAR_SPONLY = 1<<6,
        FCVAR_ARCHIVE = 1<<7,
        FCVAR_NOTIFY = 1<<8,
        FCVAR_USERINFO = 1<<9,
        FCVAR_REFERENCE = 1<<10,
        FCVAR_UNLOGGED = 1<<11,
        FCVAR_INITIAL_SETVALUE = 1<<12,
        FCVAR_REPLICATED = 1<<13,
        FCVAR_CHEAT = 1<<14,
        FCVAR_PER_USER = 1<<15,
        FCVAR_DEMO = 1<<16,
        FCVAR_DONTRECORD = 1<<17,
        FCVAR_PERFORMING_CALLBACKS = 1<<18,
        FCVAR_RELEASE = 1<<19,
        FCVAR_MENUBAR_ITEM = 1<<20,
        FCVAR_COMMANDLINE_ENFORCED = 1<<21,
        FCVAR_NOT_CONNECTED = 1<<22,
        FCVAR_VCONSOLE_FUZZY_MATCHING = 1<<23,
        FCVAR_SERVER_CAN_EXECUTE = 1<<24,
        FCVAR_CLIENT_CAN_EXECUTE = 1<<25,
        FCVAR_SERVER_CANNOT_QUERY = 1<<26,
        FCVAR_VCONSOLE_SET_FOCUS = 1<<27,
        FCVAR_CLIENTCMD_CAN_EXECUTE = 1<<28,
        FCVAR_EXECUTE_PER_TICK = 1<<29,
        FCVAR_DEFENSIVE = 1<<32    
    }
    public enum DisconnectReason
    {
        Invalid = 0,
        Shutdown = 1,
        DisconnectByUser = 2,
        DisconnectByServer = 3,
        Lost = 4,
        Overflow = 5,
        SteamBanned = 6,
        SteamInUse = 7,
        SteamTicket = 8,
        SteamLogon = 9,
        SteamAuthCancelled = 10,
        SteamAuthAlreadyUsed = 11,
        SteamAuthInvalid = 12,
        SteamVacBanned = 13,
        SteamLoggedInElsewhere = 14,
        SteamVacCheckTimedout = 15,
        SteamDropped = 16,
        SteamOwnership = 17,
        ServerInfoOverflow = 18,
        TickMsgOverflow = 19,
        StringTableMsgOverflow = 20,
        DeltaentMsgOverflow = 21,
        TempentMsgOverflow = 22,
        SoundsMsgOverflow = 23,
        SnapshotOverflow = 24,
        SnapshotError = 25,
        ReliableOverflow = 26,
        BadDeltaTick = 27,
        NoMoreSplits = 28,
        Timedout = 29,
        Disconnected = 30,
        LeavingSplit = 31,
        DifferentClassTables = 32,
        BadRelayPassword = 33,
        BadSpectatorPassword = 34,
        HLTVRestricted = 35,
        NoSpectators = 36,
        HLTVUnavailable = 37,
        HLTVStop = 38,
        Kicked = 39,
        BanAdded = 40,
        KickBanAdded = 41,
        HLTVDirect = 42,
        PureServerClientExtra = 43,
        PureServerMismatch = 44,
        UserCmd = 45,
        RejectedByGame = 46,
        MessageParseError = 47,
        InvalidMessageError = 48,
        BadServerPassword = 49,
        DirectConnectReservation = 50,
        ConnectionFailure = 51,
        NoPeerGroupHandlers = 52,
        Reconnection = 53,
        LoopShutdown = 54,
        LoopDeactivate = 55,
        HostEndGame = 56,
        LoopLevelLoadActivate = 57,
        CreateServerFailed = 58,
        Exiting = 59,
        RequestHostStateIdle = 60,
        RequestHostStateHLTVRelay = 61,
        ClientConsistencyFail = 62,
        UnableToCRCMap = 63,
        ClientNoMap = 64,
        ClientDifferentMap = 65,
        ServerRequiresSteam = 66,
        SteamDenyMisc = 67,
        SteamDenyBadAnticheat = 68,
        ServerShutdown = 69,
        ReplayIncompatible = 71,
        ConnectRequestTimedOut = 72,
        ServerIncompatible = 73,
        LocalProblemManyRelays = 74,
        LocalProblemHostedServerPrimaryRelay = 75,
        LocalProblemNetworkConfig = 76,
        LocalProblemOther = 77,
        RemoteTimeout = 79,
        RemoteTimeoutConnecting = 80,
        RemoteOther = 81,
        RemoteBadCrypt = 82,
        RemoteCertNotTrusted = 83,
        Unusual = 84,
        InternalError = 85,
        RejectBadChallenge = 128,
        RejectNoLobby = 129,
        RejectBackgroundMap = 130,
        RejectSinglePlayer = 131,
        RejectHiddenGame = 132,
        RejectLanRestrict = 133,
        RejectBadPassword = 134,
        RejectServerFull = 135,
        RejectInvalidReservation = 136,
        RejectFailedChannel = 137,
        RejectConnectFromLobby = 138,
        RejectReservedForLobby = 139,
        RejectInvalidKeyLength = 140,
        RejectOldProtocol = 141,
        RejectNewProtocol = 142,
        RejectInvalidConnection = 143,
        RejectInvalidCertLen = 144,
        RejectInvalidSteamCertLen = 145,
        RejectSteam = 146,
        RejectServerAuthDisabled = 147,
        RejectServerCDKeyAuthInvalid = 148,
        RejectBanned = 149,
        KickedTeamKilling = 150,
        KickedTKStart = 151,
        KickedUntrustedAccount = 152,
        KickedConvictedAccount = 153,
        KickedCompetitiveCooldown = 154,
        KickedTeamHurting = 155,
        KickedHostageKilling = 156,
        KickedVotedOff = 157,
        KickedIdle = 158,
        KickedSuicide = 159,
        KickedNoSteamLogin = 160,
        KickedNoSteamTicket = 161,
        KickedInputAutomation = 162,
        KickedVACNetAbnormalBehavior = 163    
    }
    public enum EConVarType
    {
        EConVarType_Invalid = -1,
        EConVarType_Bool = 0,
        EConVarType_Int16 = 1,
        EConVarType_UInt16 = 2,
        EConVarType_Int32 = 3,
        EConVarType_UInt32 = 4,
        EConVarType_Int64 = 5,
        EConVarType_UInt64 = 6,
        EConVarType_Float32 = 7,
        EConVarType_Float64 = 8,
        EConVarType_String = 9,
        EConVarType_Color = 10,
        EConVarType_Vector2 = 11,
        EConVarType_Vector3 = 12,
        EConVarType_Vector4 = 13,
        EConVarType_Qangle = 14    
    }

    public enum EventResult
    {
        Continue = 0,
        Stop = 1,
        Handled = 2    
    }

    public enum GamePhase
    {
        GAMEPHASE_WARMUP_ROUND = 0,
        GAMEPHASE_PLAYING_STANDARD = 1,
        GAMEPHASE_PLAYING_FIRST_HALF = 2,
        GAMEPHASE_PLAYING_SECOND_HALF = 3,
        GAMEPHASE_HALFTIME = 4,
        GAMEPHASE_MATCH_ENDED = 5,
        GAMEPHASE_MAX = 6    
    }
    public class HookHandle : ClassData
    {
    
    }
    public enum ListenOverride
    {
        Listen_Default = 0,
        Listen_Mute = 1,
        Listen_Hear = 2    
    }
    public enum LogType_t
    {
        Debug = 1,
        Warning = 2,
        Error = 3,
        Common = 4    
    }
    public enum MessageType
    {
        Notify = 1,
        Console = 2,
        Chat = 3,
        Center = 4    
    }
    public enum PluginState_t
    {
        Started = 0,
        Stopped = 1,
        Starting = 2    
    }
    public enum RoundEndReason_t
    {
        Unknown = 0,
        TargetBombed = 0x1,
        TerroristsEscaped = 0x4,
        CTsPreventEscape = 0x5,
        EscapingTerroristsNeutralized = 0x6,
        BombDefused = 0x7,
        CTsWin = 0x8,
        TerroristsWin = 0x9,
        RoundDraw = 0xA,
        AllHostageRescued = 0xB,
        TargetSaved = 0xC,
        HostagesNotRescued = 0xD,
        TerroristsNotEscaped = 0xE,
        GameCommencing = 0x10,
        TerroristsSurrender = 0x11,
        CTsSurrender = 0x12,
        TerroristsPlanted = 0x13,
        CTsReachedHostage = 0x14,
        SurvivalWin = 0x15,
        SurvivalDraw = 0x16    
    }
    public enum Team
    {
        None = 0,
        Spectator = 1,
        T = 2,
        CT = 3    
    }
    public class TimerHandle : ClassData
    {
    
    }
    public enum VoiceFlagValue
    {
        Speak_Normal = 0,
        Speak_Muted = 1,
        Speak_All = 2,
        Speak_ListenAll = 4,
        Speak_Team = 8,
        Speak_ListenTeam = 16    
    }
}