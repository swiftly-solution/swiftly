class GCPropDataComponent;

#ifndef _gccpropdatacomponent_h
#define _gccpropdatacomponent_h

#include "../../../scripting.h"




class GCPropDataComponent
{
private:
    void *m_ptr;

public:
    GCPropDataComponent() {}
    GCPropDataComponent(void *ptr) : m_ptr(ptr) {}

    float GetDmgModBullet() const { return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModBullet"); }
    void SetDmgModBullet(float value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModBullet", false, value); }
    float GetDmgModClub() const { return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModClub"); }
    void SetDmgModClub(float value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModClub", false, value); }
    float GetDmgModExplosive() const { return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModExplosive"); }
    void SetDmgModExplosive(float value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModExplosive", false, value); }
    float GetDmgModFire() const { return GetSchemaValue<float>(m_ptr, "CPropDataComponent", "m_flDmgModFire"); }
    void SetDmgModFire(float value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_flDmgModFire", false, value); }
    CUtlSymbolLarge GetPhysicsDamageTableName() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPropDataComponent", "m_iszPhysicsDamageTableName"); }
    void SetPhysicsDamageTableName(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_iszPhysicsDamageTableName", false, value); }
    CUtlSymbolLarge GetBasePropData() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPropDataComponent", "m_iszBasePropData"); }
    void SetBasePropData(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_iszBasePropData", false, value); }
    int32_t GetInteractions() const { return GetSchemaValue<int32_t>(m_ptr, "CPropDataComponent", "m_nInteractions"); }
    void SetInteractions(int32_t value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_nInteractions", false, value); }
    bool GetSpawnMotionDisabled() const { return GetSchemaValue<bool>(m_ptr, "CPropDataComponent", "m_bSpawnMotionDisabled"); }
    void SetSpawnMotionDisabled(bool value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_bSpawnMotionDisabled", false, value); }
    int32_t GetDisableTakePhysicsDamageSpawnFlag() const { return GetSchemaValue<int32_t>(m_ptr, "CPropDataComponent", "m_nDisableTakePhysicsDamageSpawnFlag"); }
    void SetDisableTakePhysicsDamageSpawnFlag(int32_t value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_nDisableTakePhysicsDamageSpawnFlag", false, value); }
    int32_t GetMotionDisabledSpawnFlag() const { return GetSchemaValue<int32_t>(m_ptr, "CPropDataComponent", "m_nMotionDisabledSpawnFlag"); }
    void SetMotionDisabledSpawnFlag(int32_t value) { SetSchemaValue(m_ptr, "CPropDataComponent", "m_nMotionDisabledSpawnFlag", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif