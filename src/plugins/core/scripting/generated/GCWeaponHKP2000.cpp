#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponHKP2000::GCWeaponHKP2000(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponHKP2000::GCWeaponHKP2000(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponHKP2000::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponHKP2000::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponHKP2000::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponHKP2000::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponHKP2000(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponHKP2000>("CWeaponHKP2000")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponHKP2000::GetParent, &GCWeaponHKP2000::SetParent)
        .addFunction("ToPtr", &GCWeaponHKP2000::ToPtr)
        .addFunction("IsValid", &GCWeaponHKP2000::IsValid)
        .endClass();
}