#include "../../../core/scripting/generated/classes/GC_INIT_PlaneCull.h"
#include "../core.h"

void SetupLuaClassGC_INIT_PlaneCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_PlaneCull>("C_INIT_PlaneCull")
        .addProperty("ControlPoint", &GC_INIT_PlaneCull::GetControlPoint, &GC_INIT_PlaneCull::SetControlPoint)
        .addProperty("Distance", &GC_INIT_PlaneCull::GetDistance, &GC_INIT_PlaneCull::SetDistance)
        .addProperty("CullInside", &GC_INIT_PlaneCull::GetCullInside, &GC_INIT_PlaneCull::SetCullInside)
        .endClass();
}