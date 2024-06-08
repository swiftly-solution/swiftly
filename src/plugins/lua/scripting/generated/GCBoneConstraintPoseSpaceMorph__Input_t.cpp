#include "../../../core/scripting/generated/classes/GCBoneConstraintPoseSpaceMorph__Input_t.h"
#include "../core.h"

void SetupLuaClassGCBoneConstraintPoseSpaceMorph__Input_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceMorph__Input_t>("CBoneConstraintPoseSpaceMorph__Input_t")
        .addProperty("InputValue", &GCBoneConstraintPoseSpaceMorph__Input_t::GetInputValue, &GCBoneConstraintPoseSpaceMorph__Input_t::SetInputValue)
        .addProperty("OutputWeightList", &GCBoneConstraintPoseSpaceMorph__Input_t::GetOutputWeightList, &GCBoneConstraintPoseSpaceMorph__Input_t::SetOutputWeightList)
        .endClass();
}