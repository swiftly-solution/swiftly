#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvLightProbeVolume::GCEnvLightProbeVolume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvLightProbeVolume::GCEnvLightProbeVolume(void *ptr) {
    m_ptr = ptr;
}
Vector GCEnvLightProbeVolume::GetEntity_vBoxMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvLightProbeVolume", "m_Entity_vBoxMins");
}
void GCEnvLightProbeVolume::SetEntity_vBoxMins(Vector value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_vBoxMins", false, value);
}
Vector GCEnvLightProbeVolume::GetEntity_vBoxMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CEnvLightProbeVolume", "m_Entity_vBoxMaxs");
}
void GCEnvLightProbeVolume::SetEntity_vBoxMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_vBoxMaxs", false, value);
}
bool GCEnvLightProbeVolume::GetEntity_bMoveable() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvLightProbeVolume", "m_Entity_bMoveable");
}
void GCEnvLightProbeVolume::SetEntity_bMoveable(bool value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_bMoveable", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nHandshake() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nHandshake");
}
void GCEnvLightProbeVolume::SetEntity_nHandshake(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nHandshake", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nPriority");
}
void GCEnvLightProbeVolume::SetEntity_nPriority(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nPriority", false, value);
}
bool GCEnvLightProbeVolume::GetEntity_bStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvLightProbeVolume", "m_Entity_bStartDisabled");
}
void GCEnvLightProbeVolume::SetEntity_bStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_bStartDisabled", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nLightProbeSizeX() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeSizeX");
}
void GCEnvLightProbeVolume::SetEntity_nLightProbeSizeX(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeSizeX", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nLightProbeSizeY() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeSizeY");
}
void GCEnvLightProbeVolume::SetEntity_nLightProbeSizeY(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeSizeY", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nLightProbeSizeZ() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeSizeZ");
}
void GCEnvLightProbeVolume::SetEntity_nLightProbeSizeZ(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeSizeZ", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasX() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeAtlasX");
}
void GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasX(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeAtlasX", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasY() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeAtlasY");
}
void GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasY(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeAtlasY", false, value);
}
int32_t GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasZ() const {
    return GetSchemaValue<int32_t>(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeAtlasZ");
}
void GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasZ(int32_t value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_nLightProbeAtlasZ", false, value);
}
bool GCEnvLightProbeVolume::GetEntity_bEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CEnvLightProbeVolume", "m_Entity_bEnabled");
}
void GCEnvLightProbeVolume::SetEntity_bEnabled(bool value) {
    SetSchemaValue(m_ptr, "CEnvLightProbeVolume", "m_Entity_bEnabled", false, value);
}
std::string GCEnvLightProbeVolume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvLightProbeVolume::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvLightProbeVolume::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvLightProbeVolume::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvLightProbeVolume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvLightProbeVolume>("CEnvLightProbeVolume")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entity_vBoxMins", &GCEnvLightProbeVolume::GetEntity_vBoxMins, &GCEnvLightProbeVolume::SetEntity_vBoxMins)
        .addProperty("Entity_vBoxMaxs", &GCEnvLightProbeVolume::GetEntity_vBoxMaxs, &GCEnvLightProbeVolume::SetEntity_vBoxMaxs)
        .addProperty("Entity_bMoveable", &GCEnvLightProbeVolume::GetEntity_bMoveable, &GCEnvLightProbeVolume::SetEntity_bMoveable)
        .addProperty("Entity_nHandshake", &GCEnvLightProbeVolume::GetEntity_nHandshake, &GCEnvLightProbeVolume::SetEntity_nHandshake)
        .addProperty("Entity_nPriority", &GCEnvLightProbeVolume::GetEntity_nPriority, &GCEnvLightProbeVolume::SetEntity_nPriority)
        .addProperty("Entity_bStartDisabled", &GCEnvLightProbeVolume::GetEntity_bStartDisabled, &GCEnvLightProbeVolume::SetEntity_bStartDisabled)
        .addProperty("Entity_nLightProbeSizeX", &GCEnvLightProbeVolume::GetEntity_nLightProbeSizeX, &GCEnvLightProbeVolume::SetEntity_nLightProbeSizeX)
        .addProperty("Entity_nLightProbeSizeY", &GCEnvLightProbeVolume::GetEntity_nLightProbeSizeY, &GCEnvLightProbeVolume::SetEntity_nLightProbeSizeY)
        .addProperty("Entity_nLightProbeSizeZ", &GCEnvLightProbeVolume::GetEntity_nLightProbeSizeZ, &GCEnvLightProbeVolume::SetEntity_nLightProbeSizeZ)
        .addProperty("Entity_nLightProbeAtlasX", &GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasX, &GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasX)
        .addProperty("Entity_nLightProbeAtlasY", &GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasY, &GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasY)
        .addProperty("Entity_nLightProbeAtlasZ", &GCEnvLightProbeVolume::GetEntity_nLightProbeAtlasZ, &GCEnvLightProbeVolume::SetEntity_nLightProbeAtlasZ)
        .addProperty("Entity_bEnabled", &GCEnvLightProbeVolume::GetEntity_bEnabled, &GCEnvLightProbeVolume::SetEntity_bEnabled)
        .addProperty("Parent", &GCEnvLightProbeVolume::GetParent, &GCEnvLightProbeVolume::SetParent)
        .addFunction("ToPtr", &GCEnvLightProbeVolume::ToPtr)
        .addFunction("IsValid", &GCEnvLightProbeVolume::IsValid)
        .endClass();
}