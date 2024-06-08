class GCBreakable;

#ifndef _gccbreakable_h
#define _gccbreakable_h

#include "../../../scripting.h"

#include "../types/GMaterials.h"
#include "../types/GExplosions.h"
#include "../types/GEOverrideBlockLOS_t.h"
#include "../types/GPerformanceMode_t.h"
#include "GCPropDataComponent.h"
#include "GCBaseEntity.h"
#include "GCEntityIOOutput.h"
#include "GCBasePlayerPawn.h"

class GCBreakable
{
private:
    void *m_ptr;

public:
    GCBreakable() {}
    GCBreakable(void *ptr) : m_ptr(ptr) {}

    GCPropDataComponent GetCPropDataComponent() const { return GetSchemaValue<GCPropDataComponent>(m_ptr, "CBreakable", "m_CPropDataComponent"); }
    void SetCPropDataComponent(GCPropDataComponent value) { SetSchemaValue(m_ptr, "CBreakable", "m_CPropDataComponent", false, value); }
    Materials GetMaterial() const { return GetSchemaValue<Materials>(m_ptr, "CBreakable", "m_Material"); }
    void SetMaterial(Materials value) { SetSchemaValue(m_ptr, "CBreakable", "m_Material", false, value); }
    GCBaseEntity* GetBreaker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBreakable", "m_hBreaker"); }
    void SetBreaker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Breaker' is not possible.\n"); }
    Explosions GetExplosion() const { return GetSchemaValue<Explosions>(m_ptr, "CBreakable", "m_Explosion"); }
    void SetExplosion(Explosions value) { SetSchemaValue(m_ptr, "CBreakable", "m_Explosion", false, value); }
    CUtlSymbolLarge GetSpawnObject() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakable", "m_iszSpawnObject"); }
    void SetSpawnObject(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBreakable", "m_iszSpawnObject", false, value); }
    float GetPressureDelay() const { return GetSchemaValue<float>(m_ptr, "CBreakable", "m_flPressureDelay"); }
    void SetPressureDelay(float value) { SetSchemaValue(m_ptr, "CBreakable", "m_flPressureDelay", false, value); }
    int32_t GetMinHealthDmg() const { return GetSchemaValue<int32_t>(m_ptr, "CBreakable", "m_iMinHealthDmg"); }
    void SetMinHealthDmg(int32_t value) { SetSchemaValue(m_ptr, "CBreakable", "m_iMinHealthDmg", false, value); }
    CUtlSymbolLarge GetPropData() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakable", "m_iszPropData"); }
    void SetPropData(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBreakable", "m_iszPropData", false, value); }
    float GetImpactEnergyScale() const { return GetSchemaValue<float>(m_ptr, "CBreakable", "m_impactEnergyScale"); }
    void SetImpactEnergyScale(float value) { SetSchemaValue(m_ptr, "CBreakable", "m_impactEnergyScale", false, value); }
    EOverrideBlockLOS_t GetOverrideBlockLOS() const { return GetSchemaValue<EOverrideBlockLOS_t>(m_ptr, "CBreakable", "m_nOverrideBlockLOS"); }
    void SetOverrideBlockLOS(EOverrideBlockLOS_t value) { SetSchemaValue(m_ptr, "CBreakable", "m_nOverrideBlockLOS", false, value); }
    GCEntityIOOutput GetOnBreak() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBreakable", "m_OnBreak"); }
    void SetOnBreak(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBreakable", "m_OnBreak", false, value); }
    PerformanceMode_t GetPerformanceMode() const { return GetSchemaValue<PerformanceMode_t>(m_ptr, "CBreakable", "m_PerformanceMode"); }
    void SetPerformanceMode(PerformanceMode_t value) { SetSchemaValue(m_ptr, "CBreakable", "m_PerformanceMode", false, value); }
    GCBasePlayerPawn* GetPhysicsAttacker() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CBreakable", "m_hPhysicsAttacker"); }
    void SetPhysicsAttacker(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsAttacker' is not possible.\n"); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif