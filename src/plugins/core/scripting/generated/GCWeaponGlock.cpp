#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponGlock::GCWeaponGlock(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponGlock::GCWeaponGlock(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponGlock::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponGlock::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponGlock::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponGlock::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponGlock(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponGlock>("CWeaponGlock")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponGlock::GetParent, &GCWeaponGlock::SetParent)
        .addFunction("ToPtr", &GCWeaponGlock::ToPtr)
        .addFunction("IsValid", &GCWeaponGlock::IsValid)
        .endClass();
}