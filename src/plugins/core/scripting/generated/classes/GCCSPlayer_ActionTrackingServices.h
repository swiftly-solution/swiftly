class GCCSPlayer_ActionTrackingServices;

#ifndef _gcccsplayer_actiontrackingservices_h
#define _gcccsplayer_actiontrackingservices_h

#include "../../../scripting.h"


#include "GCBasePlayerWeapon.h"
#include "GWeaponPurchaseTracker_t.h"

class GCCSPlayer_ActionTrackingServices
{
private:
    void *m_ptr;

public:
    GCCSPlayer_ActionTrackingServices() {}
    GCCSPlayer_ActionTrackingServices(void *ptr) : m_ptr(ptr) {}

    GCBasePlayerWeapon* GetLastWeaponBeforeC4AutoSwitch() const { return GetSchemaValue<GCBasePlayerWeapon*>(m_ptr, "CCSPlayer_ActionTrackingServices", "m_hLastWeaponBeforeC4AutoSwitch"); }
    void SetLastWeaponBeforeC4AutoSwitch(GCBasePlayerWeapon* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastWeaponBeforeC4AutoSwitch' is not possible.\n"); }
    bool GetIsRescuing() const { return GetSchemaValue<bool>(m_ptr, "CCSPlayer_ActionTrackingServices", "m_bIsRescuing"); }
    void SetIsRescuing(bool value) { SetSchemaValue(m_ptr, "CCSPlayer_ActionTrackingServices", "m_bIsRescuing", false, value); }
    GWeaponPurchaseTracker_t GetWeaponPurchasesThisMatch() const { return GetSchemaValue<GWeaponPurchaseTracker_t>(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisMatch"); }
    void SetWeaponPurchasesThisMatch(GWeaponPurchaseTracker_t value) { SetSchemaValue(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisMatch", false, value); }
    GWeaponPurchaseTracker_t GetWeaponPurchasesThisRound() const { return GetSchemaValue<GWeaponPurchaseTracker_t>(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisRound"); }
    void SetWeaponPurchasesThisRound(GWeaponPurchaseTracker_t value) { SetSchemaValue(m_ptr, "CCSPlayer_ActionTrackingServices", "m_weaponPurchasesThisRound", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif