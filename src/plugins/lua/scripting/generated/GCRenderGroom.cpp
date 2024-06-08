#include "../../../core/scripting/generated/classes/GCRenderGroom.h"
#include "../core.h"

void SetupLuaClassGCRenderGroom(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderGroom>("CRenderGroom")
        .addProperty("Hairs", &GCRenderGroom::GetHairs, &GCRenderGroom::SetHairs)
        .addProperty("SegmentsPerHairStrand", &GCRenderGroom::GetSegmentsPerHairStrand, &GCRenderGroom::SetSegmentsPerHairStrand)
        .addProperty("GuideHairCount", &GCRenderGroom::GetGuideHairCount, &GCRenderGroom::SetGuideHairCount)
        .addProperty("HairCount", &GCRenderGroom::GetHairCount, &GCRenderGroom::SetHairCount)
        .addProperty("GroomGroupID", &GCRenderGroom::GetGroomGroupID, &GCRenderGroom::SetGroomGroupID)
        .addProperty("AttachBoneIdx", &GCRenderGroom::GetAttachBoneIdx, &GCRenderGroom::SetAttachBoneIdx)
        .addProperty("AttachMeshIdx", &GCRenderGroom::GetAttachMeshIdx, &GCRenderGroom::SetAttachMeshIdx)
        .addProperty("AttachMeshDrawCallIdx", &GCRenderGroom::GetAttachMeshDrawCallIdx, &GCRenderGroom::SetAttachMeshDrawCallIdx)
        .addProperty("SumOfAllHairLengths", &GCRenderGroom::GetSumOfAllHairLengths, &GCRenderGroom::SetSumOfAllHairLengths)
        .addProperty("EnableSimulation", &GCRenderGroom::GetEnableSimulation, &GCRenderGroom::SetEnableSimulation)
        .endClass();
}