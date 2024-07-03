#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponXM1014::GCWeaponXM1014(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponXM1014::GCWeaponXM1014(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponXM1014::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponXM1014::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCWeaponXM1014::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCWeaponXM1014::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponXM1014(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponXM1014>("CWeaponXM1014")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponXM1014::GetParent, &GCWeaponXM1014::SetParent)
        .addFunction("ToPtr", &GCWeaponXM1014::ToPtr)
        .addFunction("IsValid", &GCWeaponXM1014::IsValid)
        .endClass();
}