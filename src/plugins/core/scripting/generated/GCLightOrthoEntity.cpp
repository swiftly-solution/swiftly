#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLightOrthoEntity::GCLightOrthoEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLightOrthoEntity::GCLightOrthoEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCLightOrthoEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLightOrthoEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCLightEntity GCLightOrthoEntity::GetParent() const {
    GCLightEntity value(m_ptr);
    return value;
}
void GCLightOrthoEntity::SetParent(GCLightEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLightOrthoEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightOrthoEntity>("CLightOrthoEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLightOrthoEntity::GetParent, &GCLightOrthoEntity::SetParent)
        .addFunction("ToPtr", &GCLightOrthoEntity::ToPtr)
        .addFunction("IsValid", &GCLightOrthoEntity::IsValid)
        .endClass();
}