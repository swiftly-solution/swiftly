#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSceneObject_t::GSceneObject_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSceneObject_t::GSceneObject_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GSceneObject_t::GetObjectID() const {
    return GetSchemaValue<uint32_t>(m_ptr, "SceneObject_t", "m_nObjectID");
}
void GSceneObject_t::SetObjectID(uint32_t value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_nObjectID", true, value);
}
std::vector<Vector4D> GSceneObject_t::GetTransform() const {
    Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "SceneObject_t", "m_vTransform"); std::vector<Vector4D> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GSceneObject_t::SetTransform(std::vector<Vector4D> value) {
    Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "SceneObject_t", "m_vTransform"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "SceneObject_t", "m_vTransform", true, outValue);
}
float GSceneObject_t::GetFadeStartDistance() const {
    return GetSchemaValue<float>(m_ptr, "SceneObject_t", "m_flFadeStartDistance");
}
void GSceneObject_t::SetFadeStartDistance(float value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_flFadeStartDistance", true, value);
}
float GSceneObject_t::GetFadeEndDistance() const {
    return GetSchemaValue<float>(m_ptr, "SceneObject_t", "m_flFadeEndDistance");
}
void GSceneObject_t::SetFadeEndDistance(float value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_flFadeEndDistance", true, value);
}
Vector4D GSceneObject_t::GetTintColor() const {
    return GetSchemaValue<Vector4D>(m_ptr, "SceneObject_t", "m_vTintColor");
}
void GSceneObject_t::SetTintColor(Vector4D value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_vTintColor", true, value);
}
std::string GSceneObject_t::GetSkin() const {
    return GetSchemaValue<CUtlString>(m_ptr, "SceneObject_t", "m_skin").Get();
}
void GSceneObject_t::SetSkin(std::string value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_skin", true, CUtlString(value.c_str()));
}
uint64_t GSceneObject_t::GetObjectTypeFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "SceneObject_t", "m_nObjectTypeFlags");
}
void GSceneObject_t::SetObjectTypeFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_nObjectTypeFlags", true, value);
}
Vector GSceneObject_t::GetLightingOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "SceneObject_t", "m_vLightingOrigin");
}
void GSceneObject_t::SetLightingOrigin(Vector value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_vLightingOrigin", true, value);
}
int16_t GSceneObject_t::GetOverlayRenderOrder() const {
    return GetSchemaValue<int16_t>(m_ptr, "SceneObject_t", "m_nOverlayRenderOrder");
}
void GSceneObject_t::SetOverlayRenderOrder(int16_t value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_nOverlayRenderOrder", true, value);
}
int16_t GSceneObject_t::GetLODOverride() const {
    return GetSchemaValue<int16_t>(m_ptr, "SceneObject_t", "m_nLODOverride");
}
void GSceneObject_t::SetLODOverride(int16_t value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_nLODOverride", true, value);
}
int32_t GSceneObject_t::GetCubeMapPrecomputedHandshake() const {
    return GetSchemaValue<int32_t>(m_ptr, "SceneObject_t", "m_nCubeMapPrecomputedHandshake");
}
void GSceneObject_t::SetCubeMapPrecomputedHandshake(int32_t value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_nCubeMapPrecomputedHandshake", true, value);
}
int32_t GSceneObject_t::GetLightProbeVolumePrecomputedHandshake() const {
    return GetSchemaValue<int32_t>(m_ptr, "SceneObject_t", "m_nLightProbeVolumePrecomputedHandshake");
}
void GSceneObject_t::SetLightProbeVolumePrecomputedHandshake(int32_t value) {
    SetSchemaValue(m_ptr, "SceneObject_t", "m_nLightProbeVolumePrecomputedHandshake", true, value);
}
std::string GSceneObject_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSceneObject_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSceneObject_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSceneObject_t>("SceneObject_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ObjectID", &GSceneObject_t::GetObjectID, &GSceneObject_t::SetObjectID)
        .addProperty("Transform", &GSceneObject_t::GetTransform, &GSceneObject_t::SetTransform)
        .addProperty("FadeStartDistance", &GSceneObject_t::GetFadeStartDistance, &GSceneObject_t::SetFadeStartDistance)
        .addProperty("FadeEndDistance", &GSceneObject_t::GetFadeEndDistance, &GSceneObject_t::SetFadeEndDistance)
        .addProperty("TintColor", &GSceneObject_t::GetTintColor, &GSceneObject_t::SetTintColor)
        .addProperty("Skin", &GSceneObject_t::GetSkin, &GSceneObject_t::SetSkin)
        .addProperty("ObjectTypeFlags", &GSceneObject_t::GetObjectTypeFlags, &GSceneObject_t::SetObjectTypeFlags)
        .addProperty("LightingOrigin", &GSceneObject_t::GetLightingOrigin, &GSceneObject_t::SetLightingOrigin)
        .addProperty("OverlayRenderOrder", &GSceneObject_t::GetOverlayRenderOrder, &GSceneObject_t::SetOverlayRenderOrder)
        .addProperty("LODOverride", &GSceneObject_t::GetLODOverride, &GSceneObject_t::SetLODOverride)
        .addProperty("CubeMapPrecomputedHandshake", &GSceneObject_t::GetCubeMapPrecomputedHandshake, &GSceneObject_t::SetCubeMapPrecomputedHandshake)
        .addProperty("LightProbeVolumePrecomputedHandshake", &GSceneObject_t::GetLightProbeVolumePrecomputedHandshake, &GSceneObject_t::SetLightProbeVolumePrecomputedHandshake)
        .addFunction("ToPtr", &GSceneObject_t::ToPtr)
        .addFunction("IsValid", &GSceneObject_t::IsValid)
        .endClass();
}