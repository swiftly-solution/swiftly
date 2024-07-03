#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollComponentUpdater::GCRagdollComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollComponentUpdater::GCRagdollComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCAnimNodePath> GCRagdollComponentUpdater::GetRagdollNodePaths() const {
    CUtlVector<GCAnimNodePath>* vec = GetSchemaValue<CUtlVector<GCAnimNodePath>*>(m_ptr, "CRagdollComponentUpdater", "m_ragdollNodePaths"); std::vector<GCAnimNodePath> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollComponentUpdater::SetRagdollNodePaths(std::vector<GCAnimNodePath> value) {
    SetSchemaValueCUtlVector<GCAnimNodePath>(m_ptr, "CRagdollComponentUpdater", "m_ragdollNodePaths", false, value);
}
std::vector<int32> GCRagdollComponentUpdater::GetBoneIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CRagdollComponentUpdater", "m_boneIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollComponentUpdater::SetBoneIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CRagdollComponentUpdater", "m_boneIndices", false, value);
}
std::vector<CUtlString> GCRagdollComponentUpdater::GetBoneNames() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CRagdollComponentUpdater", "m_boneNames"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollComponentUpdater::SetBoneNames(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CRagdollComponentUpdater", "m_boneNames", false, value);
}
std::vector<GWeightList> GCRagdollComponentUpdater::GetWeightLists() const {
    CUtlVector<GWeightList>* vec = GetSchemaValue<CUtlVector<GWeightList>*>(m_ptr, "CRagdollComponentUpdater", "m_weightLists"); std::vector<GWeightList> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRagdollComponentUpdater::SetWeightLists(std::vector<GWeightList> value) {
    SetSchemaValueCUtlVector<GWeightList>(m_ptr, "CRagdollComponentUpdater", "m_weightLists", false, value);
}
float GCRagdollComponentUpdater::GetSpringFrequencyMin() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMin");
}
void GCRagdollComponentUpdater::SetSpringFrequencyMin(float value) {
    SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMin", false, value);
}
float GCRagdollComponentUpdater::GetSpringFrequencyMax() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMax");
}
void GCRagdollComponentUpdater::SetSpringFrequencyMax(float value) {
    SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_flSpringFrequencyMax", false, value);
}
float GCRagdollComponentUpdater::GetMaxStretch() const {
    return GetSchemaValue<float>(m_ptr, "CRagdollComponentUpdater", "m_flMaxStretch");
}
void GCRagdollComponentUpdater::SetMaxStretch(float value) {
    SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_flMaxStretch", false, value);
}
bool GCRagdollComponentUpdater::GetSolidCollisionAtZeroWeight() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollComponentUpdater", "m_bSolidCollisionAtZeroWeight");
}
void GCRagdollComponentUpdater::SetSolidCollisionAtZeroWeight(bool value) {
    SetSchemaValue(m_ptr, "CRagdollComponentUpdater", "m_bSolidCollisionAtZeroWeight", false, value);
}
std::string GCRagdollComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCRagdollComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCRagdollComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollComponentUpdater>("CRagdollComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RagdollNodePaths", &GCRagdollComponentUpdater::GetRagdollNodePaths, &GCRagdollComponentUpdater::SetRagdollNodePaths)
        .addProperty("BoneIndices", &GCRagdollComponentUpdater::GetBoneIndices, &GCRagdollComponentUpdater::SetBoneIndices)
        .addProperty("BoneNames", &GCRagdollComponentUpdater::GetBoneNames, &GCRagdollComponentUpdater::SetBoneNames)
        .addProperty("WeightLists", &GCRagdollComponentUpdater::GetWeightLists, &GCRagdollComponentUpdater::SetWeightLists)
        .addProperty("SpringFrequencyMin", &GCRagdollComponentUpdater::GetSpringFrequencyMin, &GCRagdollComponentUpdater::SetSpringFrequencyMin)
        .addProperty("SpringFrequencyMax", &GCRagdollComponentUpdater::GetSpringFrequencyMax, &GCRagdollComponentUpdater::SetSpringFrequencyMax)
        .addProperty("MaxStretch", &GCRagdollComponentUpdater::GetMaxStretch, &GCRagdollComponentUpdater::SetMaxStretch)
        .addProperty("SolidCollisionAtZeroWeight", &GCRagdollComponentUpdater::GetSolidCollisionAtZeroWeight, &GCRagdollComponentUpdater::SetSolidCollisionAtZeroWeight)
        .addProperty("Parent", &GCRagdollComponentUpdater::GetParent, &GCRagdollComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCRagdollComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCRagdollComponentUpdater::IsValid)
        .endClass();
}