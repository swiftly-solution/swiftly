#include "../../../core/scripting/generated/classes/GCRagdollProp.h"
#include "../core.h"

void SetupLuaClassGCRagdollProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollProp>("CRagdollProp")
        .addProperty("Ragdoll", &GCRagdollProp::GetRagdoll, &GCRagdollProp::SetRagdoll)
        .addProperty("StartDisabled", &GCRagdollProp::GetStartDisabled, &GCRagdollProp::SetStartDisabled)
        .addProperty("RagPos", &GCRagdollProp::GetRagPos, &GCRagdollProp::SetRagPos)
        .addProperty("RagAngles", &GCRagdollProp::GetRagAngles, &GCRagdollProp::SetRagAngles)
        .addProperty("RagdollSource", &GCRagdollProp::GetRagdollSource, &GCRagdollProp::SetRagdollSource)
        .addProperty("LastUpdateTickCount", &GCRagdollProp::GetLastUpdateTickCount, &GCRagdollProp::SetLastUpdateTickCount)
        .addProperty("AllAsleep", &GCRagdollProp::GetAllAsleep, &GCRagdollProp::SetAllAsleep)
        .addProperty("FirstCollisionAfterLaunch", &GCRagdollProp::GetFirstCollisionAfterLaunch, &GCRagdollProp::SetFirstCollisionAfterLaunch)
        .addProperty("DamageEntity", &GCRagdollProp::GetDamageEntity, &GCRagdollProp::SetDamageEntity)
        .addProperty("Killer", &GCRagdollProp::GetKiller, &GCRagdollProp::SetKiller)
        .addProperty("PhysicsAttacker", &GCRagdollProp::GetPhysicsAttacker, &GCRagdollProp::SetPhysicsAttacker)
        .addProperty("FadeTime", &GCRagdollProp::GetFadeTime, &GCRagdollProp::SetFadeTime)
        .addProperty("LastOrigin", &GCRagdollProp::GetLastOrigin, &GCRagdollProp::SetLastOrigin)
        .addProperty("StrOriginClassName", &GCRagdollProp::GetStrOriginClassName, &GCRagdollProp::SetStrOriginClassName)
        .addProperty("StrSourceClassName", &GCRagdollProp::GetStrSourceClassName, &GCRagdollProp::SetStrSourceClassName)
        .addProperty("HasBeenPhysgunned", &GCRagdollProp::GetHasBeenPhysgunned, &GCRagdollProp::SetHasBeenPhysgunned)
        .addProperty("ShouldTeleportPhysics", &GCRagdollProp::GetShouldTeleportPhysics, &GCRagdollProp::SetShouldTeleportPhysics)
        .addProperty("BlendWeight", &GCRagdollProp::GetBlendWeight, &GCRagdollProp::SetBlendWeight)
        .addProperty("DefaultFadeScale", &GCRagdollProp::GetDefaultFadeScale, &GCRagdollProp::SetDefaultFadeScale)
        .addProperty("RagdollMins", &GCRagdollProp::GetRagdollMins, &GCRagdollProp::SetRagdollMins)
        .addProperty("RagdollMaxs", &GCRagdollProp::GetRagdollMaxs, &GCRagdollProp::SetRagdollMaxs)
        .addProperty("ShouldDeleteActivationRecord", &GCRagdollProp::GetShouldDeleteActivationRecord, &GCRagdollProp::SetShouldDeleteActivationRecord)
        .addProperty("ValidatePoweredRagdollPose", &GCRagdollProp::GetValidatePoweredRagdollPose, &GCRagdollProp::SetValidatePoweredRagdollPose)
        .endClass();
}