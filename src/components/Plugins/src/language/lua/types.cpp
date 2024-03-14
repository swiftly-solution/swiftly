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

    state->DoString("function vector3(x, y, z) if x == nil then x = 0.0 end if y == nil then y = 0.0 end if z == nil then z = 0.0 end local tbl = setmetatable({x = x + 0.0, y = y + 0.0, z = z + 0.0}, { __index = function(tb, key) if key ~= \"x\" and key ~= \"y\" and key ~= \"z\" then return nil end return tb[key] end, __newindex = function(tb,key,value) if key ~= \"x\" and key ~= \"y\" and key ~= \"z\" then return print(\"[Runtime] vector3 Error: The supported keys are just \\\"x\\\", \\\"y\\\" and \\\"z\\\".\"); end tb[key] = value; end, __add = function(tb1, tb2) if tb2 == nil then return tb1 end local t = type(tb2); if t == \"boolean\" or t == \"function\" or t == \"string\" then return tb1 end if t == \"number\" then tb1.x = tb1.x + tb2; tb1.y = tb1.y + tb2; tb1.z = tb1.z + tb2; else tb1.x = tb1.x + tb2.x; tb1.y = tb1.y + tb2.y; tb1.z = tb1.z + tb2.z; end return tb1; end, __sub = function(tb1, tb2) if tb2 == nil then return tb1 end local t = type(tb2); if t == \"boolean\" or t == \"function\" or t == \"string\" then return tb1 end if t == \"number\" then tb1.x = tb1.x - tb2; tb1.y = tb1.y - tb2; tb1.z = tb1.z - tb2; else tb1.x = tb1.x - tb2.x; tb1.y = tb1.y - tb2.y; tb1.z = tb1.z - tb2.z; end return tb1; end, __mul = function(tb1, tb2) if tb2 == nil then return tb1 end local t = type(tb2); if t == \"boolean\" or t == \"function\" or t == \"string\" then return tb1 end if t == \"number\" then tb1.x = tb1.x * tb2; tb1.y = tb1.y * tb2; tb1.z = tb1.z * tb2; else tb1.x = tb1.x * tb2.x; tb1.y = tb1.y * tb2.y; tb1.z = tb1.z * tb2.z; end return tb1; end, __div = function(tb1, tb2) if tb2 == nil then return tb1 end local t = type(tb2); if t == \"boolean\" or t == \"function\" or t == \"string\" then return tb1 end if t == \"number\" then tb1.x = tb1.x / tb2; tb1.y = tb1.y / tb2; tb1.z = tb1.z / tb2; else tb1.x = tb1.x / tb2.x; tb1.y = tb1.y / tb2.y; tb1.z = tb1.z / tb2.z; end return tb1; end, __eq = function(tb1, tb2) return (tb1.x == tb2.x and tb1.y == tb2.y and tb1.z == tb2.z) end, __len = function(tb1) return math.sqrt(math.pow(tb1.x, 2) + math.pow(tb1.y, 2) + math.pow(tb1.z, 2)) end, __tostring = function(tb1) return \"vector3(\"..tb1.x..\",\"..tb1.y..\",\"..tb1.z..\")\" end, }); return tbl; end");

    auto ConVarTypeTable = state->CreateTable("ConVarType");

    ConVarTypeTable.SetInteger("Invalid", -1);
    ConVarTypeTable.SetInteger("Bool", 0);
    ConVarTypeTable.SetInteger("Int16", 1);
    ConVarTypeTable.SetInteger("UInt16", 2);
    ConVarTypeTable.SetInteger("Int32", 3);
    ConVarTypeTable.SetInteger("UInt32", 4);
    ConVarTypeTable.SetInteger("Int64", 5);
    ConVarTypeTable.SetInteger("UInt64", 6);
    ConVarTypeTable.SetInteger("Float32", 7);
    ConVarTypeTable.SetInteger("Float64", 8);
    ConVarTypeTable.SetInteger("String", 9);
    ConVarTypeTable.SetInteger("Color", 10);
    ConVarTypeTable.SetInteger("Vector2", 11);
    ConVarTypeTable.SetInteger("Vector3", 12);
    ConVarTypeTable.SetInteger("Vector4", 13);
    ConVarTypeTable.SetInteger("Qangle", 14);

    auto WeaponSlotTable = state->CreateTable("WeaponSlot");

    WeaponSlotTable.SetInteger("Invalid", 0xffffffff);
    WeaponSlotTable.SetInteger("Rifle", 0x0);
    WeaponSlotTable.SetInteger("Pistol", 0x1);
    WeaponSlotTable.SetInteger("Knife", 0x2);
    WeaponSlotTable.SetInteger("Grenades", 0x3);
    WeaponSlotTable.SetInteger("C4", 0x4);
    WeaponSlotTable.SetInteger("ReservedSlot6", 0x5);
    WeaponSlotTable.SetInteger("ReservedSlot7", 0x6);
    WeaponSlotTable.SetInteger("ReservedSlot8", 0x7);
    WeaponSlotTable.SetInteger("ReservedSlot9", 0x8);
    WeaponSlotTable.SetInteger("ReservedSlot10", 0x9);
    WeaponSlotTable.SetInteger("ReservedSlot11", 0xa);
    WeaponSlotTable.SetInteger("Boosts", 0xb);
    WeaponSlotTable.SetInteger("Utility", 0xc);
    WeaponSlotTable.SetInteger("Count", 0xd);
    WeaponSlotTable.SetInteger("CurrentWeapon", 0xe);
    WeaponSlotTable.SetInteger("First", 0x0);
    WeaponSlotTable.SetInteger("Last", 0xC);

    auto WeaponSilencerTypeTable = state->CreateTable("WeaponSilencerType");

    WeaponSilencerTypeTable.SetInteger("None", 0x0);
    WeaponSilencerTypeTable.SetInteger("Detachable", 0x1);
    WeaponSilencerTypeTable.SetInteger("Integrated", 0x2);

    auto PluginStateTable = state->CreateTable("PluginState");

    PluginStateTable.SetInteger("Stopped", 0);
    PluginStateTable.SetInteger("Started", 1);

    auto CollisionGroupTable = state->CreateTable("CollisionGroup");

    CollisionGroupTable.SetInteger("Always", 0);
    CollisionGroupTable.SetInteger("Never", 1);
    CollisionGroupTable.SetInteger("Trigger", 2);
    CollisionGroupTable.SetInteger("ConditionallySolid", 3);
    CollisionGroupTable.SetInteger("Default", 4);
    CollisionGroupTable.SetInteger("Debris", 5);
    CollisionGroupTable.SetInteger("InteractiveDebris", 6);
    CollisionGroupTable.SetInteger("Interactive", 7);
    CollisionGroupTable.SetInteger("Player", 8);
    CollisionGroupTable.SetInteger("BreakableGlass", 9);
    CollisionGroupTable.SetInteger("Vehicle", 10);
    CollisionGroupTable.SetInteger("PlayerMovement", 11);
    CollisionGroupTable.SetInteger("NPC", 12);
    CollisionGroupTable.SetInteger("InVehicle", 13);
    CollisionGroupTable.SetInteger("Weapon", 14);
    CollisionGroupTable.SetInteger("VehicleClip", 15);
    CollisionGroupTable.SetInteger("Projectile", 16);
    CollisionGroupTable.SetInteger("DoorBlocker", 17);
    CollisionGroupTable.SetInteger("PassableDoor", 18);
    CollisionGroupTable.SetInteger("Dissolving", 19);
    CollisionGroupTable.SetInteger("Pushaway", 20);
    CollisionGroupTable.SetInteger("NPCActor", 21);
    CollisionGroupTable.SetInteger("NPCScripted", 22);
    CollisionGroupTable.SetInteger("PZClip", 23);
    CollisionGroupTable.SetInteger("Props", 24);
    CollisionGroupTable.SetInteger("LastSharedCollisionGroup", 25);

    auto DamageTypesTable = state->CreateTable("DamageTypes");

    DamageTypesTable.SetInteger("Generic", 0);
    DamageTypesTable.SetInteger("Crush", 1);
    DamageTypesTable.SetInteger("Bullet", 2);
    DamageTypesTable.SetInteger("Slash", 4);
    DamageTypesTable.SetInteger("Burn", 8);
    DamageTypesTable.SetInteger("Vehicle", 16);
    DamageTypesTable.SetInteger("Fall", 32);
    DamageTypesTable.SetInteger("Blast", 64);
    DamageTypesTable.SetInteger("Club", 128);
    DamageTypesTable.SetInteger("Shock", 256);
    DamageTypesTable.SetInteger("Sonic", 512);
    DamageTypesTable.SetInteger("Energybeam", 1024);
    DamageTypesTable.SetInteger("Drown", 16384);
    DamageTypesTable.SetInteger("Poison", 32768);
    DamageTypesTable.SetInteger("Radiation", 65536);
    DamageTypesTable.SetInteger("Drownrecover", 131072);
    DamageTypesTable.SetInteger("Acid", 262144);
    DamageTypesTable.SetInteger("Physgun", 1048576);
    DamageTypesTable.SetInteger("Dissolve", 2097152);
    DamageTypesTable.SetInteger("BlastSurface", 4194304);
    DamageTypesTable.SetInteger("Buckshot", 16777216);
    DamageTypesTable.SetInteger("LastGenericFlag", 16777216);
    DamageTypesTable.SetInteger("Headshot", 33554432);
    DamageTypesTable.SetInteger("Dangerzone", 67108864);

    auto DamageFlagsTable = state->CreateTable("DamageFlags");

    DamageFlagsTable.SetInteger("None", 0);
    DamageFlagsTable.SetInteger("SupressHealthChanges", 1);
    DamageFlagsTable.SetInteger("SupressPhysicsForce", 2);
    DamageFlagsTable.SetInteger("SupressEffects", 4);
    DamageFlagsTable.SetInteger("PreventDeath", 8);
    DamageFlagsTable.SetInteger("ForceDeath", 16);
    DamageFlagsTable.SetInteger("AlwaysGib", 32);
    DamageFlagsTable.SetInteger("NeverGib", 64);
    DamageFlagsTable.SetInteger("RemoveNoRagdoll", 128);
    DamageFlagsTable.SetInteger("SupressDamageModification", 256);
    DamageFlagsTable.SetInteger("AlwaysFireDamageEvents", 512);
    DamageFlagsTable.SetInteger("RadiusDmg", 1024);
    DamageFlagsTable.SetInteger("LastDFlag", 1024);
    DamageFlagsTable.SetInteger("IgnoreArmor", 2048);

    state->CreateInteger(0, "TEAM_NONE");
    state->CreateInteger(1, "TEAM_SPECTATOR");
    state->CreateInteger(2, "TEAM_T");
    state->CreateInteger(3, "TEAM_CT");

    state->CreateInteger(0, "SITE_A");
    state->CreateInteger(1, "SITE_B");
    state->CreateInteger(2, "SITE_UNKNOWN");
}