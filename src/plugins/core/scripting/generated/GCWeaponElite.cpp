#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponElite::GCWeaponElite(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponElite::GCWeaponElite(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponElite::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponElite::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponElite::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponElite::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponElite(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponElite>("CWeaponElite")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponElite::GetParent, &GCWeaponElite::SetParent)
        .addFunction("ToPtr", &GCWeaponElite::ToPtr)
        .addFunction("IsValid", &GCWeaponElite::IsValid)
        .endClass();
}