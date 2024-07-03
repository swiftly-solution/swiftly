#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoOffscreenPanoramaTexture::GCInfoOffscreenPanoramaTexture(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoOffscreenPanoramaTexture::GCInfoOffscreenPanoramaTexture(void *ptr) {
    m_ptr = ptr;
}
bool GCInfoOffscreenPanoramaTexture::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_bDisabled");
}
void GCInfoOffscreenPanoramaTexture::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_bDisabled", false, value);
}
int32_t GCInfoOffscreenPanoramaTexture::GetResolutionX() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionX");
}
void GCInfoOffscreenPanoramaTexture::SetResolutionX(int32_t value) {
    SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionX", false, value);
}
int32_t GCInfoOffscreenPanoramaTexture::GetResolutionY() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionY");
}
void GCInfoOffscreenPanoramaTexture::SetResolutionY(int32_t value) {
    SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nResolutionY", false, value);
}
std::string GCInfoOffscreenPanoramaTexture::GetLayoutFileName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szLayoutFileName").String();
}
void GCInfoOffscreenPanoramaTexture::SetLayoutFileName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szLayoutFileName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCInfoOffscreenPanoramaTexture::GetRenderAttrName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_RenderAttrName").String();
}
void GCInfoOffscreenPanoramaTexture::SetRenderAttrName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_RenderAttrName", false, CUtlSymbolLarge(value.c_str()));
}
std::vector<GCBaseModelEntity*> GCInfoOffscreenPanoramaTexture::GetTargetEntities() const {
    CUtlVector<GCBaseModelEntity*>* vec = GetSchemaValue<CUtlVector<GCBaseModelEntity*>*>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_TargetEntities"); std::vector<GCBaseModelEntity*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCInfoOffscreenPanoramaTexture::SetTargetEntities(std::vector<GCBaseModelEntity*> value) {
    SetSchemaValueCUtlVector<GCBaseModelEntity*>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_TargetEntities", false, value);
}
int32_t GCInfoOffscreenPanoramaTexture::GetTargetChangeCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nTargetChangeCount");
}
void GCInfoOffscreenPanoramaTexture::SetTargetChangeCount(int32_t value) {
    SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_nTargetChangeCount", false, value);
}
std::vector<CUtlSymbolLarge> GCInfoOffscreenPanoramaTexture::GetCSSClasses() const {
    CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_vecCSSClasses"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCInfoOffscreenPanoramaTexture::SetCSSClasses(std::vector<CUtlSymbolLarge> value) {
    SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_vecCSSClasses", false, value);
}
std::string GCInfoOffscreenPanoramaTexture::GetTargetsName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szTargetsName").String();
}
void GCInfoOffscreenPanoramaTexture::SetTargetsName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoOffscreenPanoramaTexture", "m_szTargetsName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCInfoOffscreenPanoramaTexture::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoOffscreenPanoramaTexture::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoOffscreenPanoramaTexture::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoOffscreenPanoramaTexture::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoOffscreenPanoramaTexture(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoOffscreenPanoramaTexture>("CInfoOffscreenPanoramaTexture")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCInfoOffscreenPanoramaTexture::GetDisabled, &GCInfoOffscreenPanoramaTexture::SetDisabled)
        .addProperty("ResolutionX", &GCInfoOffscreenPanoramaTexture::GetResolutionX, &GCInfoOffscreenPanoramaTexture::SetResolutionX)
        .addProperty("ResolutionY", &GCInfoOffscreenPanoramaTexture::GetResolutionY, &GCInfoOffscreenPanoramaTexture::SetResolutionY)
        .addProperty("LayoutFileName", &GCInfoOffscreenPanoramaTexture::GetLayoutFileName, &GCInfoOffscreenPanoramaTexture::SetLayoutFileName)
        .addProperty("RenderAttrName", &GCInfoOffscreenPanoramaTexture::GetRenderAttrName, &GCInfoOffscreenPanoramaTexture::SetRenderAttrName)
        .addProperty("TargetEntities", &GCInfoOffscreenPanoramaTexture::GetTargetEntities, &GCInfoOffscreenPanoramaTexture::SetTargetEntities)
        .addProperty("TargetChangeCount", &GCInfoOffscreenPanoramaTexture::GetTargetChangeCount, &GCInfoOffscreenPanoramaTexture::SetTargetChangeCount)
        .addProperty("CSSClasses", &GCInfoOffscreenPanoramaTexture::GetCSSClasses, &GCInfoOffscreenPanoramaTexture::SetCSSClasses)
        .addProperty("TargetsName", &GCInfoOffscreenPanoramaTexture::GetTargetsName, &GCInfoOffscreenPanoramaTexture::SetTargetsName)
        .addProperty("Parent", &GCInfoOffscreenPanoramaTexture::GetParent, &GCInfoOffscreenPanoramaTexture::SetParent)
        .addFunction("ToPtr", &GCInfoOffscreenPanoramaTexture::ToPtr)
        .addFunction("IsValid", &GCInfoOffscreenPanoramaTexture::IsValid)
        .endClass();
}