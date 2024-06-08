#include "../../../core/scripting/generated/classes/GCBonePositionMetricEvaluator.h"
#include "../core.h"

void SetupLuaClassGCBonePositionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBonePositionMetricEvaluator>("CBonePositionMetricEvaluator")
        .addProperty("BoneIndex", &GCBonePositionMetricEvaluator::GetBoneIndex, &GCBonePositionMetricEvaluator::SetBoneIndex)
        .endClass();
}