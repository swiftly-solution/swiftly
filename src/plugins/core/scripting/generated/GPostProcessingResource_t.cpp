#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPostProcessingResource_t::GPostProcessingResource_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPostProcessingResource_t::GPostProcessingResource_t(void *ptr) {
    m_ptr = ptr;
}
bool GPostProcessingResource_t::GetHasTonemapParams() const {
    return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasTonemapParams");
}
void GPostProcessingResource_t::SetHasTonemapParams(bool value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasTonemapParams", true, value);
}
GPostProcessingTonemapParameters_t GPostProcessingResource_t::GetToneMapParams() const {
    GPostProcessingTonemapParameters_t value(GetSchemaPtr(m_ptr, "PostProcessingResource_t", "m_toneMapParams"));
    return value;
}
void GPostProcessingResource_t::SetToneMapParams(GPostProcessingTonemapParameters_t value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_toneMapParams", true, value);
}
bool GPostProcessingResource_t::GetHasBloomParams() const {
    return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasBloomParams");
}
void GPostProcessingResource_t::SetHasBloomParams(bool value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasBloomParams", true, value);
}
GPostProcessingBloomParameters_t GPostProcessingResource_t::GetBloomParams() const {
    GPostProcessingBloomParameters_t value(GetSchemaPtr(m_ptr, "PostProcessingResource_t", "m_bloomParams"));
    return value;
}
void GPostProcessingResource_t::SetBloomParams(GPostProcessingBloomParameters_t value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bloomParams", true, value);
}
bool GPostProcessingResource_t::GetHasVignetteParams() const {
    return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasVignetteParams");
}
void GPostProcessingResource_t::SetHasVignetteParams(bool value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasVignetteParams", true, value);
}
GPostProcessingVignetteParameters_t GPostProcessingResource_t::GetVignetteParams() const {
    GPostProcessingVignetteParameters_t value(GetSchemaPtr(m_ptr, "PostProcessingResource_t", "m_vignetteParams"));
    return value;
}
void GPostProcessingResource_t::SetVignetteParams(GPostProcessingVignetteParameters_t value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_vignetteParams", true, value);
}
bool GPostProcessingResource_t::GetHasLocalContrastParams() const {
    return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasLocalContrastParams");
}
void GPostProcessingResource_t::SetHasLocalContrastParams(bool value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasLocalContrastParams", true, value);
}
GPostProcessingLocalContrastParameters_t GPostProcessingResource_t::GetLocalConstrastParams() const {
    GPostProcessingLocalContrastParameters_t value(GetSchemaPtr(m_ptr, "PostProcessingResource_t", "m_localConstrastParams"));
    return value;
}
void GPostProcessingResource_t::SetLocalConstrastParams(GPostProcessingLocalContrastParameters_t value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_localConstrastParams", true, value);
}
int32_t GPostProcessingResource_t::GetColorCorrectionVolumeDim() const {
    return GetSchemaValue<int32_t>(m_ptr, "PostProcessingResource_t", "m_nColorCorrectionVolumeDim");
}
void GPostProcessingResource_t::SetColorCorrectionVolumeDim(int32_t value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_nColorCorrectionVolumeDim", true, value);
}
bool GPostProcessingResource_t::GetHasColorCorrection() const {
    return GetSchemaValue<bool>(m_ptr, "PostProcessingResource_t", "m_bHasColorCorrection");
}
void GPostProcessingResource_t::SetHasColorCorrection(bool value) {
    SetSchemaValue(m_ptr, "PostProcessingResource_t", "m_bHasColorCorrection", true, value);
}
std::string GPostProcessingResource_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPostProcessingResource_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPostProcessingResource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingResource_t>("PostProcessingResource_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HasTonemapParams", &GPostProcessingResource_t::GetHasTonemapParams, &GPostProcessingResource_t::SetHasTonemapParams)
        .addProperty("ToneMapParams", &GPostProcessingResource_t::GetToneMapParams, &GPostProcessingResource_t::SetToneMapParams)
        .addProperty("HasBloomParams", &GPostProcessingResource_t::GetHasBloomParams, &GPostProcessingResource_t::SetHasBloomParams)
        .addProperty("BloomParams", &GPostProcessingResource_t::GetBloomParams, &GPostProcessingResource_t::SetBloomParams)
        .addProperty("HasVignetteParams", &GPostProcessingResource_t::GetHasVignetteParams, &GPostProcessingResource_t::SetHasVignetteParams)
        .addProperty("VignetteParams", &GPostProcessingResource_t::GetVignetteParams, &GPostProcessingResource_t::SetVignetteParams)
        .addProperty("HasLocalContrastParams", &GPostProcessingResource_t::GetHasLocalContrastParams, &GPostProcessingResource_t::SetHasLocalContrastParams)
        .addProperty("LocalConstrastParams", &GPostProcessingResource_t::GetLocalConstrastParams, &GPostProcessingResource_t::SetLocalConstrastParams)
        .addProperty("ColorCorrectionVolumeDim", &GPostProcessingResource_t::GetColorCorrectionVolumeDim, &GPostProcessingResource_t::SetColorCorrectionVolumeDim)
        .addProperty("HasColorCorrection", &GPostProcessingResource_t::GetHasColorCorrection, &GPostProcessingResource_t::SetHasColorCorrection)
        .addFunction("ToPtr", &GPostProcessingResource_t::ToPtr)
        .addFunction("IsValid", &GPostProcessingResource_t::IsValid)
        .endClass();
}