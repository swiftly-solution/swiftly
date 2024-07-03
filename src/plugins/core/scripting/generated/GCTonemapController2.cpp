#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTonemapController2::GCTonemapController2(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTonemapController2::GCTonemapController2(void *ptr) {
    m_ptr = ptr;
}
float GCTonemapController2::GetAutoExposureMin() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flAutoExposureMin");
}
void GCTonemapController2::SetAutoExposureMin(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flAutoExposureMin", false, value);
}
float GCTonemapController2::GetAutoExposureMax() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flAutoExposureMax");
}
void GCTonemapController2::SetAutoExposureMax(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flAutoExposureMax", false, value);
}
float GCTonemapController2::GetTonemapPercentTarget() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapPercentTarget");
}
void GCTonemapController2::SetTonemapPercentTarget(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapPercentTarget", false, value);
}
float GCTonemapController2::GetTonemapPercentBrightPixels() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapPercentBrightPixels");
}
void GCTonemapController2::SetTonemapPercentBrightPixels(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapPercentBrightPixels", false, value);
}
float GCTonemapController2::GetTonemapMinAvgLum() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapMinAvgLum");
}
void GCTonemapController2::SetTonemapMinAvgLum(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapMinAvgLum", false, value);
}
float GCTonemapController2::GetExposureAdaptationSpeedUp() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedUp");
}
void GCTonemapController2::SetExposureAdaptationSpeedUp(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedUp", false, value);
}
float GCTonemapController2::GetExposureAdaptationSpeedDown() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedDown");
}
void GCTonemapController2::SetExposureAdaptationSpeedDown(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flExposureAdaptationSpeedDown", false, value);
}
float GCTonemapController2::GetTonemapEVSmoothingRange() const {
    return GetSchemaValue<float>(m_ptr, "CTonemapController2", "m_flTonemapEVSmoothingRange");
}
void GCTonemapController2::SetTonemapEVSmoothingRange(float value) {
    SetSchemaValue(m_ptr, "CTonemapController2", "m_flTonemapEVSmoothingRange", false, value);
}
std::string GCTonemapController2::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTonemapController2::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCTonemapController2::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCTonemapController2::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTonemapController2(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTonemapController2>("CTonemapController2")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AutoExposureMin", &GCTonemapController2::GetAutoExposureMin, &GCTonemapController2::SetAutoExposureMin)
        .addProperty("AutoExposureMax", &GCTonemapController2::GetAutoExposureMax, &GCTonemapController2::SetAutoExposureMax)
        .addProperty("TonemapPercentTarget", &GCTonemapController2::GetTonemapPercentTarget, &GCTonemapController2::SetTonemapPercentTarget)
        .addProperty("TonemapPercentBrightPixels", &GCTonemapController2::GetTonemapPercentBrightPixels, &GCTonemapController2::SetTonemapPercentBrightPixels)
        .addProperty("TonemapMinAvgLum", &GCTonemapController2::GetTonemapMinAvgLum, &GCTonemapController2::SetTonemapMinAvgLum)
        .addProperty("ExposureAdaptationSpeedUp", &GCTonemapController2::GetExposureAdaptationSpeedUp, &GCTonemapController2::SetExposureAdaptationSpeedUp)
        .addProperty("ExposureAdaptationSpeedDown", &GCTonemapController2::GetExposureAdaptationSpeedDown, &GCTonemapController2::SetExposureAdaptationSpeedDown)
        .addProperty("TonemapEVSmoothingRange", &GCTonemapController2::GetTonemapEVSmoothingRange, &GCTonemapController2::SetTonemapEVSmoothingRange)
        .addProperty("Parent", &GCTonemapController2::GetParent, &GCTonemapController2::SetParent)
        .addFunction("ToPtr", &GCTonemapController2::ToPtr)
        .addFunction("IsValid", &GCTonemapController2::IsValid)
        .endClass();
}