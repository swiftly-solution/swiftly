#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponBizon::GCWeaponBizon(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponBizon::GCWeaponBizon(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponBizon::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponBizon::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponBizon::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponBizon::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponBizon(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponBizon>("CWeaponBizon")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponBizon::GetParent, &GCWeaponBizon::SetParent)
        .addFunction("ToPtr", &GCWeaponBizon::ToPtr)
        .addFunction("IsValid", &GCWeaponBizon::IsValid)
        .endClass();
}