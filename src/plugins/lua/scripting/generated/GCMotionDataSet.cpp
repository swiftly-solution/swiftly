#include "../../../core/scripting/generated/classes/GCMotionDataSet.h"
#include "../core.h"

void SetupLuaClassGCMotionDataSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionDataSet>("CMotionDataSet")
        .addProperty("Groups", &GCMotionDataSet::GetGroups, &GCMotionDataSet::SetGroups)
        .addProperty("DimensionCount", &GCMotionDataSet::GetDimensionCount, &GCMotionDataSet::SetDimensionCount)
        .endClass();
}