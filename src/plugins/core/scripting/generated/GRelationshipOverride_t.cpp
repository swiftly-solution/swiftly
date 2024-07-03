#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRelationshipOverride_t::GRelationshipOverride_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRelationshipOverride_t::GRelationshipOverride_t(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GRelationshipOverride_t::GetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "RelationshipOverride_t", "entity"));
    return value;
}
void GRelationshipOverride_t::SetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n");
}
uint64_t GRelationshipOverride_t::GetClassType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "RelationshipOverride_t", "classType");
}
void GRelationshipOverride_t::SetClassType(uint64_t value) {
    SetSchemaValue(m_ptr, "RelationshipOverride_t", "classType", true, value);
}
std::string GRelationshipOverride_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRelationshipOverride_t::IsValid() {
    return (m_ptr != nullptr);
}
GRelationship_t GRelationshipOverride_t::GetParent() const {
    GRelationship_t value(m_ptr);
    return value;
}
void GRelationshipOverride_t::SetParent(GRelationship_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassRelationshipOverride_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRelationshipOverride_t>("RelationshipOverride_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entity", &GRelationshipOverride_t::GetEntity, &GRelationshipOverride_t::SetEntity)
        .addProperty("ClassType", &GRelationshipOverride_t::GetClassType, &GRelationshipOverride_t::SetClassType)
        .addProperty("Parent", &GRelationshipOverride_t::GetParent, &GRelationshipOverride_t::SetParent)
        .addFunction("ToPtr", &GRelationshipOverride_t::ToPtr)
        .addFunction("IsValid", &GRelationshipOverride_t::IsValid)
        .endClass();
}