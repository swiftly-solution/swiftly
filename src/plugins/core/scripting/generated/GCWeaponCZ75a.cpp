#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponCZ75a::GCWeaponCZ75a(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponCZ75a::GCWeaponCZ75a(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponCZ75a::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponCZ75a::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponCZ75a::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponCZ75a::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponCZ75a(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponCZ75a>("CWeaponCZ75a")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponCZ75a::GetParent, &GCWeaponCZ75a::SetParent)
        .addFunction("ToPtr", &GCWeaponCZ75a::ToPtr)
        .addFunction("IsValid", &GCWeaponCZ75a::IsValid)
        .endClass();
}