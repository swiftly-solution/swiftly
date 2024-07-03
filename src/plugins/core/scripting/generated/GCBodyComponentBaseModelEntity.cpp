#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBodyComponentBaseModelEntity::GCBodyComponentBaseModelEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBodyComponentBaseModelEntity::GCBodyComponentBaseModelEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCBodyComponentBaseModelEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBodyComponentBaseModelEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBodyComponentSkeletonInstance GCBodyComponentBaseModelEntity::GetParent() const {
    GCBodyComponentSkeletonInstance value(m_ptr);
    return value;
}
void GCBodyComponentBaseModelEntity::SetParent(GCBodyComponentSkeletonInstance value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBodyComponentBaseModelEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponentBaseModelEntity>("CBodyComponentBaseModelEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBodyComponentBaseModelEntity::GetParent, &GCBodyComponentBaseModelEntity::SetParent)
        .addFunction("ToPtr", &GCBodyComponentBaseModelEntity::ToPtr)
        .addFunction("IsValid", &GCBodyComponentBaseModelEntity::IsValid)
        .endClass();
}