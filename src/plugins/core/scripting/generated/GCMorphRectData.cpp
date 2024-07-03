#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMorphRectData::GCMorphRectData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMorphRectData::GCMorphRectData(void *ptr) {
    m_ptr = ptr;
}
int16_t GCMorphRectData::GetXLeftDst() const {
    return GetSchemaValue<int16_t>(m_ptr, "CMorphRectData", "m_nXLeftDst");
}
void GCMorphRectData::SetXLeftDst(int16_t value) {
    SetSchemaValue(m_ptr, "CMorphRectData", "m_nXLeftDst", false, value);
}
int16_t GCMorphRectData::GetYTopDst() const {
    return GetSchemaValue<int16_t>(m_ptr, "CMorphRectData", "m_nYTopDst");
}
void GCMorphRectData::SetYTopDst(int16_t value) {
    SetSchemaValue(m_ptr, "CMorphRectData", "m_nYTopDst", false, value);
}
float GCMorphRectData::GetUWidthSrc() const {
    return GetSchemaValue<float>(m_ptr, "CMorphRectData", "m_flUWidthSrc");
}
void GCMorphRectData::SetUWidthSrc(float value) {
    SetSchemaValue(m_ptr, "CMorphRectData", "m_flUWidthSrc", false, value);
}
float GCMorphRectData::GetVHeightSrc() const {
    return GetSchemaValue<float>(m_ptr, "CMorphRectData", "m_flVHeightSrc");
}
void GCMorphRectData::SetVHeightSrc(float value) {
    SetSchemaValue(m_ptr, "CMorphRectData", "m_flVHeightSrc", false, value);
}
std::vector<GCMorphBundleData> GCMorphRectData::GetBundleDatas() const {
    CUtlVector<GCMorphBundleData>* vec = GetSchemaValue<CUtlVector<GCMorphBundleData>*>(m_ptr, "CMorphRectData", "m_bundleDatas"); std::vector<GCMorphBundleData> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMorphRectData::SetBundleDatas(std::vector<GCMorphBundleData> value) {
    SetSchemaValueCUtlVector<GCMorphBundleData>(m_ptr, "CMorphRectData", "m_bundleDatas", false, value);
}
std::string GCMorphRectData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMorphRectData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMorphRectData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphRectData>("CMorphRectData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("XLeftDst", &GCMorphRectData::GetXLeftDst, &GCMorphRectData::SetXLeftDst)
        .addProperty("YTopDst", &GCMorphRectData::GetYTopDst, &GCMorphRectData::SetYTopDst)
        .addProperty("UWidthSrc", &GCMorphRectData::GetUWidthSrc, &GCMorphRectData::SetUWidthSrc)
        .addProperty("VHeightSrc", &GCMorphRectData::GetVHeightSrc, &GCMorphRectData::SetVHeightSrc)
        .addProperty("BundleDatas", &GCMorphRectData::GetBundleDatas, &GCMorphRectData::SetBundleDatas)
        .addFunction("ToPtr", &GCMorphRectData::ToPtr)
        .addFunction("IsValid", &GCMorphRectData::IsValid)
        .endClass();
}