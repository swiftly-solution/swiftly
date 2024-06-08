#include "../../../core/scripting/generated/classes/GCFire.h"
#include "../core.h"

void SetupLuaClassGCFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFire>("CFire")
        .addProperty("Effect", &GCFire::GetEffect, &GCFire::SetEffect)
        .addProperty("Owner", &GCFire::GetOwner, &GCFire::SetOwner)
        .addProperty("FireType", &GCFire::GetFireType, &GCFire::SetFireType)
        .addProperty("Fuel", &GCFire::GetFuel, &GCFire::SetFuel)
        .addProperty("FireSize", &GCFire::GetFireSize, &GCFire::SetFireSize)
        .addProperty("HeatLevel", &GCFire::GetHeatLevel, &GCFire::SetHeatLevel)
        .addProperty("HeatAbsorb", &GCFire::GetHeatAbsorb, &GCFire::SetHeatAbsorb)
        .addProperty("DamageScale", &GCFire::GetDamageScale, &GCFire::SetDamageScale)
        .addProperty("MaxHeat", &GCFire::GetMaxHeat, &GCFire::SetMaxHeat)
        .addProperty("LastHeatLevel", &GCFire::GetLastHeatLevel, &GCFire::SetLastHeatLevel)
        .addProperty("AttackTime", &GCFire::GetAttackTime, &GCFire::SetAttackTime)
        .addProperty("Enabled", &GCFire::GetEnabled, &GCFire::SetEnabled)
        .addProperty("StartDisabled", &GCFire::GetStartDisabled, &GCFire::SetStartDisabled)
        .addProperty("DidActivate", &GCFire::GetDidActivate, &GCFire::SetDidActivate)
        .addProperty("OnIgnited", &GCFire::GetOnIgnited, &GCFire::SetOnIgnited)
        .addProperty("OnExtinguished", &GCFire::GetOnExtinguished, &GCFire::SetOnExtinguished)
        .endClass();
}