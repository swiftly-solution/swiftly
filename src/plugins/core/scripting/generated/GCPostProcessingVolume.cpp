#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPostProcessingVolume::GCPostProcessingVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPostProcessingVolume::GCPostProcessingVolume(void *ptr) {
    m_ptr = ptr;
}
float GCPostProcessingVolume::GetFadeDuration() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flFadeDuration");
}
void GCPostProcessingVolume::SetFadeDuration(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flFadeDuration", false, value);
}
float GCPostProcessingVolume::GetMinLogExposure() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMinLogExposure");
}
void GCPostProcessingVolume::SetMinLogExposure(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMinLogExposure", false, value);
}
float GCPostProcessingVolume::GetMaxLogExposure() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMaxLogExposure");
}
void GCPostProcessingVolume::SetMaxLogExposure(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMaxLogExposure", false, value);
}
float GCPostProcessingVolume::GetMinExposure() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMinExposure");
}
void GCPostProcessingVolume::SetMinExposure(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMinExposure", false, value);
}
float GCPostProcessingVolume::GetMaxExposure() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flMaxExposure");
}
void GCPostProcessingVolume::SetMaxExposure(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flMaxExposure", false, value);
}
float GCPostProcessingVolume::GetExposureCompensation() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flExposureCompensation");
}
void GCPostProcessingVolume::SetExposureCompensation(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flExposureCompensation", false, value);
}
float GCPostProcessingVolume::GetExposureFadeSpeedUp() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedUp");
}
void GCPostProcessingVolume::SetExposureFadeSpeedUp(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedUp", false, value);
}
float GCPostProcessingVolume::GetExposureFadeSpeedDown() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedDown");
}
void GCPostProcessingVolume::SetExposureFadeSpeedDown(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flExposureFadeSpeedDown", false, value);
}
float GCPostProcessingVolume::GetTonemapEVSmoothingRange() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapEVSmoothingRange");
}
void GCPostProcessingVolume::SetTonemapEVSmoothingRange(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapEVSmoothingRange", false, value);
}
bool GCPostProcessingVolume::GetMaster() const {
    return GetSchemaValue<bool>(m_ptr, "CPostProcessingVolume", "m_bMaster");
}
void GCPostProcessingVolume::SetMaster(bool value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_bMaster", false, value);
}
bool GCPostProcessingVolume::GetExposureControl() const {
    return GetSchemaValue<bool>(m_ptr, "CPostProcessingVolume", "m_bExposureControl");
}
void GCPostProcessingVolume::SetExposureControl(bool value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_bExposureControl", false, value);
}
float GCPostProcessingVolume::GetRate() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flRate");
}
void GCPostProcessingVolume::SetRate(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flRate", false, value);
}
float GCPostProcessingVolume::GetTonemapPercentTarget() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentTarget");
}
void GCPostProcessingVolume::SetTonemapPercentTarget(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentTarget", false, value);
}
float GCPostProcessingVolume::GetTonemapPercentBrightPixels() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentBrightPixels");
}
void GCPostProcessingVolume::SetTonemapPercentBrightPixels(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapPercentBrightPixels", false, value);
}
float GCPostProcessingVolume::GetTonemapMinAvgLum() const {
    return GetSchemaValue<float>(m_ptr, "CPostProcessingVolume", "m_flTonemapMinAvgLum");
}
void GCPostProcessingVolume::SetTonemapMinAvgLum(float value) {
    SetSchemaValue(m_ptr, "CPostProcessingVolume", "m_flTonemapMinAvgLum", false, value);
}
std::string GCPostProcessingVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPostProcessingVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCPostProcessingVolume::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCPostProcessingVolume::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPostProcessingVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPostProcessingVolume>("CPostProcessingVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FadeDuration", &GCPostProcessingVolume::GetFadeDuration, &GCPostProcessingVolume::SetFadeDuration)
        .addProperty("MinLogExposure", &GCPostProcessingVolume::GetMinLogExposure, &GCPostProcessingVolume::SetMinLogExposure)
        .addProperty("MaxLogExposure", &GCPostProcessingVolume::GetMaxLogExposure, &GCPostProcessingVolume::SetMaxLogExposure)
        .addProperty("MinExposure", &GCPostProcessingVolume::GetMinExposure, &GCPostProcessingVolume::SetMinExposure)
        .addProperty("MaxExposure", &GCPostProcessingVolume::GetMaxExposure, &GCPostProcessingVolume::SetMaxExposure)
        .addProperty("ExposureCompensation", &GCPostProcessingVolume::GetExposureCompensation, &GCPostProcessingVolume::SetExposureCompensation)
        .addProperty("ExposureFadeSpeedUp", &GCPostProcessingVolume::GetExposureFadeSpeedUp, &GCPostProcessingVolume::SetExposureFadeSpeedUp)
        .addProperty("ExposureFadeSpeedDown", &GCPostProcessingVolume::GetExposureFadeSpeedDown, &GCPostProcessingVolume::SetExposureFadeSpeedDown)
        .addProperty("TonemapEVSmoothingRange", &GCPostProcessingVolume::GetTonemapEVSmoothingRange, &GCPostProcessingVolume::SetTonemapEVSmoothingRange)
        .addProperty("Master", &GCPostProcessingVolume::GetMaster, &GCPostProcessingVolume::SetMaster)
        .addProperty("ExposureControl", &GCPostProcessingVolume::GetExposureControl, &GCPostProcessingVolume::SetExposureControl)
        .addProperty("Rate", &GCPostProcessingVolume::GetRate, &GCPostProcessingVolume::SetRate)
        .addProperty("TonemapPercentTarget", &GCPostProcessingVolume::GetTonemapPercentTarget, &GCPostProcessingVolume::SetTonemapPercentTarget)
        .addProperty("TonemapPercentBrightPixels", &GCPostProcessingVolume::GetTonemapPercentBrightPixels, &GCPostProcessingVolume::SetTonemapPercentBrightPixels)
        .addProperty("TonemapMinAvgLum", &GCPostProcessingVolume::GetTonemapMinAvgLum, &GCPostProcessingVolume::SetTonemapMinAvgLum)
        .addProperty("Parent", &GCPostProcessingVolume::GetParent, &GCPostProcessingVolume::SetParent)
        .addFunction("ToPtr", &GCPostProcessingVolume::ToPtr)
        .addFunction("IsValid", &GCPostProcessingVolume::IsValid)
        .endClass();
}