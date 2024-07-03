#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gmagnetted_objects_t::Gmagnetted_objects_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gmagnetted_objects_t::Gmagnetted_objects_t(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity Gmagnetted_objects_t::GetEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "magnetted_objects_t", "hEntity"));
    return value;
}
void Gmagnetted_objects_t::SetEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Entity' is not possible.\n");
}
std::string Gmagnetted_objects_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gmagnetted_objects_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassmagnetted_objects_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gmagnetted_objects_t>("magnetted_objects_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Entity", &Gmagnetted_objects_t::GetEntity, &Gmagnetted_objects_t::SetEntity)
        .addFunction("ToPtr", &Gmagnetted_objects_t::ToPtr)
        .addFunction("IsValid", &Gmagnetted_objects_t::IsValid)
        .endClass();
}