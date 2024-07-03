#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponSSG08::GCWeaponSSG08(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponSSG08::GCWeaponSSG08(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponSSG08::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponSSG08::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponSSG08::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponSSG08::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponSSG08(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSSG08>("CWeaponSSG08")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponSSG08::GetParent, &GCWeaponSSG08::SetParent)
        .addFunction("ToPtr", &GCWeaponSSG08::ToPtr)
        .addFunction("IsValid", &GCWeaponSSG08::IsValid)
        .endClass();
}