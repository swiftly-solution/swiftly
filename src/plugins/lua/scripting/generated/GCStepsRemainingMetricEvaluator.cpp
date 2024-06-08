#include "../../../core/scripting/generated/classes/GCStepsRemainingMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCStepsRemainingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStepsRemainingMetricEvaluator>("CStepsRemainingMetricEvaluator")
        .addProperty("FootIndices", &GCStepsRemainingMetricEvaluator::GetFootIndices, &GCStepsRemainingMetricEvaluator::SetFootIndices)
        .addProperty("MinStepsRemaining", &GCStepsRemainingMetricEvaluator::GetMinStepsRemaining, &GCStepsRemainingMetricEvaluator::SetMinStepsRemaining)
        .endClass();
}