class GCBreakableProp;

#ifndef _gccbreakableprop_h
#define _gccbreakableprop_h

#include "../../../scripting.h"

#include "../types/GPerformanceMode_t.h"
#include "GCPropDataComponent.h"
#include "GCEntityIOOutput.h"
#include "GCBaseEntity.h"
#include "GCBasePlayerPawn.h"

class GCBreakableProp
{
private:
    void *m_ptr;

public:
    GCBreakableProp() {}
    GCBreakableProp(void *ptr) : m_ptr(ptr) {}

    GCPropDataComponent GetCPropDataComponent() const { return GetSchemaValue<GCPropDataComponent>(m_ptr, "CBreakableProp", "m_CPropDataComponent"); }
    void SetCPropDataComponent(GCPropDataComponent value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_CPropDataComponent", false, value); }
    GCEntityIOOutput GetOnBreak() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBreakableProp", "m_OnBreak"); }
    void SetOnBreak(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_OnBreak", false, value); }
    GCEntityIOOutput GetOnTakeDamage() const { return GetSchemaValue<GCEntityIOOutput>(m_ptr, "CBreakableProp", "m_OnTakeDamage"); }
    void SetOnTakeDamage(GCEntityIOOutput value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_OnTakeDamage", false, value); }
    float GetImpactEnergyScale() const { return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_impactEnergyScale"); }
    void SetImpactEnergyScale(float value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_impactEnergyScale", false, value); }
    int32_t GetMinHealthDmg() const { return GetSchemaValue<int32_t>(m_ptr, "CBreakableProp", "m_iMinHealthDmg"); }
    void SetMinHealthDmg(int32_t value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_iMinHealthDmg", false, value); }
    QAngle GetPreferredCarryAngles() const { return GetSchemaValue<QAngle>(m_ptr, "CBreakableProp", "m_preferredCarryAngles"); }
    void SetPreferredCarryAngles(QAngle value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_preferredCarryAngles", false, value); }
    float GetPressureDelay() const { return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flPressureDelay"); }
    void SetPressureDelay(float value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_flPressureDelay", false, value); }
    float GetDefBurstScale() const { return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flDefBurstScale"); }
    void SetDefBurstScale(float value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_flDefBurstScale", false, value); }
    Vector GetDefBurstOffset() const { return GetSchemaValue<Vector>(m_ptr, "CBreakableProp", "m_vDefBurstOffset"); }
    void SetDefBurstOffset(Vector value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_vDefBurstOffset", false, value); }
    GCBaseEntity* GetBreaker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBreakableProp", "m_hBreaker"); }
    void SetBreaker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Breaker' is not possible.\n"); }
    PerformanceMode_t GetPerformanceMode() const { return GetSchemaValue<PerformanceMode_t>(m_ptr, "CBreakableProp", "m_PerformanceMode"); }
    void SetPerformanceMode(PerformanceMode_t value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_PerformanceMode", false, value); }
    bool GetHasBreakPiecesOrCommands() const { return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_bHasBreakPiecesOrCommands"); }
    void SetHasBreakPiecesOrCommands(bool value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_bHasBreakPiecesOrCommands", false, value); }
    float GetExplodeDamage() const { return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_explodeDamage"); }
    void SetExplodeDamage(float value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_explodeDamage", false, value); }
    float GetExplodeRadius() const { return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_explodeRadius"); }
    void SetExplodeRadius(float value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_explodeRadius", false, value); }
    float GetExplosionDelay() const { return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_explosionDelay"); }
    void SetExplosionDelay(float value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionDelay", false, value); }
    CUtlSymbolLarge GetExplosionBuildupSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionBuildupSound"); }
    void SetExplosionBuildupSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionBuildupSound", false, value); }
    CUtlSymbolLarge GetExplosionCustomEffect() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionCustomEffect"); }
    void SetExplosionCustomEffect(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionCustomEffect", false, value); }
    CUtlSymbolLarge GetExplosionCustomSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionCustomSound"); }
    void SetExplosionCustomSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionCustomSound", false, value); }
    CUtlSymbolLarge GetExplosionModifier() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_explosionModifier"); }
    void SetExplosionModifier(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_explosionModifier", false, value); }
    GCBasePlayerPawn* GetPhysicsAttacker() const { return GetSchemaValue<GCBasePlayerPawn*>(m_ptr, "CBreakableProp", "m_hPhysicsAttacker"); }
    void SetPhysicsAttacker(GCBasePlayerPawn* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsAttacker' is not possible.\n"); }
    bool GetOriginalBlockLOS() const { return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_bOriginalBlockLOS"); }
    void SetOriginalBlockLOS(bool value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_bOriginalBlockLOS", false, value); }
    float GetDefaultFadeScale() const { return GetSchemaValue<float>(m_ptr, "CBreakableProp", "m_flDefaultFadeScale"); }
    void SetDefaultFadeScale(float value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_flDefaultFadeScale", false, value); }
    GCBaseEntity* GetLastAttacker() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBreakableProp", "m_hLastAttacker"); }
    void SetLastAttacker(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'LastAttacker' is not possible.\n"); }
    GCBaseEntity* GetFlareEnt() const { return GetSchemaValue<GCBaseEntity*>(m_ptr, "CBreakableProp", "m_hFlareEnt"); }
    void SetFlareEnt(GCBaseEntity* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'FlareEnt' is not possible.\n"); }
    bool GetUsePuntSound() const { return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_bUsePuntSound"); }
    void SetUsePuntSound(bool value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_bUsePuntSound", false, value); }
    CUtlSymbolLarge GetPuntSound() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CBreakableProp", "m_iszPuntSound"); }
    void SetPuntSound(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_iszPuntSound", false, value); }
    bool GetNoGhostCollision() const { return GetSchemaValue<bool>(m_ptr, "CBreakableProp", "m_noGhostCollision"); }
    void SetNoGhostCollision(bool value) { SetSchemaValue(m_ptr, "CBreakableProp", "m_noGhostCollision", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif