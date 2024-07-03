#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCWeaponNOVA::GCWeaponNOVA(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCWeaponNOVA::GCWeaponNOVA(void *ptr) {
    m_ptr = ptr;
}
std::string GCWeaponNOVA::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCWeaponNOVA::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCWeaponNOVA::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCWeaponNOVA::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCWeaponNOVA(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWeaponNOVA>("CWeaponNOVA")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCWeaponNOVA::GetParent, &GCWeaponNOVA::SetParent)
        .addFunction("ToPtr", &GCWeaponNOVA::ToPtr)
        .addFunction("IsValid", &GCWeaponNOVA::IsValid)
        .endClass();
}