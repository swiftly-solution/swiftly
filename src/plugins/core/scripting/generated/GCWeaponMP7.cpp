#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponMP7::GCWeaponMP7(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponMP7::GCWeaponMP7(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponMP7::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponMP7::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponMP7::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponMP7::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponMP7(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMP7>("CWeaponMP7")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponMP7::GetParent, &GCWeaponMP7::SetParent)
        .addFunction("ToPtr", &GCWeaponMP7::ToPtr)
        .addFunction("IsValid", &GCWeaponMP7::IsValid)
        .endClass();
}