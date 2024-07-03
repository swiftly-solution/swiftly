#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GTextureControls_t::GTextureControls_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GTextureControls_t::GTextureControls_t(void *ptr) {
    m_ptr = ptr;
}
GCParticleCollectionRendererFloatInput GTextureControls_t::GetFinalTextureScaleU() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureControls_t", "m_flFinalTextureScaleU"));
    return value;
}
void GTextureControls_t::SetFinalTextureScaleU(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureScaleU", true, value);
}
GCParticleCollectionRendererFloatInput GTextureControls_t::GetFinalTextureScaleV() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureControls_t", "m_flFinalTextureScaleV"));
    return value;
}
void GTextureControls_t::SetFinalTextureScaleV(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureScaleV", true, value);
}
GCParticleCollectionRendererFloatInput GTextureControls_t::GetFinalTextureOffsetU() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetU"));
    return value;
}
void GTextureControls_t::SetFinalTextureOffsetU(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetU", true, value);
}
GCParticleCollectionRendererFloatInput GTextureControls_t::GetFinalTextureOffsetV() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetV"));
    return value;
}
void GTextureControls_t::SetFinalTextureOffsetV(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureOffsetV", true, value);
}
GCParticleCollectionRendererFloatInput GTextureControls_t::GetFinalTextureUVRotation() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureControls_t", "m_flFinalTextureUVRotation"));
    return value;
}
void GTextureControls_t::SetFinalTextureUVRotation(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_flFinalTextureUVRotation", true, value);
}
GCParticleCollectionRendererFloatInput GTextureControls_t::GetZoomScale() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureControls_t", "m_flZoomScale"));
    return value;
}
void GTextureControls_t::SetZoomScale(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_flZoomScale", true, value);
}
GCParticleCollectionRendererFloatInput GTextureControls_t::GetDistortion() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "TextureControls_t", "m_flDistortion"));
    return value;
}
void GTextureControls_t::SetDistortion(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_flDistortion", true, value);
}
bool GTextureControls_t::GetRandomizeOffsets() const {
    return GetSchemaValue<bool>(m_ptr, "TextureControls_t", "m_bRandomizeOffsets");
}
void GTextureControls_t::SetRandomizeOffsets(bool value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_bRandomizeOffsets", true, value);
}
bool GTextureControls_t::GetClampUVs() const {
    return GetSchemaValue<bool>(m_ptr, "TextureControls_t", "m_bClampUVs");
}
void GTextureControls_t::SetClampUVs(bool value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_bClampUVs", true, value);
}
uint64_t GTextureControls_t::GetPerParticleBlend() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureControls_t", "m_nPerParticleBlend");
}
void GTextureControls_t::SetPerParticleBlend(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleBlend", true, value);
}
uint64_t GTextureControls_t::GetPerParticleScale() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureControls_t", "m_nPerParticleScale");
}
void GTextureControls_t::SetPerParticleScale(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleScale", true, value);
}
uint64_t GTextureControls_t::GetPerParticleOffsetU() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureControls_t", "m_nPerParticleOffsetU");
}
void GTextureControls_t::SetPerParticleOffsetU(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleOffsetU", true, value);
}
uint64_t GTextureControls_t::GetPerParticleOffsetV() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureControls_t", "m_nPerParticleOffsetV");
}
void GTextureControls_t::SetPerParticleOffsetV(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleOffsetV", true, value);
}
uint64_t GTextureControls_t::GetPerParticleRotation() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureControls_t", "m_nPerParticleRotation");
}
void GTextureControls_t::SetPerParticleRotation(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleRotation", true, value);
}
uint64_t GTextureControls_t::GetPerParticleZoom() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureControls_t", "m_nPerParticleZoom");
}
void GTextureControls_t::SetPerParticleZoom(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleZoom", true, value);
}
uint64_t GTextureControls_t::GetPerParticleDistortion() const {
    return GetSchemaValue<uint64_t>(m_ptr, "TextureControls_t", "m_nPerParticleDistortion");
}
void GTextureControls_t::SetPerParticleDistortion(uint64_t value) {
    SetSchemaValue(m_ptr, "TextureControls_t", "m_nPerParticleDistortion", true, value);
}
std::string GTextureControls_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GTextureControls_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassTextureControls_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTextureControls_t>("TextureControls_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FinalTextureScaleU", &GTextureControls_t::GetFinalTextureScaleU, &GTextureControls_t::SetFinalTextureScaleU)
        .addProperty("FinalTextureScaleV", &GTextureControls_t::GetFinalTextureScaleV, &GTextureControls_t::SetFinalTextureScaleV)
        .addProperty("FinalTextureOffsetU", &GTextureControls_t::GetFinalTextureOffsetU, &GTextureControls_t::SetFinalTextureOffsetU)
        .addProperty("FinalTextureOffsetV", &GTextureControls_t::GetFinalTextureOffsetV, &GTextureControls_t::SetFinalTextureOffsetV)
        .addProperty("FinalTextureUVRotation", &GTextureControls_t::GetFinalTextureUVRotation, &GTextureControls_t::SetFinalTextureUVRotation)
        .addProperty("ZoomScale", &GTextureControls_t::GetZoomScale, &GTextureControls_t::SetZoomScale)
        .addProperty("Distortion", &GTextureControls_t::GetDistortion, &GTextureControls_t::SetDistortion)
        .addProperty("RandomizeOffsets", &GTextureControls_t::GetRandomizeOffsets, &GTextureControls_t::SetRandomizeOffsets)
        .addProperty("ClampUVs", &GTextureControls_t::GetClampUVs, &GTextureControls_t::SetClampUVs)
        .addProperty("PerParticleBlend", &GTextureControls_t::GetPerParticleBlend, &GTextureControls_t::SetPerParticleBlend)
        .addProperty("PerParticleScale", &GTextureControls_t::GetPerParticleScale, &GTextureControls_t::SetPerParticleScale)
        .addProperty("PerParticleOffsetU", &GTextureControls_t::GetPerParticleOffsetU, &GTextureControls_t::SetPerParticleOffsetU)
        .addProperty("PerParticleOffsetV", &GTextureControls_t::GetPerParticleOffsetV, &GTextureControls_t::SetPerParticleOffsetV)
        .addProperty("PerParticleRotation", &GTextureControls_t::GetPerParticleRotation, &GTextureControls_t::SetPerParticleRotation)
        .addProperty("PerParticleZoom", &GTextureControls_t::GetPerParticleZoom, &GTextureControls_t::SetPerParticleZoom)
        .addProperty("PerParticleDistortion", &GTextureControls_t::GetPerParticleDistortion, &GTextureControls_t::SetPerParticleDistortion)
        .addFunction("ToPtr", &GTextureControls_t::ToPtr)
        .addFunction("IsValid", &GTextureControls_t::IsValid)
        .endClass();
}