#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponM4A1Silencer::GCWeaponM4A1Silencer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponM4A1Silencer::GCWeaponM4A1Silencer(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponM4A1Silencer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponM4A1Silencer::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponM4A1Silencer::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponM4A1Silencer::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponM4A1Silencer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponM4A1Silencer>("CWeaponM4A1Silencer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponM4A1Silencer::GetParent, &GCWeaponM4A1Silencer::SetParent)
        .addFunction("ToPtr", &GCWeaponM4A1Silencer::ToPtr)
        .addFunction("IsValid", &GCWeaponM4A1Silencer::IsValid)
        .endClass();
}