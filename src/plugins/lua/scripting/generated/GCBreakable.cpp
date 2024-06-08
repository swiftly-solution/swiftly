#include "../../../core/scripting/generated/classes/GCBreakable.h"
#include "../core.h"

void SetupLuaClassGCBreakable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreakable>("CBreakable")
        .addProperty("CPropDataComponent", &GCBreakable::GetCPropDataComponent, &GCBreakable::SetCPropDataComponent)
        .addProperty("Material", &GCBreakable::GetMaterial, &GCBreakable::SetMaterial)
        .addProperty("Breaker", &GCBreakable::GetBreaker, &GCBreakable::SetBreaker)
        .addProperty("Explosion", &GCBreakable::GetExplosion, &GCBreakable::SetExplosion)
        .addProperty("SpawnObject", &GCBreakable::GetSpawnObject, &GCBreakable::SetSpawnObject)
        .addProperty("PressureDelay", &GCBreakable::GetPressureDelay, &GCBreakable::SetPressureDelay)
        .addProperty("MinHealthDmg", &GCBreakable::GetMinHealthDmg, &GCBreakable::SetMinHealthDmg)
        .addProperty("PropData", &GCBreakable::GetPropData, &GCBreakable::SetPropData)
        .addProperty("ImpactEnergyScale", &GCBreakable::GetImpactEnergyScale, &GCBreakable::SetImpactEnergyScale)
        .addProperty("OverrideBlockLOS", &GCBreakable::GetOverrideBlockLOS, &GCBreakable::SetOverrideBlockLOS)
        .addProperty("OnBreak", &GCBreakable::GetOnBreak, &GCBreakable::SetOnBreak)
        .addProperty("PerformanceMode", &GCBreakable::GetPerformanceMode, &GCBreakable::SetPerformanceMode)
        .addProperty("PhysicsAttacker", &GCBreakable::GetPhysicsAttacker, &GCBreakable::SetPhysicsAttacker)
        .endClass();
}