#include "../../../core/scripting/generated/classes/GCPathMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCPathMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathMetricEvaluator>("CPathMetricEvaluator")
        .addProperty("PathTimeSamples", &GCPathMetricEvaluator::GetPathTimeSamples, &GCPathMetricEvaluator::SetPathTimeSamples)
        .addProperty("Distance", &GCPathMetricEvaluator::GetDistance, &GCPathMetricEvaluator::SetDistance)
        .addProperty("ExtrapolateMovement", &GCPathMetricEvaluator::GetExtrapolateMovement, &GCPathMetricEvaluator::SetExtrapolateMovement)
        .addProperty("MinExtrapolationSpeed", &GCPathMetricEvaluator::GetMinExtrapolationSpeed, &GCPathMetricEvaluator::SetMinExtrapolationSpeed)
        .endClass();
}