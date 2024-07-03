#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponAug::GCWeaponAug(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponAug::GCWeaponAug(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponAug::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponAug::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponAug::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponAug::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponAug(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponAug>("CWeaponAug")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponAug::GetParent, &GCWeaponAug::SetParent)
        .addFunction("ToPtr", &GCWeaponAug::ToPtr)
        .addFunction("IsValid", &GCWeaponAug::IsValid)
        .endClass();
}