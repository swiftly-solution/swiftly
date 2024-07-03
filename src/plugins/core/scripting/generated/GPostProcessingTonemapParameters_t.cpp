#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPostProcessingTonemapParameters_t::GPostProcessingTonemapParameters_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPostProcessingTonemapParameters_t::GPostProcessingTonemapParameters_t(void *ptr) {
    m_ptr = ptr;
}
float GPostProcessingTonemapParameters_t::GetExposureBias() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBias");
}
void GPostProcessingTonemapParameters_t::SetExposureBias(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBias", true, value);
}
float GPostProcessingTonemapParameters_t::GetShoulderStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flShoulderStrength");
}
void GPostProcessingTonemapParameters_t::SetShoulderStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flShoulderStrength", true, value);
}
float GPostProcessingTonemapParameters_t::GetLinearStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearStrength");
}
void GPostProcessingTonemapParameters_t::SetLinearStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearStrength", true, value);
}
float GPostProcessingTonemapParameters_t::GetLinearAngle() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearAngle");
}
void GPostProcessingTonemapParameters_t::SetLinearAngle(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flLinearAngle", true, value);
}
float GPostProcessingTonemapParameters_t::GetToeStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeStrength");
}
void GPostProcessingTonemapParameters_t::SetToeStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeStrength", true, value);
}
float GPostProcessingTonemapParameters_t::GetToeNum() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeNum");
}
void GPostProcessingTonemapParameters_t::SetToeNum(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeNum", true, value);
}
float GPostProcessingTonemapParameters_t::GetToeDenom() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeDenom");
}
void GPostProcessingTonemapParameters_t::SetToeDenom(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flToeDenom", true, value);
}
float GPostProcessingTonemapParameters_t::GetWhitePoint() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flWhitePoint");
}
void GPostProcessingTonemapParameters_t::SetWhitePoint(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flWhitePoint", true, value);
}
float GPostProcessingTonemapParameters_t::GetLuminanceSource() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flLuminanceSource");
}
void GPostProcessingTonemapParameters_t::SetLuminanceSource(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flLuminanceSource", true, value);
}
float GPostProcessingTonemapParameters_t::GetExposureBiasShadows() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasShadows");
}
void GPostProcessingTonemapParameters_t::SetExposureBiasShadows(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasShadows", true, value);
}
float GPostProcessingTonemapParameters_t::GetExposureBiasHighlights() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasHighlights");
}
void GPostProcessingTonemapParameters_t::SetExposureBiasHighlights(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flExposureBiasHighlights", true, value);
}
float GPostProcessingTonemapParameters_t::GetMinShadowLum() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinShadowLum");
}
void GPostProcessingTonemapParameters_t::SetMinShadowLum(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinShadowLum", true, value);
}
float GPostProcessingTonemapParameters_t::GetMaxShadowLum() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxShadowLum");
}
void GPostProcessingTonemapParameters_t::SetMaxShadowLum(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxShadowLum", true, value);
}
float GPostProcessingTonemapParameters_t::GetMinHighlightLum() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinHighlightLum");
}
void GPostProcessingTonemapParameters_t::SetMinHighlightLum(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMinHighlightLum", true, value);
}
float GPostProcessingTonemapParameters_t::GetMaxHighlightLum() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxHighlightLum");
}
void GPostProcessingTonemapParameters_t::SetMaxHighlightLum(float value) {
    SetSchemaValue(m_ptr, "PostProcessingTonemapParameters_t", "m_flMaxHighlightLum", true, value);
}
std::string GPostProcessingTonemapParameters_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPostProcessingTonemapParameters_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPostProcessingTonemapParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingTonemapParameters_t>("PostProcessingTonemapParameters_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ExposureBias", &GPostProcessingTonemapParameters_t::GetExposureBias, &GPostProcessingTonemapParameters_t::SetExposureBias)
        .addProperty("ShoulderStrength", &GPostProcessingTonemapParameters_t::GetShoulderStrength, &GPostProcessingTonemapParameters_t::SetShoulderStrength)
        .addProperty("LinearStrength", &GPostProcessingTonemapParameters_t::GetLinearStrength, &GPostProcessingTonemapParameters_t::SetLinearStrength)
        .addProperty("LinearAngle", &GPostProcessingTonemapParameters_t::GetLinearAngle, &GPostProcessingTonemapParameters_t::SetLinearAngle)
        .addProperty("ToeStrength", &GPostProcessingTonemapParameters_t::GetToeStrength, &GPostProcessingTonemapParameters_t::SetToeStrength)
        .addProperty("ToeNum", &GPostProcessingTonemapParameters_t::GetToeNum, &GPostProcessingTonemapParameters_t::SetToeNum)
        .addProperty("ToeDenom", &GPostProcessingTonemapParameters_t::GetToeDenom, &GPostProcessingTonemapParameters_t::SetToeDenom)
        .addProperty("WhitePoint", &GPostProcessingTonemapParameters_t::GetWhitePoint, &GPostProcessingTonemapParameters_t::SetWhitePoint)
        .addProperty("LuminanceSource", &GPostProcessingTonemapParameters_t::GetLuminanceSource, &GPostProcessingTonemapParameters_t::SetLuminanceSource)
        .addProperty("ExposureBiasShadows", &GPostProcessingTonemapParameters_t::GetExposureBiasShadows, &GPostProcessingTonemapParameters_t::SetExposureBiasShadows)
        .addProperty("ExposureBiasHighlights", &GPostProcessingTonemapParameters_t::GetExposureBiasHighlights, &GPostProcessingTonemapParameters_t::SetExposureBiasHighlights)
        .addProperty("MinShadowLum", &GPostProcessingTonemapParameters_t::GetMinShadowLum, &GPostProcessingTonemapParameters_t::SetMinShadowLum)
        .addProperty("MaxShadowLum", &GPostProcessingTonemapParameters_t::GetMaxShadowLum, &GPostProcessingTonemapParameters_t::SetMaxShadowLum)
        .addProperty("MinHighlightLum", &GPostProcessingTonemapParameters_t::GetMinHighlightLum, &GPostProcessingTonemapParameters_t::SetMinHighlightLum)
        .addProperty("MaxHighlightLum", &GPostProcessingTonemapParameters_t::GetMaxHighlightLum, &GPostProcessingTonemapParameters_t::SetMaxHighlightLum)
        .addFunction("ToPtr", &GPostProcessingTonemapParameters_t::ToPtr)
        .addFunction("IsValid", &GPostProcessingTonemapParameters_t::IsValid)
        .endClass();
}