#include "../../../core/scripting/generated/classes/GCTimeRemainingMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCTimeRemainingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTimeRemainingMetricEvaluator>("CTimeRemainingMetricEvaluator")
        .addProperty("MatchByTimeRemaining", &GCTimeRemainingMetricEvaluator::GetMatchByTimeRemaining, &GCTimeRemainingMetricEvaluator::SetMatchByTimeRemaining)
        .addProperty("MaxTimeRemaining", &GCTimeRemainingMetricEvaluator::GetMaxTimeRemaining, &GCTimeRemainingMetricEvaluator::SetMaxTimeRemaining)
        .addProperty("FilterByTimeRemaining", &GCTimeRemainingMetricEvaluator::GetFilterByTimeRemaining, &GCTimeRemainingMetricEvaluator::SetFilterByTimeRemaining)
        .addProperty("MinTimeRemaining", &GCTimeRemainingMetricEvaluator::GetMinTimeRemaining, &GCTimeRemainingMetricEvaluator::SetMinTimeRemaining)
        .endClass();
}