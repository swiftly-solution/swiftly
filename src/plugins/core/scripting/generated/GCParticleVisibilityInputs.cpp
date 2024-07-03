#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleVisibilityInputs::GCParticleVisibilityInputs(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleVisibilityInputs::GCParticleVisibilityInputs(void *ptr) {
    m_ptr = ptr;
}
float GCParticleVisibilityInputs::GetCameraBias() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flCameraBias");
}
void GCParticleVisibilityInputs::SetCameraBias(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flCameraBias", false, value);
}
int32_t GCParticleVisibilityInputs::GetCPin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleVisibilityInputs", "m_nCPin");
}
void GCParticleVisibilityInputs::SetCPin(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_nCPin", false, value);
}
float GCParticleVisibilityInputs::GetProxyRadius() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flProxyRadius");
}
void GCParticleVisibilityInputs::SetProxyRadius(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flProxyRadius", false, value);
}
float GCParticleVisibilityInputs::GetInputMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flInputMin");
}
void GCParticleVisibilityInputs::SetInputMin(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flInputMin", false, value);
}
float GCParticleVisibilityInputs::GetInputMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flInputMax");
}
void GCParticleVisibilityInputs::SetInputMax(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flInputMax", false, value);
}
float GCParticleVisibilityInputs::GetInputPixelVisFade() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flInputPixelVisFade");
}
void GCParticleVisibilityInputs::SetInputPixelVisFade(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flInputPixelVisFade", false, value);
}
float GCParticleVisibilityInputs::GetNoPixelVisibilityFallback() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flNoPixelVisibilityFallback");
}
void GCParticleVisibilityInputs::SetNoPixelVisibilityFallback(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flNoPixelVisibilityFallback", false, value);
}
float GCParticleVisibilityInputs::GetDistanceInputMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMin");
}
void GCParticleVisibilityInputs::SetDistanceInputMin(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMin", false, value);
}
float GCParticleVisibilityInputs::GetDistanceInputMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMax");
}
void GCParticleVisibilityInputs::SetDistanceInputMax(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDistanceInputMax", false, value);
}
float GCParticleVisibilityInputs::GetDotInputMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMin");
}
void GCParticleVisibilityInputs::SetDotInputMin(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMin", false, value);
}
float GCParticleVisibilityInputs::GetDotInputMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMax");
}
void GCParticleVisibilityInputs::SetDotInputMax(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flDotInputMax", false, value);
}
bool GCParticleVisibilityInputs::GetDotCPAngles() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleVisibilityInputs", "m_bDotCPAngles");
}
void GCParticleVisibilityInputs::SetDotCPAngles(bool value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_bDotCPAngles", false, value);
}
bool GCParticleVisibilityInputs::GetDotCameraAngles() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleVisibilityInputs", "m_bDotCameraAngles");
}
void GCParticleVisibilityInputs::SetDotCameraAngles(bool value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_bDotCameraAngles", false, value);
}
float GCParticleVisibilityInputs::GetAlphaScaleMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMin");
}
void GCParticleVisibilityInputs::SetAlphaScaleMin(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMin", false, value);
}
float GCParticleVisibilityInputs::GetAlphaScaleMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMax");
}
void GCParticleVisibilityInputs::SetAlphaScaleMax(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flAlphaScaleMax", false, value);
}
float GCParticleVisibilityInputs::GetRadiusScaleMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMin");
}
void GCParticleVisibilityInputs::SetRadiusScaleMin(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMin", false, value);
}
float GCParticleVisibilityInputs::GetRadiusScaleMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMax");
}
void GCParticleVisibilityInputs::SetRadiusScaleMax(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleMax", false, value);
}
float GCParticleVisibilityInputs::GetRadiusScaleFOVBase() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleFOVBase");
}
void GCParticleVisibilityInputs::SetRadiusScaleFOVBase(float value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_flRadiusScaleFOVBase", false, value);
}
bool GCParticleVisibilityInputs::GetRightEye() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleVisibilityInputs", "m_bRightEye");
}
void GCParticleVisibilityInputs::SetRightEye(bool value) {
    SetSchemaValue(m_ptr, "CParticleVisibilityInputs", "m_bRightEye", false, value);
}
std::string GCParticleVisibilityInputs::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleVisibilityInputs::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleVisibilityInputs(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleVisibilityInputs>("CParticleVisibilityInputs")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CameraBias", &GCParticleVisibilityInputs::GetCameraBias, &GCParticleVisibilityInputs::SetCameraBias)
        .addProperty("CPin", &GCParticleVisibilityInputs::GetCPin, &GCParticleVisibilityInputs::SetCPin)
        .addProperty("ProxyRadius", &GCParticleVisibilityInputs::GetProxyRadius, &GCParticleVisibilityInputs::SetProxyRadius)
        .addProperty("InputMin", &GCParticleVisibilityInputs::GetInputMin, &GCParticleVisibilityInputs::SetInputMin)
        .addProperty("InputMax", &GCParticleVisibilityInputs::GetInputMax, &GCParticleVisibilityInputs::SetInputMax)
        .addProperty("InputPixelVisFade", &GCParticleVisibilityInputs::GetInputPixelVisFade, &GCParticleVisibilityInputs::SetInputPixelVisFade)
        .addProperty("NoPixelVisibilityFallback", &GCParticleVisibilityInputs::GetNoPixelVisibilityFallback, &GCParticleVisibilityInputs::SetNoPixelVisibilityFallback)
        .addProperty("DistanceInputMin", &GCParticleVisibilityInputs::GetDistanceInputMin, &GCParticleVisibilityInputs::SetDistanceInputMin)
        .addProperty("DistanceInputMax", &GCParticleVisibilityInputs::GetDistanceInputMax, &GCParticleVisibilityInputs::SetDistanceInputMax)
        .addProperty("DotInputMin", &GCParticleVisibilityInputs::GetDotInputMin, &GCParticleVisibilityInputs::SetDotInputMin)
        .addProperty("DotInputMax", &GCParticleVisibilityInputs::GetDotInputMax, &GCParticleVisibilityInputs::SetDotInputMax)
        .addProperty("DotCPAngles", &GCParticleVisibilityInputs::GetDotCPAngles, &GCParticleVisibilityInputs::SetDotCPAngles)
        .addProperty("DotCameraAngles", &GCParticleVisibilityInputs::GetDotCameraAngles, &GCParticleVisibilityInputs::SetDotCameraAngles)
        .addProperty("AlphaScaleMin", &GCParticleVisibilityInputs::GetAlphaScaleMin, &GCParticleVisibilityInputs::SetAlphaScaleMin)
        .addProperty("AlphaScaleMax", &GCParticleVisibilityInputs::GetAlphaScaleMax, &GCParticleVisibilityInputs::SetAlphaScaleMax)
        .addProperty("RadiusScaleMin", &GCParticleVisibilityInputs::GetRadiusScaleMin, &GCParticleVisibilityInputs::SetRadiusScaleMin)
        .addProperty("RadiusScaleMax", &GCParticleVisibilityInputs::GetRadiusScaleMax, &GCParticleVisibilityInputs::SetRadiusScaleMax)
        .addProperty("RadiusScaleFOVBase", &GCParticleVisibilityInputs::GetRadiusScaleFOVBase, &GCParticleVisibilityInputs::SetRadiusScaleFOVBase)
        .addProperty("RightEye", &GCParticleVisibilityInputs::GetRightEye, &GCParticleVisibilityInputs::SetRightEye)
        .addFunction("ToPtr", &GCParticleVisibilityInputs::ToPtr)
        .addFunction("IsValid", &GCParticleVisibilityInputs::IsValid)
        .endClass();
}