#include "../../../core/scripting/generated/classes/GCTriggerPhysics.h"
#include "../core.h"

void SetupLuaClassGCTriggerPhysics(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerPhysics>("CTriggerPhysics")
        .addProperty("GravityScale", &GCTriggerPhysics::GetGravityScale, &GCTriggerPhysics::SetGravityScale)
        .addProperty("LinearLimit", &GCTriggerPhysics::GetLinearLimit, &GCTriggerPhysics::SetLinearLimit)
        .addProperty("LinearDamping", &GCTriggerPhysics::GetLinearDamping, &GCTriggerPhysics::SetLinearDamping)
        .addProperty("AngularLimit", &GCTriggerPhysics::GetAngularLimit, &GCTriggerPhysics::SetAngularLimit)
        .addProperty("AngularDamping", &GCTriggerPhysics::GetAngularDamping, &GCTriggerPhysics::SetAngularDamping)
        .addProperty("LinearForce", &GCTriggerPhysics::GetLinearForce, &GCTriggerPhysics::SetLinearForce)
        .addProperty("Frequency", &GCTriggerPhysics::GetFrequency, &GCTriggerPhysics::SetFrequency)
        .addProperty("DampingRatio", &GCTriggerPhysics::GetDampingRatio, &GCTriggerPhysics::SetDampingRatio)
        .addProperty("LinearForcePointAt", &GCTriggerPhysics::GetLinearForcePointAt, &GCTriggerPhysics::SetLinearForcePointAt)
        .addProperty("CollapseToForcePoint", &GCTriggerPhysics::GetCollapseToForcePoint, &GCTriggerPhysics::SetCollapseToForcePoint)
        .addProperty("LinearForcePointAtWorld", &GCTriggerPhysics::GetLinearForcePointAtWorld, &GCTriggerPhysics::SetLinearForcePointAtWorld)
        .addProperty("LinearForceDirection", &GCTriggerPhysics::GetLinearForceDirection, &GCTriggerPhysics::SetLinearForceDirection)
        .addProperty("ConvertToDebrisWhenPossible", &GCTriggerPhysics::GetConvertToDebrisWhenPossible, &GCTriggerPhysics::SetConvertToDebrisWhenPossible)
        .endClass();
}