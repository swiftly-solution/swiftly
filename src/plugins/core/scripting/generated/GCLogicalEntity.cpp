#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicalEntity::GCLogicalEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicalEntity::GCLogicalEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicalEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicalEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyEntity GCLogicalEntity::GetParent() const {
    GCServerOnlyEntity value(m_ptr);
    return value;
}
void GCLogicalEntity::SetParent(GCServerOnlyEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicalEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicalEntity>("CLogicalEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLogicalEntity::GetParent, &GCLogicalEntity::SetParent)
        .addFunction("ToPtr", &GCLogicalEntity::ToPtr)
        .addFunction("IsValid", &GCLogicalEntity::IsValid)
        .endClass();
}