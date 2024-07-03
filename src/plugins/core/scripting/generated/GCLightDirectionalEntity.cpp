#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLightDirectionalEntity::GCLightDirectionalEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLightDirectionalEntity::GCLightDirectionalEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCLightDirectionalEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLightDirectionalEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCLightEntity GCLightDirectionalEntity::GetParent() const {
    GCLightEntity value(m_ptr);
    return value;
}
void GCLightDirectionalEntity::SetParent(GCLightEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLightDirectionalEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightDirectionalEntity>("CLightDirectionalEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLightDirectionalEntity::GetParent, &GCLightDirectionalEntity::SetParent)
        .addFunction("ToPtr", &GCLightDirectionalEntity::ToPtr)
        .addFunction("IsValid", &GCLightDirectionalEntity::IsValid)
        .endClass();
}