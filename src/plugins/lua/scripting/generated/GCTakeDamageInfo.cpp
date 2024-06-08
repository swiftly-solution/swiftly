#include "../../../core/scripting/generated/classes/GCTakeDamageInfo.h"
#include "../core.h"

void SetupLuaClassGCTakeDamageInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTakeDamageInfo>("CTakeDamageInfo")
        .addProperty("DamageForce", &GCTakeDamageInfo::GetDamageForce, &GCTakeDamageInfo::SetDamageForce)
        .addProperty("DamagePosition", &GCTakeDamageInfo::GetDamagePosition, &GCTakeDamageInfo::SetDamagePosition)
        .addProperty("ReportedPosition", &GCTakeDamageInfo::GetReportedPosition, &GCTakeDamageInfo::SetReportedPosition)
        .addProperty("DamageDirection", &GCTakeDamageInfo::GetDamageDirection, &GCTakeDamageInfo::SetDamageDirection)
        .addProperty("Inflictor", &GCTakeDamageInfo::GetInflictor, &GCTakeDamageInfo::SetInflictor)
        .addProperty("Attacker", &GCTakeDamageInfo::GetAttacker, &GCTakeDamageInfo::SetAttacker)
        .addProperty("Ability", &GCTakeDamageInfo::GetAbility, &GCTakeDamageInfo::SetAbility)
        .addProperty("Damage", &GCTakeDamageInfo::GetDamage, &GCTakeDamageInfo::SetDamage)
        .addProperty("TotalledDamage", &GCTakeDamageInfo::GetTotalledDamage, &GCTakeDamageInfo::SetTotalledDamage)
        .addProperty("BitsDamageType", &GCTakeDamageInfo::GetBitsDamageType, &GCTakeDamageInfo::SetBitsDamageType)
        .addProperty("DamageCustom", &GCTakeDamageInfo::GetDamageCustom, &GCTakeDamageInfo::SetDamageCustom)
        .addProperty("AmmoType", &GCTakeDamageInfo::GetAmmoType, &GCTakeDamageInfo::SetAmmoType)
        .addProperty("OriginalDamage", &GCTakeDamageInfo::GetOriginalDamage, &GCTakeDamageInfo::SetOriginalDamage)
        .addProperty("ShouldBleed", &GCTakeDamageInfo::GetShouldBleed, &GCTakeDamageInfo::SetShouldBleed)
        .addProperty("ShouldSpark", &GCTakeDamageInfo::GetShouldSpark, &GCTakeDamageInfo::SetShouldSpark)
        .addProperty("DamageFlags", &GCTakeDamageInfo::GetDamageFlags, &GCTakeDamageInfo::SetDamageFlags)
        .addProperty("NumObjectsPenetrated", &GCTakeDamageInfo::GetNumObjectsPenetrated, &GCTakeDamageInfo::SetNumObjectsPenetrated)
        .addProperty("InTakeDamageFlow", &GCTakeDamageInfo::GetInTakeDamageFlow, &GCTakeDamageInfo::SetInTakeDamageFlow)
        .endClass();
}