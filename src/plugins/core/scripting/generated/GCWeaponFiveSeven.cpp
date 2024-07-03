#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponFiveSeven::GCWeaponFiveSeven(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponFiveSeven::GCWeaponFiveSeven(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponFiveSeven::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponFiveSeven::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponFiveSeven::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponFiveSeven::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponFiveSeven(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponFiveSeven>("CWeaponFiveSeven")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponFiveSeven::GetParent, &GCWeaponFiveSeven::SetParent)
        .addFunction("ToPtr", &GCWeaponFiveSeven::ToPtr)
        .addFunction("IsValid", &GCWeaponFiveSeven::IsValid)
        .endClass();
}