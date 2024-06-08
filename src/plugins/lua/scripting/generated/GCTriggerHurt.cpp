#include "../../../core/scripting/generated/classes/GCTriggerHurt.h"
#include "../core.h"

void SetupLuaClassGCTriggerHurt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerHurt>("CTriggerHurt")
        .addProperty("OriginalDamage", &GCTriggerHurt::GetOriginalDamage, &GCTriggerHurt::SetOriginalDamage)
        .addProperty("Damage", &GCTriggerHurt::GetDamage, &GCTriggerHurt::SetDamage)
        .addProperty("DamageCap", &GCTriggerHurt::GetDamageCap, &GCTriggerHurt::SetDamageCap)
        .addProperty("ForgivenessDelay", &GCTriggerHurt::GetForgivenessDelay, &GCTriggerHurt::SetForgivenessDelay)
        .addProperty("BitsDamageInflict", &GCTriggerHurt::GetBitsDamageInflict, &GCTriggerHurt::SetBitsDamageInflict)
        .addProperty("DamageModel", &GCTriggerHurt::GetDamageModel, &GCTriggerHurt::SetDamageModel)
        .addProperty("NoDmgForce", &GCTriggerHurt::GetNoDmgForce, &GCTriggerHurt::SetNoDmgForce)
        .addProperty("DamageForce", &GCTriggerHurt::GetDamageForce, &GCTriggerHurt::SetDamageForce)
        .addProperty("ThinkAlways", &GCTriggerHurt::GetThinkAlways, &GCTriggerHurt::SetThinkAlways)
        .addProperty("HurtThinkPeriod", &GCTriggerHurt::GetHurtThinkPeriod, &GCTriggerHurt::SetHurtThinkPeriod)
        .addProperty("OnHurt", &GCTriggerHurt::GetOnHurt, &GCTriggerHurt::SetOnHurt)
        .addProperty("OnHurtPlayer", &GCTriggerHurt::GetOnHurtPlayer, &GCTriggerHurt::SetOnHurtPlayer)
        .endClass();
}