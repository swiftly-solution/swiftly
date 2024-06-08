#include "../../../core/scripting/generated/classes/GCBlockSelectionMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCBlockSelectionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlockSelectionMetricEvaluator>("CBlockSelectionMetricEvaluator")

        .endClass();
}