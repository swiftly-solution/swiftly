#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompositeMaterialInputLooseVariable_t::GCompositeMaterialInputLooseVariable_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompositeMaterialInputLooseVariable_t::GCompositeMaterialInputLooseVariable_t(void *ptr) {
    m_ptr = ptr;
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strName").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrName(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strName", true, CUtlString(value.c_str()));
}
bool GCompositeMaterialInputLooseVariable_t::GetExposeExternally() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposeExternally");
}
void GCompositeMaterialInputLooseVariable_t::SetExposeExternally(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposeExternally", true, value);
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrExposedFriendlyName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyName").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrExposedFriendlyName(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyName", true, CUtlString(value.c_str()));
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrExposedFriendlyGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyGroupName").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrExposedFriendlyGroupName(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedFriendlyGroupName", true, CUtlString(value.c_str()));
}
bool GCompositeMaterialInputLooseVariable_t::GetExposedVariableIsFixedRange() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposedVariableIsFixedRange");
}
void GCompositeMaterialInputLooseVariable_t::SetExposedVariableIsFixedRange(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bExposedVariableIsFixedRange", true, value);
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrExposedVisibleWhenTrue() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedVisibleWhenTrue").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrExposedVisibleWhenTrue(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedVisibleWhenTrue", true, CUtlString(value.c_str()));
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrExposedHiddenWhenTrue() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedHiddenWhenTrue").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrExposedHiddenWhenTrue(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strExposedHiddenWhenTrue", true, CUtlString(value.c_str()));
}
uint64_t GCompositeMaterialInputLooseVariable_t::GetVariableType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nVariableType");
}
void GCompositeMaterialInputLooseVariable_t::SetVariableType(uint64_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nVariableType", true, value);
}
bool GCompositeMaterialInputLooseVariable_t::GetValueBoolean() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bValueBoolean");
}
void GCompositeMaterialInputLooseVariable_t::SetValueBoolean(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bValueBoolean", true, value);
}
int32_t GCompositeMaterialInputLooseVariable_t::GetValueIntX() const {
    return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntX");
}
void GCompositeMaterialInputLooseVariable_t::SetValueIntX(int32_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntX", true, value);
}
int32_t GCompositeMaterialInputLooseVariable_t::GetValueIntY() const {
    return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntY");
}
void GCompositeMaterialInputLooseVariable_t::SetValueIntY(int32_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntY", true, value);
}
int32_t GCompositeMaterialInputLooseVariable_t::GetValueIntZ() const {
    return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntZ");
}
void GCompositeMaterialInputLooseVariable_t::SetValueIntZ(int32_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntZ", true, value);
}
int32_t GCompositeMaterialInputLooseVariable_t::GetValueIntW() const {
    return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntW");
}
void GCompositeMaterialInputLooseVariable_t::SetValueIntW(int32_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueIntW", true, value);
}
bool GCompositeMaterialInputLooseVariable_t::GetHasFloatBounds() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bHasFloatBounds");
}
void GCompositeMaterialInputLooseVariable_t::SetHasFloatBounds(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_bHasFloatBounds", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatX() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatX(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatX_Min() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Min");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatX_Min(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Min", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatX_Max() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Max");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatX_Max(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatX_Max", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatY() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatY(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatY_Min() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Min");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatY_Min(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Min", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatY_Max() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Max");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatY_Max(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatY_Max", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatZ() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatZ(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatZ_Min() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Min");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatZ_Min(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Min", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatZ_Max() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Max");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatZ_Max(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatZ_Max", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatW() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatW(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatW_Min() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Min");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatW_Min(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Min", true, value);
}
float GCompositeMaterialInputLooseVariable_t::GetValueFloatW_Max() const {
    return GetSchemaValue<float>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Max");
}
void GCompositeMaterialInputLooseVariable_t::SetValueFloatW_Max(float value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_flValueFloatW_Max", true, value);
}
Color GCompositeMaterialInputLooseVariable_t::GetCValueColor4() const {
    return GetSchemaValue<Color>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_cValueColor4");
}
void GCompositeMaterialInputLooseVariable_t::SetCValueColor4(Color value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_cValueColor4", true, value);
}
uint64_t GCompositeMaterialInputLooseVariable_t::GetValueSystemVar() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueSystemVar");
}
void GCompositeMaterialInputLooseVariable_t::SetValueSystemVar(uint64_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nValueSystemVar", true, value);
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrTextureContentAssetPath() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureContentAssetPath").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrTextureContentAssetPath(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureContentAssetPath", true, CUtlString(value.c_str()));
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrTextureCompilationVtexTemplate() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureCompilationVtexTemplate").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrTextureCompilationVtexTemplate(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strTextureCompilationVtexTemplate", true, CUtlString(value.c_str()));
}
uint64_t GCompositeMaterialInputLooseVariable_t::GetTextureType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nTextureType");
}
void GCompositeMaterialInputLooseVariable_t::SetTextureType(uint64_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nTextureType", true, value);
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strString").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrString(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strString", true, CUtlString(value.c_str()));
}
std::string GCompositeMaterialInputLooseVariable_t::GetStrPanoramaPanelPath() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strPanoramaPanelPath").Get();
}
void GCompositeMaterialInputLooseVariable_t::SetStrPanoramaPanelPath(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_strPanoramaPanelPath", true, CUtlString(value.c_str()));
}
int32_t GCompositeMaterialInputLooseVariable_t::GetPanoramaRenderRes() const {
    return GetSchemaValue<int32_t>(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nPanoramaRenderRes");
}
void GCompositeMaterialInputLooseVariable_t::SetPanoramaRenderRes(int32_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialInputLooseVariable_t", "m_nPanoramaRenderRes", true, value);
}
std::string GCompositeMaterialInputLooseVariable_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompositeMaterialInputLooseVariable_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompositeMaterialInputLooseVariable_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialInputLooseVariable_t>("CompositeMaterialInputLooseVariable_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StrName", &GCompositeMaterialInputLooseVariable_t::GetStrName, &GCompositeMaterialInputLooseVariable_t::SetStrName)
        .addProperty("ExposeExternally", &GCompositeMaterialInputLooseVariable_t::GetExposeExternally, &GCompositeMaterialInputLooseVariable_t::SetExposeExternally)
        .addProperty("StrExposedFriendlyName", &GCompositeMaterialInputLooseVariable_t::GetStrExposedFriendlyName, &GCompositeMaterialInputLooseVariable_t::SetStrExposedFriendlyName)
        .addProperty("StrExposedFriendlyGroupName", &GCompositeMaterialInputLooseVariable_t::GetStrExposedFriendlyGroupName, &GCompositeMaterialInputLooseVariable_t::SetStrExposedFriendlyGroupName)
        .addProperty("ExposedVariableIsFixedRange", &GCompositeMaterialInputLooseVariable_t::GetExposedVariableIsFixedRange, &GCompositeMaterialInputLooseVariable_t::SetExposedVariableIsFixedRange)
        .addProperty("StrExposedVisibleWhenTrue", &GCompositeMaterialInputLooseVariable_t::GetStrExposedVisibleWhenTrue, &GCompositeMaterialInputLooseVariable_t::SetStrExposedVisibleWhenTrue)
        .addProperty("StrExposedHiddenWhenTrue", &GCompositeMaterialInputLooseVariable_t::GetStrExposedHiddenWhenTrue, &GCompositeMaterialInputLooseVariable_t::SetStrExposedHiddenWhenTrue)
        .addProperty("VariableType", &GCompositeMaterialInputLooseVariable_t::GetVariableType, &GCompositeMaterialInputLooseVariable_t::SetVariableType)
        .addProperty("ValueBoolean", &GCompositeMaterialInputLooseVariable_t::GetValueBoolean, &GCompositeMaterialInputLooseVariable_t::SetValueBoolean)
        .addProperty("ValueIntX", &GCompositeMaterialInputLooseVariable_t::GetValueIntX, &GCompositeMaterialInputLooseVariable_t::SetValueIntX)
        .addProperty("ValueIntY", &GCompositeMaterialInputLooseVariable_t::GetValueIntY, &GCompositeMaterialInputLooseVariable_t::SetValueIntY)
        .addProperty("ValueIntZ", &GCompositeMaterialInputLooseVariable_t::GetValueIntZ, &GCompositeMaterialInputLooseVariable_t::SetValueIntZ)
        .addProperty("ValueIntW", &GCompositeMaterialInputLooseVariable_t::GetValueIntW, &GCompositeMaterialInputLooseVariable_t::SetValueIntW)
        .addProperty("HasFloatBounds", &GCompositeMaterialInputLooseVariable_t::GetHasFloatBounds, &GCompositeMaterialInputLooseVariable_t::SetHasFloatBounds)
        .addProperty("ValueFloatX", &GCompositeMaterialInputLooseVariable_t::GetValueFloatX, &GCompositeMaterialInputLooseVariable_t::SetValueFloatX)
        .addProperty("ValueFloatX_Min", &GCompositeMaterialInputLooseVariable_t::GetValueFloatX_Min, &GCompositeMaterialInputLooseVariable_t::SetValueFloatX_Min)
        .addProperty("ValueFloatX_Max", &GCompositeMaterialInputLooseVariable_t::GetValueFloatX_Max, &GCompositeMaterialInputLooseVariable_t::SetValueFloatX_Max)
        .addProperty("ValueFloatY", &GCompositeMaterialInputLooseVariable_t::GetValueFloatY, &GCompositeMaterialInputLooseVariable_t::SetValueFloatY)
        .addProperty("ValueFloatY_Min", &GCompositeMaterialInputLooseVariable_t::GetValueFloatY_Min, &GCompositeMaterialInputLooseVariable_t::SetValueFloatY_Min)
        .addProperty("ValueFloatY_Max", &GCompositeMaterialInputLooseVariable_t::GetValueFloatY_Max, &GCompositeMaterialInputLooseVariable_t::SetValueFloatY_Max)
        .addProperty("ValueFloatZ", &GCompositeMaterialInputLooseVariable_t::GetValueFloatZ, &GCompositeMaterialInputLooseVariable_t::SetValueFloatZ)
        .addProperty("ValueFloatZ_Min", &GCompositeMaterialInputLooseVariable_t::GetValueFloatZ_Min, &GCompositeMaterialInputLooseVariable_t::SetValueFloatZ_Min)
        .addProperty("ValueFloatZ_Max", &GCompositeMaterialInputLooseVariable_t::GetValueFloatZ_Max, &GCompositeMaterialInputLooseVariable_t::SetValueFloatZ_Max)
        .addProperty("ValueFloatW", &GCompositeMaterialInputLooseVariable_t::GetValueFloatW, &GCompositeMaterialInputLooseVariable_t::SetValueFloatW)
        .addProperty("ValueFloatW_Min", &GCompositeMaterialInputLooseVariable_t::GetValueFloatW_Min, &GCompositeMaterialInputLooseVariable_t::SetValueFloatW_Min)
        .addProperty("ValueFloatW_Max", &GCompositeMaterialInputLooseVariable_t::GetValueFloatW_Max, &GCompositeMaterialInputLooseVariable_t::SetValueFloatW_Max)
        .addProperty("CValueColor4", &GCompositeMaterialInputLooseVariable_t::GetCValueColor4, &GCompositeMaterialInputLooseVariable_t::SetCValueColor4)
        .addProperty("ValueSystemVar", &GCompositeMaterialInputLooseVariable_t::GetValueSystemVar, &GCompositeMaterialInputLooseVariable_t::SetValueSystemVar)
        .addProperty("StrTextureContentAssetPath", &GCompositeMaterialInputLooseVariable_t::GetStrTextureContentAssetPath, &GCompositeMaterialInputLooseVariable_t::SetStrTextureContentAssetPath)
        .addProperty("StrTextureCompilationVtexTemplate", &GCompositeMaterialInputLooseVariable_t::GetStrTextureCompilationVtexTemplate, &GCompositeMaterialInputLooseVariable_t::SetStrTextureCompilationVtexTemplate)
        .addProperty("TextureType", &GCompositeMaterialInputLooseVariable_t::GetTextureType, &GCompositeMaterialInputLooseVariable_t::SetTextureType)
        .addProperty("StrString", &GCompositeMaterialInputLooseVariable_t::GetStrString, &GCompositeMaterialInputLooseVariable_t::SetStrString)
        .addProperty("StrPanoramaPanelPath", &GCompositeMaterialInputLooseVariable_t::GetStrPanoramaPanelPath, &GCompositeMaterialInputLooseVariable_t::SetStrPanoramaPanelPath)
        .addProperty("PanoramaRenderRes", &GCompositeMaterialInputLooseVariable_t::GetPanoramaRenderRes, &GCompositeMaterialInputLooseVariable_t::SetPanoramaRenderRes)
        .addFunction("ToPtr", &GCompositeMaterialInputLooseVariable_t::ToPtr)
        .addFunction("IsValid", &GCompositeMaterialInputLooseVariable_t::IsValid)
        .endClass();
}