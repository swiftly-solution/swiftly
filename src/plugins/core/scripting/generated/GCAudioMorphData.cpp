#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAudioMorphData::GCAudioMorphData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAudioMorphData::GCAudioMorphData(void *ptr) {
    m_ptr = ptr;
}
std::vector<float32> GCAudioMorphData::GetTimes() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CAudioMorphData", "m_times"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAudioMorphData::SetTimes(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CAudioMorphData", "m_times", false, value);
}
std::vector<uint32> GCAudioMorphData::GetNameHashCodes() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CAudioMorphData", "m_nameHashCodes"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAudioMorphData::SetNameHashCodes(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CAudioMorphData", "m_nameHashCodes", false, value);
}
std::vector<CUtlString> GCAudioMorphData::GetNameStrings() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "CAudioMorphData", "m_nameStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAudioMorphData::SetNameStrings(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "CAudioMorphData", "m_nameStrings", false, value);
}
float GCAudioMorphData::GetEaseIn() const {
    return GetSchemaValue<float>(m_ptr, "CAudioMorphData", "m_flEaseIn");
}
void GCAudioMorphData::SetEaseIn(float value) {
    SetSchemaValue(m_ptr, "CAudioMorphData", "m_flEaseIn", false, value);
}
float GCAudioMorphData::GetEaseOut() const {
    return GetSchemaValue<float>(m_ptr, "CAudioMorphData", "m_flEaseOut");
}
void GCAudioMorphData::SetEaseOut(float value) {
    SetSchemaValue(m_ptr, "CAudioMorphData", "m_flEaseOut", false, value);
}
std::string GCAudioMorphData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAudioMorphData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAudioMorphData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioMorphData>("CAudioMorphData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Times", &GCAudioMorphData::GetTimes, &GCAudioMorphData::SetTimes)
        .addProperty("NameHashCodes", &GCAudioMorphData::GetNameHashCodes, &GCAudioMorphData::SetNameHashCodes)
        .addProperty("NameStrings", &GCAudioMorphData::GetNameStrings, &GCAudioMorphData::SetNameStrings)
        .addProperty("EaseIn", &GCAudioMorphData::GetEaseIn, &GCAudioMorphData::SetEaseIn)
        .addProperty("EaseOut", &GCAudioMorphData::GetEaseOut, &GCAudioMorphData::SetEaseOut)
        .addFunction("ToPtr", &GCAudioMorphData::ToPtr)
        .addFunction("IsValid", &GCAudioMorphData::IsValid)
        .endClass();
}