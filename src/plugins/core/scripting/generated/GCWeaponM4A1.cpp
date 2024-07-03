#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponM4A1::GCWeaponM4A1(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponM4A1::GCWeaponM4A1(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponM4A1::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponM4A1::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponM4A1::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponM4A1::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponM4A1(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponM4A1>("CWeaponM4A1")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponM4A1::GetParent, &GCWeaponM4A1::SetParent)
        .addFunction("ToPtr", &GCWeaponM4A1::ToPtr)
        .addFunction("IsValid", &GCWeaponM4A1::IsValid)
        .endClass();
}