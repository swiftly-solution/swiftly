#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCServerOnlyPointEntity::GCServerOnlyPointEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCServerOnlyPointEntity::GCServerOnlyPointEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCServerOnlyPointEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCServerOnlyPointEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyEntity GCServerOnlyPointEntity::GetParent() const {
    GCServerOnlyEntity value(m_ptr);
    return value;
}
void GCServerOnlyPointEntity::SetParent(GCServerOnlyEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCServerOnlyPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerOnlyPointEntity>("CServerOnlyPointEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCServerOnlyPointEntity::GetParent, &GCServerOnlyPointEntity::SetParent)
        .addFunction("ToPtr", &GCServerOnlyPointEntity::ToPtr)
        .addFunction("IsValid", &GCServerOnlyPointEntity::IsValid)
        .endClass();
}