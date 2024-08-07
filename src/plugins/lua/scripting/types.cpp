#include "core.h"

#include "../../../types/EventResult.h"
#include "../../../types/LogType.h"
#include "../../../player/Player.h"

void SetupLuaTypes(LuaPlugin *plugin, lua_State *state)
{

    luabridge::getGlobalNamespace(state)

        .beginNamespace("PluginState_t")
        .addConstant("Started", (uint64_t)PluginState_t::Started)
        .addConstant("Stopped", (uint64_t)PluginState_t::Stopped)
        .endNamespace()

        .beginNamespace("Team")
        .addConstant("None", CS_TEAM_NONE)
        .addConstant("Spectator", CS_TEAM_SPECTATOR)
        .addConstant("T", CS_TEAM_T)
        .addConstant("CT", CS_TEAM_CT)
        .endNamespace()

        .beginNamespace("EventResult")
        .addConstant("Continue", (uint64_t)EventResult::Continue)
        .addConstant("Stop", (uint64_t)EventResult::Stop)
        .addConstant("Handled", (uint64_t)EventResult::Handled)
        .endNamespace()

        .beginNamespace("MessageType")
        .addConstant("Notify", HUD_PRINTNOTIFY)
        .addConstant("Console", HUD_PRINTCONSOLE)
        .addConstant("Chat", HUD_PRINTTALK)
        .addConstant("Center", HUD_PRINTCENTER)
        .endNamespace()

        .beginNamespace("DisconnectReason")
        .addConstant("Invalid", 0)
        .addConstant("Shutdown", 1)
        .addConstant("DisconnectByUser", 2)
        .addConstant("DisconnectByServer", 3)
        .addConstant("Lost", 4)
        .addConstant("Overflow", 5)
        .addConstant("SteamBanned", 6)
        .addConstant("SteamInUse", 7)
        .addConstant("SteamTicket", 8)
        .addConstant("SteamLogon", 9)
        .addConstant("SteamAuthCancelled", 10)
        .addConstant("SteamAuthAlreadyUsed", 11)
        .addConstant("SteamAuthInvalid", 12)
        .addConstant("SteamVacBanned", 13)
        .addConstant("SteamLoggedInElsewhere", 14)
        .addConstant("SteamVacCheckTimedout", 15)
        .addConstant("SteamDropped", 16)
        .addConstant("SteamOwnership", 17)
        .addConstant("ServerInfoOverflow", 18)
        .addConstant("TickMsgOverflow", 19)
        .addConstant("StringTableMsgOverflow", 20)
        .addConstant("DeltaentMsgOverflow", 21)
        .addConstant("TempentMsgOverflow", 22)
        .addConstant("SoundsMsgOverflow", 23)
        .addConstant("SnapshotOverflow", 24)
        .addConstant("SnapshotError", 25)
        .addConstant("ReliableOverflow", 26)
        .addConstant("BadDeltaTick", 27)
        .addConstant("NoMoreSplits", 28)
        .addConstant("Timedout", 29)
        .addConstant("Disconnected", 30)
        .addConstant("LeavingSplit", 31)
        .addConstant("DifferentClassTables", 32)
        .addConstant("BadRelayPassword", 33)
        .addConstant("BadSpectatorPassword", 34)
        .addConstant("HLTVRestricted", 35)
        .addConstant("NoSpectators", 36)
        .addConstant("HLTVUnavailable", 37)
        .addConstant("HLTVStop", 38)
        .addConstant("Kicked", 39)
        .addConstant("BanAdded", 40)
        .addConstant("KickBanAdded", 41)
        .addConstant("HLTVDirect", 42)
        .addConstant("PureServerClientExtra", 43)
        .addConstant("PureServerMismatch", 44)
        .addConstant("UserCmd", 45)
        .addConstant("RejectedByGame", 46)
        .addConstant("MessageParseError", 47)
        .addConstant("InvalidMessageError", 48)
        .addConstant("BadServerPassword", 49)
        .addConstant("DirectConnectReservation", 50)
        .addConstant("ConnectionFailure", 51)
        .addConstant("NoPeerGroupHandlers", 52)
        .addConstant("Reconnection", 53)
        .addConstant("LoopShutdown", 54)
        .addConstant("LoopDeactivate", 55)
        .addConstant("HostEndGame", 56)
        .addConstant("LoopLevelLoadActivate", 57)
        .addConstant("CreateServerFailed", 58)
        .addConstant("Exiting", 59)
        .addConstant("RequestHostStateIdle", 60)
        .addConstant("RequestHostStateHLTVRelay", 61)
        .addConstant("ClientConsistencyFail", 62)
        .addConstant("UnableToCRCMap", 63)
        .addConstant("ClientNoMap", 64)
        .addConstant("ClientDifferentMap", 65)
        .addConstant("ServerRequiresSteam", 66)
        .addConstant("SteamDenyMisc", 67)
        .addConstant("SteamDenyBadAnticheat", 68)
        .addConstant("ServerShutdown", 69)
        .endNamespace()

        .beginNamespace("EConVarType")
        .addConstant("EConVarType_Invalid", (uint64_t)EConVarType::EConVarType_Invalid)
        .addConstant("EConVarType_Bool", (uint64_t)EConVarType::EConVarType_Bool)
        .addConstant("EConVarType_Int16", (uint64_t)EConVarType::EConVarType_Int16)
        .addConstant("EConVarType_UInt16", (uint64_t)EConVarType::EConVarType_UInt16)
        .addConstant("EConVarType_Int32", (uint64_t)EConVarType::EConVarType_Int32)
        .addConstant("EConVarType_UInt32", (uint64_t)EConVarType::EConVarType_UInt32)
        .addConstant("EConVarType_Int64", (uint64_t)EConVarType::EConVarType_Int64)
        .addConstant("EConVarType_UInt64", (uint64_t)EConVarType::EConVarType_UInt64)
        .addConstant("EConVarType_Float32", (uint64_t)EConVarType::EConVarType_Float32)
        .addConstant("EConVarType_Float64", (uint64_t)EConVarType::EConVarType_Float64)
        .addConstant("EConVarType_String", (uint64_t)EConVarType::EConVarType_String)
        .addConstant("EConVarType_Color", (uint64_t)EConVarType::EConVarType_Color)
        .addConstant("EConVarType_Vector2", (uint64_t)EConVarType::EConVarType_Vector2)
        .addConstant("EConVarType_Vector3", (uint64_t)EConVarType::EConVarType_Vector3)
        .addConstant("EConVarType_Vector4", (uint64_t)EConVarType::EConVarType_Vector4)
        .addConstant("EConVarType_Qangle", (uint64_t)EConVarType::EConVarType_Qangle)

        .endNamespace()

        .beginNamespace("ListenOverride")
        .addConstant("Listen_Default", 0)
        .addConstant("Listen_Mute", 1)
        .addConstant("Listen_Hear", 2)
        .endNamespace()

        .beginNamespace("VoiceFlagValue")
        .addConstant("Speak_Normal", 0)
        .addConstant("Speak_Muted", 1 << 0)
        .addConstant("Speak_All", 1 << 1)
        .addConstant("Speak_ListenAll", 1 << 2)
        .addConstant("Speak_Team", 1 << 3)
        .addConstant("Speak_ListenTeam", 1 << 4)
        .endNamespace()

        .beginNamespace("LogType_t")
        .addConstant("Debug", (uint64_t)LogType_t::Debug)
        .addConstant("Warning", (uint64_t)LogType_t::Warning)
        .addConstant("Error", (uint64_t)LogType_t::Error)
        .addConstant("Common", (uint64_t)LogType_t::Common)
        .endNamespace();
}