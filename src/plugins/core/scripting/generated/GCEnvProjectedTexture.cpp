#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvProjectedTexture::GCEnvProjectedTexture(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvProjectedTexture::GCEnvProjectedTexture(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCEnvProjectedTexture::GetTargetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CEnvProjectedTexture", "m_hTargetEntity"));
    return value;
}
void GCEnvProjectedTexture::SetTargetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetEntity' is not possible.\n");
}
bool GCEnvProjectedTexture::GetState() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bState");
}
void GCEnvProjectedTexture::SetState(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bState", false, value);
}
bool GCEnvProjectedTexture::GetAlwaysUpdate() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bAlwaysUpdate");
}
void GCEnvProjectedTexture::SetAlwaysUpdate(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bAlwaysUpdate", false, value);
}
float GCEnvProjectedTexture::GetLightFOV() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flLightFOV");
}
void GCEnvProjectedTexture::SetLightFOV(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flLightFOV", false, value);
}
bool GCEnvProjectedTexture::GetEnableShadows() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bEnableShadows");
}
void GCEnvProjectedTexture::SetEnableShadows(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bEnableShadows", false, value);
}
bool GCEnvProjectedTexture::GetSimpleProjection() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bSimpleProjection");
}
void GCEnvProjectedTexture::SetSimpleProjection(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bSimpleProjection", false, value);
}
bool GCEnvProjectedTexture::GetLightOnlyTarget() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bLightOnlyTarget");
}
void GCEnvProjectedTexture::SetLightOnlyTarget(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bLightOnlyTarget", false, value);
}
bool GCEnvProjectedTexture::GetLightWorld() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bLightWorld");
}
void GCEnvProjectedTexture::SetLightWorld(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bLightWorld", false, value);
}
bool GCEnvProjectedTexture::GetCameraSpace() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bCameraSpace");
}
void GCEnvProjectedTexture::SetCameraSpace(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bCameraSpace", false, value);
}
float GCEnvProjectedTexture::GetBrightnessScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flBrightnessScale");
}
void GCEnvProjectedTexture::SetBrightnessScale(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flBrightnessScale", false, value);
}
Color GCEnvProjectedTexture::GetLightColor() const {
    return GetSchemaValue<Color>(m_ptr, "CEnvProjectedTexture", "m_LightColor");
}
void GCEnvProjectedTexture::SetLightColor(Color value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_LightColor", false, value);
}
float GCEnvProjectedTexture::GetIntensity() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flIntensity");
}
void GCEnvProjectedTexture::SetIntensity(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flIntensity", false, value);
}
float GCEnvProjectedTexture::GetLinearAttenuation() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flLinearAttenuation");
}
void GCEnvProjectedTexture::SetLinearAttenuation(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flLinearAttenuation", false, value);
}
float GCEnvProjectedTexture::GetQuadraticAttenuation() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flQuadraticAttenuation");
}
void GCEnvProjectedTexture::SetQuadraticAttenuation(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flQuadraticAttenuation", false, value);
}
bool GCEnvProjectedTexture::GetVolumetric() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bVolumetric");
}
void GCEnvProjectedTexture::SetVolumetric(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bVolumetric", false, value);
}
float GCEnvProjectedTexture::GetNoiseStrength() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flNoiseStrength");
}
void GCEnvProjectedTexture::SetNoiseStrength(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flNoiseStrength", false, value);
}
float GCEnvProjectedTexture::GetFlashlightTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flFlashlightTime");
}
void GCEnvProjectedTexture::SetFlashlightTime(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flFlashlightTime", false, value);
}
uint32_t GCEnvProjectedTexture::GetNumPlanes() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEnvProjectedTexture", "m_nNumPlanes");
}
void GCEnvProjectedTexture::SetNumPlanes(uint32_t value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_nNumPlanes", false, value);
}
float GCEnvProjectedTexture::GetPlaneOffset() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flPlaneOffset");
}
void GCEnvProjectedTexture::SetPlaneOffset(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flPlaneOffset", false, value);
}
float GCEnvProjectedTexture::GetVolumetricIntensity() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flVolumetricIntensity");
}
void GCEnvProjectedTexture::SetVolumetricIntensity(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flVolumetricIntensity", false, value);
}
float GCEnvProjectedTexture::GetColorTransitionTime() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flColorTransitionTime");
}
void GCEnvProjectedTexture::SetColorTransitionTime(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flColorTransitionTime", false, value);
}
float GCEnvProjectedTexture::GetAmbient() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flAmbient");
}
void GCEnvProjectedTexture::SetAmbient(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flAmbient", false, value);
}
std::string GCEnvProjectedTexture::GetSpotlightTextureName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CEnvProjectedTexture", "m_SpotlightTextureName");
}
void GCEnvProjectedTexture::SetSpotlightTextureName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CEnvProjectedTexture", "m_SpotlightTextureName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
int32_t GCEnvProjectedTexture::GetSpotlightTextureFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvProjectedTexture", "m_nSpotlightTextureFrame");
}
void GCEnvProjectedTexture::SetSpotlightTextureFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_nSpotlightTextureFrame", false, value);
}
uint32_t GCEnvProjectedTexture::GetShadowQuality() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CEnvProjectedTexture", "m_nShadowQuality");
}
void GCEnvProjectedTexture::SetShadowQuality(uint32_t value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_nShadowQuality", false, value);
}
float GCEnvProjectedTexture::GetNearZ() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flNearZ");
}
void GCEnvProjectedTexture::SetNearZ(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flNearZ", false, value);
}
float GCEnvProjectedTexture::GetFarZ() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flFarZ");
}
void GCEnvProjectedTexture::SetFarZ(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flFarZ", false, value);
}
float GCEnvProjectedTexture::GetProjectionSize() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flProjectionSize");
}
void GCEnvProjectedTexture::SetProjectionSize(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flProjectionSize", false, value);
}
float GCEnvProjectedTexture::GetRotation() const {
    return GetSchemaValue<float>(m_ptr, "CEnvProjectedTexture", "m_flRotation");
}
void GCEnvProjectedTexture::SetRotation(float value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_flRotation", false, value);
}
bool GCEnvProjectedTexture::GetFlipHorizontal() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvProjectedTexture", "m_bFlipHorizontal");
}
void GCEnvProjectedTexture::SetFlipHorizontal(bool value) {
    SetSchemaValue(m_ptr, "CEnvProjectedTexture", "m_bFlipHorizontal", false, value);
}
std::string GCEnvProjectedTexture::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvProjectedTexture::IsValid() {
    return (m_ptr != nullptr);
}
GCModelPointEntity GCEnvProjectedTexture::GetParent() const {
    GCModelPointEntity value(m_ptr);
    return value;
}
void GCEnvProjectedTexture::SetParent(GCModelPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvProjectedTexture(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvProjectedTexture>("CEnvProjectedTexture")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetEntity", &GCEnvProjectedTexture::GetTargetEntity, &GCEnvProjectedTexture::SetTargetEntity)
        .addProperty("State", &GCEnvProjectedTexture::GetState, &GCEnvProjectedTexture::SetState)
        .addProperty("AlwaysUpdate", &GCEnvProjectedTexture::GetAlwaysUpdate, &GCEnvProjectedTexture::SetAlwaysUpdate)
        .addProperty("LightFOV", &GCEnvProjectedTexture::GetLightFOV, &GCEnvProjectedTexture::SetLightFOV)
        .addProperty("EnableShadows", &GCEnvProjectedTexture::GetEnableShadows, &GCEnvProjectedTexture::SetEnableShadows)
        .addProperty("SimpleProjection", &GCEnvProjectedTexture::GetSimpleProjection, &GCEnvProjectedTexture::SetSimpleProjection)
        .addProperty("LightOnlyTarget", &GCEnvProjectedTexture::GetLightOnlyTarget, &GCEnvProjectedTexture::SetLightOnlyTarget)
        .addProperty("LightWorld", &GCEnvProjectedTexture::GetLightWorld, &GCEnvProjectedTexture::SetLightWorld)
        .addProperty("CameraSpace", &GCEnvProjectedTexture::GetCameraSpace, &GCEnvProjectedTexture::SetCameraSpace)
        .addProperty("BrightnessScale", &GCEnvProjectedTexture::GetBrightnessScale, &GCEnvProjectedTexture::SetBrightnessScale)
        .addProperty("LightColor", &GCEnvProjectedTexture::GetLightColor, &GCEnvProjectedTexture::SetLightColor)
        .addProperty("Intensity", &GCEnvProjectedTexture::GetIntensity, &GCEnvProjectedTexture::SetIntensity)
        .addProperty("LinearAttenuation", &GCEnvProjectedTexture::GetLinearAttenuation, &GCEnvProjectedTexture::SetLinearAttenuation)
        .addProperty("QuadraticAttenuation", &GCEnvProjectedTexture::GetQuadraticAttenuation, &GCEnvProjectedTexture::SetQuadraticAttenuation)
        .addProperty("Volumetric", &GCEnvProjectedTexture::GetVolumetric, &GCEnvProjectedTexture::SetVolumetric)
        .addProperty("NoiseStrength", &GCEnvProjectedTexture::GetNoiseStrength, &GCEnvProjectedTexture::SetNoiseStrength)
        .addProperty("FlashlightTime", &GCEnvProjectedTexture::GetFlashlightTime, &GCEnvProjectedTexture::SetFlashlightTime)
        .addProperty("NumPlanes", &GCEnvProjectedTexture::GetNumPlanes, &GCEnvProjectedTexture::SetNumPlanes)
        .addProperty("PlaneOffset", &GCEnvProjectedTexture::GetPlaneOffset, &GCEnvProjectedTexture::SetPlaneOffset)
        .addProperty("VolumetricIntensity", &GCEnvProjectedTexture::GetVolumetricIntensity, &GCEnvProjectedTexture::SetVolumetricIntensity)
        .addProperty("ColorTransitionTime", &GCEnvProjectedTexture::GetColorTransitionTime, &GCEnvProjectedTexture::SetColorTransitionTime)
        .addProperty("Ambient", &GCEnvProjectedTexture::GetAmbient, &GCEnvProjectedTexture::SetAmbient)
        .addProperty("SpotlightTextureName", &GCEnvProjectedTexture::GetSpotlightTextureName, &GCEnvProjectedTexture::SetSpotlightTextureName)
        .addProperty("SpotlightTextureFrame", &GCEnvProjectedTexture::GetSpotlightTextureFrame, &GCEnvProjectedTexture::SetSpotlightTextureFrame)
        .addProperty("ShadowQuality", &GCEnvProjectedTexture::GetShadowQuality, &GCEnvProjectedTexture::SetShadowQuality)
        .addProperty("NearZ", &GCEnvProjectedTexture::GetNearZ, &GCEnvProjectedTexture::SetNearZ)
        .addProperty("FarZ", &GCEnvProjectedTexture::GetFarZ, &GCEnvProjectedTexture::SetFarZ)
        .addProperty("ProjectionSize", &GCEnvProjectedTexture::GetProjectionSize, &GCEnvProjectedTexture::SetProjectionSize)
        .addProperty("Rotation", &GCEnvProjectedTexture::GetRotation, &GCEnvProjectedTexture::SetRotation)
        .addProperty("FlipHorizontal", &GCEnvProjectedTexture::GetFlipHorizontal, &GCEnvProjectedTexture::SetFlipHorizontal)
        .addProperty("Parent", &GCEnvProjectedTexture::GetParent, &GCEnvProjectedTexture::SetParent)
        .addFunction("ToPtr", &GCEnvProjectedTexture::ToPtr)
        .addFunction("IsValid", &GCEnvProjectedTexture::IsValid)
        .endClass();
}