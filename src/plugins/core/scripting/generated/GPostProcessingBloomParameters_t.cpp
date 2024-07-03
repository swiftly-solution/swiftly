#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPostProcessingBloomParameters_t::GPostProcessingBloomParameters_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPostProcessingBloomParameters_t::GPostProcessingBloomParameters_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GPostProcessingBloomParameters_t::GetBlendMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "PostProcessingBloomParameters_t", "m_blendMode");
}
void GPostProcessingBloomParameters_t::SetBlendMode(uint64_t value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_blendMode", true, value);
}
float GPostProcessingBloomParameters_t::GetBloomStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStrength");
}
void GPostProcessingBloomParameters_t::SetBloomStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStrength", true, value);
}
float GPostProcessingBloomParameters_t::GetScreenBloomStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flScreenBloomStrength");
}
void GPostProcessingBloomParameters_t::SetScreenBloomStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flScreenBloomStrength", true, value);
}
float GPostProcessingBloomParameters_t::GetBlurBloomStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurBloomStrength");
}
void GPostProcessingBloomParameters_t::SetBlurBloomStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurBloomStrength", true, value);
}
float GPostProcessingBloomParameters_t::GetBloomThreshold() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThreshold");
}
void GPostProcessingBloomParameters_t::SetBloomThreshold(float value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThreshold", true, value);
}
float GPostProcessingBloomParameters_t::GetBloomThresholdWidth() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThresholdWidth");
}
void GPostProcessingBloomParameters_t::SetBloomThresholdWidth(float value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomThresholdWidth", true, value);
}
float GPostProcessingBloomParameters_t::GetSkyboxBloomStrength() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flSkyboxBloomStrength");
}
void GPostProcessingBloomParameters_t::SetSkyboxBloomStrength(float value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flSkyboxBloomStrength", true, value);
}
float GPostProcessingBloomParameters_t::GetBloomStartValue() const {
    return GetSchemaValue<float>(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStartValue");
}
void GPostProcessingBloomParameters_t::SetBloomStartValue(float value) {
    SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBloomStartValue", true, value);
}
std::vector<float> GPostProcessingBloomParameters_t::GetBlurWeight() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurWeight"); std::vector<float> ret; for(int i = 0; i < 5; i++) { ret.push_back(outValue[i]); } return ret;
}
void GPostProcessingBloomParameters_t::SetBlurWeight(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurWeight"); for(int i = 0; i < 5; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_flBlurWeight", true, outValue);
}
std::vector<Vector> GPostProcessingBloomParameters_t::GetBlurTint() const {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "PostProcessingBloomParameters_t", "m_vBlurTint"); std::vector<Vector> ret; for(int i = 0; i < 5; i++) { ret.push_back(outValue[i]); } return ret;
}
void GPostProcessingBloomParameters_t::SetBlurTint(std::vector<Vector> value) {
    Vector* outValue = GetSchemaValue<Vector*>(m_ptr, "PostProcessingBloomParameters_t", "m_vBlurTint"); for(int i = 0; i < 5; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "PostProcessingBloomParameters_t", "m_vBlurTint", true, outValue);
}
std::string GPostProcessingBloomParameters_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPostProcessingBloomParameters_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPostProcessingBloomParameters_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPostProcessingBloomParameters_t>("PostProcessingBloomParameters_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BlendMode", &GPostProcessingBloomParameters_t::GetBlendMode, &GPostProcessingBloomParameters_t::SetBlendMode)
        .addProperty("BloomStrength", &GPostProcessingBloomParameters_t::GetBloomStrength, &GPostProcessingBloomParameters_t::SetBloomStrength)
        .addProperty("ScreenBloomStrength", &GPostProcessingBloomParameters_t::GetScreenBloomStrength, &GPostProcessingBloomParameters_t::SetScreenBloomStrength)
        .addProperty("BlurBloomStrength", &GPostProcessingBloomParameters_t::GetBlurBloomStrength, &GPostProcessingBloomParameters_t::SetBlurBloomStrength)
        .addProperty("BloomThreshold", &GPostProcessingBloomParameters_t::GetBloomThreshold, &GPostProcessingBloomParameters_t::SetBloomThreshold)
        .addProperty("BloomThresholdWidth", &GPostProcessingBloomParameters_t::GetBloomThresholdWidth, &GPostProcessingBloomParameters_t::SetBloomThresholdWidth)
        .addProperty("SkyboxBloomStrength", &GPostProcessingBloomParameters_t::GetSkyboxBloomStrength, &GPostProcessingBloomParameters_t::SetSkyboxBloomStrength)
        .addProperty("BloomStartValue", &GPostProcessingBloomParameters_t::GetBloomStartValue, &GPostProcessingBloomParameters_t::SetBloomStartValue)
        .addProperty("BlurWeight", &GPostProcessingBloomParameters_t::GetBlurWeight, &GPostProcessingBloomParameters_t::SetBlurWeight)
        .addProperty("BlurTint", &GPostProcessingBloomParameters_t::GetBlurTint, &GPostProcessingBloomParameters_t::SetBlurTint)
        .addFunction("ToPtr", &GPostProcessingBloomParameters_t::ToPtr)
        .addFunction("IsValid", &GPostProcessingBloomParameters_t::IsValid)
        .endClass();
}