#include "../../../core/scripting/generated/classes/GC_OP_ConstrainDistanceToUserSpecifiedPath.h"
#include "../core.h"

void SetupLuaClassGC_OP_ConstrainDistanceToUserSpecifiedPath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ConstrainDistanceToUserSpecifiedPath>("C_OP_ConstrainDistanceToUserSpecifiedPath")
        .addProperty("MinDistance", &GC_OP_ConstrainDistanceToUserSpecifiedPath::GetMinDistance, &GC_OP_ConstrainDistanceToUserSpecifiedPath::SetMinDistance)
        .addProperty("MaxDistance", &GC_OP_ConstrainDistanceToUserSpecifiedPath::GetMaxDistance, &GC_OP_ConstrainDistanceToUserSpecifiedPath::SetMaxDistance)
        .addProperty("TimeScale", &GC_OP_ConstrainDistanceToUserSpecifiedPath::GetTimeScale, &GC_OP_ConstrainDistanceToUserSpecifiedPath::SetTimeScale)
        .addProperty("LoopedPath", &GC_OP_ConstrainDistanceToUserSpecifiedPath::GetLoopedPath, &GC_OP_ConstrainDistanceToUserSpecifiedPath::SetLoopedPath)
        .addProperty("PointList", &GC_OP_ConstrainDistanceToUserSpecifiedPath::GetPointList, &GC_OP_ConstrainDistanceToUserSpecifiedPath::SetPointList)
        .endClass();
}