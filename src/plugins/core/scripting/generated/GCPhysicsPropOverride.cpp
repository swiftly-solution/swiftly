#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsPropOverride::GCPhysicsPropOverride(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsPropOverride::GCPhysicsPropOverride(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysicsPropOverride::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsPropOverride::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysicsProp GCPhysicsPropOverride::GetParent() const {
    GCPhysicsProp value(m_ptr);
    return value;
}
void GCPhysicsPropOverride::SetParent(GCPhysicsProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicsPropOverride(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsPropOverride>("CPhysicsPropOverride")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPhysicsPropOverride::GetParent, &GCPhysicsPropOverride::SetParent)
        .addFunction("ToPtr", &GCPhysicsPropOverride::ToPtr)
        .addFunction("IsValid", &GCPhysicsPropOverride::IsValid)
        .endClass();
}