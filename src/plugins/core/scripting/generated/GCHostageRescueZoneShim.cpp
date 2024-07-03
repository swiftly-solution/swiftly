#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHostageRescueZoneShim::GCHostageRescueZoneShim(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHostageRescueZoneShim::GCHostageRescueZoneShim(void *ptr) {
    m_ptr = ptr;
}
std::string GCHostageRescueZoneShim::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHostageRescueZoneShim::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCHostageRescueZoneShim::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCHostageRescueZoneShim::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHostageRescueZoneShim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageRescueZoneShim>("CHostageRescueZoneShim")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCHostageRescueZoneShim::GetParent, &GCHostageRescueZoneShim::SetParent)
        .addFunction("ToPtr", &GCHostageRescueZoneShim::ToPtr)
        .addFunction("IsValid", &GCHostageRescueZoneShim::IsValid)
        .endClass();
}