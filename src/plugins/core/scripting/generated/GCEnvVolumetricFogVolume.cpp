#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvVolumetricFogVolume::GCEnvVolumetricFogVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvVolumetricFogVolume::GCEnvVolumetricFogVolume(void *ptr) {
    m_ptr = ptr;
}
bool GCEnvVolumetricFogVolume::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bActive");
}
void GCEnvVolumetricFogVolume::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bActive", false, value);
}
Vector GCEnvVolumetricFogVolume::GetBoxMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMins");
}
void GCEnvVolumetricFogVolume::SetBoxMins(Vector value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMins", false, value);
}
Vector GCEnvVolumetricFogVolume::GetBoxMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMaxs");
}
void GCEnvVolumetricFogVolume::SetBoxMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_vBoxMaxs", false, value);
}
bool GCEnvVolumetricFogVolume::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bStartDisabled");
}
void GCEnvVolumetricFogVolume::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bStartDisabled", false, value);
}
float GCEnvVolumetricFogVolume::GetStrength() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_flStrength");
}
void GCEnvVolumetricFogVolume::SetStrength(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_flStrength", false, value);
}
int32_t GCEnvVolumetricFogVolume::GetFalloffShape() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogVolume", "m_nFalloffShape");
}
void GCEnvVolumetricFogVolume::SetFalloffShape(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_nFalloffShape", false, value);
}
float GCEnvVolumetricFogVolume::GetFalloffExponent() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_flFalloffExponent");
}
void GCEnvVolumetricFogVolume::SetFalloffExponent(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_flFalloffExponent", false, value);
}
float GCEnvVolumetricFogVolume::GetHeightFogDepth() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_flHeightFogDepth");
}
void GCEnvVolumetricFogVolume::SetHeightFogDepth(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_flHeightFogDepth", false, value);
}
float GCEnvVolumetricFogVolume::GetHeightFogEdgeWidth() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fHeightFogEdgeWidth");
}
void GCEnvVolumetricFogVolume::SetHeightFogEdgeWidth(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fHeightFogEdgeWidth", false, value);
}
float GCEnvVolumetricFogVolume::GetIndirectLightStrength() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fIndirectLightStrength");
}
void GCEnvVolumetricFogVolume::SetIndirectLightStrength(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fIndirectLightStrength", false, value);
}
float GCEnvVolumetricFogVolume::GetSunLightStrength() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fSunLightStrength");
}
void GCEnvVolumetricFogVolume::SetSunLightStrength(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fSunLightStrength", false, value);
}
float GCEnvVolumetricFogVolume::GetNoiseStrength() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogVolume", "m_fNoiseStrength");
}
void GCEnvVolumetricFogVolume::SetNoiseStrength(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_fNoiseStrength", false, value);
}
bool GCEnvVolumetricFogVolume::GetOverrideIndirectLightStrength() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideIndirectLightStrength");
}
void GCEnvVolumetricFogVolume::SetOverrideIndirectLightStrength(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideIndirectLightStrength", false, value);
}
bool GCEnvVolumetricFogVolume::GetOverrideSunLightStrength() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideSunLightStrength");
}
void GCEnvVolumetricFogVolume::SetOverrideSunLightStrength(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideSunLightStrength", false, value);
}
bool GCEnvVolumetricFogVolume::GetOverrideNoiseStrength() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideNoiseStrength");
}
void GCEnvVolumetricFogVolume::SetOverrideNoiseStrength(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogVolume", "m_bOverrideNoiseStrength", false, value);
}
std::string GCEnvVolumetricFogVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvVolumetricFogVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvVolumetricFogVolume::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvVolumetricFogVolume::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvVolumetricFogVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvVolumetricFogVolume>("CEnvVolumetricFogVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Active", &GCEnvVolumetricFogVolume::GetActive, &GCEnvVolumetricFogVolume::SetActive)
        .addProperty("BoxMins", &GCEnvVolumetricFogVolume::GetBoxMins, &GCEnvVolumetricFogVolume::SetBoxMins)
        .addProperty("BoxMaxs", &GCEnvVolumetricFogVolume::GetBoxMaxs, &GCEnvVolumetricFogVolume::SetBoxMaxs)
        .addProperty("StartDisabled", &GCEnvVolumetricFogVolume::GetStartDisabled, &GCEnvVolumetricFogVolume::SetStartDisabled)
        .addProperty("Strength", &GCEnvVolumetricFogVolume::GetStrength, &GCEnvVolumetricFogVolume::SetStrength)
        .addProperty("FalloffShape", &GCEnvVolumetricFogVolume::GetFalloffShape, &GCEnvVolumetricFogVolume::SetFalloffShape)
        .addProperty("FalloffExponent", &GCEnvVolumetricFogVolume::GetFalloffExponent, &GCEnvVolumetricFogVolume::SetFalloffExponent)
        .addProperty("HeightFogDepth", &GCEnvVolumetricFogVolume::GetHeightFogDepth, &GCEnvVolumetricFogVolume::SetHeightFogDepth)
        .addProperty("HeightFogEdgeWidth", &GCEnvVolumetricFogVolume::GetHeightFogEdgeWidth, &GCEnvVolumetricFogVolume::SetHeightFogEdgeWidth)
        .addProperty("IndirectLightStrength", &GCEnvVolumetricFogVolume::GetIndirectLightStrength, &GCEnvVolumetricFogVolume::SetIndirectLightStrength)
        .addProperty("SunLightStrength", &GCEnvVolumetricFogVolume::GetSunLightStrength, &GCEnvVolumetricFogVolume::SetSunLightStrength)
        .addProperty("NoiseStrength", &GCEnvVolumetricFogVolume::GetNoiseStrength, &GCEnvVolumetricFogVolume::SetNoiseStrength)
        .addProperty("OverrideIndirectLightStrength", &GCEnvVolumetricFogVolume::GetOverrideIndirectLightStrength, &GCEnvVolumetricFogVolume::SetOverrideIndirectLightStrength)
        .addProperty("OverrideSunLightStrength", &GCEnvVolumetricFogVolume::GetOverrideSunLightStrength, &GCEnvVolumetricFogVolume::SetOverrideSunLightStrength)
        .addProperty("OverrideNoiseStrength", &GCEnvVolumetricFogVolume::GetOverrideNoiseStrength, &GCEnvVolumetricFogVolume::SetOverrideNoiseStrength)
        .addProperty("Parent", &GCEnvVolumetricFogVolume::GetParent, &GCEnvVolumetricFogVolume::SetParent)
        .addFunction("ToPtr", &GCEnvVolumetricFogVolume::ToPtr)
        .addFunction("IsValid", &GCEnvVolumetricFogVolume::IsValid)
        .endClass();
}