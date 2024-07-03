#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponG3SG1::GCWeaponG3SG1(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponG3SG1::GCWeaponG3SG1(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponG3SG1::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponG3SG1::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponG3SG1::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponG3SG1::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponG3SG1(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponG3SG1>("CWeaponG3SG1")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponG3SG1::GetParent, &GCWeaponG3SG1::SetParent)
        .addFunction("ToPtr", &GCWeaponG3SG1::ToPtr)
        .addFunction("IsValid", &GCWeaponG3SG1::IsValid)
        .endClass();
}