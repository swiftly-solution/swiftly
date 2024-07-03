#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponP90::GCWeaponP90(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponP90::GCWeaponP90(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponP90::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponP90::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponP90::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponP90::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponP90(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponP90>("CWeaponP90")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponP90::GetParent, &GCWeaponP90::SetParent)
        .addFunction("ToPtr", &GCWeaponP90::ToPtr)
        .addFunction("IsValid", &GCWeaponP90::IsValid)
        .endClass();
}