class GCBasePlayerWeaponVData;

#ifndef _gccbaseplayerweaponvdata_h
#define _gccbaseplayerweaponvdata_h

#include "../../../scripting.h"

#include "../types/GItemFlagTypes_t.h"
#include "../types/GRumbleEffect_t.h"


class GCBasePlayerWeaponVData
{
private:
    void *m_ptr;

public:
    GCBasePlayerWeaponVData() {}
    GCBasePlayerWeaponVData(void *ptr) : m_ptr(ptr) {}

    bool GetBuiltRightHanded() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bBuiltRightHanded"); }
    void SetBuiltRightHanded(bool value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bBuiltRightHanded", false, value); }
    bool GetAllowFlipping() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bAllowFlipping"); }
    void SetAllowFlipping(bool value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bAllowFlipping", false, value); }
    CUtlString GetMuzzleAttachment() const { return GetSchemaValue<CUtlString>(m_ptr, "CBasePlayerWeaponVData", "m_sMuzzleAttachment"); }
    void SetMuzzleAttachment(CUtlString value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_sMuzzleAttachment", false, value); }
    ItemFlagTypes_t GetFlags() const { return GetSchemaValue<ItemFlagTypes_t>(m_ptr, "CBasePlayerWeaponVData", "m_iFlags"); }
    void SetFlags(ItemFlagTypes_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iFlags", false, value); }
    uint8_t GetPrimaryAmmoType() const { return GetSchemaValue<uint8_t>(m_ptr, "CBasePlayerWeaponVData", "m_nPrimaryAmmoType"); }
    void SetPrimaryAmmoType(uint8_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_nPrimaryAmmoType", false, value); }
    uint8_t GetSecondaryAmmoType() const { return GetSchemaValue<uint8_t>(m_ptr, "CBasePlayerWeaponVData", "m_nSecondaryAmmoType"); }
    void SetSecondaryAmmoType(uint8_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_nSecondaryAmmoType", false, value); }
    int32_t GetMaxClip1() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip1"); }
    void SetMaxClip1(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip1", false, value); }
    int32_t GetMaxClip2() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip2"); }
    void SetMaxClip2(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iMaxClip2", false, value); }
    int32_t GetDefaultClip1() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip1"); }
    void SetDefaultClip1(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip1", false, value); }
    int32_t GetDefaultClip2() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip2"); }
    void SetDefaultClip2(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iDefaultClip2", false, value); }
    int32_t GetWeight() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iWeight"); }
    void SetWeight(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iWeight", false, value); }
    bool GetAutoSwitchTo() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchTo"); }
    void SetAutoSwitchTo(bool value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchTo", false, value); }
    bool GetAutoSwitchFrom() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchFrom"); }
    void SetAutoSwitchFrom(bool value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bAutoSwitchFrom", false, value); }
    RumbleEffect_t GetRumbleEffect() const { return GetSchemaValue<RumbleEffect_t>(m_ptr, "CBasePlayerWeaponVData", "m_iRumbleEffect"); }
    void SetRumbleEffect(RumbleEffect_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iRumbleEffect", false, value); }
    bool GetLinkedCooldowns() const { return GetSchemaValue<bool>(m_ptr, "CBasePlayerWeaponVData", "m_bLinkedCooldowns"); }
    void SetLinkedCooldowns(bool value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_bLinkedCooldowns", false, value); }
    int32_t GetSlot() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iSlot"); }
    void SetSlot(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iSlot", false, value); }
    int32_t GetPosition() const { return GetSchemaValue<int32_t>(m_ptr, "CBasePlayerWeaponVData", "m_iPosition"); }
    void SetPosition(int32_t value) { SetSchemaValue(m_ptr, "CBasePlayerWeaponVData", "m_iPosition", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif