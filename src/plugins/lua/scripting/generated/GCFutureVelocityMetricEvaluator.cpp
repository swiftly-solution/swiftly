#include "../../../core/scripting/generated/classes/GCFutureVelocityMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCFutureVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFutureVelocityMetricEvaluator>("CFutureVelocityMetricEvaluator")
        .addProperty("Distance", &GCFutureVelocityMetricEvaluator::GetDistance, &GCFutureVelocityMetricEvaluator::SetDistance)
        .addProperty("StoppingDistance", &GCFutureVelocityMetricEvaluator::GetStoppingDistance, &GCFutureVelocityMetricEvaluator::SetStoppingDistance)
        .addProperty("TargetSpeed", &GCFutureVelocityMetricEvaluator::GetTargetSpeed, &GCFutureVelocityMetricEvaluator::SetTargetSpeed)
        .addProperty("Mode", &GCFutureVelocityMetricEvaluator::GetMode, &GCFutureVelocityMetricEvaluator::SetMode)
        .endClass();
}