#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerPawnBase::GCCSPlayerPawnBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerPawnBase::GCCSPlayerPawnBase(void *ptr) {
    m_ptr = ptr;
}
GCTouchExpansionComponent GCCSPlayerPawnBase::GetCTouchExpansionComponent() const {
    GCTouchExpansionComponent value(GetSchemaPtr(m_ptr, "CCSPlayerPawnBase", "m_CTouchExpansionComponent"));
    return value;
}
void GCCSPlayerPawnBase::SetCTouchExpansionComponent(GCTouchExpansionComponent value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_CTouchExpansionComponent", false, value);
}
GCCSPlayer_PingServices GCCSPlayerPawnBase::GetPingServices() const {
    GCCSPlayer_PingServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawnBase", "m_pPingServices"));
    return value;
}
void GCCSPlayerPawnBase::SetPingServices(GCCSPlayer_PingServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PingServices' is not possible.\n");
}
GCPlayer_ViewModelServices GCCSPlayerPawnBase::GetViewModelServices() const {
    GCPlayer_ViewModelServices value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawnBase", "m_pViewModelServices"));
    return value;
}
void GCCSPlayerPawnBase::SetViewModelServices(GCPlayer_ViewModelServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ViewModelServices' is not possible.\n");
}
float GCCSPlayerPawnBase::GetBlindUntilTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_blindUntilTime");
}
void GCCSPlayerPawnBase::SetBlindUntilTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_blindUntilTime", false, value);
}
float GCCSPlayerPawnBase::GetBlindStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_blindStartTime");
}
void GCCSPlayerPawnBase::SetBlindStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_blindStartTime", false, value);
}
uint64_t GCCSPlayerPawnBase::GetPlayerState() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSPlayerPawnBase", "m_iPlayerState");
}
void GCCSPlayerPawnBase::SetPlayerState(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_iPlayerState", false, value);
}
bool GCCSPlayerPawnBase::GetRespawning() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bRespawning");
}
void GCCSPlayerPawnBase::SetRespawning(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bRespawning", false, value);
}
float GCCSPlayerPawnBase::GetImmuneToGunGameDamageTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_fImmuneToGunGameDamageTime");
}
void GCCSPlayerPawnBase::SetImmuneToGunGameDamageTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_fImmuneToGunGameDamageTime", false, value);
}
bool GCCSPlayerPawnBase::GetGunGameImmunity() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bGunGameImmunity");
}
void GCCSPlayerPawnBase::SetGunGameImmunity(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bGunGameImmunity", false, value);
}
float GCCSPlayerPawnBase::GetMolotovDamageTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_fMolotovDamageTime");
}
void GCCSPlayerPawnBase::SetMolotovDamageTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_fMolotovDamageTime", false, value);
}
bool GCCSPlayerPawnBase::GetHasMovedSinceSpawn() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bHasMovedSinceSpawn");
}
void GCCSPlayerPawnBase::SetHasMovedSinceSpawn(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bHasMovedSinceSpawn", false, value);
}
int32_t GCCSPlayerPawnBase::GetNumSpawns() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawnBase", "m_iNumSpawns");
}
void GCCSPlayerPawnBase::SetNumSpawns(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_iNumSpawns", false, value);
}
float GCCSPlayerPawnBase::GetIdleTimeSinceLastAction() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flIdleTimeSinceLastAction");
}
void GCCSPlayerPawnBase::SetIdleTimeSinceLastAction(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flIdleTimeSinceLastAction", false, value);
}
float GCCSPlayerPawnBase::GetNextRadarUpdateTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_fNextRadarUpdateTime");
}
void GCCSPlayerPawnBase::SetNextRadarUpdateTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_fNextRadarUpdateTime", false, value);
}
float GCCSPlayerPawnBase::GetFlashDuration() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flFlashDuration");
}
void GCCSPlayerPawnBase::SetFlashDuration(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flFlashDuration", false, value);
}
float GCCSPlayerPawnBase::GetFlashMaxAlpha() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flFlashMaxAlpha");
}
void GCCSPlayerPawnBase::SetFlashMaxAlpha(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flFlashMaxAlpha", false, value);
}
float GCCSPlayerPawnBase::GetProgressBarStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSPlayerPawnBase", "m_flProgressBarStartTime");
}
void GCCSPlayerPawnBase::SetProgressBarStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_flProgressBarStartTime", false, value);
}
int32_t GCCSPlayerPawnBase::GetProgressBarDuration() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawnBase", "m_iProgressBarDuration");
}
void GCCSPlayerPawnBase::SetProgressBarDuration(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_iProgressBarDuration", false, value);
}
QAngle GCCSPlayerPawnBase::GetEyeAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSPlayerPawnBase", "m_angEyeAngles");
}
void GCCSPlayerPawnBase::SetEyeAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_angEyeAngles", false, value);
}
int32_t GCCSPlayerPawnBase::GetNumEnemiesAtRoundStart() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSPlayerPawnBase", "m_NumEnemiesAtRoundStart");
}
void GCCSPlayerPawnBase::SetNumEnemiesAtRoundStart(int32_t value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_NumEnemiesAtRoundStart", false, value);
}
bool GCCSPlayerPawnBase::GetWasNotKilledNaturally() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_wasNotKilledNaturally");
}
void GCCSPlayerPawnBase::SetWasNotKilledNaturally(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_wasNotKilledNaturally", false, value);
}
bool GCCSPlayerPawnBase::GetCommittingSuicideOnTeamChange() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerPawnBase", "m_bCommittingSuicideOnTeamChange");
}
void GCCSPlayerPawnBase::SetCommittingSuicideOnTeamChange(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerPawnBase", "m_bCommittingSuicideOnTeamChange", false, value);
}
GCCSPlayerController GCCSPlayerPawnBase::GetOriginalController() const {
    GCCSPlayerController value(*GetSchemaValuePtr<void*>(m_ptr, "CCSPlayerPawnBase", "m_hOriginalController"));
    return value;
}
void GCCSPlayerPawnBase::SetOriginalController(GCCSPlayerController* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'OriginalController' is not possible.\n");
}
std::string GCCSPlayerPawnBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerPawnBase::IsValid() {
    return (m_ptr != nullptr);
}
GCBasePlayerPawn GCCSPlayerPawnBase::GetParent() const {
    GCBasePlayerPawn value(m_ptr);
    return value;
}
void GCCSPlayerPawnBase::SetParent(GCBasePlayerPawn value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerPawnBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerPawnBase>("CCSPlayerPawnBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CTouchExpansionComponent", &GCCSPlayerPawnBase::GetCTouchExpansionComponent, &GCCSPlayerPawnBase::SetCTouchExpansionComponent)
        .addProperty("PingServices", &GCCSPlayerPawnBase::GetPingServices, &GCCSPlayerPawnBase::SetPingServices)
        .addProperty("ViewModelServices", &GCCSPlayerPawnBase::GetViewModelServices, &GCCSPlayerPawnBase::SetViewModelServices)
        .addProperty("BlindUntilTime", &GCCSPlayerPawnBase::GetBlindUntilTime, &GCCSPlayerPawnBase::SetBlindUntilTime)
        .addProperty("BlindStartTime", &GCCSPlayerPawnBase::GetBlindStartTime, &GCCSPlayerPawnBase::SetBlindStartTime)
        .addProperty("PlayerState", &GCCSPlayerPawnBase::GetPlayerState, &GCCSPlayerPawnBase::SetPlayerState)
        .addProperty("Respawning", &GCCSPlayerPawnBase::GetRespawning, &GCCSPlayerPawnBase::SetRespawning)
        .addProperty("ImmuneToGunGameDamageTime", &GCCSPlayerPawnBase::GetImmuneToGunGameDamageTime, &GCCSPlayerPawnBase::SetImmuneToGunGameDamageTime)
        .addProperty("GunGameImmunity", &GCCSPlayerPawnBase::GetGunGameImmunity, &GCCSPlayerPawnBase::SetGunGameImmunity)
        .addProperty("MolotovDamageTime", &GCCSPlayerPawnBase::GetMolotovDamageTime, &GCCSPlayerPawnBase::SetMolotovDamageTime)
        .addProperty("HasMovedSinceSpawn", &GCCSPlayerPawnBase::GetHasMovedSinceSpawn, &GCCSPlayerPawnBase::SetHasMovedSinceSpawn)
        .addProperty("NumSpawns", &GCCSPlayerPawnBase::GetNumSpawns, &GCCSPlayerPawnBase::SetNumSpawns)
        .addProperty("IdleTimeSinceLastAction", &GCCSPlayerPawnBase::GetIdleTimeSinceLastAction, &GCCSPlayerPawnBase::SetIdleTimeSinceLastAction)
        .addProperty("NextRadarUpdateTime", &GCCSPlayerPawnBase::GetNextRadarUpdateTime, &GCCSPlayerPawnBase::SetNextRadarUpdateTime)
        .addProperty("FlashDuration", &GCCSPlayerPawnBase::GetFlashDuration, &GCCSPlayerPawnBase::SetFlashDuration)
        .addProperty("FlashMaxAlpha", &GCCSPlayerPawnBase::GetFlashMaxAlpha, &GCCSPlayerPawnBase::SetFlashMaxAlpha)
        .addProperty("ProgressBarStartTime", &GCCSPlayerPawnBase::GetProgressBarStartTime, &GCCSPlayerPawnBase::SetProgressBarStartTime)
        .addProperty("ProgressBarDuration", &GCCSPlayerPawnBase::GetProgressBarDuration, &GCCSPlayerPawnBase::SetProgressBarDuration)
        .addProperty("EyeAngles", &GCCSPlayerPawnBase::GetEyeAngles, &GCCSPlayerPawnBase::SetEyeAngles)
        .addProperty("NumEnemiesAtRoundStart", &GCCSPlayerPawnBase::GetNumEnemiesAtRoundStart, &GCCSPlayerPawnBase::SetNumEnemiesAtRoundStart)
        .addProperty("WasNotKilledNaturally", &GCCSPlayerPawnBase::GetWasNotKilledNaturally, &GCCSPlayerPawnBase::SetWasNotKilledNaturally)
        .addProperty("CommittingSuicideOnTeamChange", &GCCSPlayerPawnBase::GetCommittingSuicideOnTeamChange, &GCCSPlayerPawnBase::SetCommittingSuicideOnTeamChange)
        .addProperty("OriginalController", &GCCSPlayerPawnBase::GetOriginalController, &GCCSPlayerPawnBase::SetOriginalController)
        .addProperty("Parent", &GCCSPlayerPawnBase::GetParent, &GCCSPlayerPawnBase::SetParent)
        .addFunction("ToPtr", &GCCSPlayerPawnBase::ToPtr)
        .addFunction("IsValid", &GCCSPlayerPawnBase::IsValid)
        .endClass();
}