#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvVolumetricFogController::GCEnvVolumetricFogController(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvVolumetricFogController::GCEnvVolumetricFogController(void *ptr) {
    m_ptr = ptr;
}
float GCEnvVolumetricFogController::GetScattering() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flScattering");
}
void GCEnvVolumetricFogController::SetScattering(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flScattering", false, value);
}
float GCEnvVolumetricFogController::GetAnisotropy() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flAnisotropy");
}
void GCEnvVolumetricFogController::SetAnisotropy(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flAnisotropy", false, value);
}
float GCEnvVolumetricFogController::GetFadeSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flFadeSpeed");
}
void GCEnvVolumetricFogController::SetFadeSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flFadeSpeed", false, value);
}
float GCEnvVolumetricFogController::GetDrawDistance() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDrawDistance");
}
void GCEnvVolumetricFogController::SetDrawDistance(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDrawDistance", false, value);
}
float GCEnvVolumetricFogController::GetFadeInStart() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flFadeInStart");
}
void GCEnvVolumetricFogController::SetFadeInStart(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flFadeInStart", false, value);
}
float GCEnvVolumetricFogController::GetFadeInEnd() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flFadeInEnd");
}
void GCEnvVolumetricFogController::SetFadeInEnd(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flFadeInEnd", false, value);
}
float GCEnvVolumetricFogController::GetIndirectStrength() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flIndirectStrength");
}
void GCEnvVolumetricFogController::SetIndirectStrength(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flIndirectStrength", false, value);
}
int32_t GCEnvVolumetricFogController::GetIndirectTextureDimX() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimX");
}
void GCEnvVolumetricFogController::SetIndirectTextureDimX(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimX", false, value);
}
int32_t GCEnvVolumetricFogController::GetIndirectTextureDimY() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimY");
}
void GCEnvVolumetricFogController::SetIndirectTextureDimY(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimY", false, value);
}
int32_t GCEnvVolumetricFogController::GetIndirectTextureDimZ() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimZ");
}
void GCEnvVolumetricFogController::SetIndirectTextureDimZ(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nIndirectTextureDimZ", false, value);
}
Vector GCEnvVolumetricFogController::GetBoxMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogController", "m_vBoxMins");
}
void GCEnvVolumetricFogController::SetBoxMins(Vector value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_vBoxMins", false, value);
}
Vector GCEnvVolumetricFogController::GetBoxMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogController", "m_vBoxMaxs");
}
void GCEnvVolumetricFogController::SetBoxMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_vBoxMaxs", false, value);
}
bool GCEnvVolumetricFogController::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bActive");
}
void GCEnvVolumetricFogController::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bActive", false, value);
}
float GCEnvVolumetricFogController::GetStartAnisoTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartAnisoTime");
}
void GCEnvVolumetricFogController::SetStartAnisoTime(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartAnisoTime", false, value);
}
float GCEnvVolumetricFogController::GetStartScatterTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartScatterTime");
}
void GCEnvVolumetricFogController::SetStartScatterTime(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartScatterTime", false, value);
}
float GCEnvVolumetricFogController::GetStartDrawDistanceTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartDrawDistanceTime");
}
void GCEnvVolumetricFogController::SetStartDrawDistanceTime(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartDrawDistanceTime", false, value);
}
float GCEnvVolumetricFogController::GetStartAnisotropy() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartAnisotropy");
}
void GCEnvVolumetricFogController::SetStartAnisotropy(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartAnisotropy", false, value);
}
float GCEnvVolumetricFogController::GetStartScattering() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartScattering");
}
void GCEnvVolumetricFogController::SetStartScattering(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartScattering", false, value);
}
float GCEnvVolumetricFogController::GetStartDrawDistance() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flStartDrawDistance");
}
void GCEnvVolumetricFogController::SetStartDrawDistance(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flStartDrawDistance", false, value);
}
float GCEnvVolumetricFogController::GetDefaultAnisotropy() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDefaultAnisotropy");
}
void GCEnvVolumetricFogController::SetDefaultAnisotropy(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDefaultAnisotropy", false, value);
}
float GCEnvVolumetricFogController::GetDefaultScattering() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDefaultScattering");
}
void GCEnvVolumetricFogController::SetDefaultScattering(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDefaultScattering", false, value);
}
float GCEnvVolumetricFogController::GetDefaultDrawDistance() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_flDefaultDrawDistance");
}
void GCEnvVolumetricFogController::SetDefaultDrawDistance(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_flDefaultDrawDistance", false, value);
}
bool GCEnvVolumetricFogController::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bStartDisabled");
}
void GCEnvVolumetricFogController::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bStartDisabled", false, value);
}
bool GCEnvVolumetricFogController::GetEnableIndirect() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bEnableIndirect");
}
void GCEnvVolumetricFogController::SetEnableIndirect(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bEnableIndirect", false, value);
}
bool GCEnvVolumetricFogController::GetIndirectUseLPVs() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bIndirectUseLPVs");
}
void GCEnvVolumetricFogController::SetIndirectUseLPVs(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bIndirectUseLPVs", false, value);
}
bool GCEnvVolumetricFogController::GetIsMaster() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bIsMaster");
}
void GCEnvVolumetricFogController::SetIsMaster(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bIsMaster", false, value);
}
int32_t GCEnvVolumetricFogController::GetForceRefreshCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvVolumetricFogController", "m_nForceRefreshCount");
}
void GCEnvVolumetricFogController::SetForceRefreshCount(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_nForceRefreshCount", false, value);
}
float GCEnvVolumetricFogController::GetNoiseSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_fNoiseSpeed");
}
void GCEnvVolumetricFogController::SetNoiseSpeed(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_fNoiseSpeed", false, value);
}
float GCEnvVolumetricFogController::GetNoiseStrength() const {
    return GetSchemaValue<float>(m_ptr, "CEnvVolumetricFogController", "m_fNoiseStrength");
}
void GCEnvVolumetricFogController::SetNoiseStrength(float value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_fNoiseStrength", false, value);
}
Vector GCEnvVolumetricFogController::GetNoiseScale() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvVolumetricFogController", "m_vNoiseScale");
}
void GCEnvVolumetricFogController::SetNoiseScale(Vector value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_vNoiseScale", false, value);
}
bool GCEnvVolumetricFogController::GetFirstTime() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvVolumetricFogController", "m_bFirstTime");
}
void GCEnvVolumetricFogController::SetFirstTime(bool value) {
    SetSchemaValue(m_ptr, "CEnvVolumetricFogController", "m_bFirstTime", false, value);
}
std::string GCEnvVolumetricFogController::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvVolumetricFogController::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvVolumetricFogController::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvVolumetricFogController::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvVolumetricFogController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvVolumetricFogController>("CEnvVolumetricFogController")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Scattering", &GCEnvVolumetricFogController::GetScattering, &GCEnvVolumetricFogController::SetScattering)
        .addProperty("Anisotropy", &GCEnvVolumetricFogController::GetAnisotropy, &GCEnvVolumetricFogController::SetAnisotropy)
        .addProperty("FadeSpeed", &GCEnvVolumetricFogController::GetFadeSpeed, &GCEnvVolumetricFogController::SetFadeSpeed)
        .addProperty("DrawDistance", &GCEnvVolumetricFogController::GetDrawDistance, &GCEnvVolumetricFogController::SetDrawDistance)
        .addProperty("FadeInStart", &GCEnvVolumetricFogController::GetFadeInStart, &GCEnvVolumetricFogController::SetFadeInStart)
        .addProperty("FadeInEnd", &GCEnvVolumetricFogController::GetFadeInEnd, &GCEnvVolumetricFogController::SetFadeInEnd)
        .addProperty("IndirectStrength", &GCEnvVolumetricFogController::GetIndirectStrength, &GCEnvVolumetricFogController::SetIndirectStrength)
        .addProperty("IndirectTextureDimX", &GCEnvVolumetricFogController::GetIndirectTextureDimX, &GCEnvVolumetricFogController::SetIndirectTextureDimX)
        .addProperty("IndirectTextureDimY", &GCEnvVolumetricFogController::GetIndirectTextureDimY, &GCEnvVolumetricFogController::SetIndirectTextureDimY)
        .addProperty("IndirectTextureDimZ", &GCEnvVolumetricFogController::GetIndirectTextureDimZ, &GCEnvVolumetricFogController::SetIndirectTextureDimZ)
        .addProperty("BoxMins", &GCEnvVolumetricFogController::GetBoxMins, &GCEnvVolumetricFogController::SetBoxMins)
        .addProperty("BoxMaxs", &GCEnvVolumetricFogController::GetBoxMaxs, &GCEnvVolumetricFogController::SetBoxMaxs)
        .addProperty("Active", &GCEnvVolumetricFogController::GetActive, &GCEnvVolumetricFogController::SetActive)
        .addProperty("StartAnisoTime", &GCEnvVolumetricFogController::GetStartAnisoTime, &GCEnvVolumetricFogController::SetStartAnisoTime)
        .addProperty("StartScatterTime", &GCEnvVolumetricFogController::GetStartScatterTime, &GCEnvVolumetricFogController::SetStartScatterTime)
        .addProperty("StartDrawDistanceTime", &GCEnvVolumetricFogController::GetStartDrawDistanceTime, &GCEnvVolumetricFogController::SetStartDrawDistanceTime)
        .addProperty("StartAnisotropy", &GCEnvVolumetricFogController::GetStartAnisotropy, &GCEnvVolumetricFogController::SetStartAnisotropy)
        .addProperty("StartScattering", &GCEnvVolumetricFogController::GetStartScattering, &GCEnvVolumetricFogController::SetStartScattering)
        .addProperty("StartDrawDistance", &GCEnvVolumetricFogController::GetStartDrawDistance, &GCEnvVolumetricFogController::SetStartDrawDistance)
        .addProperty("DefaultAnisotropy", &GCEnvVolumetricFogController::GetDefaultAnisotropy, &GCEnvVolumetricFogController::SetDefaultAnisotropy)
        .addProperty("DefaultScattering", &GCEnvVolumetricFogController::GetDefaultScattering, &GCEnvVolumetricFogController::SetDefaultScattering)
        .addProperty("DefaultDrawDistance", &GCEnvVolumetricFogController::GetDefaultDrawDistance, &GCEnvVolumetricFogController::SetDefaultDrawDistance)
        .addProperty("StartDisabled", &GCEnvVolumetricFogController::GetStartDisabled, &GCEnvVolumetricFogController::SetStartDisabled)
        .addProperty("EnableIndirect", &GCEnvVolumetricFogController::GetEnableIndirect, &GCEnvVolumetricFogController::SetEnableIndirect)
        .addProperty("IndirectUseLPVs", &GCEnvVolumetricFogController::GetIndirectUseLPVs, &GCEnvVolumetricFogController::SetIndirectUseLPVs)
        .addProperty("IsMaster", &GCEnvVolumetricFogController::GetIsMaster, &GCEnvVolumetricFogController::SetIsMaster)
        .addProperty("ForceRefreshCount", &GCEnvVolumetricFogController::GetForceRefreshCount, &GCEnvVolumetricFogController::SetForceRefreshCount)
        .addProperty("NoiseSpeed", &GCEnvVolumetricFogController::GetNoiseSpeed, &GCEnvVolumetricFogController::SetNoiseSpeed)
        .addProperty("NoiseStrength", &GCEnvVolumetricFogController::GetNoiseStrength, &GCEnvVolumetricFogController::SetNoiseStrength)
        .addProperty("NoiseScale", &GCEnvVolumetricFogController::GetNoiseScale, &GCEnvVolumetricFogController::SetNoiseScale)
        .addProperty("FirstTime", &GCEnvVolumetricFogController::GetFirstTime, &GCEnvVolumetricFogController::SetFirstTime)
        .addProperty("Parent", &GCEnvVolumetricFogController::GetParent, &GCEnvVolumetricFogController::SetParent)
        .addFunction("ToPtr", &GCEnvVolumetricFogController::ToPtr)
        .addFunction("IsValid", &GCEnvVolumetricFogController::IsValid)
        .endClass();
}