#include "../../../core/scripting/generated/classes/GCBoneConstraintPoseSpaceBone__Input_t.h"
#include "../core.h"

void SetupLuaClassGCBoneConstraintPoseSpaceBone__Input_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceBone__Input_t>("CBoneConstraintPoseSpaceBone__Input_t")
        .addProperty("InputValue", &GCBoneConstraintPoseSpaceBone__Input_t::GetInputValue, &GCBoneConstraintPoseSpaceBone__Input_t::SetInputValue)
        .endClass();
}