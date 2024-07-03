#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponUSPSilencer::GCWeaponUSPSilencer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponUSPSilencer::GCWeaponUSPSilencer(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponUSPSilencer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponUSPSilencer::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponUSPSilencer::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponUSPSilencer::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponUSPSilencer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponUSPSilencer>("CWeaponUSPSilencer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponUSPSilencer::GetParent, &GCWeaponUSPSilencer::SetParent)
        .addFunction("ToPtr", &GCWeaponUSPSilencer::ToPtr)
        .addFunction("IsValid", &GCWeaponUSPSilencer::IsValid)
        .endClass();
}