class GCCSWeaponBaseGun;

#ifndef _gcccsweaponbasegun_h
#define _gcccsweaponbasegun_h

#include "../../../scripting.h"




class GCCSWeaponBaseGun
{
private:
    void *m_ptr;

public:
    GCCSWeaponBaseGun() {}
    GCCSWeaponBaseGun(void *ptr) : m_ptr(ptr) {}

    int32_t GetZoomLevel() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseGun", "m_zoomLevel"); }
    void SetZoomLevel(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_zoomLevel", false, value); }
    int32_t GetBurstShotsRemaining() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseGun", "m_iBurstShotsRemaining"); }
    void SetBurstShotsRemaining(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_iBurstShotsRemaining", false, value); }
    int32_t GetSilencedModelIndex() const { return GetSchemaValue<int32_t>(m_ptr, "CCSWeaponBaseGun", "m_silencedModelIndex"); }
    void SetSilencedModelIndex(int32_t value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_silencedModelIndex", false, value); }
    bool GetInPrecache() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_inPrecache"); }
    void SetInPrecache(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_inPrecache", false, value); }
    bool GetNeedsBoltAction() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bNeedsBoltAction"); }
    void SetNeedsBoltAction(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bNeedsBoltAction", false, value); }
    bool GetSkillReloadAvailable() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadAvailable"); }
    void SetSkillReloadAvailable(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadAvailable", false, value); }
    bool GetSkillReloadLiftedReloadKey() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadLiftedReloadKey"); }
    void SetSkillReloadLiftedReloadKey(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillReloadLiftedReloadKey", false, value); }
    bool GetSkillBoltInterruptAvailable() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltInterruptAvailable"); }
    void SetSkillBoltInterruptAvailable(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltInterruptAvailable", false, value); }
    bool GetSkillBoltLiftedFireKey() const { return GetSchemaValue<bool>(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltLiftedFireKey"); }
    void SetSkillBoltLiftedFireKey(bool value) { SetSchemaValue(m_ptr, "CCSWeaponBaseGun", "m_bSkillBoltLiftedFireKey", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif