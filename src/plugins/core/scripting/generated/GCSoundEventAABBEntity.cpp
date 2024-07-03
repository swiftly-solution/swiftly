#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventAABBEntity::GCSoundEventAABBEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventAABBEntity::GCSoundEventAABBEntity(void *ptr) {
    m_ptr = ptr;
}
Vector GCSoundEventAABBEntity::GetMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundEventAABBEntity", "m_vMins");
}
void GCSoundEventAABBEntity::SetMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundEventAABBEntity", "m_vMins", false, value);
}
Vector GCSoundEventAABBEntity::GetMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundEventAABBEntity", "m_vMaxs");
}
void GCSoundEventAABBEntity::SetMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundEventAABBEntity", "m_vMaxs", false, value);
}
std::string GCSoundEventAABBEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventAABBEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundEventEntity GCSoundEventAABBEntity::GetParent() const {
    GCSoundEventEntity value(m_ptr);
    return value;
}
void GCSoundEventAABBEntity::SetParent(GCSoundEventEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEventAABBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventAABBEntity>("CSoundEventAABBEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mins", &GCSoundEventAABBEntity::GetMins, &GCSoundEventAABBEntity::SetMins)
        .addProperty("Maxs", &GCSoundEventAABBEntity::GetMaxs, &GCSoundEventAABBEntity::SetMaxs)
        .addProperty("Parent", &GCSoundEventAABBEntity::GetParent, &GCSoundEventAABBEntity::SetParent)
        .addFunction("ToPtr", &GCSoundEventAABBEntity::ToPtr)
        .addFunction("IsValid", &GCSoundEventAABBEntity::IsValid)
        .endClass();
}