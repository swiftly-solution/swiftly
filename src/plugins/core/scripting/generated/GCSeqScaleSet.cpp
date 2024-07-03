#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqScaleSet::GCSeqScaleSet(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqScaleSet::GCSeqScaleSet(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSeqScaleSet::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqScaleSet", "m_sName");
}
void GCSeqScaleSet::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqScaleSet", "m_sName", false, value);
}
bool GCSeqScaleSet::GetRootOffset() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqScaleSet", "m_bRootOffset");
}
void GCSeqScaleSet::SetRootOffset(bool value) {
    SetSchemaValue(m_ptr, "CSeqScaleSet", "m_bRootOffset", false, value);
}
Vector GCSeqScaleSet::GetRootOffset1() const {
    return GetSchemaValue<Vector>(m_ptr, "CSeqScaleSet", "m_vRootOffset");
}
void GCSeqScaleSet::SetRootOffset1(Vector value) {
    SetSchemaValue(m_ptr, "CSeqScaleSet", "m_vRootOffset", false, value);
}
std::vector<int16> GCSeqScaleSet::GetLocalBoneArray() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CSeqScaleSet", "m_nLocalBoneArray"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqScaleSet::SetLocalBoneArray(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "CSeqScaleSet", "m_nLocalBoneArray", false, value);
}
std::vector<float32> GCSeqScaleSet::GetBoneScaleArray() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CSeqScaleSet", "m_flBoneScaleArray"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqScaleSet::SetBoneScaleArray(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CSeqScaleSet", "m_flBoneScaleArray", false, value);
}
std::string GCSeqScaleSet::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqScaleSet::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqScaleSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqScaleSet>("CSeqScaleSet")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSeqScaleSet::GetName, &GCSeqScaleSet::SetName)
        .addProperty("RootOffset", &GCSeqScaleSet::GetRootOffset, &GCSeqScaleSet::SetRootOffset)
        .addProperty("RootOffset1", &GCSeqScaleSet::GetRootOffset1, &GCSeqScaleSet::SetRootOffset1)
        .addProperty("LocalBoneArray", &GCSeqScaleSet::GetLocalBoneArray, &GCSeqScaleSet::SetLocalBoneArray)
        .addProperty("BoneScaleArray", &GCSeqScaleSet::GetBoneScaleArray, &GCSeqScaleSet::SetBoneScaleArray)
        .addFunction("ToPtr", &GCSeqScaleSet::ToPtr)
        .addFunction("IsValid", &GCSeqScaleSet::IsValid)
        .endClass();
}