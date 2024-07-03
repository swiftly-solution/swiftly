#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseTrailRenderer::GCBaseTrailRenderer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseTrailRenderer::GCBaseTrailRenderer(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCBaseTrailRenderer::GetOrientationType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBaseTrailRenderer", "m_nOrientationType");
}
void GCBaseTrailRenderer::SetOrientationType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_nOrientationType", false, value);
}
int32_t GCBaseTrailRenderer::GetOrientationControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseTrailRenderer", "m_nOrientationControlPoint");
}
void GCBaseTrailRenderer::SetOrientationControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_nOrientationControlPoint", false, value);
}
float GCBaseTrailRenderer::GetMinSize() const {
    return GetSchemaValue<float>(m_ptr, "CBaseTrailRenderer", "m_flMinSize");
}
void GCBaseTrailRenderer::SetMinSize(float value) {
    SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flMinSize", false, value);
}
float GCBaseTrailRenderer::GetMaxSize() const {
    return GetSchemaValue<float>(m_ptr, "CBaseTrailRenderer", "m_flMaxSize");
}
void GCBaseTrailRenderer::SetMaxSize(float value) {
    SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flMaxSize", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseTrailRenderer::GetStartFadeSize() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseTrailRenderer", "m_flStartFadeSize"));
    return value;
}
void GCBaseTrailRenderer::SetStartFadeSize(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flStartFadeSize", false, value);
}
GCParticleCollectionRendererFloatInput GCBaseTrailRenderer::GetEndFadeSize() const {
    GCParticleCollectionRendererFloatInput value(GetSchemaPtr(m_ptr, "CBaseTrailRenderer", "m_flEndFadeSize"));
    return value;
}
void GCBaseTrailRenderer::SetEndFadeSize(GCParticleCollectionRendererFloatInput value) {
    SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_flEndFadeSize", false, value);
}
bool GCBaseTrailRenderer::GetClampV() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseTrailRenderer", "m_bClampV");
}
void GCBaseTrailRenderer::SetClampV(bool value) {
    SetSchemaValue(m_ptr, "CBaseTrailRenderer", "m_bClampV", false, value);
}
std::string GCBaseTrailRenderer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseTrailRenderer::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseRendererSource2 GCBaseTrailRenderer::GetParent() const {
    GCBaseRendererSource2 value(m_ptr);
    return value;
}
void GCBaseTrailRenderer::SetParent(GCBaseRendererSource2 value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseTrailRenderer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseTrailRenderer>("CBaseTrailRenderer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OrientationType", &GCBaseTrailRenderer::GetOrientationType, &GCBaseTrailRenderer::SetOrientationType)
        .addProperty("OrientationControlPoint", &GCBaseTrailRenderer::GetOrientationControlPoint, &GCBaseTrailRenderer::SetOrientationControlPoint)
        .addProperty("MinSize", &GCBaseTrailRenderer::GetMinSize, &GCBaseTrailRenderer::SetMinSize)
        .addProperty("MaxSize", &GCBaseTrailRenderer::GetMaxSize, &GCBaseTrailRenderer::SetMaxSize)
        .addProperty("StartFadeSize", &GCBaseTrailRenderer::GetStartFadeSize, &GCBaseTrailRenderer::SetStartFadeSize)
        .addProperty("EndFadeSize", &GCBaseTrailRenderer::GetEndFadeSize, &GCBaseTrailRenderer::SetEndFadeSize)
        .addProperty("ClampV", &GCBaseTrailRenderer::GetClampV, &GCBaseTrailRenderer::SetClampV)
        .addProperty("Parent", &GCBaseTrailRenderer::GetParent, &GCBaseTrailRenderer::SetParent)
        .addFunction("ToPtr", &GCBaseTrailRenderer::ToPtr)
        .addFunction("IsValid", &GCBaseTrailRenderer::IsValid)
        .endClass();
}