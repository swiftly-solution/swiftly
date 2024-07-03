#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponNegev::GCWeaponNegev(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponNegev::GCWeaponNegev(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponNegev::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponNegev::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponNegev::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponNegev::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponNegev(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponNegev>("CWeaponNegev")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponNegev::GetParent, &GCWeaponNegev::SetParent)
        .addFunction("ToPtr", &GCWeaponNegev::ToPtr)
        .addFunction("IsValid", &GCWeaponNegev::IsValid)
        .endClass();
}