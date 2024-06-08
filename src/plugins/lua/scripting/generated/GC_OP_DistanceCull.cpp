#include "../../../core/scripting/generated/classes/GC_OP_DistanceCull.h"
#include "../core.h"

void SetupLuaClassGC_OP_DistanceCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DistanceCull>("C_OP_DistanceCull")
        .addProperty("ControlPoint", &GC_OP_DistanceCull::GetControlPoint, &GC_OP_DistanceCull::SetControlPoint)
        .addProperty("PointOffset", &GC_OP_DistanceCull::GetPointOffset, &GC_OP_DistanceCull::SetPointOffset)
        .addProperty("Distance", &GC_OP_DistanceCull::GetDistance, &GC_OP_DistanceCull::SetDistance)
        .addProperty("CullInside", &GC_OP_DistanceCull::GetCullInside, &GC_OP_DistanceCull::SetCullInside)
        .endClass();
}