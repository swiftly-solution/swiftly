#include "../../../core/scripting/generated/classes/GCBoneConstraintPoseSpaceBone.h"
#include "../core.h"

void SetupLuaClassGCBoneConstraintPoseSpaceBone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceBone>("CBoneConstraintPoseSpaceBone")
        .addProperty("InputList", &GCBoneConstraintPoseSpaceBone::GetInputList, &GCBoneConstraintPoseSpaceBone::SetInputList)
        .endClass();
}