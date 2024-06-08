#include "../../../core/scripting/generated/classes/GCRagdollComponentUpdater.h"
#include "../core.h"

void SetupLuaClassGCRagdollComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollComponentUpdater>("CRagdollComponentUpdater")
        .addProperty("RagdollNodePaths", &GCRagdollComponentUpdater::GetRagdollNodePaths, &GCRagdollComponentUpdater::SetRagdollNodePaths)
        .addProperty("BoneIndices", &GCRagdollComponentUpdater::GetBoneIndices, &GCRagdollComponentUpdater::SetBoneIndices)
        .addProperty("BoneNames", &GCRagdollComponentUpdater::GetBoneNames, &GCRagdollComponentUpdater::SetBoneNames)
        .addProperty("WeightLists", &GCRagdollComponentUpdater::GetWeightLists, &GCRagdollComponentUpdater::SetWeightLists)
        .addProperty("SpringFrequencyMin", &GCRagdollComponentUpdater::GetSpringFrequencyMin, &GCRagdollComponentUpdater::SetSpringFrequencyMin)
        .addProperty("SpringFrequencyMax", &GCRagdollComponentUpdater::GetSpringFrequencyMax, &GCRagdollComponentUpdater::SetSpringFrequencyMax)
        .addProperty("MaxStretch", &GCRagdollComponentUpdater::GetMaxStretch, &GCRagdollComponentUpdater::SetMaxStretch)
        .addProperty("SolidCollisionAtZeroWeight", &GCRagdollComponentUpdater::GetSolidCollisionAtZeroWeight, &GCRagdollComponentUpdater::SetSolidCollisionAtZeroWeight)
        .endClass();
}