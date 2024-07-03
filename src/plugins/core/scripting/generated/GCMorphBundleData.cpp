#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMorphBundleData::GCMorphBundleData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMorphBundleData::GCMorphBundleData(void *ptr) {
    m_ptr = ptr;
}
float GCMorphBundleData::GetULeftSrc() const {
    return GetSchemaValue<float>(m_ptr, "CMorphBundleData", "m_flULeftSrc");
}
void GCMorphBundleData::SetULeftSrc(float value) {
    SetSchemaValue(m_ptr, "CMorphBundleData", "m_flULeftSrc", false, value);
}
float GCMorphBundleData::GetVTopSrc() const {
    return GetSchemaValue<float>(m_ptr, "CMorphBundleData", "m_flVTopSrc");
}
void GCMorphBundleData::SetVTopSrc(float value) {
    SetSchemaValue(m_ptr, "CMorphBundleData", "m_flVTopSrc", false, value);
}
std::vector<float32> GCMorphBundleData::GetOffsets() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMorphBundleData", "m_offsets"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphBundleData::SetOffsets(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CMorphBundleData", "m_offsets", false, value);
}
std::vector<float32> GCMorphBundleData::GetRanges() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMorphBundleData", "m_ranges"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphBundleData::SetRanges(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CMorphBundleData", "m_ranges", false, value);
}
std::string GCMorphBundleData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMorphBundleData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMorphBundleData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphBundleData>("CMorphBundleData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ULeftSrc", &GCMorphBundleData::GetULeftSrc, &GCMorphBundleData::SetULeftSrc)
        .addProperty("VTopSrc", &GCMorphBundleData::GetVTopSrc, &GCMorphBundleData::SetVTopSrc)
        .addProperty("Offsets", &GCMorphBundleData::GetOffsets, &GCMorphBundleData::SetOffsets)
        .addProperty("Ranges", &GCMorphBundleData::GetRanges, &GCMorphBundleData::SetRanges)
        .addFunction("ToPtr", &GCMorphBundleData::ToPtr)
        .addFunction("IsValid", &GCMorphBundleData::IsValid)
        .endClass();
}