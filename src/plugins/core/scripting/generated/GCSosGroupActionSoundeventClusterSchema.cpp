#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSosGroupActionSoundeventClusterSchema::GCSosGroupActionSoundeventClusterSchema(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSosGroupActionSoundeventClusterSchema::GCSosGroupActionSoundeventClusterSchema(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSosGroupActionSoundeventClusterSchema::GetMinNearby() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_nMinNearby");
}
void GCSosGroupActionSoundeventClusterSchema::SetMinNearby(int32_t value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_nMinNearby", false, value);
}
float GCSosGroupActionSoundeventClusterSchema::GetClusterEpsilon() const {
    return GetSchemaValue<float>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_flClusterEpsilon");
}
void GCSosGroupActionSoundeventClusterSchema::SetClusterEpsilon(float value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_flClusterEpsilon", false, value);
}
std::string GCSosGroupActionSoundeventClusterSchema::GetShouldPlayOpvar() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayOpvar").Get();
}
void GCSosGroupActionSoundeventClusterSchema::SetShouldPlayOpvar(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayOpvar", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventClusterSchema::GetShouldPlayClusterChild() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayClusterChild").Get();
}
void GCSosGroupActionSoundeventClusterSchema::SetShouldPlayClusterChild(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_shouldPlayClusterChild", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventClusterSchema::GetClusterSizeOpvar() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_clusterSizeOpvar").Get();
}
void GCSosGroupActionSoundeventClusterSchema::SetClusterSizeOpvar(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_clusterSizeOpvar", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventClusterSchema::GetGroupBoundingBoxMinsOpvar() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMinsOpvar").Get();
}
void GCSosGroupActionSoundeventClusterSchema::SetGroupBoundingBoxMinsOpvar(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMinsOpvar", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventClusterSchema::GetGroupBoundingBoxMaxsOpvar() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMaxsOpvar").Get();
}
void GCSosGroupActionSoundeventClusterSchema::SetGroupBoundingBoxMaxsOpvar(std::string value) {
    SetSchemaValue(m_ptr, "CSosGroupActionSoundeventClusterSchema", "m_groupBoundingBoxMaxsOpvar", false, CUtlString(value.c_str()));
}
std::string GCSosGroupActionSoundeventClusterSchema::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSosGroupActionSoundeventClusterSchema::IsValid() {
    return (m_ptr != nullptr);
}
GCSosGroupActionSchema GCSosGroupActionSoundeventClusterSchema::GetParent() const {
    GCSosGroupActionSchema value(m_ptr);
    return value;
}
void GCSosGroupActionSoundeventClusterSchema::SetParent(GCSosGroupActionSchema value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSosGroupActionSoundeventClusterSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSoundeventClusterSchema>("CSosGroupActionSoundeventClusterSchema")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinNearby", &GCSosGroupActionSoundeventClusterSchema::GetMinNearby, &GCSosGroupActionSoundeventClusterSchema::SetMinNearby)
        .addProperty("ClusterEpsilon", &GCSosGroupActionSoundeventClusterSchema::GetClusterEpsilon, &GCSosGroupActionSoundeventClusterSchema::SetClusterEpsilon)
        .addProperty("ShouldPlayOpvar", &GCSosGroupActionSoundeventClusterSchema::GetShouldPlayOpvar, &GCSosGroupActionSoundeventClusterSchema::SetShouldPlayOpvar)
        .addProperty("ShouldPlayClusterChild", &GCSosGroupActionSoundeventClusterSchema::GetShouldPlayClusterChild, &GCSosGroupActionSoundeventClusterSchema::SetShouldPlayClusterChild)
        .addProperty("ClusterSizeOpvar", &GCSosGroupActionSoundeventClusterSchema::GetClusterSizeOpvar, &GCSosGroupActionSoundeventClusterSchema::SetClusterSizeOpvar)
        .addProperty("GroupBoundingBoxMinsOpvar", &GCSosGroupActionSoundeventClusterSchema::GetGroupBoundingBoxMinsOpvar, &GCSosGroupActionSoundeventClusterSchema::SetGroupBoundingBoxMinsOpvar)
        .addProperty("GroupBoundingBoxMaxsOpvar", &GCSosGroupActionSoundeventClusterSchema::GetGroupBoundingBoxMaxsOpvar, &GCSosGroupActionSoundeventClusterSchema::SetGroupBoundingBoxMaxsOpvar)
        .addProperty("Parent", &GCSosGroupActionSoundeventClusterSchema::GetParent, &GCSosGroupActionSoundeventClusterSchema::SetParent)
        .addFunction("ToPtr", &GCSosGroupActionSoundeventClusterSchema::ToPtr)
        .addFunction("IsValid", &GCSosGroupActionSoundeventClusterSchema::IsValid)
        .endClass();
}