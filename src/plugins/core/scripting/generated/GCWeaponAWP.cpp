#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponAWP::GCWeaponAWP(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponAWP::GCWeaponAWP(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponAWP::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponAWP::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponAWP::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponAWP::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponAWP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponAWP>("CWeaponAWP")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponAWP::GetParent, &GCWeaponAWP::SetParent)
        .addFunction("ToPtr", &GCWeaponAWP::ToPtr)
        .addFunction("IsValid", &GCWeaponAWP::IsValid)
        .endClass();
}