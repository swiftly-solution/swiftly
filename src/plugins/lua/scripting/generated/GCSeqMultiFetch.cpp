#include "../../../core/scripting/generated/classes/GCSeqMultiFetch.h"
#include "../core.h"

void SetupLuaClassGCSeqMultiFetch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqMultiFetch>("CSeqMultiFetch")
        .addProperty("Flags", &GCSeqMultiFetch::GetFlags, &GCSeqMultiFetch::SetFlags)
        .addProperty("LocalReferenceArray", &GCSeqMultiFetch::GetLocalReferenceArray, &GCSeqMultiFetch::SetLocalReferenceArray)
        .addProperty("GroupSize", &GCSeqMultiFetch::GetGroupSize, &GCSeqMultiFetch::SetGroupSize)
        .addProperty("LocalPose", &GCSeqMultiFetch::GetLocalPose, &GCSeqMultiFetch::SetLocalPose)
        .addProperty("PoseKeyArray0", &GCSeqMultiFetch::GetPoseKeyArray0, &GCSeqMultiFetch::SetPoseKeyArray0)
        .addProperty("PoseKeyArray1", &GCSeqMultiFetch::GetPoseKeyArray1, &GCSeqMultiFetch::SetPoseKeyArray1)
        .addProperty("LocalCyclePoseParameter", &GCSeqMultiFetch::GetLocalCyclePoseParameter, &GCSeqMultiFetch::SetLocalCyclePoseParameter)
        .addProperty("CalculatePoseParameters", &GCSeqMultiFetch::GetCalculatePoseParameters, &GCSeqMultiFetch::SetCalculatePoseParameters)
        .addProperty("FixedBlendWeight", &GCSeqMultiFetch::GetFixedBlendWeight, &GCSeqMultiFetch::SetFixedBlendWeight)
        .addProperty("FixedBlendWeightVals", &GCSeqMultiFetch::GetFixedBlendWeightVals, &GCSeqMultiFetch::SetFixedBlendWeightVals)
        .endClass();
}