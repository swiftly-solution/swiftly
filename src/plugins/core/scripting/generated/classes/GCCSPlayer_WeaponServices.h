class GCCSPlayer_WeaponServices;

#ifndef _gcccsplayer_weaponservices_h
#define _gcccsplayer_weaponservices_h

#include "../../../scripting.h"


#include "GCBasePlayerWeapon.h"

class GCCSPlayer_WeaponServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_WeaponServices() {}
    GCCSPlayer_WeaponServices(void *ptr) : m_ptr(ptr) {}

    bool GetIsLookingAtWeapon() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsLookingAtWeapon"); }
    void SetIsLookingAtWeapon(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsLookingAtWeapon", false, value); }
    bool GetIsHoldingLookAtWeapon() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsHoldingLookAtWeapon"); }
    void SetIsHoldingLookAtWeapon(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsHoldingLookAtWeapon", false, value); }
    GCBasePlayerWeapon* GetSavedWeapon() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CCSPlayer_WeaponServices", "m_hSavedWeapon"); }
    void SetSavedWeapon(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SavedWeapon' is not possible.\n"); }
    int32_t GetTimeToMelee() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToMelee"); }
    void SetTimeToMelee(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToMelee", false, value); }
    int32_t GetTimeToSecondary() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSecondary"); }
    void SetTimeToSecondary(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSecondary", false, value); }
    int32_t GetTimeToPrimary() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToPrimary"); }
    void SetTimeToPrimary(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToPrimary", false, value); }
    int32_t GetTimeToSniperRifle() const { return GetSchemaValue<int32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSniperRifle"); }
    void SetTimeToSniperRifle(int32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nTimeToSniperRifle", false, value); }
    bool GetIsBeingGivenItem() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsBeingGivenItem"); }
    void SetIsBeingGivenItem(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsBeingGivenItem", false, value); }
    bool GetIsPickingUpItemWithUse() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpItemWithUse"); }
    void SetIsPickingUpItemWithUse(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpItemWithUse", false, value); }
    bool GetPickedUpWeapon() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bPickedUpWeapon"); }
    void SetPickedUpWeapon(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bPickedUpWeapon", false, value); }
    bool GetDisableAutoDeploy() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bDisableAutoDeploy"); }
    void SetDisableAutoDeploy(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bDisableAutoDeploy", false, value); }
    bool GetIsPickingUpGroundWeapon() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpGroundWeapon"); }
    void SetIsPickingUpGroundWeapon(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_bIsPickingUpGroundWeapon", false, value); }
    uint32_t GetOldShootPositionHistoryCount() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nOldShootPositionHistoryCount"); }
    void SetOldShootPositionHistoryCount(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nOldShootPositionHistoryCount", false, value); }
    uint32_t GetOldInputHistoryCount() const { return GetSchemaValue<uint32_t>(m_ptr, "CCSPlayer_WeaponServices", "m_nOldInputHistoryCount"); }
    void SetOldInputHistoryCount(uint32_t value) { SetSchemaValue(m_ptr, "CCSPlayer_WeaponServices", "m_nOldInputHistoryCount", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif