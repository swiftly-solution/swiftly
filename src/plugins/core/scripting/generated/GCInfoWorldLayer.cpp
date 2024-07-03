#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoWorldLayer::GCInfoWorldLayer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoWorldLayer::GCInfoWorldLayer(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCInfoWorldLayer::GetOutputOnEntitiesSpawned() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CInfoWorldLayer", "m_pOutputOnEntitiesSpawned"));
    return value;
}
void GCInfoWorldLayer::SetOutputOnEntitiesSpawned(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_pOutputOnEntitiesSpawned", false, value);
}
std::string GCInfoWorldLayer::GetWorldName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoWorldLayer", "m_worldName").String();
}
void GCInfoWorldLayer::SetWorldName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_worldName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCInfoWorldLayer::GetLayerName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoWorldLayer", "m_layerName").String();
}
void GCInfoWorldLayer::SetLayerName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_layerName", false, CUtlSymbolLarge(value.c_str()));
}
bool GCInfoWorldLayer::GetWorldLayerVisible() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoWorldLayer", "m_bWorldLayerVisible");
}
void GCInfoWorldLayer::SetWorldLayerVisible(bool value) {
    SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_bWorldLayerVisible", false, value);
}
bool GCInfoWorldLayer::GetEntitiesSpawned() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoWorldLayer", "m_bEntitiesSpawned");
}
void GCInfoWorldLayer::SetEntitiesSpawned(bool value) {
    SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_bEntitiesSpawned", false, value);
}
bool GCInfoWorldLayer::GetCreateAsChildSpawnGroup() const {
    return GetSchemaValue<bool>(m_ptr, "CInfoWorldLayer", "m_bCreateAsChildSpawnGroup");
}
void GCInfoWorldLayer::SetCreateAsChildSpawnGroup(bool value) {
    SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_bCreateAsChildSpawnGroup", false, value);
}
uint32_t GCInfoWorldLayer::GetLayerSpawnGroup() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CInfoWorldLayer", "m_hLayerSpawnGroup");
}
void GCInfoWorldLayer::SetLayerSpawnGroup(uint32_t value) {
    SetSchemaValue(m_ptr, "CInfoWorldLayer", "m_hLayerSpawnGroup", false, value);
}
std::string GCInfoWorldLayer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoWorldLayer::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCInfoWorldLayer::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCInfoWorldLayer::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoWorldLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoWorldLayer>("CInfoWorldLayer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OutputOnEntitiesSpawned", &GCInfoWorldLayer::GetOutputOnEntitiesSpawned, &GCInfoWorldLayer::SetOutputOnEntitiesSpawned)
        .addProperty("WorldName", &GCInfoWorldLayer::GetWorldName, &GCInfoWorldLayer::SetWorldName)
        .addProperty("LayerName", &GCInfoWorldLayer::GetLayerName, &GCInfoWorldLayer::SetLayerName)
        .addProperty("WorldLayerVisible", &GCInfoWorldLayer::GetWorldLayerVisible, &GCInfoWorldLayer::SetWorldLayerVisible)
        .addProperty("EntitiesSpawned", &GCInfoWorldLayer::GetEntitiesSpawned, &GCInfoWorldLayer::SetEntitiesSpawned)
        .addProperty("CreateAsChildSpawnGroup", &GCInfoWorldLayer::GetCreateAsChildSpawnGroup, &GCInfoWorldLayer::SetCreateAsChildSpawnGroup)
        .addProperty("LayerSpawnGroup", &GCInfoWorldLayer::GetLayerSpawnGroup, &GCInfoWorldLayer::SetLayerSpawnGroup)
        .addProperty("Parent", &GCInfoWorldLayer::GetParent, &GCInfoWorldLayer::SetParent)
        .addFunction("ToPtr", &GCInfoWorldLayer::ToPtr)
        .addFunction("IsValid", &GCInfoWorldLayer::IsValid)
        .endClass();
}