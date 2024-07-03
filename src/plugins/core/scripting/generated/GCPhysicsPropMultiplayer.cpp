#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsPropMultiplayer::GCPhysicsPropMultiplayer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsPropMultiplayer::GCPhysicsPropMultiplayer(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysicsPropMultiplayer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsPropMultiplayer::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysicsProp GCPhysicsPropMultiplayer::GetParent() const {
    GCPhysicsProp value(m_ptr);
    return value;
}
void GCPhysicsPropMultiplayer::SetParent(GCPhysicsProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicsPropMultiplayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsPropMultiplayer>("CPhysicsPropMultiplayer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPhysicsPropMultiplayer::GetParent, &GCPhysicsPropMultiplayer::SetParent)
        .addFunction("ToPtr", &GCPhysicsPropMultiplayer::ToPtr)
        .addFunction("IsValid", &GCPhysicsPropMultiplayer::IsValid)
        .endClass();
}