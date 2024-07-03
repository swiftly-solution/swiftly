#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvCombinedLightProbeVolume::GCEnvCombinedLightProbeVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvCombinedLightProbeVolume::GCEnvCombinedLightProbeVolume(void *ptr) {
    m_ptr = ptr;
}
Color GCEnvCombinedLightProbeVolume::GetEntity_Color() const {
    return GetSchemaValue<Color>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_Color");
}
void GCEnvCombinedLightProbeVolume::SetEntity_Color(Color value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_Color", false, value);
}
float GCEnvCombinedLightProbeVolume::GetEntity_flBrightness() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flBrightness");
}
void GCEnvCombinedLightProbeVolume::SetEntity_flBrightness(float value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flBrightness", false, value);
}
bool GCEnvCombinedLightProbeVolume::GetEntity_bCustomCubemapTexture() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bCustomCubemapTexture");
}
void GCEnvCombinedLightProbeVolume::SetEntity_bCustomCubemapTexture(bool value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bCustomCubemapTexture", false, value);
}
Vector GCEnvCombinedLightProbeVolume::GetEntity_vBoxMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMins");
}
void GCEnvCombinedLightProbeVolume::SetEntity_vBoxMins(Vector value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMins", false, value);
}
Vector GCEnvCombinedLightProbeVolume::GetEntity_vBoxMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMaxs");
}
void GCEnvCombinedLightProbeVolume::SetEntity_vBoxMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vBoxMaxs", false, value);
}
bool GCEnvCombinedLightProbeVolume::GetEntity_bMoveable() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bMoveable");
}
void GCEnvCombinedLightProbeVolume::SetEntity_bMoveable(bool value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bMoveable", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nHandshake() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nHandshake");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nHandshake(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nHandshake", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nEnvCubeMapArrayIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nEnvCubeMapArrayIndex");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nEnvCubeMapArrayIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nEnvCubeMapArrayIndex", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nPriority");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nPriority", false, value);
}
bool GCEnvCombinedLightProbeVolume::GetEntity_bStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bStartDisabled");
}
void GCEnvCombinedLightProbeVolume::SetEntity_bStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bStartDisabled", false, value);
}
float GCEnvCombinedLightProbeVolume::GetEntity_flEdgeFadeDist() const {
    return GetSchemaValue<float>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flEdgeFadeDist");
}
void GCEnvCombinedLightProbeVolume::SetEntity_flEdgeFadeDist(float value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_flEdgeFadeDist", false, value);
}
Vector GCEnvCombinedLightProbeVolume::GetEntity_vEdgeFadeDists() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vEdgeFadeDists");
}
void GCEnvCombinedLightProbeVolume::SetEntity_vEdgeFadeDists(Vector value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_vEdgeFadeDists", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeX() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeX");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeX(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeX", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeY() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeY");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeY(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeY", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeZ() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeZ");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeZ(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeSizeZ", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasX() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasX");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasX(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasX", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasY() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasY");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasY(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasY", false, value);
}
int32_t GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasZ() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasZ");
}
void GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasZ(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_nLightProbeAtlasZ", false, value);
}
bool GCEnvCombinedLightProbeVolume::GetEntity_bEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bEnabled");
}
void GCEnvCombinedLightProbeVolume::SetEntity_bEnabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvCombinedLightProbeVolume", "m_Entity_bEnabled", false, value);
}
std::string GCEnvCombinedLightProbeVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvCombinedLightProbeVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvCombinedLightProbeVolume::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvCombinedLightProbeVolume::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvCombinedLightProbeVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvCombinedLightProbeVolume>("CEnvCombinedLightProbeVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entity_Color", &GCEnvCombinedLightProbeVolume::GetEntity_Color, &GCEnvCombinedLightProbeVolume::SetEntity_Color)
        .addProperty("Entity_flBrightness", &GCEnvCombinedLightProbeVolume::GetEntity_flBrightness, &GCEnvCombinedLightProbeVolume::SetEntity_flBrightness)
        .addProperty("Entity_bCustomCubemapTexture", &GCEnvCombinedLightProbeVolume::GetEntity_bCustomCubemapTexture, &GCEnvCombinedLightProbeVolume::SetEntity_bCustomCubemapTexture)
        .addProperty("Entity_vBoxMins", &GCEnvCombinedLightProbeVolume::GetEntity_vBoxMins, &GCEnvCombinedLightProbeVolume::SetEntity_vBoxMins)
        .addProperty("Entity_vBoxMaxs", &GCEnvCombinedLightProbeVolume::GetEntity_vBoxMaxs, &GCEnvCombinedLightProbeVolume::SetEntity_vBoxMaxs)
        .addProperty("Entity_bMoveable", &GCEnvCombinedLightProbeVolume::GetEntity_bMoveable, &GCEnvCombinedLightProbeVolume::SetEntity_bMoveable)
        .addProperty("Entity_nHandshake", &GCEnvCombinedLightProbeVolume::GetEntity_nHandshake, &GCEnvCombinedLightProbeVolume::SetEntity_nHandshake)
        .addProperty("Entity_nEnvCubeMapArrayIndex", &GCEnvCombinedLightProbeVolume::GetEntity_nEnvCubeMapArrayIndex, &GCEnvCombinedLightProbeVolume::SetEntity_nEnvCubeMapArrayIndex)
        .addProperty("Entity_nPriority", &GCEnvCombinedLightProbeVolume::GetEntity_nPriority, &GCEnvCombinedLightProbeVolume::SetEntity_nPriority)
        .addProperty("Entity_bStartDisabled", &GCEnvCombinedLightProbeVolume::GetEntity_bStartDisabled, &GCEnvCombinedLightProbeVolume::SetEntity_bStartDisabled)
        .addProperty("Entity_flEdgeFadeDist", &GCEnvCombinedLightProbeVolume::GetEntity_flEdgeFadeDist, &GCEnvCombinedLightProbeVolume::SetEntity_flEdgeFadeDist)
        .addProperty("Entity_vEdgeFadeDists", &GCEnvCombinedLightProbeVolume::GetEntity_vEdgeFadeDists, &GCEnvCombinedLightProbeVolume::SetEntity_vEdgeFadeDists)
        .addProperty("Entity_nLightProbeSizeX", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeX, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeX)
        .addProperty("Entity_nLightProbeSizeY", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeY, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeY)
        .addProperty("Entity_nLightProbeSizeZ", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeSizeZ, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeSizeZ)
        .addProperty("Entity_nLightProbeAtlasX", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasX, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasX)
        .addProperty("Entity_nLightProbeAtlasY", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasY, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasY)
        .addProperty("Entity_nLightProbeAtlasZ", &GCEnvCombinedLightProbeVolume::GetEntity_nLightProbeAtlasZ, &GCEnvCombinedLightProbeVolume::SetEntity_nLightProbeAtlasZ)
        .addProperty("Entity_bEnabled", &GCEnvCombinedLightProbeVolume::GetEntity_bEnabled, &GCEnvCombinedLightProbeVolume::SetEntity_bEnabled)
        .addProperty("Parent", &GCEnvCombinedLightProbeVolume::GetParent, &GCEnvCombinedLightProbeVolume::SetParent)
        .addFunction("ToPtr", &GCEnvCombinedLightProbeVolume::ToPtr)
        .addFunction("IsValid", &GCEnvCombinedLightProbeVolume::IsValid)
        .endClass();
}