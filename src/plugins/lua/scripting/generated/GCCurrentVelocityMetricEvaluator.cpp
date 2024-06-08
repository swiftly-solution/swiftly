#include "../../../core/scripting/generated/classes/GCCurrentVelocityMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCCurrentVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCurrentVelocityMetricEvaluator>("CCurrentVelocityMetricEvaluator")

        .endClass();
}