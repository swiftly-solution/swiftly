#include "../../../core/scripting/generated/classes/GCFutureFacingMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCFutureFacingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFutureFacingMetricEvaluator>("CFutureFacingMetricEvaluator")
        .addProperty("Distance", &GCFutureFacingMetricEvaluator::GetDistance, &GCFutureFacingMetricEvaluator::SetDistance)
        .addProperty("Time", &GCFutureFacingMetricEvaluator::GetTime, &GCFutureFacingMetricEvaluator::SetTime)
        .endClass();
}