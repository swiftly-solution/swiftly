#include "../../../core/scripting/generated/classes/GCDistanceRemainingMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCDistanceRemainingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDistanceRemainingMetricEvaluator>("CDistanceRemainingMetricEvaluator")
        .addProperty("MaxDistance", &GCDistanceRemainingMetricEvaluator::GetMaxDistance, &GCDistanceRemainingMetricEvaluator::SetMaxDistance)
        .addProperty("MinDistance", &GCDistanceRemainingMetricEvaluator::GetMinDistance, &GCDistanceRemainingMetricEvaluator::SetMinDistance)
        .addProperty("StartGoalFilterDistance", &GCDistanceRemainingMetricEvaluator::GetStartGoalFilterDistance, &GCDistanceRemainingMetricEvaluator::SetStartGoalFilterDistance)
        .addProperty("MaxGoalOvershootScale", &GCDistanceRemainingMetricEvaluator::GetMaxGoalOvershootScale, &GCDistanceRemainingMetricEvaluator::SetMaxGoalOvershootScale)
        .addProperty("FilterFixedMinDistance", &GCDistanceRemainingMetricEvaluator::GetFilterFixedMinDistance, &GCDistanceRemainingMetricEvaluator::SetFilterFixedMinDistance)
        .addProperty("FilterGoalDistance", &GCDistanceRemainingMetricEvaluator::GetFilterGoalDistance, &GCDistanceRemainingMetricEvaluator::SetFilterGoalDistance)
        .addProperty("FilterGoalOvershoot", &GCDistanceRemainingMetricEvaluator::GetFilterGoalOvershoot, &GCDistanceRemainingMetricEvaluator::SetFilterGoalOvershoot)
        .endClass();
}