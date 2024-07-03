#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLightEntity::GCLightEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLightEntity::GCLightEntity(void *ptr) {
    m_ptr = ptr;
}
GCLightComponent GCLightEntity::GetCLightComponent() const {
    GCLightComponent value(*GetSchemaValuePtr<void*>(m_ptr, "CLightEntity", "m_CLightComponent"));
    return value;
}
void GCLightEntity::SetCLightComponent(GCLightComponent* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'CLightComponent' is not possible.\n");
}
std::string GCLightEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLightEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCLightEntity::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCLightEntity::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLightEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightEntity>("CLightEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CLightComponent", &GCLightEntity::GetCLightComponent, &GCLightEntity::SetCLightComponent)
        .addProperty("Parent", &GCLightEntity::GetParent, &GCLightEntity::SetParent)
        .addFunction("ToPtr", &GCLightEntity::ToPtr)
        .addFunction("IsValid", &GCLightEntity::IsValid)
        .endClass();
}