#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

void SetupLuaTypes(luacpp::LuaState *state, Plugin *plugin)
{

    auto ContentTypeTable = state->CreateTable("ContentType");

    ContentTypeTable.SetInteger("APPLICATION_JSON", 1);
    ContentTypeTable.SetInteger("APPLICATION_FORM_URLENCODE", 2);
    ContentTypeTable.SetInteger("MULTIPART_FORMDATA", 3);
    ContentTypeTable.SetInteger("TEXT_CSS", 4);
    ContentTypeTable.SetInteger("TEXT_CSV", 5);
    ContentTypeTable.SetInteger("TEXT_HTML", 6);
    ContentTypeTable.SetInteger("TEXT_JAVASCRIPT", 7);
    ContentTypeTable.SetInteger("TEXT_PLAIN", 8);
    ContentTypeTable.SetInteger("TEXT_XML", 9);

    auto LogLevelTable = state->CreateTable("LogType");

    LogLevelTable.SetInteger("Debug", 1);
    LogLevelTable.SetInteger("Warning", 2);
    LogLevelTable.SetInteger("Error", 3);
    LogLevelTable.SetInteger("Common", 4);

    auto PlayerStatTable = state->CreateTable("PlayerStat");

    PlayerStatTable.SetInteger("Kills", 0);
    PlayerStatTable.SetInteger("Deaths", 1);
    PlayerStatTable.SetInteger("Assists", 2);
    PlayerStatTable.SetInteger("Damage", 3);

    auto MessageTypeTable = state->CreateTable("MessageType");

    MessageTypeTable.SetInteger("Notify", 1);
    MessageTypeTable.SetInteger("Console", 2);
    MessageTypeTable.SetInteger("Chat", 3);
    MessageTypeTable.SetInteger("Center", 4);

    auto DisconnectReasonTable = state->CreateTable("DisconnectReason");

    DisconnectReasonTable.SetInteger("Invalid", 0);
    DisconnectReasonTable.SetInteger("Shutdown", 1);
    DisconnectReasonTable.SetInteger("DisconnectByUser", 2);
    DisconnectReasonTable.SetInteger("DisconnectByServer", 3);
    DisconnectReasonTable.SetInteger("Lost", 4);
    DisconnectReasonTable.SetInteger("Overflow", 5);
    DisconnectReasonTable.SetInteger("SteamBanned", 6);
    DisconnectReasonTable.SetInteger("SteamInUse", 7);
    DisconnectReasonTable.SetInteger("SteamTicket", 8);
    DisconnectReasonTable.SetInteger("SteamLogon", 9);
    DisconnectReasonTable.SetInteger("SteamAuthCancelled", 10);
    DisconnectReasonTable.SetInteger("SteamAuthAlreadyUsed", 11);
    DisconnectReasonTable.SetInteger("SteamAuthInvalid", 12);
    DisconnectReasonTable.SetInteger("SteamVacBanned", 13);
    DisconnectReasonTable.SetInteger("SteamLoggedInElsewhere", 14);
    DisconnectReasonTable.SetInteger("SteamVacCheckTimedout", 15);
    DisconnectReasonTable.SetInteger("SteamDropped", 16);
    DisconnectReasonTable.SetInteger("SteamOwnership", 17);
    DisconnectReasonTable.SetInteger("ServerInfoOverflow", 18);
    DisconnectReasonTable.SetInteger("TickMsgOverflow", 19);
    DisconnectReasonTable.SetInteger("StringTableMsgOverflow", 20);
    DisconnectReasonTable.SetInteger("DeltaentMsgOverflow", 21);
    DisconnectReasonTable.SetInteger("TempentMsgOverflow", 22);
    DisconnectReasonTable.SetInteger("SoundsMsgOverflow", 23);
    DisconnectReasonTable.SetInteger("SnapshotOverflow", 24);
    DisconnectReasonTable.SetInteger("SnapshotError", 25);
    DisconnectReasonTable.SetInteger("ReliableOverflow", 26);
    DisconnectReasonTable.SetInteger("BadDeltaTick", 27);
    DisconnectReasonTable.SetInteger("NoMoreSplits", 28);
    DisconnectReasonTable.SetInteger("Timedout", 29);
    DisconnectReasonTable.SetInteger("Disconnected", 30);
    DisconnectReasonTable.SetInteger("LeavingSplit", 31);
    DisconnectReasonTable.SetInteger("DifferentClassTables", 32);
    DisconnectReasonTable.SetInteger("BadRelayPassword", 33);
    DisconnectReasonTable.SetInteger("BadSpectatorPassword", 34);
    DisconnectReasonTable.SetInteger("HLTVRestricted", 35);
    DisconnectReasonTable.SetInteger("NoSpectators", 36);
    DisconnectReasonTable.SetInteger("HLTVUnavailable", 37);
    DisconnectReasonTable.SetInteger("HLTVStop", 38);
    DisconnectReasonTable.SetInteger("Kicked", 39);
    DisconnectReasonTable.SetInteger("BanAdded", 40);
    DisconnectReasonTable.SetInteger("KickBanAdded", 41);
    DisconnectReasonTable.SetInteger("HLTVDirect", 42);
    DisconnectReasonTable.SetInteger("PureServerClientExtra", 43);
    DisconnectReasonTable.SetInteger("PureServerMismatch", 44);
    DisconnectReasonTable.SetInteger("UserCmd", 45);
    DisconnectReasonTable.SetInteger("RejectedByGame", 46);
    DisconnectReasonTable.SetInteger("MessageParseError", 47);
    DisconnectReasonTable.SetInteger("InvalidMessageError", 48);
    DisconnectReasonTable.SetInteger("BadServerPassword", 49);
    DisconnectReasonTable.SetInteger("DirectConnectReservation", 50);
    DisconnectReasonTable.SetInteger("ConnectionFailure", 51);
    DisconnectReasonTable.SetInteger("NoPeerGroupHandlers", 52);
    DisconnectReasonTable.SetInteger("Reconnection", 53);
    DisconnectReasonTable.SetInteger("LoopShutdown", 54);
    DisconnectReasonTable.SetInteger("LoopDeactivate", 55);
    DisconnectReasonTable.SetInteger("HostEndGame", 56);
    DisconnectReasonTable.SetInteger("LoopLevelLoadActivate", 57);
    DisconnectReasonTable.SetInteger("CreateServerFailed", 58);
    DisconnectReasonTable.SetInteger("Exiting", 59);
    DisconnectReasonTable.SetInteger("RequestHostStateIdle", 60);
    DisconnectReasonTable.SetInteger("RequestHostStateHLTVRelay", 61);
    DisconnectReasonTable.SetInteger("ClientConsistencyFail", 62);
    DisconnectReasonTable.SetInteger("UnableToCRCMap", 63);
    DisconnectReasonTable.SetInteger("ClientNoMap", 64);
    DisconnectReasonTable.SetInteger("ClientDifferentMap", 65);
    DisconnectReasonTable.SetInteger("ServerRequiresSteam", 66);
    DisconnectReasonTable.SetInteger("SteamDenyMisc", 67);
    DisconnectReasonTable.SetInteger("SteamDenyBadAnticheat", 68);
    DisconnectReasonTable.SetInteger("ServerShutdown", 69);

    PRINT("Scripting - Lua", "Types loaded.\n");
}