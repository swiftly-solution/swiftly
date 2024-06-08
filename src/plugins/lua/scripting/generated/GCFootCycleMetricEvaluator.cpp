#include "../../../core/scripting/generated/classes/GCFootCycleMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCFootCycleMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootCycleMetricEvaluator>("CFootCycleMetricEvaluator")
        .addProperty("FootIndices", &GCFootCycleMetricEvaluator::GetFootIndices, &GCFootCycleMetricEvaluator::SetFootIndices)
        .endClass();
}