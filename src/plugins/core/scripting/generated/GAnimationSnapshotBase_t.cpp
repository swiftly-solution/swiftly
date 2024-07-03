#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAnimationSnapshotBase_t::GAnimationSnapshotBase_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAnimationSnapshotBase_t::GAnimationSnapshotBase_t(void *ptr) {
    m_ptr = ptr;
}
float GAnimationSnapshotBase_t::GetRealTime() const {
    return GetSchemaValue<float>(m_ptr, "AnimationSnapshotBase_t", "m_flRealTime");
}
void GAnimationSnapshotBase_t::SetRealTime(float value) {
    SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_flRealTime", true, value);
}
matrix3x4a_t GAnimationSnapshotBase_t::GetRootToWorld() const {
    return GetSchemaValue<matrix3x4a_t>(m_ptr, "AnimationSnapshotBase_t", "m_rootToWorld");
}
void GAnimationSnapshotBase_t::SetRootToWorld(matrix3x4a_t value) {
    SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_rootToWorld", true, value);
}
bool GAnimationSnapshotBase_t::GetBonesInWorldSpace() const {
    return GetSchemaValue<bool>(m_ptr, "AnimationSnapshotBase_t", "m_bBonesInWorldSpace");
}
void GAnimationSnapshotBase_t::SetBonesInWorldSpace(bool value) {
    SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_bBonesInWorldSpace", true, value);
}
std::vector<uint32> GAnimationSnapshotBase_t::GetBoneSetupMask() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "AnimationSnapshotBase_t", "m_boneSetupMask"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationSnapshotBase_t::SetBoneSetupMask(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "AnimationSnapshotBase_t", "m_boneSetupMask", true, value);
}
std::vector<matrix3x4a_t> GAnimationSnapshotBase_t::GetBoneTransforms() const {
    CUtlVector<matrix3x4a_t>* vec = GetSchemaValue<CUtlVector<matrix3x4a_t>*>(m_ptr, "AnimationSnapshotBase_t", "m_boneTransforms"); std::vector<matrix3x4a_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationSnapshotBase_t::SetBoneTransforms(std::vector<matrix3x4a_t> value) {
    SetSchemaValueCUtlVector<matrix3x4a_t>(m_ptr, "AnimationSnapshotBase_t", "m_boneTransforms", true, value);
}
std::vector<float32> GAnimationSnapshotBase_t::GetFlexControllers() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "AnimationSnapshotBase_t", "m_flexControllers"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GAnimationSnapshotBase_t::SetFlexControllers(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "AnimationSnapshotBase_t", "m_flexControllers", true, value);
}
uint64_t GAnimationSnapshotBase_t::GetSnapshotType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "AnimationSnapshotBase_t", "m_SnapshotType");
}
void GAnimationSnapshotBase_t::SetSnapshotType(uint64_t value) {
    SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_SnapshotType", true, value);
}
bool GAnimationSnapshotBase_t::GetHasDecodeDump() const {
    return GetSchemaValue<bool>(m_ptr, "AnimationSnapshotBase_t", "m_bHasDecodeDump");
}
void GAnimationSnapshotBase_t::SetHasDecodeDump(bool value) {
    SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_bHasDecodeDump", true, value);
}
GAnimationDecodeDebugDumpElement_t GAnimationSnapshotBase_t::GetDecodeDump() const {
    GAnimationDecodeDebugDumpElement_t value(GetSchemaPtr(m_ptr, "AnimationSnapshotBase_t", "m_DecodeDump"));
    return value;
}
void GAnimationSnapshotBase_t::SetDecodeDump(GAnimationDecodeDebugDumpElement_t value) {
    SetSchemaValue(m_ptr, "AnimationSnapshotBase_t", "m_DecodeDump", true, value);
}
std::string GAnimationSnapshotBase_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAnimationSnapshotBase_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAnimationSnapshotBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAnimationSnapshotBase_t>("AnimationSnapshotBase_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RealTime", &GAnimationSnapshotBase_t::GetRealTime, &GAnimationSnapshotBase_t::SetRealTime)
        .addProperty("RootToWorld", &GAnimationSnapshotBase_t::GetRootToWorld, &GAnimationSnapshotBase_t::SetRootToWorld)
        .addProperty("BonesInWorldSpace", &GAnimationSnapshotBase_t::GetBonesInWorldSpace, &GAnimationSnapshotBase_t::SetBonesInWorldSpace)
        .addProperty("BoneSetupMask", &GAnimationSnapshotBase_t::GetBoneSetupMask, &GAnimationSnapshotBase_t::SetBoneSetupMask)
        .addProperty("BoneTransforms", &GAnimationSnapshotBase_t::GetBoneTransforms, &GAnimationSnapshotBase_t::SetBoneTransforms)
        .addProperty("FlexControllers", &GAnimationSnapshotBase_t::GetFlexControllers, &GAnimationSnapshotBase_t::SetFlexControllers)
        .addProperty("SnapshotType", &GAnimationSnapshotBase_t::GetSnapshotType, &GAnimationSnapshotBase_t::SetSnapshotType)
        .addProperty("HasDecodeDump", &GAnimationSnapshotBase_t::GetHasDecodeDump, &GAnimationSnapshotBase_t::SetHasDecodeDump)
        .addProperty("DecodeDump", &GAnimationSnapshotBase_t::GetDecodeDump, &GAnimationSnapshotBase_t::SetDecodeDump)
        .addFunction("ToPtr", &GAnimationSnapshotBase_t::ToPtr)
        .addFunction("IsValid", &GAnimationSnapshotBase_t::IsValid)
        .endClass();
}