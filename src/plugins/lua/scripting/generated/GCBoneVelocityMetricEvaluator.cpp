#include "../../../core/scripting/generated/classes/GCBoneVelocityMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCBoneVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneVelocityMetricEvaluator>("CBoneVelocityMetricEvaluator")
        .addProperty("BoneIndex", &GCBoneVelocityMetricEvaluator::GetBoneIndex, &GCBoneVelocityMetricEvaluator::SetBoneIndex)
        .endClass();
}