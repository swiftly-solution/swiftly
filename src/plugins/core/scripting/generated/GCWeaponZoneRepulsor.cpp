#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponZoneRepulsor::GCWeaponZoneRepulsor(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponZoneRepulsor::GCWeaponZoneRepulsor(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponZoneRepulsor::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponZoneRepulsor::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponZoneRepulsor::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponZoneRepulsor::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponZoneRepulsor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponZoneRepulsor>("CWeaponZoneRepulsor")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponZoneRepulsor::GetParent, &GCWeaponZoneRepulsor::SetParent)
        .addFunction("ToPtr", &GCWeaponZoneRepulsor::ToPtr)
        .addFunction("IsValid", &GCWeaponZoneRepulsor::IsValid)
        .endClass();
}