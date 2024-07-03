#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSWeaponBaseVData::GCCSWeaponBaseVData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSWeaponBaseVData::GCCSWeaponBaseVData(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCCSWeaponBaseVData::GetWeaponType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBaseVData", "m_WeaponType");
}
void GCCSWeaponBaseVData::SetWeaponType(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_WeaponType", false, value);
}
uint64_t GCCSWeaponBaseVData::GetWeaponCategory() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBaseVData", "m_WeaponCategory");
}
void GCCSWeaponBaseVData::SetWeaponCategory(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_WeaponCategory", false, value);
}
uint64_t GCCSWeaponBaseVData::GetGearSlot() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBaseVData", "m_GearSlot");
}
void GCCSWeaponBaseVData::SetGearSlot(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_GearSlot", false, value);
}
int32_t GCCSWeaponBaseVData::GetGearSlotPosition() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_GearSlotPosition");
}
void GCCSWeaponBaseVData::SetGearSlotPosition(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_GearSlotPosition", false, value);
}
uint64_t GCCSWeaponBaseVData::GetDefaultLoadoutSlot() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBaseVData", "m_DefaultLoadoutSlot");
}
void GCCSWeaponBaseVData::SetDefaultLoadoutSlot(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_DefaultLoadoutSlot", false, value);
}
std::string GCCSWeaponBaseVData::GetWrongTeamMsg() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSWeaponBaseVData", "m_sWrongTeamMsg").Get();
}
void GCCSWeaponBaseVData::SetWrongTeamMsg(std::string value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_sWrongTeamMsg", false, CUtlString(value.c_str()));
}
int32_t GCCSWeaponBaseVData::GetPrice() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nPrice");
}
void GCCSWeaponBaseVData::SetPrice(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nPrice", false, value);
}
int32_t GCCSWeaponBaseVData::GetKillAward() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nKillAward");
}
void GCCSWeaponBaseVData::SetKillAward(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nKillAward", false, value);
}
int32_t GCCSWeaponBaseVData::GetPrimaryReserveAmmoMax() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nPrimaryReserveAmmoMax");
}
void GCCSWeaponBaseVData::SetPrimaryReserveAmmoMax(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nPrimaryReserveAmmoMax", false, value);
}
int32_t GCCSWeaponBaseVData::GetSecondaryReserveAmmoMax() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nSecondaryReserveAmmoMax");
}
void GCCSWeaponBaseVData::SetSecondaryReserveAmmoMax(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nSecondaryReserveAmmoMax", false, value);
}
bool GCCSWeaponBaseVData::GetMeleeWeapon() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bMeleeWeapon");
}
void GCCSWeaponBaseVData::SetMeleeWeapon(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bMeleeWeapon", false, value);
}
bool GCCSWeaponBaseVData::GetHasBurstMode() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bHasBurstMode");
}
void GCCSWeaponBaseVData::SetHasBurstMode(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bHasBurstMode", false, value);
}
bool GCCSWeaponBaseVData::GetIsRevolver() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bIsRevolver");
}
void GCCSWeaponBaseVData::SetIsRevolver(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bIsRevolver", false, value);
}
bool GCCSWeaponBaseVData::GetCannotShootUnderwater() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bCannotShootUnderwater");
}
void GCCSWeaponBaseVData::SetCannotShootUnderwater(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bCannotShootUnderwater", false, value);
}
std::string GCCSWeaponBaseVData::GetAnimExtension() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSWeaponBaseVData", "m_szAnimExtension").Get();
}
void GCCSWeaponBaseVData::SetAnimExtension(std::string value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_szAnimExtension", false, CUtlString(value.c_str()));
}
uint64_t GCCSWeaponBaseVData::GetSilencerType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CCSWeaponBaseVData", "m_eSilencerType");
}
void GCCSWeaponBaseVData::SetSilencerType(uint64_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_eSilencerType", false, value);
}
int32_t GCCSWeaponBaseVData::GetCrosshairMinDistance() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairMinDistance");
}
void GCCSWeaponBaseVData::SetCrosshairMinDistance(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairMinDistance", false, value);
}
int32_t GCCSWeaponBaseVData::GetCrosshairDeltaDistance() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairDeltaDistance");
}
void GCCSWeaponBaseVData::SetCrosshairDeltaDistance(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairDeltaDistance", false, value);
}
bool GCCSWeaponBaseVData::GetIsFullAuto() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bIsFullAuto");
}
void GCCSWeaponBaseVData::SetIsFullAuto(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bIsFullAuto", false, value);
}
int32_t GCCSWeaponBaseVData::GetNumBullets() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nNumBullets");
}
void GCCSWeaponBaseVData::SetNumBullets(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nNumBullets", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetCycleTime() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flCycleTime"));
    return value;
}
void GCCSWeaponBaseVData::SetCycleTime(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flCycleTime", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetMaxSpeed() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flMaxSpeed"));
    return value;
}
void GCCSWeaponBaseVData::SetMaxSpeed(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flMaxSpeed", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetSpread() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flSpread"));
    return value;
}
void GCCSWeaponBaseVData::SetSpread(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flSpread", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetInaccuracyCrouch() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyCrouch"));
    return value;
}
void GCCSWeaponBaseVData::SetInaccuracyCrouch(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyCrouch", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetInaccuracyStand() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyStand"));
    return value;
}
void GCCSWeaponBaseVData::SetInaccuracyStand(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyStand", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetInaccuracyJump() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJump"));
    return value;
}
void GCCSWeaponBaseVData::SetInaccuracyJump(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJump", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetInaccuracyLand() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLand"));
    return value;
}
void GCCSWeaponBaseVData::SetInaccuracyLand(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLand", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetInaccuracyLadder() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLadder"));
    return value;
}
void GCCSWeaponBaseVData::SetInaccuracyLadder(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLadder", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetInaccuracyFire() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyFire"));
    return value;
}
void GCCSWeaponBaseVData::SetInaccuracyFire(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyFire", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetInaccuracyMove() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyMove"));
    return value;
}
void GCCSWeaponBaseVData::SetInaccuracyMove(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyMove", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetRecoilAngle() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngle"));
    return value;
}
void GCCSWeaponBaseVData::SetRecoilAngle(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngle", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetRecoilAngleVariance() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngleVariance"));
    return value;
}
void GCCSWeaponBaseVData::SetRecoilAngleVariance(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngleVariance", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetRecoilMagnitude() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitude"));
    return value;
}
void GCCSWeaponBaseVData::SetRecoilMagnitude(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitude", false, value);
}
GCFiringModeFloat GCCSWeaponBaseVData::GetRecoilMagnitudeVariance() const {
    GCFiringModeFloat value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitudeVariance"));
    return value;
}
void GCCSWeaponBaseVData::SetRecoilMagnitudeVariance(GCFiringModeFloat value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitudeVariance", false, value);
}
GCFiringModeInt GCCSWeaponBaseVData::GetTracerFrequency() const {
    GCFiringModeInt value(GetSchemaPtr(m_ptr, "CCSWeaponBaseVData", "m_nTracerFrequency"));
    return value;
}
void GCCSWeaponBaseVData::SetTracerFrequency(GCFiringModeInt value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nTracerFrequency", false, value);
}
float GCCSWeaponBaseVData::GetInaccuracyJumpInitial() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpInitial");
}
void GCCSWeaponBaseVData::SetInaccuracyJumpInitial(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpInitial", false, value);
}
float GCCSWeaponBaseVData::GetInaccuracyJumpApex() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpApex");
}
void GCCSWeaponBaseVData::SetInaccuracyJumpApex(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpApex", false, value);
}
float GCCSWeaponBaseVData::GetInaccuracyReload() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyReload");
}
void GCCSWeaponBaseVData::SetInaccuracyReload(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyReload", false, value);
}
int32_t GCCSWeaponBaseVData::GetRecoilSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nRecoilSeed");
}
void GCCSWeaponBaseVData::SetRecoilSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nRecoilSeed", false, value);
}
int32_t GCCSWeaponBaseVData::GetSpreadSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nSpreadSeed");
}
void GCCSWeaponBaseVData::SetSpreadSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nSpreadSeed", false, value);
}
float GCCSWeaponBaseVData::GetTimeToIdleAfterFire() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flTimeToIdleAfterFire");
}
void GCCSWeaponBaseVData::SetTimeToIdleAfterFire(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flTimeToIdleAfterFire", false, value);
}
float GCCSWeaponBaseVData::GetIdleInterval() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIdleInterval");
}
void GCCSWeaponBaseVData::SetIdleInterval(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIdleInterval", false, value);
}
float GCCSWeaponBaseVData::GetAttackMovespeedFactor() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flAttackMovespeedFactor");
}
void GCCSWeaponBaseVData::SetAttackMovespeedFactor(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flAttackMovespeedFactor", false, value);
}
float GCCSWeaponBaseVData::GetHeatPerShot() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flHeatPerShot");
}
void GCCSWeaponBaseVData::SetHeatPerShot(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flHeatPerShot", false, value);
}
float GCCSWeaponBaseVData::GetInaccuracyPitchShift() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyPitchShift");
}
void GCCSWeaponBaseVData::SetInaccuracyPitchShift(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyPitchShift", false, value);
}
float GCCSWeaponBaseVData::GetInaccuracyAltSoundThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyAltSoundThreshold");
}
void GCCSWeaponBaseVData::SetInaccuracyAltSoundThreshold(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyAltSoundThreshold", false, value);
}
float GCCSWeaponBaseVData::GetBotAudibleRange() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flBotAudibleRange");
}
void GCCSWeaponBaseVData::SetBotAudibleRange(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flBotAudibleRange", false, value);
}
std::string GCCSWeaponBaseVData::GetUseRadioSubtitle() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CCSWeaponBaseVData", "m_szUseRadioSubtitle").Get();
}
void GCCSWeaponBaseVData::SetUseRadioSubtitle(std::string value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_szUseRadioSubtitle", false, CUtlString(value.c_str()));
}
bool GCCSWeaponBaseVData::GetUnzoomsAfterShot() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bUnzoomsAfterShot");
}
void GCCSWeaponBaseVData::SetUnzoomsAfterShot(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bUnzoomsAfterShot", false, value);
}
bool GCCSWeaponBaseVData::GetHideViewModelWhenZoomed() const {
    return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bHideViewModelWhenZoomed");
}
void GCCSWeaponBaseVData::SetHideViewModelWhenZoomed(bool value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bHideViewModelWhenZoomed", false, value);
}
int32_t GCCSWeaponBaseVData::GetZoomLevels() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nZoomLevels");
}
void GCCSWeaponBaseVData::SetZoomLevels(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nZoomLevels", false, value);
}
int32_t GCCSWeaponBaseVData::GetZoomFOV1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV1");
}
void GCCSWeaponBaseVData::SetZoomFOV1(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV1", false, value);
}
int32_t GCCSWeaponBaseVData::GetZoomFOV2() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV2");
}
void GCCSWeaponBaseVData::SetZoomFOV2(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV2", false, value);
}
float GCCSWeaponBaseVData::GetZoomTime0() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime0");
}
void GCCSWeaponBaseVData::SetZoomTime0(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime0", false, value);
}
float GCCSWeaponBaseVData::GetZoomTime1() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime1");
}
void GCCSWeaponBaseVData::SetZoomTime1(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime1", false, value);
}
float GCCSWeaponBaseVData::GetZoomTime2() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime2");
}
void GCCSWeaponBaseVData::SetZoomTime2(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime2", false, value);
}
float GCCSWeaponBaseVData::GetIronSightPullUpSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPullUpSpeed");
}
void GCCSWeaponBaseVData::SetIronSightPullUpSpeed(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPullUpSpeed", false, value);
}
float GCCSWeaponBaseVData::GetIronSightPutDownSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPutDownSpeed");
}
void GCCSWeaponBaseVData::SetIronSightPutDownSpeed(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPutDownSpeed", false, value);
}
float GCCSWeaponBaseVData::GetIronSightFOV() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightFOV");
}
void GCCSWeaponBaseVData::SetIronSightFOV(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightFOV", false, value);
}
float GCCSWeaponBaseVData::GetIronSightPivotForward() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPivotForward");
}
void GCCSWeaponBaseVData::SetIronSightPivotForward(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPivotForward", false, value);
}
float GCCSWeaponBaseVData::GetIronSightLooseness() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightLooseness");
}
void GCCSWeaponBaseVData::SetIronSightLooseness(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightLooseness", false, value);
}
QAngle GCCSWeaponBaseVData::GetPivotAngle() const {
    return GetSchemaValue<QAngle>(m_ptr, "CCSWeaponBaseVData", "m_angPivotAngle");
}
void GCCSWeaponBaseVData::SetPivotAngle(QAngle value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_angPivotAngle", false, value);
}
Vector GCCSWeaponBaseVData::GetIronSightEyePos() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSWeaponBaseVData", "m_vecIronSightEyePos");
}
void GCCSWeaponBaseVData::SetIronSightEyePos(Vector value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_vecIronSightEyePos", false, value);
}
int32_t GCCSWeaponBaseVData::GetDamage() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nDamage");
}
void GCCSWeaponBaseVData::SetDamage(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nDamage", false, value);
}
float GCCSWeaponBaseVData::GetHeadshotMultiplier() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flHeadshotMultiplier");
}
void GCCSWeaponBaseVData::SetHeadshotMultiplier(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flHeadshotMultiplier", false, value);
}
float GCCSWeaponBaseVData::GetArmorRatio() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flArmorRatio");
}
void GCCSWeaponBaseVData::SetArmorRatio(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flArmorRatio", false, value);
}
float GCCSWeaponBaseVData::GetPenetration() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flPenetration");
}
void GCCSWeaponBaseVData::SetPenetration(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flPenetration", false, value);
}
float GCCSWeaponBaseVData::GetRange() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRange");
}
void GCCSWeaponBaseVData::SetRange(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRange", false, value);
}
float GCCSWeaponBaseVData::GetRangeModifier() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRangeModifier");
}
void GCCSWeaponBaseVData::SetRangeModifier(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRangeModifier", false, value);
}
float GCCSWeaponBaseVData::GetFlinchVelocityModifierLarge() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierLarge");
}
void GCCSWeaponBaseVData::SetFlinchVelocityModifierLarge(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierLarge", false, value);
}
float GCCSWeaponBaseVData::GetFlinchVelocityModifierSmall() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierSmall");
}
void GCCSWeaponBaseVData::SetFlinchVelocityModifierSmall(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierSmall", false, value);
}
float GCCSWeaponBaseVData::GetRecoveryTimeCrouch() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouch");
}
void GCCSWeaponBaseVData::SetRecoveryTimeCrouch(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouch", false, value);
}
float GCCSWeaponBaseVData::GetRecoveryTimeStand() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStand");
}
void GCCSWeaponBaseVData::SetRecoveryTimeStand(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStand", false, value);
}
float GCCSWeaponBaseVData::GetRecoveryTimeCrouchFinal() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouchFinal");
}
void GCCSWeaponBaseVData::SetRecoveryTimeCrouchFinal(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouchFinal", false, value);
}
float GCCSWeaponBaseVData::GetRecoveryTimeStandFinal() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStandFinal");
}
void GCCSWeaponBaseVData::SetRecoveryTimeStandFinal(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStandFinal", false, value);
}
int32_t GCCSWeaponBaseVData::GetRecoveryTransitionStartBullet() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionStartBullet");
}
void GCCSWeaponBaseVData::SetRecoveryTransitionStartBullet(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionStartBullet", false, value);
}
int32_t GCCSWeaponBaseVData::GetRecoveryTransitionEndBullet() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionEndBullet");
}
void GCCSWeaponBaseVData::SetRecoveryTransitionEndBullet(int32_t value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionEndBullet", false, value);
}
float GCCSWeaponBaseVData::GetThrowVelocity() const {
    return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flThrowVelocity");
}
void GCCSWeaponBaseVData::SetThrowVelocity(float value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flThrowVelocity", false, value);
}
Vector GCCSWeaponBaseVData::GetSmokeColor() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSWeaponBaseVData", "m_vSmokeColor");
}
void GCCSWeaponBaseVData::SetSmokeColor(Vector value) {
    SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_vSmokeColor", false, value);
}
std::string GCCSWeaponBaseVData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSWeaponBaseVData::IsValid() {
    return (m_ptr != nullptr);
}
GCBasePlayerWeaponVData GCCSWeaponBaseVData::GetParent() const {
    GCBasePlayerWeaponVData value(m_ptr);
    return value;
}
void GCCSWeaponBaseVData::SetParent(GCBasePlayerWeaponVData value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSWeaponBaseVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSWeaponBaseVData>("CCSWeaponBaseVData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WeaponType", &GCCSWeaponBaseVData::GetWeaponType, &GCCSWeaponBaseVData::SetWeaponType)
        .addProperty("WeaponCategory", &GCCSWeaponBaseVData::GetWeaponCategory, &GCCSWeaponBaseVData::SetWeaponCategory)
        .addProperty("GearSlot", &GCCSWeaponBaseVData::GetGearSlot, &GCCSWeaponBaseVData::SetGearSlot)
        .addProperty("GearSlotPosition", &GCCSWeaponBaseVData::GetGearSlotPosition, &GCCSWeaponBaseVData::SetGearSlotPosition)
        .addProperty("DefaultLoadoutSlot", &GCCSWeaponBaseVData::GetDefaultLoadoutSlot, &GCCSWeaponBaseVData::SetDefaultLoadoutSlot)
        .addProperty("WrongTeamMsg", &GCCSWeaponBaseVData::GetWrongTeamMsg, &GCCSWeaponBaseVData::SetWrongTeamMsg)
        .addProperty("Price", &GCCSWeaponBaseVData::GetPrice, &GCCSWeaponBaseVData::SetPrice)
        .addProperty("KillAward", &GCCSWeaponBaseVData::GetKillAward, &GCCSWeaponBaseVData::SetKillAward)
        .addProperty("PrimaryReserveAmmoMax", &GCCSWeaponBaseVData::GetPrimaryReserveAmmoMax, &GCCSWeaponBaseVData::SetPrimaryReserveAmmoMax)
        .addProperty("SecondaryReserveAmmoMax", &GCCSWeaponBaseVData::GetSecondaryReserveAmmoMax, &GCCSWeaponBaseVData::SetSecondaryReserveAmmoMax)
        .addProperty("MeleeWeapon", &GCCSWeaponBaseVData::GetMeleeWeapon, &GCCSWeaponBaseVData::SetMeleeWeapon)
        .addProperty("HasBurstMode", &GCCSWeaponBaseVData::GetHasBurstMode, &GCCSWeaponBaseVData::SetHasBurstMode)
        .addProperty("IsRevolver", &GCCSWeaponBaseVData::GetIsRevolver, &GCCSWeaponBaseVData::SetIsRevolver)
        .addProperty("CannotShootUnderwater", &GCCSWeaponBaseVData::GetCannotShootUnderwater, &GCCSWeaponBaseVData::SetCannotShootUnderwater)
        .addProperty("AnimExtension", &GCCSWeaponBaseVData::GetAnimExtension, &GCCSWeaponBaseVData::SetAnimExtension)
        .addProperty("SilencerType", &GCCSWeaponBaseVData::GetSilencerType, &GCCSWeaponBaseVData::SetSilencerType)
        .addProperty("CrosshairMinDistance", &GCCSWeaponBaseVData::GetCrosshairMinDistance, &GCCSWeaponBaseVData::SetCrosshairMinDistance)
        .addProperty("CrosshairDeltaDistance", &GCCSWeaponBaseVData::GetCrosshairDeltaDistance, &GCCSWeaponBaseVData::SetCrosshairDeltaDistance)
        .addProperty("IsFullAuto", &GCCSWeaponBaseVData::GetIsFullAuto, &GCCSWeaponBaseVData::SetIsFullAuto)
        .addProperty("NumBullets", &GCCSWeaponBaseVData::GetNumBullets, &GCCSWeaponBaseVData::SetNumBullets)
        .addProperty("CycleTime", &GCCSWeaponBaseVData::GetCycleTime, &GCCSWeaponBaseVData::SetCycleTime)
        .addProperty("MaxSpeed", &GCCSWeaponBaseVData::GetMaxSpeed, &GCCSWeaponBaseVData::SetMaxSpeed)
        .addProperty("Spread", &GCCSWeaponBaseVData::GetSpread, &GCCSWeaponBaseVData::SetSpread)
        .addProperty("InaccuracyCrouch", &GCCSWeaponBaseVData::GetInaccuracyCrouch, &GCCSWeaponBaseVData::SetInaccuracyCrouch)
        .addProperty("InaccuracyStand", &GCCSWeaponBaseVData::GetInaccuracyStand, &GCCSWeaponBaseVData::SetInaccuracyStand)
        .addProperty("InaccuracyJump", &GCCSWeaponBaseVData::GetInaccuracyJump, &GCCSWeaponBaseVData::SetInaccuracyJump)
        .addProperty("InaccuracyLand", &GCCSWeaponBaseVData::GetInaccuracyLand, &GCCSWeaponBaseVData::SetInaccuracyLand)
        .addProperty("InaccuracyLadder", &GCCSWeaponBaseVData::GetInaccuracyLadder, &GCCSWeaponBaseVData::SetInaccuracyLadder)
        .addProperty("InaccuracyFire", &GCCSWeaponBaseVData::GetInaccuracyFire, &GCCSWeaponBaseVData::SetInaccuracyFire)
        .addProperty("InaccuracyMove", &GCCSWeaponBaseVData::GetInaccuracyMove, &GCCSWeaponBaseVData::SetInaccuracyMove)
        .addProperty("RecoilAngle", &GCCSWeaponBaseVData::GetRecoilAngle, &GCCSWeaponBaseVData::SetRecoilAngle)
        .addProperty("RecoilAngleVariance", &GCCSWeaponBaseVData::GetRecoilAngleVariance, &GCCSWeaponBaseVData::SetRecoilAngleVariance)
        .addProperty("RecoilMagnitude", &GCCSWeaponBaseVData::GetRecoilMagnitude, &GCCSWeaponBaseVData::SetRecoilMagnitude)
        .addProperty("RecoilMagnitudeVariance", &GCCSWeaponBaseVData::GetRecoilMagnitudeVariance, &GCCSWeaponBaseVData::SetRecoilMagnitudeVariance)
        .addProperty("TracerFrequency", &GCCSWeaponBaseVData::GetTracerFrequency, &GCCSWeaponBaseVData::SetTracerFrequency)
        .addProperty("InaccuracyJumpInitial", &GCCSWeaponBaseVData::GetInaccuracyJumpInitial, &GCCSWeaponBaseVData::SetInaccuracyJumpInitial)
        .addProperty("InaccuracyJumpApex", &GCCSWeaponBaseVData::GetInaccuracyJumpApex, &GCCSWeaponBaseVData::SetInaccuracyJumpApex)
        .addProperty("InaccuracyReload", &GCCSWeaponBaseVData::GetInaccuracyReload, &GCCSWeaponBaseVData::SetInaccuracyReload)
        .addProperty("RecoilSeed", &GCCSWeaponBaseVData::GetRecoilSeed, &GCCSWeaponBaseVData::SetRecoilSeed)
        .addProperty("SpreadSeed", &GCCSWeaponBaseVData::GetSpreadSeed, &GCCSWeaponBaseVData::SetSpreadSeed)
        .addProperty("TimeToIdleAfterFire", &GCCSWeaponBaseVData::GetTimeToIdleAfterFire, &GCCSWeaponBaseVData::SetTimeToIdleAfterFire)
        .addProperty("IdleInterval", &GCCSWeaponBaseVData::GetIdleInterval, &GCCSWeaponBaseVData::SetIdleInterval)
        .addProperty("AttackMovespeedFactor", &GCCSWeaponBaseVData::GetAttackMovespeedFactor, &GCCSWeaponBaseVData::SetAttackMovespeedFactor)
        .addProperty("HeatPerShot", &GCCSWeaponBaseVData::GetHeatPerShot, &GCCSWeaponBaseVData::SetHeatPerShot)
        .addProperty("InaccuracyPitchShift", &GCCSWeaponBaseVData::GetInaccuracyPitchShift, &GCCSWeaponBaseVData::SetInaccuracyPitchShift)
        .addProperty("InaccuracyAltSoundThreshold", &GCCSWeaponBaseVData::GetInaccuracyAltSoundThreshold, &GCCSWeaponBaseVData::SetInaccuracyAltSoundThreshold)
        .addProperty("BotAudibleRange", &GCCSWeaponBaseVData::GetBotAudibleRange, &GCCSWeaponBaseVData::SetBotAudibleRange)
        .addProperty("UseRadioSubtitle", &GCCSWeaponBaseVData::GetUseRadioSubtitle, &GCCSWeaponBaseVData::SetUseRadioSubtitle)
        .addProperty("UnzoomsAfterShot", &GCCSWeaponBaseVData::GetUnzoomsAfterShot, &GCCSWeaponBaseVData::SetUnzoomsAfterShot)
        .addProperty("HideViewModelWhenZoomed", &GCCSWeaponBaseVData::GetHideViewModelWhenZoomed, &GCCSWeaponBaseVData::SetHideViewModelWhenZoomed)
        .addProperty("ZoomLevels", &GCCSWeaponBaseVData::GetZoomLevels, &GCCSWeaponBaseVData::SetZoomLevels)
        .addProperty("ZoomFOV1", &GCCSWeaponBaseVData::GetZoomFOV1, &GCCSWeaponBaseVData::SetZoomFOV1)
        .addProperty("ZoomFOV2", &GCCSWeaponBaseVData::GetZoomFOV2, &GCCSWeaponBaseVData::SetZoomFOV2)
        .addProperty("ZoomTime0", &GCCSWeaponBaseVData::GetZoomTime0, &GCCSWeaponBaseVData::SetZoomTime0)
        .addProperty("ZoomTime1", &GCCSWeaponBaseVData::GetZoomTime1, &GCCSWeaponBaseVData::SetZoomTime1)
        .addProperty("ZoomTime2", &GCCSWeaponBaseVData::GetZoomTime2, &GCCSWeaponBaseVData::SetZoomTime2)
        .addProperty("IronSightPullUpSpeed", &GCCSWeaponBaseVData::GetIronSightPullUpSpeed, &GCCSWeaponBaseVData::SetIronSightPullUpSpeed)
        .addProperty("IronSightPutDownSpeed", &GCCSWeaponBaseVData::GetIronSightPutDownSpeed, &GCCSWeaponBaseVData::SetIronSightPutDownSpeed)
        .addProperty("IronSightFOV", &GCCSWeaponBaseVData::GetIronSightFOV, &GCCSWeaponBaseVData::SetIronSightFOV)
        .addProperty("IronSightPivotForward", &GCCSWeaponBaseVData::GetIronSightPivotForward, &GCCSWeaponBaseVData::SetIronSightPivotForward)
        .addProperty("IronSightLooseness", &GCCSWeaponBaseVData::GetIronSightLooseness, &GCCSWeaponBaseVData::SetIronSightLooseness)
        .addProperty("PivotAngle", &GCCSWeaponBaseVData::GetPivotAngle, &GCCSWeaponBaseVData::SetPivotAngle)
        .addProperty("IronSightEyePos", &GCCSWeaponBaseVData::GetIronSightEyePos, &GCCSWeaponBaseVData::SetIronSightEyePos)
        .addProperty("Damage", &GCCSWeaponBaseVData::GetDamage, &GCCSWeaponBaseVData::SetDamage)
        .addProperty("HeadshotMultiplier", &GCCSWeaponBaseVData::GetHeadshotMultiplier, &GCCSWeaponBaseVData::SetHeadshotMultiplier)
        .addProperty("ArmorRatio", &GCCSWeaponBaseVData::GetArmorRatio, &GCCSWeaponBaseVData::SetArmorRatio)
        .addProperty("Penetration", &GCCSWeaponBaseVData::GetPenetration, &GCCSWeaponBaseVData::SetPenetration)
        .addProperty("Range", &GCCSWeaponBaseVData::GetRange, &GCCSWeaponBaseVData::SetRange)
        .addProperty("RangeModifier", &GCCSWeaponBaseVData::GetRangeModifier, &GCCSWeaponBaseVData::SetRangeModifier)
        .addProperty("FlinchVelocityModifierLarge", &GCCSWeaponBaseVData::GetFlinchVelocityModifierLarge, &GCCSWeaponBaseVData::SetFlinchVelocityModifierLarge)
        .addProperty("FlinchVelocityModifierSmall", &GCCSWeaponBaseVData::GetFlinchVelocityModifierSmall, &GCCSWeaponBaseVData::SetFlinchVelocityModifierSmall)
        .addProperty("RecoveryTimeCrouch", &GCCSWeaponBaseVData::GetRecoveryTimeCrouch, &GCCSWeaponBaseVData::SetRecoveryTimeCrouch)
        .addProperty("RecoveryTimeStand", &GCCSWeaponBaseVData::GetRecoveryTimeStand, &GCCSWeaponBaseVData::SetRecoveryTimeStand)
        .addProperty("RecoveryTimeCrouchFinal", &GCCSWeaponBaseVData::GetRecoveryTimeCrouchFinal, &GCCSWeaponBaseVData::SetRecoveryTimeCrouchFinal)
        .addProperty("RecoveryTimeStandFinal", &GCCSWeaponBaseVData::GetRecoveryTimeStandFinal, &GCCSWeaponBaseVData::SetRecoveryTimeStandFinal)
        .addProperty("RecoveryTransitionStartBullet", &GCCSWeaponBaseVData::GetRecoveryTransitionStartBullet, &GCCSWeaponBaseVData::SetRecoveryTransitionStartBullet)
        .addProperty("RecoveryTransitionEndBullet", &GCCSWeaponBaseVData::GetRecoveryTransitionEndBullet, &GCCSWeaponBaseVData::SetRecoveryTransitionEndBullet)
        .addProperty("ThrowVelocity", &GCCSWeaponBaseVData::GetThrowVelocity, &GCCSWeaponBaseVData::SetThrowVelocity)
        .addProperty("SmokeColor", &GCCSWeaponBaseVData::GetSmokeColor, &GCCSWeaponBaseVData::SetSmokeColor)
        .addProperty("Parent", &GCCSWeaponBaseVData::GetParent, &GCCSWeaponBaseVData::SetParent)
        .addFunction("ToPtr", &GCCSWeaponBaseVData::ToPtr)
        .addFunction("IsValid", &GCCSWeaponBaseVData::IsValid)
        .endClass();
}