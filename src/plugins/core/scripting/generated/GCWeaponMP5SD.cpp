#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponMP5SD::GCWeaponMP5SD(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponMP5SD::GCWeaponMP5SD(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponMP5SD::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponMP5SD::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponMP5SD::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponMP5SD::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponMP5SD(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMP5SD>("CWeaponMP5SD")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponMP5SD::GetParent, &GCWeaponMP5SD::SetParent)
        .addFunction("ToPtr", &GCWeaponMP5SD::ToPtr)
        .addFunction("IsValid", &GCWeaponMP5SD::IsValid)
        .endClass();
}