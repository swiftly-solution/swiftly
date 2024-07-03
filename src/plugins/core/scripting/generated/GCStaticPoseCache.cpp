#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStaticPoseCache::GCStaticPoseCache(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStaticPoseCache::GCStaticPoseCache(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCCachedPose> GCStaticPoseCache::GetPoses() const {
    CUtlVector<GCCachedPose>* vec = GetSchemaValue<CUtlVector<GCCachedPose>*>(m_ptr, "CStaticPoseCache", "m_poses"); std::vector<GCCachedPose> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCStaticPoseCache::SetPoses(std::vector<GCCachedPose> value) {
    SetSchemaValueCUtlVector<GCCachedPose>(m_ptr, "CStaticPoseCache", "m_poses", false, value);
}
int32_t GCStaticPoseCache::GetBoneCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CStaticPoseCache", "m_nBoneCount");
}
void GCStaticPoseCache::SetBoneCount(int32_t value) {
    SetSchemaValue(m_ptr, "CStaticPoseCache", "m_nBoneCount", false, value);
}
int32_t GCStaticPoseCache::GetMorphCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CStaticPoseCache", "m_nMorphCount");
}
void GCStaticPoseCache::SetMorphCount(int32_t value) {
    SetSchemaValue(m_ptr, "CStaticPoseCache", "m_nMorphCount", false, value);
}
std::string GCStaticPoseCache::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStaticPoseCache::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCStaticPoseCache(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStaticPoseCache>("CStaticPoseCache")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Poses", &GCStaticPoseCache::GetPoses, &GCStaticPoseCache::SetPoses)
        .addProperty("BoneCount", &GCStaticPoseCache::GetBoneCount, &GCStaticPoseCache::SetBoneCount)
        .addProperty("MorphCount", &GCStaticPoseCache::GetMorphCount, &GCStaticPoseCache::SetMorphCount)
        .addFunction("ToPtr", &GCStaticPoseCache::ToPtr)
        .addFunction("IsValid", &GCStaticPoseCache::IsValid)
        .endClass();
}