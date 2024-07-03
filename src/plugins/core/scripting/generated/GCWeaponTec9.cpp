#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponTec9::GCWeaponTec9(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponTec9::GCWeaponTec9(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponTec9::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponTec9::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponTec9::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponTec9::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponTec9(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponTec9>("CWeaponTec9")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponTec9::GetParent, &GCWeaponTec9::SetParent)
        .addFunction("ToPtr", &GCWeaponTec9::ToPtr)
        .addFunction("IsValid", &GCWeaponTec9::IsValid)
        .endClass();
}