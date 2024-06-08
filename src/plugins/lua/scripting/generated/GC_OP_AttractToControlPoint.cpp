#include "../../../core/scripting/generated/classes/GC_OP_AttractToControlPoint.h"
#include "../core.h"

void SetupLuaClassGC_OP_AttractToControlPoint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_AttractToControlPoint>("C_OP_AttractToControlPoint")
        .addProperty("ComponentScale", &GC_OP_AttractToControlPoint::GetComponentScale, &GC_OP_AttractToControlPoint::SetComponentScale)
        .addProperty("ForceAmount", &GC_OP_AttractToControlPoint::GetForceAmount, &GC_OP_AttractToControlPoint::SetForceAmount)
        .addProperty("FalloffPower", &GC_OP_AttractToControlPoint::GetFalloffPower, &GC_OP_AttractToControlPoint::SetFalloffPower)
        .addProperty("TransformInput", &GC_OP_AttractToControlPoint::GetTransformInput, &GC_OP_AttractToControlPoint::SetTransformInput)
        .addProperty("ForceAmountMin", &GC_OP_AttractToControlPoint::GetForceAmountMin, &GC_OP_AttractToControlPoint::SetForceAmountMin)
        .addProperty("ApplyMinForce", &GC_OP_AttractToControlPoint::GetApplyMinForce, &GC_OP_AttractToControlPoint::SetApplyMinForce)
        .endClass();
}