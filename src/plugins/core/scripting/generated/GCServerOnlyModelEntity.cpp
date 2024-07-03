#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCServerOnlyModelEntity::GCServerOnlyModelEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCServerOnlyModelEntity::GCServerOnlyModelEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCServerOnlyModelEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCServerOnlyModelEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCServerOnlyModelEntity::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCServerOnlyModelEntity::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCServerOnlyModelEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerOnlyModelEntity>("CServerOnlyModelEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCServerOnlyModelEntity::GetParent, &GCServerOnlyModelEntity::SetParent)
        .addFunction("ToPtr", &GCServerOnlyModelEntity::ToPtr)
        .addFunction("IsValid", &GCServerOnlyModelEntity::IsValid)
        .endClass();
}