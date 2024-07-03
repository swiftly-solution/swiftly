#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventOBBEntity::GCSoundEventOBBEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventOBBEntity::GCSoundEventOBBEntity(void *ptr) {
    m_ptr = ptr;
}
Vector GCSoundEventOBBEntity::GetMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundEventOBBEntity", "m_vMins");
}
void GCSoundEventOBBEntity::SetMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundEventOBBEntity", "m_vMins", false, value);
}
Vector GCSoundEventOBBEntity::GetMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundEventOBBEntity", "m_vMaxs");
}
void GCSoundEventOBBEntity::SetMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundEventOBBEntity", "m_vMaxs", false, value);
}
std::string GCSoundEventOBBEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventOBBEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundEventEntity GCSoundEventOBBEntity::GetParent() const {
    GCSoundEventEntity value(m_ptr);
    return value;
}
void GCSoundEventOBBEntity::SetParent(GCSoundEventEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEventOBBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventOBBEntity>("CSoundEventOBBEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mins", &GCSoundEventOBBEntity::GetMins, &GCSoundEventOBBEntity::SetMins)
        .addProperty("Maxs", &GCSoundEventOBBEntity::GetMaxs, &GCSoundEventOBBEntity::SetMaxs)
        .addProperty("Parent", &GCSoundEventOBBEntity::GetParent, &GCSoundEventOBBEntity::SetParent)
        .addFunction("ToPtr", &GCSoundEventOBBEntity::ToPtr)
        .addFunction("IsValid", &GCSoundEventOBBEntity::IsValid)
        .endClass();
}