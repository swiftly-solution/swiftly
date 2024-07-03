#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponP250::GCWeaponP250(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponP250::GCWeaponP250(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponP250::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponP250::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponP250::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponP250::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponP250(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponP250>("CWeaponP250")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponP250::GetParent, &GCWeaponP250::SetParent)
        .addFunction("ToPtr", &GCWeaponP250::ToPtr)
        .addFunction("IsValid", &GCWeaponP250::IsValid)
        .endClass();
}