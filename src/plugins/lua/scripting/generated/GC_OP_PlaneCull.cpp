#include "../../../core/scripting/generated/classes/GC_OP_PlaneCull.h"
#include "../core.h"

void SetupLuaClassGC_OP_PlaneCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_PlaneCull>("C_OP_PlaneCull")
        .addProperty("PlaneControlPoint", &GC_OP_PlaneCull::GetPlaneControlPoint, &GC_OP_PlaneCull::SetPlaneControlPoint)
        .addProperty("PlaneDirection", &GC_OP_PlaneCull::GetPlaneDirection, &GC_OP_PlaneCull::SetPlaneDirection)
        .addProperty("LocalSpace", &GC_OP_PlaneCull::GetLocalSpace, &GC_OP_PlaneCull::SetLocalSpace)
        .addProperty("PlaneOffset", &GC_OP_PlaneCull::GetPlaneOffset, &GC_OP_PlaneCull::SetPlaneOffset)
        .endClass();
}