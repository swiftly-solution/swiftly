#include "../../../core/scripting/generated/classes/GCBaseCombatCharacter.h"
#include "../core.h"

void SetupLuaClassGCBaseCombatCharacter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseCombatCharacter>("CBaseCombatCharacter")
        .addProperty("ForceServerRagdoll", &GCBaseCombatCharacter::GetForceServerRagdoll, &GCBaseCombatCharacter::SetForceServerRagdoll)
        .addProperty("MyWearables", &GCBaseCombatCharacter::GetMyWearables, &GCBaseCombatCharacter::SetMyWearables)
        .addProperty("FieldOfView", &GCBaseCombatCharacter::GetFieldOfView, &GCBaseCombatCharacter::SetFieldOfView)
        .addProperty("ImpactEnergyScale", &GCBaseCombatCharacter::GetImpactEnergyScale, &GCBaseCombatCharacter::SetImpactEnergyScale)
        .addProperty("LastHitGroup", &GCBaseCombatCharacter::GetLastHitGroup, &GCBaseCombatCharacter::SetLastHitGroup)
        .addProperty("ApplyStressDamage", &GCBaseCombatCharacter::GetApplyStressDamage, &GCBaseCombatCharacter::SetApplyStressDamage)
        .addProperty("DamageCount", &GCBaseCombatCharacter::GetDamageCount, &GCBaseCombatCharacter::SetDamageCount)
        .addProperty("StrRelationships", &GCBaseCombatCharacter::GetStrRelationships, &GCBaseCombatCharacter::SetStrRelationships)
        .addProperty("Hull", &GCBaseCombatCharacter::GetHull, &GCBaseCombatCharacter::SetHull)
        .addProperty("NavHullIdx", &GCBaseCombatCharacter::GetNavHullIdx, &GCBaseCombatCharacter::SetNavHullIdx)
        .endClass();
}