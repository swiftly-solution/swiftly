#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponRevolver::GCWeaponRevolver(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponRevolver::GCWeaponRevolver(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponRevolver::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponRevolver::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponRevolver::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponRevolver::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponRevolver(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponRevolver>("CWeaponRevolver")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponRevolver::GetParent, &GCWeaponRevolver::SetParent)
        .addFunction("ToPtr", &GCWeaponRevolver::ToPtr)
        .addFunction("IsValid", &GCWeaponRevolver::IsValid)
        .endClass();
}