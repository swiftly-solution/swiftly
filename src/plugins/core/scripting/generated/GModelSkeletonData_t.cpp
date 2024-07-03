#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GModelSkeletonData_t::GModelSkeletonData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GModelSkeletonData_t::GModelSkeletonData_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<CUtlString> GModelSkeletonData_t::GetBoneName() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "ModelSkeletonData_t", "m_boneName"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GModelSkeletonData_t::SetBoneName(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "ModelSkeletonData_t", "m_boneName", true, value);
}
std::vector<int16> GModelSkeletonData_t::GetParent() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "ModelSkeletonData_t", "m_nParent"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GModelSkeletonData_t::SetParent(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "ModelSkeletonData_t", "m_nParent", true, value);
}
std::vector<float32> GModelSkeletonData_t::GetBoneSphere() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "ModelSkeletonData_t", "m_boneSphere"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GModelSkeletonData_t::SetBoneSphere(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "ModelSkeletonData_t", "m_boneSphere", true, value);
}
std::vector<uint32> GModelSkeletonData_t::GetFlag() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "ModelSkeletonData_t", "m_nFlag"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GModelSkeletonData_t::SetFlag(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "ModelSkeletonData_t", "m_nFlag", true, value);
}
std::vector<Vector> GModelSkeletonData_t::GetBonePosParent() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "ModelSkeletonData_t", "m_bonePosParent"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GModelSkeletonData_t::SetBonePosParent(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "ModelSkeletonData_t", "m_bonePosParent", true, value);
}
std::vector<float32> GModelSkeletonData_t::GetBoneScaleParent() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "ModelSkeletonData_t", "m_boneScaleParent"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GModelSkeletonData_t::SetBoneScaleParent(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "ModelSkeletonData_t", "m_boneScaleParent", true, value);
}
std::string GModelSkeletonData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GModelSkeletonData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassModelSkeletonData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelSkeletonData_t>("ModelSkeletonData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneName", &GModelSkeletonData_t::GetBoneName, &GModelSkeletonData_t::SetBoneName)
        .addProperty("Parent", &GModelSkeletonData_t::GetParent, &GModelSkeletonData_t::SetParent)
        .addProperty("BoneSphere", &GModelSkeletonData_t::GetBoneSphere, &GModelSkeletonData_t::SetBoneSphere)
        .addProperty("Flag", &GModelSkeletonData_t::GetFlag, &GModelSkeletonData_t::SetFlag)
        .addProperty("BonePosParent", &GModelSkeletonData_t::GetBonePosParent, &GModelSkeletonData_t::SetBonePosParent)
        .addProperty("BoneScaleParent", &GModelSkeletonData_t::GetBoneScaleParent, &GModelSkeletonData_t::SetBoneScaleParent)
        .addFunction("ToPtr", &GModelSkeletonData_t::ToPtr)
        .addFunction("IsValid", &GModelSkeletonData_t::IsValid)
        .endClass();
}