#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRenderSkeleton::GCRenderSkeleton(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRenderSkeleton::GCRenderSkeleton(void *ptr) {
    m_ptr = ptr;
}
std::vector<GRenderSkeletonBone_t> GCRenderSkeleton::GetBones() const {
    CUtlVector<GRenderSkeletonBone_t>* vec = GetSchemaValue<CUtlVector<GRenderSkeletonBone_t>*>(m_ptr, "CRenderSkeleton", "m_bones"); std::vector<GRenderSkeletonBone_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRenderSkeleton::SetBones(std::vector<GRenderSkeletonBone_t> value) {
    SetSchemaValueCUtlVector<GRenderSkeletonBone_t>(m_ptr, "CRenderSkeleton", "m_bones", false, value);
}
std::vector<int32> GCRenderSkeleton::GetBoneParents() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CRenderSkeleton", "m_boneParents"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRenderSkeleton::SetBoneParents(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CRenderSkeleton", "m_boneParents", false, value);
}
int32_t GCRenderSkeleton::GetBoneWeightCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CRenderSkeleton", "m_nBoneWeightCount");
}
void GCRenderSkeleton::SetBoneWeightCount(int32_t value) {
    SetSchemaValue(m_ptr, "CRenderSkeleton", "m_nBoneWeightCount", false, value);
}
std::string GCRenderSkeleton::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRenderSkeleton::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRenderSkeleton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderSkeleton>("CRenderSkeleton")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Bones", &GCRenderSkeleton::GetBones, &GCRenderSkeleton::SetBones)
        .addProperty("BoneParents", &GCRenderSkeleton::GetBoneParents, &GCRenderSkeleton::SetBoneParents)
        .addProperty("BoneWeightCount", &GCRenderSkeleton::GetBoneWeightCount, &GCRenderSkeleton::SetBoneWeightCount)
        .addFunction("ToPtr", &GCRenderSkeleton::ToPtr)
        .addFunction("IsValid", &GCRenderSkeleton::IsValid)
        .endClass();
}