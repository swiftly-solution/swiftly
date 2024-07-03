#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponMAC10::GCWeaponMAC10(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponMAC10::GCWeaponMAC10(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponMAC10::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponMAC10::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponMAC10::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponMAC10::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponMAC10(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponMAC10>("CWeaponMAC10")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponMAC10::GetParent, &GCWeaponMAC10::SetParent)
        .addFunction("ToPtr", &GCWeaponMAC10::ToPtr)
        .addFunction("IsValid", &GCWeaponMAC10::IsValid)
        .endClass();
}