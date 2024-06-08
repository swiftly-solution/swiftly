#include "../../../core/scripting/generated/classes/GC_OP_SetCPOrientationToPointAtCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetCPOrientationToPointAtCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetCPOrientationToPointAtCP>("C_OP_SetCPOrientationToPointAtCP")
        .addProperty("InputCP", &GC_OP_SetCPOrientationToPointAtCP::GetInputCP, &GC_OP_SetCPOrientationToPointAtCP::SetInputCP)
        .addProperty("OutputCP", &GC_OP_SetCPOrientationToPointAtCP::GetOutputCP, &GC_OP_SetCPOrientationToPointAtCP::SetOutputCP)
        .addProperty("Interpolation", &GC_OP_SetCPOrientationToPointAtCP::GetInterpolation, &GC_OP_SetCPOrientationToPointAtCP::SetInterpolation)
        .addProperty("2DOrientation", &GC_OP_SetCPOrientationToPointAtCP::Get2DOrientation, &GC_OP_SetCPOrientationToPointAtCP::Set2DOrientation)
        .addProperty("AvoidSingularity", &GC_OP_SetCPOrientationToPointAtCP::GetAvoidSingularity, &GC_OP_SetCPOrientationToPointAtCP::SetAvoidSingularity)
        .addProperty("PointAway", &GC_OP_SetCPOrientationToPointAtCP::GetPointAway, &GC_OP_SetCPOrientationToPointAtCP::SetPointAway)
        .endClass();
}