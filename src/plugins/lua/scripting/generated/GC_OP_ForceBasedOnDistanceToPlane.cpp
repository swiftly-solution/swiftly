#include "../../../core/scripting/generated/classes/GC_OP_ForceBasedOnDistanceToPlane.h"
#include "../core.h"

void SetupLuaClassGC_OP_ForceBasedOnDistanceToPlane(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ForceBasedOnDistanceToPlane>("C_OP_ForceBasedOnDistanceToPlane")
        .addProperty("MinDist", &GC_OP_ForceBasedOnDistanceToPlane::GetMinDist, &GC_OP_ForceBasedOnDistanceToPlane::SetMinDist)
        .addProperty("ForceAtMinDist", &GC_OP_ForceBasedOnDistanceToPlane::GetForceAtMinDist, &GC_OP_ForceBasedOnDistanceToPlane::SetForceAtMinDist)
        .addProperty("MaxDist", &GC_OP_ForceBasedOnDistanceToPlane::GetMaxDist, &GC_OP_ForceBasedOnDistanceToPlane::SetMaxDist)
        .addProperty("ForceAtMaxDist", &GC_OP_ForceBasedOnDistanceToPlane::GetForceAtMaxDist, &GC_OP_ForceBasedOnDistanceToPlane::SetForceAtMaxDist)
        .addProperty("PlaneNormal", &GC_OP_ForceBasedOnDistanceToPlane::GetPlaneNormal, &GC_OP_ForceBasedOnDistanceToPlane::SetPlaneNormal)
        .addProperty("ControlPointNumber", &GC_OP_ForceBasedOnDistanceToPlane::GetControlPointNumber, &GC_OP_ForceBasedOnDistanceToPlane::SetControlPointNumber)
        .addProperty("Exponent", &GC_OP_ForceBasedOnDistanceToPlane::GetExponent, &GC_OP_ForceBasedOnDistanceToPlane::SetExponent)
        .endClass();
}