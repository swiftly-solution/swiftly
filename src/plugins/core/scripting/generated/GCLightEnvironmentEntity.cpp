#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLightEnvironmentEntity::GCLightEnvironmentEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLightEnvironmentEntity::GCLightEnvironmentEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCLightEnvironmentEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLightEnvironmentEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCLightDirectionalEntity GCLightEnvironmentEntity::GetParent() const {
    GCLightDirectionalEntity value(m_ptr);
    return value;
}
void GCLightEnvironmentEntity::SetParent(GCLightDirectionalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLightEnvironmentEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightEnvironmentEntity>("CLightEnvironmentEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLightEnvironmentEntity::GetParent, &GCLightEnvironmentEntity::SetParent)
        .addFunction("ToPtr", &GCLightEnvironmentEntity::ToPtr)
        .addFunction("IsValid", &GCLightEnvironmentEntity::IsValid)
        .endClass();
}