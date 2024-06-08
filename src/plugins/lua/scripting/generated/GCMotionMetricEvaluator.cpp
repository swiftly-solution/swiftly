#include "../../../core/scripting/generated/classes/GCMotionMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCMotionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionMetricEvaluator>("CMotionMetricEvaluator")
        .addProperty("Means", &GCMotionMetricEvaluator::GetMeans, &GCMotionMetricEvaluator::SetMeans)
        .addProperty("StandardDeviations", &GCMotionMetricEvaluator::GetStandardDeviations, &GCMotionMetricEvaluator::SetStandardDeviations)
        .addProperty("Weight", &GCMotionMetricEvaluator::GetWeight, &GCMotionMetricEvaluator::SetWeight)
        .addProperty("DimensionStartIndex", &GCMotionMetricEvaluator::GetDimensionStartIndex, &GCMotionMetricEvaluator::SetDimensionStartIndex)
        .endClass();
}