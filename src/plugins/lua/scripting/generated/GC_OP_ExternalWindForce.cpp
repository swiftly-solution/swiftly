#include "../../../core/scripting/generated/classes/GC_OP_ExternalWindForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_ExternalWindForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ExternalWindForce>("C_OP_ExternalWindForce")
        .addProperty("SamplePosition", &GC_OP_ExternalWindForce::GetSamplePosition, &GC_OP_ExternalWindForce::SetSamplePosition)
        .addProperty("Scale", &GC_OP_ExternalWindForce::GetScale, &GC_OP_ExternalWindForce::SetScale)
        .addProperty("SampleWind", &GC_OP_ExternalWindForce::GetSampleWind, &GC_OP_ExternalWindForce::SetSampleWind)
        .addProperty("SampleWater", &GC_OP_ExternalWindForce::GetSampleWater, &GC_OP_ExternalWindForce::SetSampleWater)
        .addProperty("DampenNearWaterPlane", &GC_OP_ExternalWindForce::GetDampenNearWaterPlane, &GC_OP_ExternalWindForce::SetDampenNearWaterPlane)
        .addProperty("SampleGravity", &GC_OP_ExternalWindForce::GetSampleGravity, &GC_OP_ExternalWindForce::SetSampleGravity)
        .addProperty("GravityForce", &GC_OP_ExternalWindForce::GetGravityForce, &GC_OP_ExternalWindForce::SetGravityForce)
        .addProperty("UseBasicMovementGravity", &GC_OP_ExternalWindForce::GetUseBasicMovementGravity, &GC_OP_ExternalWindForce::SetUseBasicMovementGravity)
        .addProperty("LocalGravityScale", &GC_OP_ExternalWindForce::GetLocalGravityScale, &GC_OP_ExternalWindForce::SetLocalGravityScale)
        .addProperty("LocalBuoyancyScale", &GC_OP_ExternalWindForce::GetLocalBuoyancyScale, &GC_OP_ExternalWindForce::SetLocalBuoyancyScale)
        .addProperty("BuoyancyForce", &GC_OP_ExternalWindForce::GetBuoyancyForce, &GC_OP_ExternalWindForce::SetBuoyancyForce)
        .endClass();
}