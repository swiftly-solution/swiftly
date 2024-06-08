#include "../../../core/scripting/generated/classes/GC_INIT_DistanceCull.h"
#include "../core.h"

void SetupLuaClassGC_INIT_DistanceCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_DistanceCull>("C_INIT_DistanceCull")
        .addProperty("ControlPoint", &GC_INIT_DistanceCull::GetControlPoint, &GC_INIT_DistanceCull::SetControlPoint)
        .addProperty("Distance", &GC_INIT_DistanceCull::GetDistance, &GC_INIT_DistanceCull::SetDistance)
        .addProperty("CullInside", &GC_INIT_DistanceCull::GetCullInside, &GC_INIT_DistanceCull::SetCullInside)
        .endClass();
}