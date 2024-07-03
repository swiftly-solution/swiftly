#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBasePlayerController::GCBasePlayerController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBasePlayerController::GCBasePlayerController(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCBasePlayerController::GetInButtonsWhichAreToggles() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerController", "m_nInButtonsWhichAreToggles");
}
void GCBasePlayerController::SetInButtonsWhichAreToggles(uint64_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_nInButtonsWhichAreToggles", false, value);
}
uint32_t GCBasePlayerController::GetTickBase() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerController", "m_nTickBase");
}
void GCBasePlayerController::SetTickBase(uint32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_nTickBase", false, value);
}
GCBasePlayerPawn GCBasePlayerController::GetPawn() const {
    GCBasePlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerController", "m_hPawn"));
    return value;
}
void GCBasePlayerController::SetPawn(GCBasePlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Pawn' is not possible.\n");
}
bool GCBasePlayerController::GetKnownTeamMismatch() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bKnownTeamMismatch");
}
void GCBasePlayerController::SetKnownTeamMismatch(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bKnownTeamMismatch", false, value);
}
int32_t GCBasePlayerController::GetSplitScreenSlot() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nSplitScreenSlot");
}
void GCBasePlayerController::SetSplitScreenSlot(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_nSplitScreenSlot", false, value);
}
GCBasePlayerController GCBasePlayerController::GetSplitOwner() const {
    GCBasePlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CBasePlayerController", "m_hSplitOwner"));
    return value;
}
void GCBasePlayerController::SetSplitOwner(GCBasePlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'SplitOwner' is not possible.\n");
}
bool GCBasePlayerController::GetIsHLTV() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bIsHLTV");
}
void GCBasePlayerController::SetIsHLTV(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bIsHLTV", false, value);
}
uint64_t GCBasePlayerController::GetConnected() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerController", "m_iConnected");
}
void GCBasePlayerController::SetConnected(uint64_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_iConnected", false, value);
}
std::string GCBasePlayerController::GetPlayerName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CBasePlayerController", "m_iszPlayerName");
}
void GCBasePlayerController::SetPlayerName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CBasePlayerController", "m_iszPlayerName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 128);
}
std::string GCBasePlayerController::GetNetworkIDString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CBasePlayerController", "m_szNetworkIDString").Get();
}
void GCBasePlayerController::SetNetworkIDString(std::string value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_szNetworkIDString", false, CUtlString(value.c_str()));
}
float GCBasePlayerController::GetLerpTime() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerController", "m_fLerpTime");
}
void GCBasePlayerController::SetLerpTime(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_fLerpTime", false, value);
}
bool GCBasePlayerController::GetLagCompensation() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bLagCompensation");
}
void GCBasePlayerController::SetLagCompensation(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bLagCompensation", false, value);
}
bool GCBasePlayerController::GetPredict() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bPredict");
}
void GCBasePlayerController::SetPredict(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bPredict", false, value);
}
bool GCBasePlayerController::GetAutoKickDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bAutoKickDisabled");
}
void GCBasePlayerController::SetAutoKickDisabled(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bAutoKickDisabled", false, value);
}
bool GCBasePlayerController::GetIsLowViolence() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bIsLowViolence");
}
void GCBasePlayerController::SetIsLowViolence(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bIsLowViolence", false, value);
}
bool GCBasePlayerController::GetGamePaused() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bGamePaused");
}
void GCBasePlayerController::SetGamePaused(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bGamePaused", false, value);
}
int32_t GCBasePlayerController::GetLastRealCommandNumberExecuted() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nLastRealCommandNumberExecuted");
}
void GCBasePlayerController::SetLastRealCommandNumberExecuted(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_nLastRealCommandNumberExecuted", false, value);
}
int32_t GCBasePlayerController::GetLastLateCommandExecuted() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nLastLateCommandExecuted");
}
void GCBasePlayerController::SetLastLateCommandExecuted(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_nLastLateCommandExecuted", false, value);
}
uint64_t GCBasePlayerController::GetIgnoreGlobalChat() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerController", "m_iIgnoreGlobalChat");
}
void GCBasePlayerController::SetIgnoreGlobalChat(uint64_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_iIgnoreGlobalChat", false, value);
}
float GCBasePlayerController::GetLastPlayerTalkTime() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerController", "m_flLastPlayerTalkTime");
}
void GCBasePlayerController::SetLastPlayerTalkTime(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_flLastPlayerTalkTime", false, value);
}
float GCBasePlayerController::GetLastEntitySteadyState() const {
    return GetSchemaValue<float>(m_ptr, "CBasePlayerController", "m_flLastEntitySteadyState");
}
void GCBasePlayerController::SetLastEntitySteadyState(float value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_flLastEntitySteadyState", false, value);
}
int32_t GCBasePlayerController::GetAvailableEntitySteadyState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerController", "m_nAvailableEntitySteadyState");
}
void GCBasePlayerController::SetAvailableEntitySteadyState(int32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_nAvailableEntitySteadyState", false, value);
}
bool GCBasePlayerController::GetHasAnySteadyStateEnts() const {
    return GetSchemaValue<bool>(m_ptr, "CBasePlayerController", "m_bHasAnySteadyStateEnts");
}
void GCBasePlayerController::SetHasAnySteadyStateEnts(bool value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_bHasAnySteadyStateEnts", false, value);
}
uint64_t GCBasePlayerController::GetSteamID() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBasePlayerController", "m_steamID");
}
void GCBasePlayerController::SetSteamID(uint64_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_steamID", false, value);
}
uint32_t GCBasePlayerController::GetDesiredFOV() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBasePlayerController", "m_iDesiredFOV");
}
void GCBasePlayerController::SetDesiredFOV(uint32_t value) {
    SetSchemaValue(m_ptr, "CBasePlayerController", "m_iDesiredFOV", false, value);
}
std::string GCBasePlayerController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBasePlayerController::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCBasePlayerController::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCBasePlayerController::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBasePlayerController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBasePlayerController>("CBasePlayerController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InButtonsWhichAreToggles", &GCBasePlayerController::GetInButtonsWhichAreToggles, &GCBasePlayerController::SetInButtonsWhichAreToggles)
        .addProperty("TickBase", &GCBasePlayerController::GetTickBase, &GCBasePlayerController::SetTickBase)
        .addProperty("Pawn", &GCBasePlayerController::GetPawn, &GCBasePlayerController::SetPawn)
        .addProperty("KnownTeamMismatch", &GCBasePlayerController::GetKnownTeamMismatch, &GCBasePlayerController::SetKnownTeamMismatch)
        .addProperty("SplitScreenSlot", &GCBasePlayerController::GetSplitScreenSlot, &GCBasePlayerController::SetSplitScreenSlot)
        .addProperty("SplitOwner", &GCBasePlayerController::GetSplitOwner, &GCBasePlayerController::SetSplitOwner)
        .addProperty("IsHLTV", &GCBasePlayerController::GetIsHLTV, &GCBasePlayerController::SetIsHLTV)
        .addProperty("Connected", &GCBasePlayerController::GetConnected, &GCBasePlayerController::SetConnected)
        .addProperty("PlayerName", &GCBasePlayerController::GetPlayerName, &GCBasePlayerController::SetPlayerName)
        .addProperty("NetworkIDString", &GCBasePlayerController::GetNetworkIDString, &GCBasePlayerController::SetNetworkIDString)
        .addProperty("LerpTime", &GCBasePlayerController::GetLerpTime, &GCBasePlayerController::SetLerpTime)
        .addProperty("LagCompensation", &GCBasePlayerController::GetLagCompensation, &GCBasePlayerController::SetLagCompensation)
        .addProperty("Predict", &GCBasePlayerController::GetPredict, &GCBasePlayerController::SetPredict)
        .addProperty("AutoKickDisabled", &GCBasePlayerController::GetAutoKickDisabled, &GCBasePlayerController::SetAutoKickDisabled)
        .addProperty("IsLowViolence", &GCBasePlayerController::GetIsLowViolence, &GCBasePlayerController::SetIsLowViolence)
        .addProperty("GamePaused", &GCBasePlayerController::GetGamePaused, &GCBasePlayerController::SetGamePaused)
        .addProperty("LastRealCommandNumberExecuted", &GCBasePlayerController::GetLastRealCommandNumberExecuted, &GCBasePlayerController::SetLastRealCommandNumberExecuted)
        .addProperty("LastLateCommandExecuted", &GCBasePlayerController::GetLastLateCommandExecuted, &GCBasePlayerController::SetLastLateCommandExecuted)
        .addProperty("IgnoreGlobalChat", &GCBasePlayerController::GetIgnoreGlobalChat, &GCBasePlayerController::SetIgnoreGlobalChat)
        .addProperty("LastPlayerTalkTime", &GCBasePlayerController::GetLastPlayerTalkTime, &GCBasePlayerController::SetLastPlayerTalkTime)
        .addProperty("LastEntitySteadyState", &GCBasePlayerController::GetLastEntitySteadyState, &GCBasePlayerController::SetLastEntitySteadyState)
        .addProperty("AvailableEntitySteadyState", &GCBasePlayerController::GetAvailableEntitySteadyState, &GCBasePlayerController::SetAvailableEntitySteadyState)
        .addProperty("HasAnySteadyStateEnts", &GCBasePlayerController::GetHasAnySteadyStateEnts, &GCBasePlayerController::SetHasAnySteadyStateEnts)
        .addProperty("SteamID", &GCBasePlayerController::GetSteamID, &GCBasePlayerController::SetSteamID)
        .addProperty("DesiredFOV", &GCBasePlayerController::GetDesiredFOV, &GCBasePlayerController::SetDesiredFOV)
        .addProperty("Parent", &GCBasePlayerController::GetParent, &GCBasePlayerController::SetParent)
        .addFunction("ToPtr", &GCBasePlayerController::ToPtr)
        .addFunction("IsValid", &GCBasePlayerController::IsValid)
        .endClass();
}