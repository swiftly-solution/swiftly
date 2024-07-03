#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointCamera::GCPointCamera(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointCamera::GCPointCamera(void *ptr) {
    m_ptr = ptr;
}
float GCPointCamera::GetFOV() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_FOV");
}
void GCPointCamera::SetFOV(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_FOV", false, value);
}
float GCPointCamera::GetResolution() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_Resolution");
}
void GCPointCamera::SetResolution(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_Resolution", false, value);
}
bool GCPointCamera::GetFogEnable() const {
    return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bFogEnable");
}
void GCPointCamera::SetFogEnable(bool value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_bFogEnable", false, value);
}
Color GCPointCamera::GetFogColor() const {
    return GetSchemaValue<Color>(m_ptr, "CPointCamera", "m_FogColor");
}
void GCPointCamera::SetFogColor(Color value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_FogColor", false, value);
}
float GCPointCamera::GetFogStart() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flFogStart");
}
void GCPointCamera::SetFogStart(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flFogStart", false, value);
}
float GCPointCamera::GetFogEnd() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flFogEnd");
}
void GCPointCamera::SetFogEnd(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flFogEnd", false, value);
}
float GCPointCamera::GetFogMaxDensity() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flFogMaxDensity");
}
void GCPointCamera::SetFogMaxDensity(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flFogMaxDensity", false, value);
}
bool GCPointCamera::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bActive");
}
void GCPointCamera::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_bActive", false, value);
}
bool GCPointCamera::GetUseScreenAspectRatio() const {
    return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bUseScreenAspectRatio");
}
void GCPointCamera::SetUseScreenAspectRatio(bool value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_bUseScreenAspectRatio", false, value);
}
float GCPointCamera::GetAspectRatio() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flAspectRatio");
}
void GCPointCamera::SetAspectRatio(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flAspectRatio", false, value);
}
bool GCPointCamera::GetNoSky() const {
    return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bNoSky");
}
void GCPointCamera::SetNoSky(bool value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_bNoSky", false, value);
}
float GCPointCamera::GetBrightness() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_fBrightness");
}
void GCPointCamera::SetBrightness(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_fBrightness", false, value);
}
float GCPointCamera::GetZFar() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flZFar");
}
void GCPointCamera::SetZFar(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flZFar", false, value);
}
float GCPointCamera::GetZNear() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flZNear");
}
void GCPointCamera::SetZNear(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flZNear", false, value);
}
bool GCPointCamera::GetCanHLTVUse() const {
    return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bCanHLTVUse");
}
void GCPointCamera::SetCanHLTVUse(bool value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_bCanHLTVUse", false, value);
}
bool GCPointCamera::GetDofEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bDofEnabled");
}
void GCPointCamera::SetDofEnabled(bool value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_bDofEnabled", false, value);
}
float GCPointCamera::GetDofNearBlurry() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofNearBlurry");
}
void GCPointCamera::SetDofNearBlurry(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flDofNearBlurry", false, value);
}
float GCPointCamera::GetDofNearCrisp() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofNearCrisp");
}
void GCPointCamera::SetDofNearCrisp(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flDofNearCrisp", false, value);
}
float GCPointCamera::GetDofFarCrisp() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofFarCrisp");
}
void GCPointCamera::SetDofFarCrisp(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flDofFarCrisp", false, value);
}
float GCPointCamera::GetDofFarBlurry() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofFarBlurry");
}
void GCPointCamera::SetDofFarBlurry(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flDofFarBlurry", false, value);
}
float GCPointCamera::GetDofTiltToGround() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_flDofTiltToGround");
}
void GCPointCamera::SetDofTiltToGround(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_flDofTiltToGround", false, value);
}
float GCPointCamera::GetTargetFOV() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_TargetFOV");
}
void GCPointCamera::SetTargetFOV(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_TargetFOV", false, value);
}
float GCPointCamera::GetDegreesPerSecond() const {
    return GetSchemaValue<float>(m_ptr, "CPointCamera", "m_DegreesPerSecond");
}
void GCPointCamera::SetDegreesPerSecond(float value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_DegreesPerSecond", false, value);
}
bool GCPointCamera::GetIsOn() const {
    return GetSchemaValue<bool>(m_ptr, "CPointCamera", "m_bIsOn");
}
void GCPointCamera::SetIsOn(bool value) {
    SetSchemaValue(m_ptr, "CPointCamera", "m_bIsOn", false, value);
}
GCPointCamera GCPointCamera::GetNext() const {
    GCPointCamera value(*GetSchemaValuePtr<void*>(m_ptr, "CPointCamera", "m_pNext"));
    return value;
}
void GCPointCamera::SetNext(GCPointCamera* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Next' is not possible.\n");
}
std::string GCPointCamera::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointCamera::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPointCamera::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPointCamera::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointCamera(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointCamera>("CPointCamera")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FOV", &GCPointCamera::GetFOV, &GCPointCamera::SetFOV)
        .addProperty("Resolution", &GCPointCamera::GetResolution, &GCPointCamera::SetResolution)
        .addProperty("FogEnable", &GCPointCamera::GetFogEnable, &GCPointCamera::SetFogEnable)
        .addProperty("FogColor", &GCPointCamera::GetFogColor, &GCPointCamera::SetFogColor)
        .addProperty("FogStart", &GCPointCamera::GetFogStart, &GCPointCamera::SetFogStart)
        .addProperty("FogEnd", &GCPointCamera::GetFogEnd, &GCPointCamera::SetFogEnd)
        .addProperty("FogMaxDensity", &GCPointCamera::GetFogMaxDensity, &GCPointCamera::SetFogMaxDensity)
        .addProperty("Active", &GCPointCamera::GetActive, &GCPointCamera::SetActive)
        .addProperty("UseScreenAspectRatio", &GCPointCamera::GetUseScreenAspectRatio, &GCPointCamera::SetUseScreenAspectRatio)
        .addProperty("AspectRatio", &GCPointCamera::GetAspectRatio, &GCPointCamera::SetAspectRatio)
        .addProperty("NoSky", &GCPointCamera::GetNoSky, &GCPointCamera::SetNoSky)
        .addProperty("Brightness", &GCPointCamera::GetBrightness, &GCPointCamera::SetBrightness)
        .addProperty("ZFar", &GCPointCamera::GetZFar, &GCPointCamera::SetZFar)
        .addProperty("ZNear", &GCPointCamera::GetZNear, &GCPointCamera::SetZNear)
        .addProperty("CanHLTVUse", &GCPointCamera::GetCanHLTVUse, &GCPointCamera::SetCanHLTVUse)
        .addProperty("DofEnabled", &GCPointCamera::GetDofEnabled, &GCPointCamera::SetDofEnabled)
        .addProperty("DofNearBlurry", &GCPointCamera::GetDofNearBlurry, &GCPointCamera::SetDofNearBlurry)
        .addProperty("DofNearCrisp", &GCPointCamera::GetDofNearCrisp, &GCPointCamera::SetDofNearCrisp)
        .addProperty("DofFarCrisp", &GCPointCamera::GetDofFarCrisp, &GCPointCamera::SetDofFarCrisp)
        .addProperty("DofFarBlurry", &GCPointCamera::GetDofFarBlurry, &GCPointCamera::SetDofFarBlurry)
        .addProperty("DofTiltToGround", &GCPointCamera::GetDofTiltToGround, &GCPointCamera::SetDofTiltToGround)
        .addProperty("TargetFOV", &GCPointCamera::GetTargetFOV, &GCPointCamera::SetTargetFOV)
        .addProperty("DegreesPerSecond", &GCPointCamera::GetDegreesPerSecond, &GCPointCamera::SetDegreesPerSecond)
        .addProperty("IsOn", &GCPointCamera::GetIsOn, &GCPointCamera::SetIsOn)
        .addProperty("Next", &GCPointCamera::GetNext, &GCPointCamera::SetNext)
        .addProperty("Parent", &GCPointCamera::GetParent, &GCPointCamera::SetParent)
        .addFunction("ToPtr", &GCPointCamera::ToPtr)
        .addFunction("IsValid", &GCPointCamera::IsValid)
        .endClass();
}