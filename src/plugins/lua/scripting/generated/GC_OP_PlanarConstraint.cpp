#include "../../../core/scripting/generated/classes/GC_OP_PlanarConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_PlanarConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PlanarConstraint>("C_OP_PlanarConstraint")
        .addProperty("PointOnPlane", &GC_OP_PlanarConstraint::GetPointOnPlane, &GC_OP_PlanarConstraint::SetPointOnPlane)
        .addProperty("PlaneNormal", &GC_OP_PlanarConstraint::GetPlaneNormal, &GC_OP_PlanarConstraint::SetPlaneNormal)
        .addProperty("ControlPointNumber", &GC_OP_PlanarConstraint::GetControlPointNumber, &GC_OP_PlanarConstraint::SetControlPointNumber)
        .addProperty("GlobalOrigin", &GC_OP_PlanarConstraint::GetGlobalOrigin, &GC_OP_PlanarConstraint::SetGlobalOrigin)
        .addProperty("GlobalNormal", &GC_OP_PlanarConstraint::GetGlobalNormal, &GC_OP_PlanarConstraint::SetGlobalNormal)
        .addProperty("RadiusScale", &GC_OP_PlanarConstraint::GetRadiusScale, &GC_OP_PlanarConstraint::SetRadiusScale)
        .addProperty("MaximumDistanceToCP", &GC_OP_PlanarConstraint::GetMaximumDistanceToCP, &GC_OP_PlanarConstraint::SetMaximumDistanceToCP)
        .addProperty("UseOldCode", &GC_OP_PlanarConstraint::GetUseOldCode, &GC_OP_PlanarConstraint::SetUseOldCode)
        .endClass();
}