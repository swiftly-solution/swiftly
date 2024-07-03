#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponSG556::GCWeaponSG556(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponSG556::GCWeaponSG556(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponSG556::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponSG556::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponSG556::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponSG556::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponSG556(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSG556>("CWeaponSG556")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponSG556::GetParent, &GCWeaponSG556::SetParent)
        .addFunction("ToPtr", &GCWeaponSG556::ToPtr)
        .addFunction("IsValid", &GCWeaponSG556::IsValid)
        .endClass();
}