class GCBaseCSGrenade;

#ifndef _gccbasecsgrenade_h
#define _gccbasecsgrenade_h

#include "../../../scripting.h"


#include "GCCSWeaponBase.h"

class GCBaseCSGrenade
{
private:
    void *m_ptr;

public:
    GCBaseCSGrenade() {}
    GCBaseCSGrenade(void *ptr) : m_ptr(ptr) {}

    bool GetRedraw() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bRedraw"); }
    void SetRedraw(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bRedraw", false, value); }
    bool GetIsHeldByPlayer() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bIsHeldByPlayer"); }
    void SetIsHeldByPlayer(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bIsHeldByPlayer", false, value); }
    bool GetPinPulled() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bPinPulled"); }
    void SetPinPulled(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bPinPulled", false, value); }
    bool GetJumpThrow() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bJumpThrow"); }
    void SetJumpThrow(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bJumpThrow", false, value); }
    bool GetThrowAnimating() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bThrowAnimating"); }
    void SetThrowAnimating(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bThrowAnimating", false, value); }
    float GetThrowStrength() const { return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_flThrowStrength"); }
    void SetThrowStrength(float value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_flThrowStrength", false, value); }
    float GetThrowStrengthApproach() const { return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_flThrowStrengthApproach"); }
    void SetThrowStrengthApproach(float value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_flThrowStrengthApproach", false, value); }
    bool GetJustPulledPin() const { return GetSchemaValue<bool>(m_ptr, "CBaseCSGrenade", "m_bJustPulledPin"); }
    void SetJustPulledPin(bool value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_bJustPulledPin", false, value); }
    float GetNextHoldFrac() const { return GetSchemaValue<float>(m_ptr, "CBaseCSGrenade", "m_flNextHoldFrac"); }
    void SetNextHoldFrac(float value) { SetSchemaValue(m_ptr, "CBaseCSGrenade", "m_flNextHoldFrac", false, value); }
    GCCSWeaponBase* GetSwitchToWeaponAfterThrow() const { return GetSchemaValue<GCCSWeaponBase*>(m_ptr, "CBaseCSGrenade", "m_hSwitchToWeaponAfterThrow"); }
    void SetSwitchToWeaponAfterThrow(GCCSWeaponBase* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'SwitchToWeaponAfterThrow' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif