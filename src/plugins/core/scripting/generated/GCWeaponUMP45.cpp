#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponUMP45::GCWeaponUMP45(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponUMP45::GCWeaponUMP45(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponUMP45::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponUMP45::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponUMP45::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponUMP45::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponUMP45(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponUMP45>("CWeaponUMP45")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponUMP45::GetParent, &GCWeaponUMP45::SetParent)
        .addFunction("ToPtr", &GCWeaponUMP45::ToPtr)
        .addFunction("IsValid", &GCWeaponUMP45::IsValid)
        .endClass();
}