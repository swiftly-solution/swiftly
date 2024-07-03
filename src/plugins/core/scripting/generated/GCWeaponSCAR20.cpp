#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponSCAR20::GCWeaponSCAR20(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponSCAR20::GCWeaponSCAR20(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponSCAR20::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponSCAR20::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponSCAR20::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponSCAR20::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponSCAR20(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSCAR20>("CWeaponSCAR20")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponSCAR20::GetParent, &GCWeaponSCAR20::SetParent)
        .addFunction("ToPtr", &GCWeaponSCAR20::ToPtr)
        .addFunction("IsValid", &GCWeaponSCAR20::IsValid)
        .endClass();
}