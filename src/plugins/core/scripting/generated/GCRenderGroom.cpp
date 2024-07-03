#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRenderGroom::GCRenderGroom(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRenderGroom::GCRenderGroom(void *ptr) {
    m_ptr = ptr;
}
std::vector<GRenderHairStrandInfo_t> GCRenderGroom::GetHairs() const {
    CUtlVector<GRenderHairStrandInfo_t>* vec = GetSchemaValue<CUtlVector<GRenderHairStrandInfo_t>*>(m_ptr, "CRenderGroom", "m_hairs"); std::vector<GRenderHairStrandInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRenderGroom::SetHairs(std::vector<GRenderHairStrandInfo_t> value) {
    SetSchemaValueCUtlVector<GRenderHairStrandInfo_t>(m_ptr, "CRenderGroom", "m_hairs", false, value);
}
int32_t GCRenderGroom::GetSegmentsPerHairStrand() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nSegmentsPerHairStrand");
}
void GCRenderGroom::SetSegmentsPerHairStrand(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_nSegmentsPerHairStrand", false, value);
}
int32_t GCRenderGroom::GetGuideHairCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nGuideHairCount");
}
void GCRenderGroom::SetGuideHairCount(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_nGuideHairCount", false, value);
}
int32_t GCRenderGroom::GetHairCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nHairCount");
}
void GCRenderGroom::SetHairCount(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_nHairCount", false, value);
}
int32_t GCRenderGroom::GetGroomGroupID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nGroomGroupID");
}
void GCRenderGroom::SetGroomGroupID(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_nGroomGroupID", false, value);
}
int32_t GCRenderGroom::GetAttachBoneIdx() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nAttachBoneIdx");
}
void GCRenderGroom::SetAttachBoneIdx(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_nAttachBoneIdx", false, value);
}
int32_t GCRenderGroom::GetAttachMeshIdx() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nAttachMeshIdx");
}
void GCRenderGroom::SetAttachMeshIdx(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_nAttachMeshIdx", false, value);
}
int32_t GCRenderGroom::GetAttachMeshDrawCallIdx() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderGroom", "m_nAttachMeshDrawCallIdx");
}
void GCRenderGroom::SetAttachMeshDrawCallIdx(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_nAttachMeshDrawCallIdx", false, value);
}
float GCRenderGroom::GetSumOfAllHairLengths() const {
    return GetSchemaValue<float>(m_ptr, "CRenderGroom", "m_flSumOfAllHairLengths");
}
void GCRenderGroom::SetSumOfAllHairLengths(float value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_flSumOfAllHairLengths", false, value);
}
bool GCRenderGroom::GetEnableSimulation() const {
    return GetSchemaValue<bool>(m_ptr, "CRenderGroom", "m_bEnableSimulation");
}
void GCRenderGroom::SetEnableSimulation(bool value) {
    SetSchemaValue(m_ptr, "CRenderGroom", "m_bEnableSimulation", false, value);
}
std::string GCRenderGroom::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRenderGroom::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRenderGroom(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderGroom>("CRenderGroom")
        .addConstructor<void (*)(std::string)>()
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
        .addFunction("ToPtr", &GCRenderGroom::ToPtr)
        .addFunction("IsValid", &GCRenderGroom::IsValid)
        .endClass();
}