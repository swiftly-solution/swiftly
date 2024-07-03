#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqBoneMaskList::GCSeqBoneMaskList(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqBoneMaskList::GCSeqBoneMaskList(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSeqBoneMaskList::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqBoneMaskList", "m_sName");
}
void GCSeqBoneMaskList::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqBoneMaskList", "m_sName", false, value);
}
std::vector<int16> GCSeqBoneMaskList::GetLocalBoneArray() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CSeqBoneMaskList", "m_nLocalBoneArray"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqBoneMaskList::SetLocalBoneArray(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "CSeqBoneMaskList", "m_nLocalBoneArray", false, value);
}
std::vector<float32> GCSeqBoneMaskList::GetBoneWeightArray() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqBoneMaskList", "m_flBoneWeightArray"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqBoneMaskList::SetBoneWeightArray(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqBoneMaskList", "m_flBoneWeightArray", false, value);
}
float GCSeqBoneMaskList::GetDefaultMorphCtrlWeight() const {
    return GetSchemaValue<float>(m_ptr, "CSeqBoneMaskList", "m_flDefaultMorphCtrlWeight");
}
void GCSeqBoneMaskList::SetDefaultMorphCtrlWeight(float value) {
    SetSchemaValue(m_ptr, "CSeqBoneMaskList", "m_flDefaultMorphCtrlWeight", false, value);
}
std::string GCSeqBoneMaskList::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqBoneMaskList::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqBoneMaskList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqBoneMaskList>("CSeqBoneMaskList")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSeqBoneMaskList::GetName, &GCSeqBoneMaskList::SetName)
        .addProperty("LocalBoneArray", &GCSeqBoneMaskList::GetLocalBoneArray, &GCSeqBoneMaskList::SetLocalBoneArray)
        .addProperty("BoneWeightArray", &GCSeqBoneMaskList::GetBoneWeightArray, &GCSeqBoneMaskList::SetBoneWeightArray)
        .addProperty("DefaultMorphCtrlWeight", &GCSeqBoneMaskList::GetDefaultMorphCtrlWeight, &GCSeqBoneMaskList::SetDefaultMorphCtrlWeight)
        .addFunction("ToPtr", &GCSeqBoneMaskList::ToPtr)
        .addFunction("IsValid", &GCSeqBoneMaskList::IsValid)
        .endClass();
}