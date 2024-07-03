#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNullEntity::GCNullEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNullEntity::GCNullEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCNullEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNullEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCNullEntity::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCNullEntity::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNullEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNullEntity>("CNullEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNullEntity::GetParent, &GCNullEntity::SetParent)
        .addFunction("ToPtr", &GCNullEntity::ToPtr)
        .addFunction("IsValid", &GCNullEntity::IsValid)
        .endClass();
}