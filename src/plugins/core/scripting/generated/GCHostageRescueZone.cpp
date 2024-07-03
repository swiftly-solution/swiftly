#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHostageRescueZone::GCHostageRescueZone(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHostageRescueZone::GCHostageRescueZone(void *ptr) {
    m_ptr = ptr;
}
std::string GCHostageRescueZone::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHostageRescueZone::IsValid() {
    return (m_ptr != nullptr);
}
GCHostageRescueZoneShim GCHostageRescueZone::GetParent() const {
    GCHostageRescueZoneShim value(m_ptr);
    return value;
}
void GCHostageRescueZone::SetParent(GCHostageRescueZoneShim value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHostageRescueZone(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageRescueZone>("CHostageRescueZone")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCHostageRescueZone::GetParent, &GCHostageRescueZone::SetParent)
        .addFunction("ToPtr", &GCHostageRescueZone::ToPtr)
        .addFunction("IsValid", &GCHostageRescueZone::IsValid)
        .endClass();
}