class GCCSWeaponBase;

#ifndef _gcccsweaponbase_h
#define _gcccsweaponbase_h

#include "../../../scripting.h"

#include "../types/GPlayerAnimEvent_t.h"
#include "../types/GWeaponAttackType_t.h"
#include "../types/GCSWeaponState_t.h"
#include "../types/GCSWeaponMode.h"
#include "GCEntityIOOutput.h"
#include "GCCSPlayerPawn.h"
#include "GCIronSightController.h"

class GCCSWeaponBase
{
private:
    void *m_ptr;

public:
    GCCSWeaponBase() {}
    GCCSWeaponBase(void *ptr) : m_ptr(ptr) {}

    bool GetRemoveable() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bRemoveable"); }
    void SetRemoveable(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bRemoveable", false, value); }
    float GetFireSequenceStartTime() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flFireSequenceStartTime"); }
    void SetFireSequenceStartTime(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flFireSequenceStartTime", false, value); }
    int32_t GetFireSequenceStartTimeChange() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeChange"); }
    void SetFireSequenceStartTimeChange(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeChange", false, value); }
    int32_t GetFireSequenceStartTimeAck() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeAck"); }
    void SetFireSequenceStartTimeAck(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nFireSequenceStartTimeAck", false, value); }
    PlayerAnimEvent_t GetPlayerFireEvent() const { return GetSchemaValue<PlayerAnimEvent_t>(m_ptr, "CCSWeaponBase", "m_ePlayerFireEvent"); }
    void SetPlayerFireEvent(PlayerAnimEvent_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_ePlayerFireEvent", false, value); }
    WeaponAttackType_t GetPlayerFireEventAttackType() const { return GetSchemaValue<WeaponAttackType_t>(m_ptr, "CCSWeaponBase", "m_ePlayerFireEventAttackType"); }
    void SetPlayerFireEventAttackType(WeaponAttackType_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_ePlayerFireEventAttackType", false, value); }
    int32_t GetSilencerBoneIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nSilencerBoneIndex"); }
    void SetSilencerBoneIndex(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nSilencerBoneIndex", false, value); }
    bool GetPlayerAmmoStockOnPickup() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bPlayerAmmoStockOnPickup"); }
    void SetPlayerAmmoStockOnPickup(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bPlayerAmmoStockOnPickup", false, value); }
    bool GetRequireUseToTouch() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bRequireUseToTouch"); }
    void SetRequireUseToTouch(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bRequireUseToTouch", false, value); }
    CSWeaponState_t GetState() const { return GetSchemaValue<CSWeaponState_t>(m_ptr, "CCSWeaponBase", "m_iState"); }
    void SetState(CSWeaponState_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iState", false, value); }
    int32_t GetLastEmptySoundCmdNum() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_nLastEmptySoundCmdNum"); }
    void SetLastEmptySoundCmdNum(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nLastEmptySoundCmdNum", false, value); }
    uint32_t GetViewModelIndex() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSWeaponBase", "m_nViewModelIndex"); }
    void SetViewModelIndex(uint32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_nViewModelIndex", false, value); }
    bool GetReloadsWithClips() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bReloadsWithClips"); }
    void SetReloadsWithClips(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bReloadsWithClips", false, value); }
    bool GetFireOnEmpty() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bFireOnEmpty"); }
    void SetFireOnEmpty(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bFireOnEmpty", false, value); }
    GCEntityIOOutput GetOnPlayerPickup() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CCSWeaponBase", "m_OnPlayerPickup"); }
    void SetOnPlayerPickup(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_OnPlayerPickup", false, value); }
    CSWeaponMode GetWeaponMode() const { return GetSchemaValue<CSWeaponMode>(m_ptr, "CCSWeaponBase", "m_weaponMode"); }
    void SetWeaponMode(CSWeaponMode value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_weaponMode", false, value); }
    float GetTurningInaccuracyDelta() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracyDelta"); }
    void SetTurningInaccuracyDelta(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracyDelta", false, value); }
    Vector GetTurningInaccuracyEyeDirLast() const { return GetSchemaValue<Vector>(m_ptr, "CCSWeaponBase", "m_vecTurningInaccuracyEyeDirLast"); }
    void SetTurningInaccuracyEyeDirLast(Vector value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_vecTurningInaccuracyEyeDirLast", false, value); }
    float GetTurningInaccuracy() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracy"); }
    void SetTurningInaccuracy(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flTurningInaccuracy", false, value); }
    float GetAccuracyPenalty() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_fAccuracyPenalty"); }
    void SetAccuracyPenalty(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_fAccuracyPenalty", false, value); }
    float GetAccuracySmoothedForZoom() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_fAccuracySmoothedForZoom"); }
    void SetAccuracySmoothedForZoom(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_fAccuracySmoothedForZoom", false, value); }
    int32_t GetRecoilIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iRecoilIndex"); }
    void SetRecoilIndex(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iRecoilIndex", false, value); }
    float GetRecoilIndex1() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flRecoilIndex"); }
    void SetRecoilIndex1(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flRecoilIndex", false, value); }
    bool GetBurstMode() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bBurstMode"); }
    void SetBurstMode(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bBurstMode", false, value); }
    float GetPostponeFireReadyFrac() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flPostponeFireReadyFrac"); }
    void SetPostponeFireReadyFrac(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flPostponeFireReadyFrac", false, value); }
    bool GetInReload() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bInReload"); }
    void SetInReload(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bInReload", false, value); }
    bool GetReloadVisuallyComplete() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bReloadVisuallyComplete"); }
    void SetReloadVisuallyComplete(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bReloadVisuallyComplete", false, value); }
    bool GetIsHauledBack() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bIsHauledBack"); }
    void SetIsHauledBack(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bIsHauledBack", false, value); }
    bool GetSilencerOn() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bSilencerOn"); }
    void SetSilencerOn(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bSilencerOn", false, value); }
    int32_t GetOriginalTeamNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iOriginalTeamNumber"); }
    void SetOriginalTeamNumber(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iOriginalTeamNumber", false, value); }
    int32_t GetMostRecentTeamNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iMostRecentTeamNumber"); }
    void SetMostRecentTeamNumber(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iMostRecentTeamNumber", false, value); }
    bool GetDroppedNearBuyZone() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bDroppedNearBuyZone"); }
    void SetDroppedNearBuyZone(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bDroppedNearBuyZone", false, value); }
    float GetNextAttackRenderTimeOffset() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flNextAttackRenderTimeOffset"); }
    void SetNextAttackRenderTimeOffset(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flNextAttackRenderTimeOffset", false, value); }
    bool GetCanBePickedUp() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bCanBePickedUp"); }
    void SetCanBePickedUp(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bCanBePickedUp", false, value); }
    bool GetUseCanOverrideNextOwnerTouchTime() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bUseCanOverrideNextOwnerTouchTime"); }
    void SetUseCanOverrideNextOwnerTouchTime(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bUseCanOverrideNextOwnerTouchTime", false, value); }
    GCCSPlayerPawn* GetPrevOwner() const { return GetSchemaValue<GCCSPlayerPawn*>(m_ptr, "CCSWeaponBase", "m_hPrevOwner"); }
    void SetPrevOwner(GCCSPlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PrevOwner' is not possible.\n"); }
    bool GetDonated() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_donated"); }
    void SetDonated(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_donated", false, value); }
    bool GetWasOwnedByCT() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bWasOwnedByCT"); }
    void SetWasOwnedByCT(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bWasOwnedByCT", false, value); }
    bool GetWasOwnedByTerrorist() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bWasOwnedByTerrorist"); }
    void SetWasOwnedByTerrorist(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bWasOwnedByTerrorist", false, value); }
    bool GetFiredOutOfAmmoEvent() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBase", "m_bFiredOutOfAmmoEvent"); }
    void SetFiredOutOfAmmoEvent(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_bFiredOutOfAmmoEvent", false, value); }
    int32_t GetNumRemoveUnownedWeaponThink() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_numRemoveUnownedWeaponThink"); }
    void SetNumRemoveUnownedWeaponThink(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_numRemoveUnownedWeaponThink", false, value); }
    GCIronSightController GetIronSightController() const { return GetSchemaValue<GCIronSightController>(m_ptr, "CCSWeaponBase", "m_IronSightController"); }
    void SetIronSightController(GCIronSightController value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_IronSightController", false, value); }
    int32_t GetIronSightMode() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iIronSightMode"); }
    void SetIronSightMode(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iIronSightMode", false, value); }
    int32_t GetNumEmptyAttacks() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBase", "m_iNumEmptyAttacks"); }
    void SetNumEmptyAttacks(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_iNumEmptyAttacks", false, value); }
    float GetWatTickOffset() const { return GetSchemaValue<float>(m_ptr, "CCSWeaponBase", "m_flWatTickOffset"); }
    void SetWatTickOffset(float value) { SetSchemaValue(m_ptr, "CCSWeaponBase", "m_flWatTickOffset", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif