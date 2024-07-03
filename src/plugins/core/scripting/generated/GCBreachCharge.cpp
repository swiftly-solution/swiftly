#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBreachCharge::GCBreachCharge(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBreachCharge::GCBreachCharge(void *ptr) {
    m_ptr = ptr;
}
std::string GCBreachCharge::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBreachCharge::IsValid() {
    return (m_ptr != nullptr);
}
GCCSWeaponBase GCBreachCharge::GetParent() const {
    GCCSWeaponBase value(m_ptr);
    return value;
}
void GCBreachCharge::SetParent(GCCSWeaponBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBreachCharge(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreachCharge>("CBreachCharge")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBreachCharge::GetParent, &GCBreachCharge::SetParent)
        .addFunction("ToPtr", &GCBreachCharge::ToPtr)
        .addFunction("IsValid", &GCBreachCharge::IsValid)
        .endClass();
}