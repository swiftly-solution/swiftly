#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvCubemap::GCEnvCubemap(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvCubemap::GCEnvCubemap(void *ptr) {
    m_ptr = ptr;
}
bool GCEnvCubemap::GetEntity_bCustomCubemapTexture() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bCustomCubemapTexture");
}
void GCEnvCubemap::SetEntity_bCustomCubemapTexture(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bCustomCubemapTexture", false, value);
}
float GCEnvCubemap::GetEntity_flInfluenceRadius() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemap", "m_Entity_flInfluenceRadius");
}
void GCEnvCubemap::SetEntity_flInfluenceRadius(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_flInfluenceRadius", false, value);
}
Vector GCEnvCubemap::GetEntity_vBoxProjectMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMins");
}
void GCEnvCubemap::SetEntity_vBoxProjectMins(Vector value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMins", false, value);
}
Vector GCEnvCubemap::GetEntity_vBoxProjectMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMaxs");
}
void GCEnvCubemap::SetEntity_vBoxProjectMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_vBoxProjectMaxs", false, value);
}
bool GCEnvCubemap::GetEntity_bMoveable() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bMoveable");
}
void GCEnvCubemap::SetEntity_bMoveable(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bMoveable", false, value);
}
int32_t GCEnvCubemap::GetEntity_nHandshake() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemap", "m_Entity_nHandshake");
}
void GCEnvCubemap::SetEntity_nHandshake(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_nHandshake", false, value);
}
int32_t GCEnvCubemap::GetEntity_nEnvCubeMapArrayIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemap", "m_Entity_nEnvCubeMapArrayIndex");
}
void GCEnvCubemap::SetEntity_nEnvCubeMapArrayIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_nEnvCubeMapArrayIndex", false, value);
}
int32_t GCEnvCubemap::GetEntity_nPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCubemap", "m_Entity_nPriority");
}
void GCEnvCubemap::SetEntity_nPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_nPriority", false, value);
}
float GCEnvCubemap::GetEntity_flEdgeFadeDist() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemap", "m_Entity_flEdgeFadeDist");
}
void GCEnvCubemap::SetEntity_flEdgeFadeDist(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_flEdgeFadeDist", false, value);
}
Vector GCEnvCubemap::GetEntity_vEdgeFadeDists() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvCubemap", "m_Entity_vEdgeFadeDists");
}
void GCEnvCubemap::SetEntity_vEdgeFadeDists(Vector value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_vEdgeFadeDists", false, value);
}
float GCEnvCubemap::GetEntity_flDiffuseScale() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCubemap", "m_Entity_flDiffuseScale");
}
void GCEnvCubemap::SetEntity_flDiffuseScale(float value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_flDiffuseScale", false, value);
}
bool GCEnvCubemap::GetEntity_bStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bStartDisabled");
}
void GCEnvCubemap::SetEntity_bStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bStartDisabled", false, value);
}
bool GCEnvCubemap::GetEntity_bDefaultEnvMap() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bDefaultEnvMap");
}
void GCEnvCubemap::SetEntity_bDefaultEnvMap(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bDefaultEnvMap", false, value);
}
bool GCEnvCubemap::GetEntity_bDefaultSpecEnvMap() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bDefaultSpecEnvMap");
}
void GCEnvCubemap::SetEntity_bDefaultSpecEnvMap(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bDefaultSpecEnvMap", false, value);
}
bool GCEnvCubemap::GetEntity_bIndoorCubeMap() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bIndoorCubeMap");
}
void GCEnvCubemap::SetEntity_bIndoorCubeMap(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bIndoorCubeMap", false, value);
}
bool GCEnvCubemap::GetEntity_bCopyDiffuseFromDefaultCubemap() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bCopyDiffuseFromDefaultCubemap");
}
void GCEnvCubemap::SetEntity_bCopyDiffuseFromDefaultCubemap(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bCopyDiffuseFromDefaultCubemap", false, value);
}
bool GCEnvCubemap::GetEntity_bEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCubemap", "m_Entity_bEnabled");
}
void GCEnvCubemap::SetEntity_bEnabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvCubemap", "m_Entity_bEnabled", false, value);
}
std::string GCEnvCubemap::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvCubemap::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvCubemap::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvCubemap::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvCubemap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCubemap>("CEnvCubemap")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entity_bCustomCubemapTexture", &GCEnvCubemap::GetEntity_bCustomCubemapTexture, &GCEnvCubemap::SetEntity_bCustomCubemapTexture)
        .addProperty("Entity_flInfluenceRadius", &GCEnvCubemap::GetEntity_flInfluenceRadius, &GCEnvCubemap::SetEntity_flInfluenceRadius)
        .addProperty("Entity_vBoxProjectMins", &GCEnvCubemap::GetEntity_vBoxProjectMins, &GCEnvCubemap::SetEntity_vBoxProjectMins)
        .addProperty("Entity_vBoxProjectMaxs", &GCEnvCubemap::GetEntity_vBoxProjectMaxs, &GCEnvCubemap::SetEntity_vBoxProjectMaxs)
        .addProperty("Entity_bMoveable", &GCEnvCubemap::GetEntity_bMoveable, &GCEnvCubemap::SetEntity_bMoveable)
        .addProperty("Entity_nHandshake", &GCEnvCubemap::GetEntity_nHandshake, &GCEnvCubemap::SetEntity_nHandshake)
        .addProperty("Entity_nEnvCubeMapArrayIndex", &GCEnvCubemap::GetEntity_nEnvCubeMapArrayIndex, &GCEnvCubemap::SetEntity_nEnvCubeMapArrayIndex)
        .addProperty("Entity_nPriority", &GCEnvCubemap::GetEntity_nPriority, &GCEnvCubemap::SetEntity_nPriority)
        .addProperty("Entity_flEdgeFadeDist", &GCEnvCubemap::GetEntity_flEdgeFadeDist, &GCEnvCubemap::SetEntity_flEdgeFadeDist)
        .addProperty("Entity_vEdgeFadeDists", &GCEnvCubemap::GetEntity_vEdgeFadeDists, &GCEnvCubemap::SetEntity_vEdgeFadeDists)
        .addProperty("Entity_flDiffuseScale", &GCEnvCubemap::GetEntity_flDiffuseScale, &GCEnvCubemap::SetEntity_flDiffuseScale)
        .addProperty("Entity_bStartDisabled", &GCEnvCubemap::GetEntity_bStartDisabled, &GCEnvCubemap::SetEntity_bStartDisabled)
        .addProperty("Entity_bDefaultEnvMap", &GCEnvCubemap::GetEntity_bDefaultEnvMap, &GCEnvCubemap::SetEntity_bDefaultEnvMap)
        .addProperty("Entity_bDefaultSpecEnvMap", &GCEnvCubemap::GetEntity_bDefaultSpecEnvMap, &GCEnvCubemap::SetEntity_bDefaultSpecEnvMap)
        .addProperty("Entity_bIndoorCubeMap", &GCEnvCubemap::GetEntity_bIndoorCubeMap, &GCEnvCubemap::SetEntity_bIndoorCubeMap)
        .addProperty("Entity_bCopyDiffuseFromDefaultCubemap", &GCEnvCubemap::GetEntity_bCopyDiffuseFromDefaultCubemap, &GCEnvCubemap::SetEntity_bCopyDiffuseFromDefaultCubemap)
        .addProperty("Entity_bEnabled", &GCEnvCubemap::GetEntity_bEnabled, &GCEnvCubemap::SetEntity_bEnabled)
        .addProperty("Parent", &GCEnvCubemap::GetParent, &GCEnvCubemap::SetParent)
        .addFunction("ToPtr", &GCEnvCubemap::ToPtr)
        .addFunction("IsValid", &GCEnvCubemap::IsValid)
        .endClass();
}