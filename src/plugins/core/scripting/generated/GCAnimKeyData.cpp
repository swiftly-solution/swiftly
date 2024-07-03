#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimKeyData::GCAnimKeyData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimKeyData::GCAnimKeyData(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimKeyData::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimKeyData", "m_name");
}
void GCAnimKeyData::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimKeyData", "m_name", false, value);
}
std::vector<GCAnimBone> GCAnimKeyData::GetBoneArray() const {
    CUtlVector<GCAnimBone>* vec = GetSchemaValue<CUtlVector<GCAnimBone>*>(m_ptr, "CAnimKeyData", "m_boneArray"); std::vector<GCAnimBone> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimKeyData::SetBoneArray(std::vector<GCAnimBone> value) {
    SetSchemaValueCUtlVector<GCAnimBone>(m_ptr, "CAnimKeyData", "m_boneArray", false, value);
}
std::vector<GCAnimUser> GCAnimKeyData::GetUserArray() const {
    CUtlVector<GCAnimUser>* vec = GetSchemaValue<CUtlVector<GCAnimUser>*>(m_ptr, "CAnimKeyData", "m_userArray"); std::vector<GCAnimUser> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimKeyData::SetUserArray(std::vector<GCAnimUser> value) {
    SetSchemaValueCUtlVector<GCAnimUser>(m_ptr, "CAnimKeyData", "m_userArray", false, value);
}
std::vector<CBufferString> GCAnimKeyData::GetMorphArray() const {
    CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CAnimKeyData", "m_morphArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimKeyData::SetMorphArray(std::vector<CBufferString> value) {
    SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CAnimKeyData", "m_morphArray", false, value);
}
int32_t GCAnimKeyData::GetChannelElements() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimKeyData", "m_nChannelElements");
}
void GCAnimKeyData::SetChannelElements(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimKeyData", "m_nChannelElements", false, value);
}
std::vector<GCAnimDataChannelDesc> GCAnimKeyData::GetDataChannelArray() const {
    CUtlVector<GCAnimDataChannelDesc>* vec = GetSchemaValue<CUtlVector<GCAnimDataChannelDesc>*>(m_ptr, "CAnimKeyData", "m_dataChannelArray"); std::vector<GCAnimDataChannelDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimKeyData::SetDataChannelArray(std::vector<GCAnimDataChannelDesc> value) {
    SetSchemaValueCUtlVector<GCAnimDataChannelDesc>(m_ptr, "CAnimKeyData", "m_dataChannelArray", false, value);
}
std::string GCAnimKeyData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimKeyData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimKeyData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimKeyData>("CAnimKeyData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimKeyData::GetName, &GCAnimKeyData::SetName)
        .addProperty("BoneArray", &GCAnimKeyData::GetBoneArray, &GCAnimKeyData::SetBoneArray)
        .addProperty("UserArray", &GCAnimKeyData::GetUserArray, &GCAnimKeyData::SetUserArray)
        .addProperty("MorphArray", &GCAnimKeyData::GetMorphArray, &GCAnimKeyData::SetMorphArray)
        .addProperty("ChannelElements", &GCAnimKeyData::GetChannelElements, &GCAnimKeyData::SetChannelElements)
        .addProperty("DataChannelArray", &GCAnimKeyData::GetDataChannelArray, &GCAnimKeyData::SetDataChannelArray)
        .addFunction("ToPtr", &GCAnimKeyData::ToPtr)
        .addFunction("IsValid", &GCAnimKeyData::IsValid)
        .endClass();
}