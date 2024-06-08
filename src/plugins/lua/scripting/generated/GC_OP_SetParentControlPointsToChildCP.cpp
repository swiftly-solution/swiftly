#include "../../../core/scripting/generated/classes/GC_OP_SetParentControlPointsToChildCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetParentControlPointsToChildCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetParentControlPointsToChildCP>("C_OP_SetParentControlPointsToChildCP")
        .addProperty("ChildGroupID", &GC_OP_SetParentControlPointsToChildCP::GetChildGroupID, &GC_OP_SetParentControlPointsToChildCP::SetChildGroupID)
        .addProperty("ChildControlPoint", &GC_OP_SetParentControlPointsToChildCP::GetChildControlPoint, &GC_OP_SetParentControlPointsToChildCP::SetChildControlPoint)
        .addProperty("NumControlPoints", &GC_OP_SetParentControlPointsToChildCP::GetNumControlPoints, &GC_OP_SetParentControlPointsToChildCP::SetNumControlPoints)
        .addProperty("FirstSourcePoint", &GC_OP_SetParentControlPointsToChildCP::GetFirstSourcePoint, &GC_OP_SetParentControlPointsToChildCP::SetFirstSourcePoint)
        .addProperty("SetOrientation", &GC_OP_SetParentControlPointsToChildCP::GetSetOrientation, &GC_OP_SetParentControlPointsToChildCP::SetSetOrientation)
        .endClass();
}