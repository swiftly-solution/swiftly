#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GBoneDemoCaptureSettings_t::GBoneDemoCaptureSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GBoneDemoCaptureSettings_t::GBoneDemoCaptureSettings_t(void *ptr) {
    m_ptr = ptr;
}
std::string GBoneDemoCaptureSettings_t::GetBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "BoneDemoCaptureSettings_t", "m_boneName").Get();
}
void GBoneDemoCaptureSettings_t::SetBoneName(std::string value) {
    SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_boneName", true, CUtlString(value.c_str()));
}
float GBoneDemoCaptureSettings_t::GetErrorSplineRotationMax() const {
    return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineRotationMax");
}
void GBoneDemoCaptureSettings_t::SetErrorSplineRotationMax(float value) {
    SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineRotationMax", true, value);
}
float GBoneDemoCaptureSettings_t::GetErrorSplineTranslationMax() const {
    return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineTranslationMax");
}
void GBoneDemoCaptureSettings_t::SetErrorSplineTranslationMax(float value) {
    SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineTranslationMax", true, value);
}
float GBoneDemoCaptureSettings_t::GetErrorSplineScaleMax() const {
    return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineScaleMax");
}
void GBoneDemoCaptureSettings_t::SetErrorSplineScaleMax(float value) {
    SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorSplineScaleMax", true, value);
}
float GBoneDemoCaptureSettings_t::GetErrorQuantizationRotationMax() const {
    return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationRotationMax");
}
void GBoneDemoCaptureSettings_t::SetErrorQuantizationRotationMax(float value) {
    SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationRotationMax", true, value);
}
float GBoneDemoCaptureSettings_t::GetErrorQuantizationTranslationMax() const {
    return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationTranslationMax");
}
void GBoneDemoCaptureSettings_t::SetErrorQuantizationTranslationMax(float value) {
    SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationTranslationMax", true, value);
}
float GBoneDemoCaptureSettings_t::GetErrorQuantizationScaleMax() const {
    return GetSchemaValue<float>(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationScaleMax");
}
void GBoneDemoCaptureSettings_t::SetErrorQuantizationScaleMax(float value) {
    SetSchemaValue(m_ptr, "BoneDemoCaptureSettings_t", "m_flErrorQuantizationScaleMax", true, value);
}
std::string GBoneDemoCaptureSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GBoneDemoCaptureSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassBoneDemoCaptureSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GBoneDemoCaptureSettings_t>("BoneDemoCaptureSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneName", &GBoneDemoCaptureSettings_t::GetBoneName, &GBoneDemoCaptureSettings_t::SetBoneName)
        .addProperty("ErrorSplineRotationMax", &GBoneDemoCaptureSettings_t::GetErrorSplineRotationMax, &GBoneDemoCaptureSettings_t::SetErrorSplineRotationMax)
        .addProperty("ErrorSplineTranslationMax", &GBoneDemoCaptureSettings_t::GetErrorSplineTranslationMax, &GBoneDemoCaptureSettings_t::SetErrorSplineTranslationMax)
        .addProperty("ErrorSplineScaleMax", &GBoneDemoCaptureSettings_t::GetErrorSplineScaleMax, &GBoneDemoCaptureSettings_t::SetErrorSplineScaleMax)
        .addProperty("ErrorQuantizationRotationMax", &GBoneDemoCaptureSettings_t::GetErrorQuantizationRotationMax, &GBoneDemoCaptureSettings_t::SetErrorQuantizationRotationMax)
        .addProperty("ErrorQuantizationTranslationMax", &GBoneDemoCaptureSettings_t::GetErrorQuantizationTranslationMax, &GBoneDemoCaptureSettings_t::SetErrorQuantizationTranslationMax)
        .addProperty("ErrorQuantizationScaleMax", &GBoneDemoCaptureSettings_t::GetErrorQuantizationScaleMax, &GBoneDemoCaptureSettings_t::SetErrorQuantizationScaleMax)
        .addFunction("ToPtr", &GBoneDemoCaptureSettings_t::ToPtr)
        .addFunction("IsValid", &GBoneDemoCaptureSettings_t::IsValid)
        .endClass();
}