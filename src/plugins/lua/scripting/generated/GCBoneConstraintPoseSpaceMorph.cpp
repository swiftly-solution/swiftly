#include "../../../core/scripting/generated/classes/GCBoneConstraintPoseSpaceMorph.h"
#include "../core.h"

void SetupLuaClassGCBoneConstraintPoseSpaceMorph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneConstraintPoseSpaceMorph>("CBoneConstraintPoseSpaceMorph")
        .addProperty("BoneName", &GCBoneConstraintPoseSpaceMorph::GetBoneName, &GCBoneConstraintPoseSpaceMorph::SetBoneName)
        .addProperty("AttachmentName", &GCBoneConstraintPoseSpaceMorph::GetAttachmentName, &GCBoneConstraintPoseSpaceMorph::SetAttachmentName)
        .addProperty("OutputMorph", &GCBoneConstraintPoseSpaceMorph::GetOutputMorph, &GCBoneConstraintPoseSpaceMorph::SetOutputMorph)
        .addProperty("InputList", &GCBoneConstraintPoseSpaceMorph::GetInputList, &GCBoneConstraintPoseSpaceMorph::SetInputList)
        .addProperty("Clamp", &GCBoneConstraintPoseSpaceMorph::GetClamp, &GCBoneConstraintPoseSpaceMorph::SetClamp)
        .endClass();
}