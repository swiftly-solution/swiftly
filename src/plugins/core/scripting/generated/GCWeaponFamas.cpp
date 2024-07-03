#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponFamas::GCWeaponFamas(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponFamas::GCWeaponFamas(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponFamas::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponFamas::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponFamas::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponFamas::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponFamas(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponFamas>("CWeaponFamas")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponFamas::GetParent, &GCWeaponFamas::SetParent)
        .addFunction("ToPtr", &GCWeaponFamas::ToPtr)
        .addFunction("IsValid", &GCWeaponFamas::IsValid)
        .endClass();
}