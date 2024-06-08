class GCFire;

#ifndef _gccfire_h
#define _gccfire_h

#include "../../../scripting.h"


#include "GCBaseFire.h"
#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"

class GCFire
{
private:
    void *m_ptr;

public:
    GCFire() {}
    GCFire(void *ptr) : m_ptr(ptr) {}

    GCBaseFire* GetEffect() const { return GetSchemaValue<GCBaseFire*>(m_ptr, "CFire", "m_hEffect"); }
    void SetEffect(GCBaseFire* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Effect' is not possible.\n"); }
    GCBaseEntity* GetOwner() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CFire", "m_hOwner"); }
    void SetOwner(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n"); }
    int32_t GetFireType() const { return GetSchemaValue<int32_t>(m_ptr, "CFire", "m_nFireType"); }
    void SetFireType(int32_t value) { SetSchemaValue(m_ptr, "CFire", "m_nFireType", false, value); }
    float GetFuel() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flFuel"); }
    void SetFuel(float value) { SetSchemaValue(m_ptr, "CFire", "m_flFuel", false, value); }
    float GetFireSize() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flFireSize"); }
    void SetFireSize(float value) { SetSchemaValue(m_ptr, "CFire", "m_flFireSize", false, value); }
    float GetHeatLevel() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flHeatLevel"); }
    void SetHeatLevel(float value) { SetSchemaValue(m_ptr, "CFire", "m_flHeatLevel", false, value); }
    float GetHeatAbsorb() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flHeatAbsorb"); }
    void SetHeatAbsorb(float value) { SetSchemaValue(m_ptr, "CFire", "m_flHeatAbsorb", false, value); }
    float GetDamageScale() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flDamageScale"); }
    void SetDamageScale(float value) { SetSchemaValue(m_ptr, "CFire", "m_flDamageScale", false, value); }
    float GetMaxHeat() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flMaxHeat"); }
    void SetMaxHeat(float value) { SetSchemaValue(m_ptr, "CFire", "m_flMaxHeat", false, value); }
    float GetLastHeatLevel() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flLastHeatLevel"); }
    void SetLastHeatLevel(float value) { SetSchemaValue(m_ptr, "CFire", "m_flLastHeatLevel", false, value); }
    float GetAttackTime() const { return GetSchemaValue<float>(m_ptr, "CFire", "m_flAttackTime"); }
    void SetAttackTime(float value) { SetSchemaValue(m_ptr, "CFire", "m_flAttackTime", false, value); }
    bool GetEnabled() const { return GetSchemaValue<bool>(m_ptr, "CFire", "m_bEnabled"); }
    void SetEnabled(bool value) { SetSchemaValue(m_ptr, "CFire", "m_bEnabled", false, value); }
    bool GetStartDisabled() const { return GetSchemaValue<bool>(m_ptr, "CFire", "m_bStartDisabled"); }
    void SetStartDisabled(bool value) { SetSchemaValue(m_ptr, "CFire", "m_bStartDisabled", false, value); }
    bool GetDidActivate() const { return GetSchemaValue<bool>(m_ptr, "CFire", "m_bDidActivate"); }
    void SetDidActivate(bool value) { SetSchemaValue(m_ptr, "CFire", "m_bDidActivate", false, value); }
    GCEntityIOOutput GetOnIgnited() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFire", "m_OnIgnited"); }
    void SetOnIgnited(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFire", "m_OnIgnited", false, value); }
    GCEntityIOOutput GetOnExtinguished() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CFire", "m_OnExtinguished"); }
    void SetOnExtinguished(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CFire", "m_OnExtinguished", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif