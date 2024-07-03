#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponGalilAR::GCWeaponGalilAR(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponGalilAR::GCWeaponGalilAR(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponGalilAR::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponGalilAR::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBaseGun GCWeaponGalilAR::GetParent() const {
    GCCSWeaponBaseGun value(m_ptr);
    return value;
}
void GCWeaponGalilAR::SetParent(GCCSWeaponBaseGun value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponGalilAR(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponGalilAR>("CWeaponGalilAR")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponGalilAR::GetParent, &GCWeaponGalilAR::SetParent)
        .addFunction("ToPtr", &GCWeaponGalilAR::ToPtr)
        .addFunction("IsValid", &GCWeaponGalilAR::IsValid)
        .endClass();
}