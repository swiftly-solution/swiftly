#include "../../../core/scripting/generated/classes/GC_OP_SetChildControlPoints.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetChildControlPoints(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetChildControlPoints>("C_OP_SetChildControlPoints")
        .addProperty("ChildGroupID", &GC_OP_SetChildControlPoints::GetChildGroupID, &GC_OP_SetChildControlPoints::SetChildGroupID)
        .addProperty("FirstControlPoint", &GC_OP_SetChildControlPoints::GetFirstControlPoint, &GC_OP_SetChildControlPoints::SetFirstControlPoint)
        .addProperty("NumControlPoints", &GC_OP_SetChildControlPoints::GetNumControlPoints, &GC_OP_SetChildControlPoints::SetNumControlPoints)
        .addProperty("FirstSourcePoint", &GC_OP_SetChildControlPoints::GetFirstSourcePoint, &GC_OP_SetChildControlPoints::SetFirstSourcePoint)
        .addProperty("Reverse", &GC_OP_SetChildControlPoints::GetReverse, &GC_OP_SetChildControlPoints::SetReverse)
        .addProperty("SetOrientation", &GC_OP_SetChildControlPoints::GetSetOrientation, &GC_OP_SetChildControlPoints::SetSetOrientation)
        .endClass();
}