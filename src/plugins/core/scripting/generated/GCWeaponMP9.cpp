#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponMP9::GCWeaponMP9(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponMP9::GCWeaponMP9(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponMP9::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponMP9::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponMP9::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponMP9::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponMP9(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMP9>("CWeaponMP9")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponMP9::GetParent, &GCWeaponMP9::SetParent)
        .addFunction("ToPtr", &GCWeaponMP9::ToPtr)
        .addFunction("IsValid", &GCWeaponMP9::IsValid)
        .endClass();
}