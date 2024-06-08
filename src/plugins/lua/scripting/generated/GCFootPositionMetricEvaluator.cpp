#include "../../../core/scripting/generated/classes/GCFootPositionMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCFootPositionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootPositionMetricEvaluator>("CFootPositionMetricEvaluator")
        .addProperty("FootIndices", &GCFootPositionMetricEvaluator::GetFootIndices, &GCFootPositionMetricEvaluator::SetFootIndices)
        .addProperty("IgnoreSlope", &GCFootPositionMetricEvaluator::GetIgnoreSlope, &GCFootPositionMetricEvaluator::SetIgnoreSlope)
        .endClass();
}