#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRelationship_t::GRelationship_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRelationship_t::GRelationship_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GRelationship_t::GetDisposition() const {
    return GetSchemaValue<uint64_t>(m_ptr, "Relationship_t", "disposition");
}
void GRelationship_t::SetDisposition(uint64_t value) {
    SetSchemaValue(m_ptr, "Relationship_t", "disposition", true, value);
}
int32_t GRelationship_t::GetPriority() const {
    return GetSchemaValue<int32_t>(m_ptr, "Relationship_t", "priority");
}
void GRelationship_t::SetPriority(int32_t value) {
    SetSchemaValue(m_ptr, "Relationship_t", "priority", true, value);
}
std::string GRelationship_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRelationship_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRelationship_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRelationship_t>("Relationship_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disposition", &GRelationship_t::GetDisposition, &GRelationship_t::SetDisposition)
        .addProperty("Priority", &GRelationship_t::GetPriority, &GRelationship_t::SetPriority)
        .addFunction("ToPtr", &GRelationship_t::ToPtr)
        .addFunction("IsValid", &GRelationship_t::IsValid)
        .endClass();
}