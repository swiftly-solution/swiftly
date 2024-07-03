#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSpawnPoint::GSpawnPoint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSpawnPoint::GSpawnPoint(void *ptr) {
    m_ptr = ptr;
}
int32_t GSpawnPoint::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "SpawnPoint", "m_iPriority");
}
void GSpawnPoint::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "SpawnPoint", "m_iPriority", false, value);
}
bool GSpawnPoint::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "SpawnPoint", "m_bEnabled");
}
void GSpawnPoint::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "SpawnPoint", "m_bEnabled", false, value);
}
int32_t GSpawnPoint::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "SpawnPoint", "m_nType");
}
void GSpawnPoint::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "SpawnPoint", "m_nType", false, value);
}
std::string GSpawnPoint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSpawnPoint::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyPointEntity GSpawnPoint::GetParent() const {
    GCServerOnlyPointEntity value(m_ptr);
    return value;
}
void GSpawnPoint::SetParent(GCServerOnlyPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassSpawnPoint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSpawnPoint>("SpawnPoint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Priority", &GSpawnPoint::GetPriority, &GSpawnPoint::SetPriority)
        .addProperty("Enabled", &GSpawnPoint::GetEnabled, &GSpawnPoint::SetEnabled)
        .addProperty("Type", &GSpawnPoint::GetType, &GSpawnPoint::SetType)
        .addProperty("Parent", &GSpawnPoint::GetParent, &GSpawnPoint::SetParent)
        .addFunction("ToPtr", &GSpawnPoint::ToPtr)
        .addFunction("IsValid", &GSpawnPoint::IsValid)
        .endClass();
}