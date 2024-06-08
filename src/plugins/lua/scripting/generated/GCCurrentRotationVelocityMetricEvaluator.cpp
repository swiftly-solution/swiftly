#include "../../../core/scripting/generated/classes/GCCurrentRotationVelocityMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCCurrentRotationVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCurrentRotationVelocityMetricEvaluator>("CCurrentRotationVelocityMetricEvaluator")

        .endClass();
}