#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponMag7::GCWeaponMag7(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponMag7::GCWeaponMag7(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponMag7::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponMag7::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponMag7::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponMag7::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponMag7(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMag7>("CWeaponMag7")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponMag7::GetParent, &GCWeaponMag7::SetParent)
        .addFunction("ToPtr", &GCWeaponMag7::ToPtr)
        .addFunction("IsValid", &GCWeaponMag7::IsValid)
        .endClass();
}