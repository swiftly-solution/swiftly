#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gfogparams_t::Gfogparams_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gfogparams_t::Gfogparams_t(void *ptr) {
    m_ptr = ptr;
}
Vector Gfogparams_t::GetDirPrimary() const {
    return GetSchemaValue<Vector>(m_ptr, "fogparams_t", "dirPrimary");
}
void Gfogparams_t::SetDirPrimary(Vector value) {
    SetSchemaValue(m_ptr, "fogparams_t", "dirPrimary", true, value);
}
Color Gfogparams_t::GetColorPrimary() const {
    return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorPrimary");
}
void Gfogparams_t::SetColorPrimary(Color value) {
    SetSchemaValue(m_ptr, "fogparams_t", "colorPrimary", true, value);
}
Color Gfogparams_t::GetColorSecondary() const {
    return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorSecondary");
}
void Gfogparams_t::SetColorSecondary(Color value) {
    SetSchemaValue(m_ptr, "fogparams_t", "colorSecondary", true, value);
}
Color Gfogparams_t::GetColorPrimaryLerpTo() const {
    return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorPrimaryLerpTo");
}
void Gfogparams_t::SetColorPrimaryLerpTo(Color value) {
    SetSchemaValue(m_ptr, "fogparams_t", "colorPrimaryLerpTo", true, value);
}
Color Gfogparams_t::GetColorSecondaryLerpTo() const {
    return GetSchemaValue<Color>(m_ptr, "fogparams_t", "colorSecondaryLerpTo");
}
void Gfogparams_t::SetColorSecondaryLerpTo(Color value) {
    SetSchemaValue(m_ptr, "fogparams_t", "colorSecondaryLerpTo", true, value);
}
float Gfogparams_t::GetStart() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "start");
}
void Gfogparams_t::SetStart(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "start", true, value);
}
float Gfogparams_t::GetEnd() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "end");
}
void Gfogparams_t::SetEnd(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "end", true, value);
}
float Gfogparams_t::GetFarz() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "farz");
}
void Gfogparams_t::SetFarz(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "farz", true, value);
}
float Gfogparams_t::GetMaxdensity() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "maxdensity");
}
void Gfogparams_t::SetMaxdensity(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "maxdensity", true, value);
}
float Gfogparams_t::GetExponent() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "exponent");
}
void Gfogparams_t::SetExponent(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "exponent", true, value);
}
float Gfogparams_t::GetHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "HDRColorScale");
}
void Gfogparams_t::SetHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "HDRColorScale", true, value);
}
float Gfogparams_t::GetSkyboxFogFactor() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "skyboxFogFactor");
}
void Gfogparams_t::SetSkyboxFogFactor(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "skyboxFogFactor", true, value);
}
float Gfogparams_t::GetSkyboxFogFactorLerpTo() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "skyboxFogFactorLerpTo");
}
void Gfogparams_t::SetSkyboxFogFactorLerpTo(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "skyboxFogFactorLerpTo", true, value);
}
float Gfogparams_t::GetStartLerpTo() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "startLerpTo");
}
void Gfogparams_t::SetStartLerpTo(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "startLerpTo", true, value);
}
float Gfogparams_t::GetEndLerpTo() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "endLerpTo");
}
void Gfogparams_t::SetEndLerpTo(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "endLerpTo", true, value);
}
float Gfogparams_t::GetMaxdensityLerpTo() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "maxdensityLerpTo");
}
void Gfogparams_t::SetMaxdensityLerpTo(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "maxdensityLerpTo", true, value);
}
float Gfogparams_t::GetLerptime() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "lerptime");
}
void Gfogparams_t::SetLerptime(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "lerptime", true, value);
}
float Gfogparams_t::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "duration");
}
void Gfogparams_t::SetDuration(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "duration", true, value);
}
float Gfogparams_t::GetBlendtobackground() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "blendtobackground");
}
void Gfogparams_t::SetBlendtobackground(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "blendtobackground", true, value);
}
float Gfogparams_t::GetScattering() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "scattering");
}
void Gfogparams_t::SetScattering(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "scattering", true, value);
}
float Gfogparams_t::GetLocallightscale() const {
    return GetSchemaValue<float>(m_ptr, "fogparams_t", "locallightscale");
}
void Gfogparams_t::SetLocallightscale(float value) {
    SetSchemaValue(m_ptr, "fogparams_t", "locallightscale", true, value);
}
bool Gfogparams_t::GetEnable() const {
    return GetSchemaValue<bool>(m_ptr, "fogparams_t", "enable");
}
void Gfogparams_t::SetEnable(bool value) {
    SetSchemaValue(m_ptr, "fogparams_t", "enable", true, value);
}
bool Gfogparams_t::GetBlend() const {
    return GetSchemaValue<bool>(m_ptr, "fogparams_t", "blend");
}
void Gfogparams_t::SetBlend(bool value) {
    SetSchemaValue(m_ptr, "fogparams_t", "blend", true, value);
}
bool Gfogparams_t::GetNoReflectionFog() const {
    return GetSchemaValue<bool>(m_ptr, "fogparams_t", "m_bNoReflectionFog");
}
void Gfogparams_t::SetNoReflectionFog(bool value) {
    SetSchemaValue(m_ptr, "fogparams_t", "m_bNoReflectionFog", true, value);
}
bool Gfogparams_t::GetPadding() const {
    return GetSchemaValue<bool>(m_ptr, "fogparams_t", "m_bPadding");
}
void Gfogparams_t::SetPadding(bool value) {
    SetSchemaValue(m_ptr, "fogparams_t", "m_bPadding", true, value);
}
std::string Gfogparams_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gfogparams_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassfogparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gfogparams_t>("fogparams_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DirPrimary", &Gfogparams_t::GetDirPrimary, &Gfogparams_t::SetDirPrimary)
        .addProperty("ColorPrimary", &Gfogparams_t::GetColorPrimary, &Gfogparams_t::SetColorPrimary)
        .addProperty("ColorSecondary", &Gfogparams_t::GetColorSecondary, &Gfogparams_t::SetColorSecondary)
        .addProperty("ColorPrimaryLerpTo", &Gfogparams_t::GetColorPrimaryLerpTo, &Gfogparams_t::SetColorPrimaryLerpTo)
        .addProperty("ColorSecondaryLerpTo", &Gfogparams_t::GetColorSecondaryLerpTo, &Gfogparams_t::SetColorSecondaryLerpTo)
        .addProperty("Start", &Gfogparams_t::GetStart, &Gfogparams_t::SetStart)
        .addProperty("End", &Gfogparams_t::GetEnd, &Gfogparams_t::SetEnd)
        .addProperty("Farz", &Gfogparams_t::GetFarz, &Gfogparams_t::SetFarz)
        .addProperty("Maxdensity", &Gfogparams_t::GetMaxdensity, &Gfogparams_t::SetMaxdensity)
        .addProperty("Exponent", &Gfogparams_t::GetExponent, &Gfogparams_t::SetExponent)
        .addProperty("HDRColorScale", &Gfogparams_t::GetHDRColorScale, &Gfogparams_t::SetHDRColorScale)
        .addProperty("SkyboxFogFactor", &Gfogparams_t::GetSkyboxFogFactor, &Gfogparams_t::SetSkyboxFogFactor)
        .addProperty("SkyboxFogFactorLerpTo", &Gfogparams_t::GetSkyboxFogFactorLerpTo, &Gfogparams_t::SetSkyboxFogFactorLerpTo)
        .addProperty("StartLerpTo", &Gfogparams_t::GetStartLerpTo, &Gfogparams_t::SetStartLerpTo)
        .addProperty("EndLerpTo", &Gfogparams_t::GetEndLerpTo, &Gfogparams_t::SetEndLerpTo)
        .addProperty("MaxdensityLerpTo", &Gfogparams_t::GetMaxdensityLerpTo, &Gfogparams_t::SetMaxdensityLerpTo)
        .addProperty("Lerptime", &Gfogparams_t::GetLerptime, &Gfogparams_t::SetLerptime)
        .addProperty("Duration", &Gfogparams_t::GetDuration, &Gfogparams_t::SetDuration)
        .addProperty("Blendtobackground", &Gfogparams_t::GetBlendtobackground, &Gfogparams_t::SetBlendtobackground)
        .addProperty("Scattering", &Gfogparams_t::GetScattering, &Gfogparams_t::SetScattering)
        .addProperty("Locallightscale", &Gfogparams_t::GetLocallightscale, &Gfogparams_t::SetLocallightscale)
        .addProperty("Enable", &Gfogparams_t::GetEnable, &Gfogparams_t::SetEnable)
        .addProperty("Blend", &Gfogparams_t::GetBlend, &Gfogparams_t::SetBlend)
        .addProperty("NoReflectionFog", &Gfogparams_t::GetNoReflectionFog, &Gfogparams_t::SetNoReflectionFog)
        .addProperty("Padding", &Gfogparams_t::GetPadding, &Gfogparams_t::SetPadding)
        .addFunction("ToPtr", &Gfogparams_t::ToPtr)
        .addFunction("IsValid", &Gfogparams_t::IsValid)
        .endClass();
}