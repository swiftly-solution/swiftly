#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCServerOnlyEntity::GCServerOnlyEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCServerOnlyEntity::GCServerOnlyEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCServerOnlyEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCServerOnlyEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCServerOnlyEntity::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCServerOnlyEntity::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCServerOnlyEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerOnlyEntity>("CServerOnlyEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCServerOnlyEntity::GetParent, &GCServerOnlyEntity::SetParent)
        .addFunction("ToPtr", &GCServerOnlyEntity::ToPtr)
        .addFunction("IsValid", &GCServerOnlyEntity::IsValid)
        .endClass();
}