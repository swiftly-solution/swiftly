class GCCSWeaponBaseVData;

#ifndef _gcccsweaponbasevdata_h
#define _gcccsweaponbasevdata_h

#include "../../../scripting.h"

#include "../types/GCSWeaponType.h"
#include "../types/GCSWeaponCategory.h"
#include "../types/Ggear_slot_t.h"
#include "../types/Gloadout_slot_t.h"
#include "../types/GCSWeaponSilencerType.h"
#include "GCFiringModeFloat.h"
#include "GCFiringModeInt.h"

class GCCSWeaponBaseVData
{
private:
    void *m_ptr;

public:
    GCCSWeaponBaseVData() {}
    GCCSWeaponBaseVData(void *ptr) : m_ptr(ptr) {}

    CSWeaponType GetWeaponType() const { return GetSchemaValue<CSWeaponType>(m_ptr, "CCSWeaponBaseVData", "m_WeaponType"); }
    void SetWeaponType(CSWeaponType value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_WeaponType", false, value); }
    CSWeaponCategory GetWeaponCategory() const { return GetSchemaValue<CSWeaponCategory>(m_ptr, "CCSWeaponBaseVData", "m_WeaponCategory"); }
    void SetWeaponCategory(CSWeaponCategory value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_WeaponCategory", false, value); }
    gear_slot_t GetGearSlot() const { return GetSchemaValue<gear_slot_t>(m_ptr, "CCSWeaponBaseVData", "m_GearSlot"); }
    void SetGearSlot(gear_slot_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_GearSlot", false, value); }
    int32_t GetGearSlotPosition() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_GearSlotPosition"); }
    void SetGearSlotPosition(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_GearSlotPosition", false, value); }
    loadout_slot_t GetDefaultLoadoutSlot() const { return GetSchemaValue<loadout_slot_t>(m_ptr, "CCSWeaponBaseVData", "m_DefaultLoadoutSlot"); }
    void SetDefaultLoadoutSlot(loadout_slot_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_DefaultLoadoutSlot", false, value); }
    CUtlString GetWrongTeamMsg() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSWeaponBaseVData", "m_sWrongTeamMsg"); }
    void SetWrongTeamMsg(CUtlString value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_sWrongTeamMsg", false, value); }
    int32_t GetPrice() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nPrice"); }
    void SetPrice(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nPrice", false, value); }
    int32_t GetKillAward() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nKillAward"); }
    void SetKillAward(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nKillAward", false, value); }
    int32_t GetPrimaryReserveAmmoMax() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nPrimaryReserveAmmoMax"); }
    void SetPrimaryReserveAmmoMax(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nPrimaryReserveAmmoMax", false, value); }
    int32_t GetSecondaryReserveAmmoMax() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nSecondaryReserveAmmoMax"); }
    void SetSecondaryReserveAmmoMax(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nSecondaryReserveAmmoMax", false, value); }
    bool GetMeleeWeapon() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bMeleeWeapon"); }
    void SetMeleeWeapon(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bMeleeWeapon", false, value); }
    bool GetHasBurstMode() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bHasBurstMode"); }
    void SetHasBurstMode(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bHasBurstMode", false, value); }
    bool GetIsRevolver() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bIsRevolver"); }
    void SetIsRevolver(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bIsRevolver", false, value); }
    bool GetCannotShootUnderwater() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bCannotShootUnderwater"); }
    void SetCannotShootUnderwater(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bCannotShootUnderwater", false, value); }
    CUtlString GetAnimExtension() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSWeaponBaseVData", "m_szAnimExtension"); }
    void SetAnimExtension(CUtlString value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_szAnimExtension", false, value); }
    CSWeaponSilencerType GetSilencerType() const { return GetSchemaValue<CSWeaponSilencerType>(m_ptr, "CCSWeaponBaseVData", "m_eSilencerType"); }
    void SetSilencerType(CSWeaponSilencerType value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_eSilencerType", false, value); }
    int32_t GetCrosshairMinDistance() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairMinDistance"); }
    void SetCrosshairMinDistance(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairMinDistance", false, value); }
    int32_t GetCrosshairDeltaDistance() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairDeltaDistance"); }
    void SetCrosshairDeltaDistance(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nCrosshairDeltaDistance", false, value); }
    bool GetIsFullAuto() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bIsFullAuto"); }
    void SetIsFullAuto(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bIsFullAuto", false, value); }
    int32_t GetNumBullets() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nNumBullets"); }
    void SetNumBullets(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nNumBullets", false, value); }
    GCFiringModeFloat GetCycleTime() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flCycleTime"); }
    void SetCycleTime(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flCycleTime", false, value); }
    GCFiringModeFloat GetMaxSpeed() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flMaxSpeed"); }
    void SetMaxSpeed(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flMaxSpeed", false, value); }
    GCFiringModeFloat GetSpread() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flSpread"); }
    void SetSpread(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flSpread", false, value); }
    GCFiringModeFloat GetInaccuracyCrouch() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyCrouch"); }
    void SetInaccuracyCrouch(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyCrouch", false, value); }
    GCFiringModeFloat GetInaccuracyStand() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyStand"); }
    void SetInaccuracyStand(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyStand", false, value); }
    GCFiringModeFloat GetInaccuracyJump() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJump"); }
    void SetInaccuracyJump(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJump", false, value); }
    GCFiringModeFloat GetInaccuracyLand() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLand"); }
    void SetInaccuracyLand(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLand", false, value); }
    GCFiringModeFloat GetInaccuracyLadder() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLadder"); }
    void SetInaccuracyLadder(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyLadder", false, value); }
    GCFiringModeFloat GetInaccuracyFire() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyFire"); }
    void SetInaccuracyFire(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyFire", false, value); }
    GCFiringModeFloat GetInaccuracyMove() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyMove"); }
    void SetInaccuracyMove(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyMove", false, value); }
    GCFiringModeFloat GetRecoilAngle() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngle"); }
    void SetRecoilAngle(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngle", false, value); }
    GCFiringModeFloat GetRecoilAngleVariance() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngleVariance"); }
    void SetRecoilAngleVariance(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilAngleVariance", false, value); }
    GCFiringModeFloat GetRecoilMagnitude() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitude"); }
    void SetRecoilMagnitude(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitude", false, value); }
    GCFiringModeFloat GetRecoilMagnitudeVariance() const { return GetSchemaValue<GCFiringModeFloat>(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitudeVariance"); }
    void SetRecoilMagnitudeVariance(GCFiringModeFloat value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoilMagnitudeVariance", false, value); }
    GCFiringModeInt GetTracerFrequency() const { return GetSchemaValue<GCFiringModeInt>(m_ptr, "CCSWeaponBaseVData", "m_nTracerFrequency"); }
    void SetTracerFrequency(GCFiringModeInt value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nTracerFrequency", false, value); }
    float GetInaccuracyJumpInitial() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpInitial"); }
    void SetInaccuracyJumpInitial(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpInitial", false, value); }
    float GetInaccuracyJumpApex() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpApex"); }
    void SetInaccuracyJumpApex(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyJumpApex", false, value); }
    float GetInaccuracyReload() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyReload"); }
    void SetInaccuracyReload(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyReload", false, value); }
    int32_t GetRecoilSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nRecoilSeed"); }
    void SetRecoilSeed(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nRecoilSeed", false, value); }
    int32_t GetSpreadSeed() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nSpreadSeed"); }
    void SetSpreadSeed(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nSpreadSeed", false, value); }
    float GetTimeToIdleAfterFire() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flTimeToIdleAfterFire"); }
    void SetTimeToIdleAfterFire(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flTimeToIdleAfterFire", false, value); }
    float GetIdleInterval() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIdleInterval"); }
    void SetIdleInterval(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIdleInterval", false, value); }
    float GetAttackMovespeedFactor() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flAttackMovespeedFactor"); }
    void SetAttackMovespeedFactor(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flAttackMovespeedFactor", false, value); }
    float GetHeatPerShot() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flHeatPerShot"); }
    void SetHeatPerShot(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flHeatPerShot", false, value); }
    float GetInaccuracyPitchShift() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyPitchShift"); }
    void SetInaccuracyPitchShift(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyPitchShift", false, value); }
    float GetInaccuracyAltSoundThreshold() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyAltSoundThreshold"); }
    void SetInaccuracyAltSoundThreshold(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flInaccuracyAltSoundThreshold", false, value); }
    float GetBotAudibleRange() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flBotAudibleRange"); }
    void SetBotAudibleRange(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flBotAudibleRange", false, value); }
    CUtlString GetUseRadioSubtitle() const { return GetSchemaValue<CUtlString>(m_ptr, "CCSWeaponBaseVData", "m_szUseRadioSubtitle"); }
    void SetUseRadioSubtitle(CUtlString value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_szUseRadioSubtitle", false, value); }
    bool GetUnzoomsAfterShot() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bUnzoomsAfterShot"); }
    void SetUnzoomsAfterShot(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bUnzoomsAfterShot", false, value); }
    bool GetHideViewModelWhenZoomed() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseVData", "m_bHideViewModelWhenZoomed"); }
    void SetHideViewModelWhenZoomed(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_bHideViewModelWhenZoomed", false, value); }
    int32_t GetZoomLevels() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nZoomLevels"); }
    void SetZoomLevels(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nZoomLevels", false, value); }
    int32_t GetZoomFOV1() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV1"); }
    void SetZoomFOV1(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV1", false, value); }
    int32_t GetZoomFOV2() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV2"); }
    void SetZoomFOV2(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nZoomFOV2", false, value); }
    float GetZoomTime0() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime0"); }
    void SetZoomTime0(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime0", false, value); }
    float GetZoomTime1() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime1"); }
    void SetZoomTime1(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime1", false, value); }
    float GetZoomTime2() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime2"); }
    void SetZoomTime2(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flZoomTime2", false, value); }
    float GetIronSightPullUpSpeed() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPullUpSpeed"); }
    void SetIronSightPullUpSpeed(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPullUpSpeed", false, value); }
    float GetIronSightPutDownSpeed() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPutDownSpeed"); }
    void SetIronSightPutDownSpeed(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPutDownSpeed", false, value); }
    float GetIronSightFOV() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightFOV"); }
    void SetIronSightFOV(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightFOV", false, value); }
    float GetIronSightPivotForward() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPivotForward"); }
    void SetIronSightPivotForward(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightPivotForward", false, value); }
    float GetIronSightLooseness() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flIronSightLooseness"); }
    void SetIronSightLooseness(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flIronSightLooseness", false, value); }
    QAngle GetPivotAngle() const { return GetSchemaValue<QAngle>(m_ptr, "CCSWeaponBaseVData", "m_angPivotAngle"); }
    void SetPivotAngle(QAngle value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_angPivotAngle", false, value); }
    Vector GetIronSightEyePos() const { return GetSchemaValue<Vector>(m_ptr, "CCSWeaponBaseVData", "m_vecIronSightEyePos"); }
    void SetIronSightEyePos(Vector value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_vecIronSightEyePos", false, value); }
    int32_t GetDamage() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nDamage"); }
    void SetDamage(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nDamage", false, value); }
    float GetHeadshotMultiplier() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flHeadshotMultiplier"); }
    void SetHeadshotMultiplier(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flHeadshotMultiplier", false, value); }
    float GetArmorRatio() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flArmorRatio"); }
    void SetArmorRatio(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flArmorRatio", false, value); }
    float GetPenetration() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flPenetration"); }
    void SetPenetration(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flPenetration", false, value); }
    float GetRange() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRange"); }
    void SetRange(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRange", false, value); }
    float GetRangeModifier() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRangeModifier"); }
    void SetRangeModifier(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRangeModifier", false, value); }
    float GetFlinchVelocityModifierLarge() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierLarge"); }
    void SetFlinchVelocityModifierLarge(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierLarge", false, value); }
    float GetFlinchVelocityModifierSmall() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierSmall"); }
    void SetFlinchVelocityModifierSmall(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flFlinchVelocityModifierSmall", false, value); }
    float GetRecoveryTimeCrouch() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouch"); }
    void SetRecoveryTimeCrouch(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouch", false, value); }
    float GetRecoveryTimeStand() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStand"); }
    void SetRecoveryTimeStand(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStand", false, value); }
    float GetRecoveryTimeCrouchFinal() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouchFinal"); }
    void SetRecoveryTimeCrouchFinal(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeCrouchFinal", false, value); }
    float GetRecoveryTimeStandFinal() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStandFinal"); }
    void SetRecoveryTimeStandFinal(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flRecoveryTimeStandFinal", false, value); }
    int32_t GetRecoveryTransitionStartBullet() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionStartBullet"); }
    void SetRecoveryTransitionStartBullet(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionStartBullet", false, value); }
    int32_t GetRecoveryTransitionEndBullet() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionEndBullet"); }
    void SetRecoveryTransitionEndBullet(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_nRecoveryTransitionEndBullet", false, value); }
    float GetThrowVelocity() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBaseVData", "m_flThrowVelocity"); }
    void SetThrowVelocity(float value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_flThrowVelocity", false, value); }
    Vector GetSmokeColor() const { return GetSchemaValue<Vector>(m_ptr, "CCSWeaponBaseVData", "m_vSmokeColor"); }
    void SetSmokeColor(Vector value) { SetSchemaValue(m_ptr, "CCSWeaponBaseVData", "m_vSmokeColor", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif