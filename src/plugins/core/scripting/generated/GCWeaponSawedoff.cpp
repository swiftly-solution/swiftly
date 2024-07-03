#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponSawedoff::GCWeaponSawedoff(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponSawedoff::GCWeaponSawedoff(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponSawedoff::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponSawedoff::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCWeaponSawedoff::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCWeaponSawedoff::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponSawedoff(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponSawedoff>("CWeaponSawedoff")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponSawedoff::GetParent, &GCWeaponSawedoff::SetParent)
        .addFunction("ToPtr", &GCWeaponSawedoff::ToPtr)
        .addFunction("IsValid", &GCWeaponSawedoff::IsValid)
        .endClass();
}