#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSWeaponBase::GCCSWeaponBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSWeaponBase::GCCSWeaponBase(void *ptr) {
    m_ptr = ptr;
}
bool GCCSWeaponBase::GetRemoveable() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bRemoveable");
}
void GCCSWeaponBase::SetRemoveable(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bRemoveable", false, value);
}
float GCCSWeaponBase::GetFireSequenceStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flFireSequenceStartTime");
}
void GCCSWeaponBase::SetFireSequenceStartTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flFireSequenceStartTime", false, value);
}
int32_t GCCSWeaponBase::GetFireSequenceStartTimeChange() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeChange");
}
void GCCSWeaponBase::SetFireSequenceStartTimeChange(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeChange", false, value);
}
int32_t GCCSWeaponBase::GetFireSequenceStartTimeAck() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeAck");
}
void GCCSWeaponBase::SetFireSequenceStartTimeAck(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeAck", false, value);
}
uint64_t GCCSWeaponBase::GetPlayerFireEvent() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBase", "m_ePlayerFireEvent");
}
void GCCSWeaponBase::SetPlayerFireEvent(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_ePlayerFireEvent", false, value);
}
uint64_t GCCSWeaponBase::GetPlayerFireEventAttackType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBase", "m_ePlayerFireEventAttackType");
}
void GCCSWeaponBase::SetPlayerFireEventAttackType(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_ePlayerFireEventAttackType", false, value);
}
int32_t GCCSWeaponBase::GetSilencerBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nSilencerBoneIndex");
}
void GCCSWeaponBase::SetSilencerBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nSilencerBoneIndex", false, value);
}
bool GCCSWeaponBase::GetPlayerAmmoStockOnPickup() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bPlayerAmmoStockOnPickup");
}
void GCCSWeaponBase::SetPlayerAmmoStockOnPickup(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bPlayerAmmoStockOnPickup", false, value);
}
bool GCCSWeaponBase::GetRequireUseToTouch() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bRequireUseToTouch");
}
void GCCSWeaponBase::SetRequireUseToTouch(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bRequireUseToTouch", false, value);
}
uint64_t GCCSWeaponBase::GetState() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBase", "m_iState");
}
void GCCSWeaponBase::SetState(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iState", false, value);
}
float GCCSWeaponBase::GetLastTimeInAir() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flLastTimeInAir");
}
void GCCSWeaponBase::SetLastTimeInAir(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flLastTimeInAir", false, value);
}
float GCCSWeaponBase::GetLastDeployTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flLastDeployTime");
}
void GCCSWeaponBase::SetLastDeployTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flLastDeployTime", false, value);
}
int32_t GCCSWeaponBase::GetLastEmptySoundCmdNum() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nLastEmptySoundCmdNum");
}
void GCCSWeaponBase::SetLastEmptySoundCmdNum(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nLastEmptySoundCmdNum", false, value);
}
uint32_t GCCSWeaponBase::GetViewModelIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CCSWeaponBase", "m_nViewModelIndex");
}
void GCCSWeaponBase::SetViewModelIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nViewModelIndex", false, value);
}
bool GCCSWeaponBase::GetReloadsWithClips() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bReloadsWithClips");
}
void GCCSWeaponBase::SetReloadsWithClips(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bReloadsWithClips", false, value);
}
float GCCSWeaponBase::GetTimeWeaponIdle() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flTimeWeaponIdle");
}
void GCCSWeaponBase::SetTimeWeaponIdle(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flTimeWeaponIdle", false, value);
}
bool GCCSWeaponBase::GetFireOnEmpty() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bFireOnEmpty");
}
void GCCSWeaponBase::SetFireOnEmpty(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bFireOnEmpty", false, value);
}
GCEntityIOOutput GCCSWeaponBase::GetOnPlayerPickup() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CCSWeaponBase", "m_OnPlayerPickup"));
    return value;
}
void GCCSWeaponBase::SetOnPlayerPickup(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_OnPlayerPickup", false, value);
}
uint64_t GCCSWeaponBase::GetWeaponMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBase", "m_weaponMode");
}
void GCCSWeaponBase::SetWeaponMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_weaponMode", false, value);
}
float GCCSWeaponBase::GetTurningInaccuracyDelta() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracyDelta");
}
void GCCSWeaponBase::SetTurningInaccuracyDelta(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracyDelta", false, value);
}
Vector GCCSWeaponBase::GetTurningInaccuracyEyeDirLast() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSWeaponBase", "m_vecTurningInaccuracyEyeDirLast");
}
void GCCSWeaponBase::SetTurningInaccuracyEyeDirLast(Vector value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_vecTurningInaccuracyEyeDirLast", false, value);
}
float GCCSWeaponBase::GetTurningInaccuracy() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracy");
}
void GCCSWeaponBase::SetTurningInaccuracy(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracy", false, value);
}
float GCCSWeaponBase::GetAccuracyPenalty() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_fAccuracyPenalty");
}
void GCCSWeaponBase::SetAccuracyPenalty(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_fAccuracyPenalty", false, value);
}
float GCCSWeaponBase::GetLastAccuracyUpdateTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flLastAccuracyUpdateTime");
}
void GCCSWeaponBase::SetLastAccuracyUpdateTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flLastAccuracyUpdateTime", false, value);
}
float GCCSWeaponBase::GetAccuracySmoothedForZoom() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_fAccuracySmoothedForZoom");
}
void GCCSWeaponBase::SetAccuracySmoothedForZoom(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_fAccuracySmoothedForZoom", false, value);
}
float GCCSWeaponBase::GetScopeZoomEndTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_fScopeZoomEndTime");
}
void GCCSWeaponBase::SetScopeZoomEndTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_fScopeZoomEndTime", false, value);
}
int32_t GCCSWeaponBase::GetRecoilIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iRecoilIndex");
}
void GCCSWeaponBase::SetRecoilIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iRecoilIndex", false, value);
}
float GCCSWeaponBase::GetRecoilIndex1() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flRecoilIndex");
}
void GCCSWeaponBase::SetRecoilIndex1(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flRecoilIndex", false, value);
}
bool GCCSWeaponBase::GetBurstMode() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bBurstMode");
}
void GCCSWeaponBase::SetBurstMode(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bBurstMode", false, value);
}
int32 GCCSWeaponBase::GetPostponeFireReadyTicks() const {
    return GetSchemaValue<int32>(m_ptr, "CCSWeaponBase", "m_nPostponeFireReadyTicks");
}
void GCCSWeaponBase::SetPostponeFireReadyTicks(int32 value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nPostponeFireReadyTicks", false, value);
}
float GCCSWeaponBase::GetPostponeFireReadyFrac() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flPostponeFireReadyFrac");
}
void GCCSWeaponBase::SetPostponeFireReadyFrac(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flPostponeFireReadyFrac", false, value);
}
bool GCCSWeaponBase::GetInReload() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bInReload");
}
void GCCSWeaponBase::SetInReload(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bInReload", false, value);
}
bool GCCSWeaponBase::GetReloadVisuallyComplete() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bReloadVisuallyComplete");
}
void GCCSWeaponBase::SetReloadVisuallyComplete(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bReloadVisuallyComplete", false, value);
}
float GCCSWeaponBase::GetDroppedAtTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flDroppedAtTime");
}
void GCCSWeaponBase::SetDroppedAtTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flDroppedAtTime", false, value);
}
bool GCCSWeaponBase::GetIsHauledBack() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bIsHauledBack");
}
void GCCSWeaponBase::SetIsHauledBack(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bIsHauledBack", false, value);
}
bool GCCSWeaponBase::GetSilencerOn() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bSilencerOn");
}
void GCCSWeaponBase::SetSilencerOn(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bSilencerOn", false, value);
}
float GCCSWeaponBase::GetTimeSilencerSwitchComplete() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flTimeSilencerSwitchComplete");
}
void GCCSWeaponBase::SetTimeSilencerSwitchComplete(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flTimeSilencerSwitchComplete", false, value);
}
int32_t GCCSWeaponBase::GetOriginalTeamNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iOriginalTeamNumber");
}
void GCCSWeaponBase::SetOriginalTeamNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iOriginalTeamNumber", false, value);
}
int32_t GCCSWeaponBase::GetMostRecentTeamNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iMostRecentTeamNumber");
}
void GCCSWeaponBase::SetMostRecentTeamNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iMostRecentTeamNumber", false, value);
}
bool GCCSWeaponBase::GetDroppedNearBuyZone() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bDroppedNearBuyZone");
}
void GCCSWeaponBase::SetDroppedNearBuyZone(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bDroppedNearBuyZone", false, value);
}
float GCCSWeaponBase::GetNextAttackRenderTimeOffset() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flNextAttackRenderTimeOffset");
}
void GCCSWeaponBase::SetNextAttackRenderTimeOffset(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flNextAttackRenderTimeOffset", false, value);
}
bool GCCSWeaponBase::GetCanBePickedUp() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bCanBePickedUp");
}
void GCCSWeaponBase::SetCanBePickedUp(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bCanBePickedUp", false, value);
}
bool GCCSWeaponBase::GetUseCanOverrideNextOwnerTouchTime() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bUseCanOverrideNextOwnerTouchTime");
}
void GCCSWeaponBase::SetUseCanOverrideNextOwnerTouchTime(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bUseCanOverrideNextOwnerTouchTime", false, value);
}
float GCCSWeaponBase::GetNextOwnerTouchTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_nextOwnerTouchTime");
}
void GCCSWeaponBase::SetNextOwnerTouchTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nextOwnerTouchTime", false, value);
}
float GCCSWeaponBase::GetNextPrevOwnerTouchTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_nextPrevOwnerTouchTime");
}
void GCCSWeaponBase::SetNextPrevOwnerTouchTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nextPrevOwnerTouchTime", false, value);
}
GCCSPlayerPawn GCCSWeaponBase::GetPrevOwner() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CCSWeaponBase", "m_hPrevOwner"));
    return value;
}
void GCCSWeaponBase::SetPrevOwner(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PrevOwner' is not possible.\n");
}
int32 GCCSWeaponBase::GetDropTick() const {
    return GetSchemaValue<int32>(m_ptr, "CCSWeaponBase", "m_nDropTick");
}
void GCCSWeaponBase::SetDropTick(int32 value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nDropTick", false, value);
}
bool GCCSWeaponBase::GetDonated() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_donated");
}
void GCCSWeaponBase::SetDonated(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_donated", false, value);
}
float GCCSWeaponBase::GetLastShotTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_fLastShotTime");
}
void GCCSWeaponBase::SetLastShotTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_fLastShotTime", false, value);
}
bool GCCSWeaponBase::GetWasOwnedByCT() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bWasOwnedByCT");
}
void GCCSWeaponBase::SetWasOwnedByCT(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bWasOwnedByCT", false, value);
}
bool GCCSWeaponBase::GetWasOwnedByTerrorist() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bWasOwnedByTerrorist");
}
void GCCSWeaponBase::SetWasOwnedByTerrorist(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bWasOwnedByTerrorist", false, value);
}
bool GCCSWeaponBase::GetFiredOutOfAmmoEvent() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bFiredOutOfAmmoEvent");
}
void GCCSWeaponBase::SetFiredOutOfAmmoEvent(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bFiredOutOfAmmoEvent", false, value);
}
int32_t GCCSWeaponBase::GetNumRemoveUnownedWeaponThink() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_numRemoveUnownedWeaponThink");
}
void GCCSWeaponBase::SetNumRemoveUnownedWeaponThink(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_numRemoveUnownedWeaponThink", false, value);
}
GCIronSightController GCCSWeaponBase::GetIronSightController() const {
    GCIronSightController value(GetSchemaPtr(m_ptr, "CCSWeaponBase", "m_IronSightController"));
    return value;
}
void GCCSWeaponBase::SetIronSightController(GCIronSightController value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_IronSightController", false, value);
}
int32_t GCCSWeaponBase::GetIronSightMode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iIronSightMode");
}
void GCCSWeaponBase::SetIronSightMode(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iIronSightMode", false, value);
}
float GCCSWeaponBase::GetLastLOSTraceFailureTime() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flLastLOSTraceFailureTime");
}
void GCCSWeaponBase::SetLastLOSTraceFailureTime(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flLastLOSTraceFailureTime", false, value);
}
int32_t GCCSWeaponBase::GetNumEmptyAttacks() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iNumEmptyAttacks");
}
void GCCSWeaponBase::SetNumEmptyAttacks(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iNumEmptyAttacks", false, value);
}
float GCCSWeaponBase::GetWatTickOffset() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flWatTickOffset");
}
void GCCSWeaponBase::SetWatTickOffset(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flWatTickOffset", false, value);
}
std::string GCCSWeaponBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSWeaponBase::IsValid() {
    return (m_ptr != nullptr);
}
GCBasePlayerWeapon GCCSWeaponBase::GetParent() const {
    GCBasePlayerWeapon value(m_ptr);
    return value;
}
void GCCSWeaponBase::SetParent(GCBasePlayerWeapon value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSWeaponBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSWeaponBase>("CCSWeaponBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Removeable", &GCCSWeaponBase::GetRemoveable, &GCCSWeaponBase::SetRemoveable)
        .addProperty("FireSequenceStartTime", &GCCSWeaponBase::GetFireSequenceStartTime, &GCCSWeaponBase::SetFireSequenceStartTime)
        .addProperty("FireSequenceStartTimeChange", &GCCSWeaponBase::GetFireSequenceStartTimeChange, &GCCSWeaponBase::SetFireSequenceStartTimeChange)
        .addProperty("FireSequenceStartTimeAck", &GCCSWeaponBase::GetFireSequenceStartTimeAck, &GCCSWeaponBase::SetFireSequenceStartTimeAck)
        .addProperty("PlayerFireEvent", &GCCSWeaponBase::GetPlayerFireEvent, &GCCSWeaponBase::SetPlayerFireEvent)
        .addProperty("PlayerFireEventAttackType", &GCCSWeaponBase::GetPlayerFireEventAttackType, &GCCSWeaponBase::SetPlayerFireEventAttackType)
        .addProperty("SilencerBoneIndex", &GCCSWeaponBase::GetSilencerBoneIndex, &GCCSWeaponBase::SetSilencerBoneIndex)
        .addProperty("PlayerAmmoStockOnPickup", &GCCSWeaponBase::GetPlayerAmmoStockOnPickup, &GCCSWeaponBase::SetPlayerAmmoStockOnPickup)
        .addProperty("RequireUseToTouch", &GCCSWeaponBase::GetRequireUseToTouch, &GCCSWeaponBase::SetRequireUseToTouch)
        .addProperty("State", &GCCSWeaponBase::GetState, &GCCSWeaponBase::SetState)
        .addProperty("LastTimeInAir", &GCCSWeaponBase::GetLastTimeInAir, &GCCSWeaponBase::SetLastTimeInAir)
        .addProperty("LastDeployTime", &GCCSWeaponBase::GetLastDeployTime, &GCCSWeaponBase::SetLastDeployTime)
        .addProperty("LastEmptySoundCmdNum", &GCCSWeaponBase::GetLastEmptySoundCmdNum, &GCCSWeaponBase::SetLastEmptySoundCmdNum)
        .addProperty("ViewModelIndex", &GCCSWeaponBase::GetViewModelIndex, &GCCSWeaponBase::SetViewModelIndex)
        .addProperty("ReloadsWithClips", &GCCSWeaponBase::GetReloadsWithClips, &GCCSWeaponBase::SetReloadsWithClips)
        .addProperty("TimeWeaponIdle", &GCCSWeaponBase::GetTimeWeaponIdle, &GCCSWeaponBase::SetTimeWeaponIdle)
        .addProperty("FireOnEmpty", &GCCSWeaponBase::GetFireOnEmpty, &GCCSWeaponBase::SetFireOnEmpty)
        .addProperty("OnPlayerPickup", &GCCSWeaponBase::GetOnPlayerPickup, &GCCSWeaponBase::SetOnPlayerPickup)
        .addProperty("WeaponMode", &GCCSWeaponBase::GetWeaponMode, &GCCSWeaponBase::SetWeaponMode)
        .addProperty("TurningInaccuracyDelta", &GCCSWeaponBase::GetTurningInaccuracyDelta, &GCCSWeaponBase::SetTurningInaccuracyDelta)
        .addProperty("TurningInaccuracyEyeDirLast", &GCCSWeaponBase::GetTurningInaccuracyEyeDirLast, &GCCSWeaponBase::SetTurningInaccuracyEyeDirLast)
        .addProperty("TurningInaccuracy", &GCCSWeaponBase::GetTurningInaccuracy, &GCCSWeaponBase::SetTurningInaccuracy)
        .addProperty("AccuracyPenalty", &GCCSWeaponBase::GetAccuracyPenalty, &GCCSWeaponBase::SetAccuracyPenalty)
        .addProperty("LastAccuracyUpdateTime", &GCCSWeaponBase::GetLastAccuracyUpdateTime, &GCCSWeaponBase::SetLastAccuracyUpdateTime)
        .addProperty("AccuracySmoothedForZoom", &GCCSWeaponBase::GetAccuracySmoothedForZoom, &GCCSWeaponBase::SetAccuracySmoothedForZoom)
        .addProperty("ScopeZoomEndTime", &GCCSWeaponBase::GetScopeZoomEndTime, &GCCSWeaponBase::SetScopeZoomEndTime)
        .addProperty("RecoilIndex", &GCCSWeaponBase::GetRecoilIndex, &GCCSWeaponBase::SetRecoilIndex)
        .addProperty("RecoilIndex1", &GCCSWeaponBase::GetRecoilIndex1, &GCCSWeaponBase::SetRecoilIndex1)
        .addProperty("BurstMode", &GCCSWeaponBase::GetBurstMode, &GCCSWeaponBase::SetBurstMode)
        .addProperty("PostponeFireReadyTicks", &GCCSWeaponBase::GetPostponeFireReadyTicks, &GCCSWeaponBase::SetPostponeFireReadyTicks)
        .addProperty("PostponeFireReadyFrac", &GCCSWeaponBase::GetPostponeFireReadyFrac, &GCCSWeaponBase::SetPostponeFireReadyFrac)
        .addProperty("InReload", &GCCSWeaponBase::GetInReload, &GCCSWeaponBase::SetInReload)
        .addProperty("ReloadVisuallyComplete", &GCCSWeaponBase::GetReloadVisuallyComplete, &GCCSWeaponBase::SetReloadVisuallyComplete)
        .addProperty("DroppedAtTime", &GCCSWeaponBase::GetDroppedAtTime, &GCCSWeaponBase::SetDroppedAtTime)
        .addProperty("IsHauledBack", &GCCSWeaponBase::GetIsHauledBack, &GCCSWeaponBase::SetIsHauledBack)
        .addProperty("SilencerOn", &GCCSWeaponBase::GetSilencerOn, &GCCSWeaponBase::SetSilencerOn)
        .addProperty("TimeSilencerSwitchComplete", &GCCSWeaponBase::GetTimeSilencerSwitchComplete, &GCCSWeaponBase::SetTimeSilencerSwitchComplete)
        .addProperty("OriginalTeamNumber", &GCCSWeaponBase::GetOriginalTeamNumber, &GCCSWeaponBase::SetOriginalTeamNumber)
        .addProperty("MostRecentTeamNumber", &GCCSWeaponBase::GetMostRecentTeamNumber, &GCCSWeaponBase::SetMostRecentTeamNumber)
        .addProperty("DroppedNearBuyZone", &GCCSWeaponBase::GetDroppedNearBuyZone, &GCCSWeaponBase::SetDroppedNearBuyZone)
        .addProperty("NextAttackRenderTimeOffset", &GCCSWeaponBase::GetNextAttackRenderTimeOffset, &GCCSWeaponBase::SetNextAttackRenderTimeOffset)
        .addProperty("CanBePickedUp", &GCCSWeaponBase::GetCanBePickedUp, &GCCSWeaponBase::SetCanBePickedUp)
        .addProperty("UseCanOverrideNextOwnerTouchTime", &GCCSWeaponBase::GetUseCanOverrideNextOwnerTouchTime, &GCCSWeaponBase::SetUseCanOverrideNextOwnerTouchTime)
        .addProperty("NextOwnerTouchTime", &GCCSWeaponBase::GetNextOwnerTouchTime, &GCCSWeaponBase::SetNextOwnerTouchTime)
        .addProperty("NextPrevOwnerTouchTime", &GCCSWeaponBase::GetNextPrevOwnerTouchTime, &GCCSWeaponBase::SetNextPrevOwnerTouchTime)
        .addProperty("PrevOwner", &GCCSWeaponBase::GetPrevOwner, &GCCSWeaponBase::SetPrevOwner)
        .addProperty("DropTick", &GCCSWeaponBase::GetDropTick, &GCCSWeaponBase::SetDropTick)
        .addProperty("Donated", &GCCSWeaponBase::GetDonated, &GCCSWeaponBase::SetDonated)
        .addProperty("LastShotTime", &GCCSWeaponBase::GetLastShotTime, &GCCSWeaponBase::SetLastShotTime)
        .addProperty("WasOwnedByCT", &GCCSWeaponBase::GetWasOwnedByCT, &GCCSWeaponBase::SetWasOwnedByCT)
        .addProperty("WasOwnedByTerrorist", &GCCSWeaponBase::GetWasOwnedByTerrorist, &GCCSWeaponBase::SetWasOwnedByTerrorist)
        .addProperty("FiredOutOfAmmoEvent", &GCCSWeaponBase::GetFiredOutOfAmmoEvent, &GCCSWeaponBase::SetFiredOutOfAmmoEvent)
        .addProperty("NumRemoveUnownedWeaponThink", &GCCSWeaponBase::GetNumRemoveUnownedWeaponThink, &GCCSWeaponBase::SetNumRemoveUnownedWeaponThink)
        .addProperty("IronSightController", &GCCSWeaponBase::GetIronSightController, &GCCSWeaponBase::SetIronSightController)
        .addProperty("IronSightMode", &GCCSWeaponBase::GetIronSightMode, &GCCSWeaponBase::SetIronSightMode)
        .addProperty("LastLOSTraceFailureTime", &GCCSWeaponBase::GetLastLOSTraceFailureTime, &GCCSWeaponBase::SetLastLOSTraceFailureTime)
        .addProperty("NumEmptyAttacks", &GCCSWeaponBase::GetNumEmptyAttacks, &GCCSWeaponBase::SetNumEmptyAttacks)
        .addProperty("WatTickOffset", &GCCSWeaponBase::GetWatTickOffset, &GCCSWeaponBase::SetWatTickOffset)
        .addProperty("Parent", &GCCSWeaponBase::GetParent, &GCCSWeaponBase::SetParent)
        .addFunction("ToPtr", &GCCSWeaponBase::ToPtr)
        .addFunction("IsValid", &GCCSWeaponBase::IsValid)
        .endClass();
}