#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBreachChargeProjectile::GCBreachChargeProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBreachChargeProjectile::GCBreachChargeProjectile(void *ptr) {
    m_ptr = ptr;
}
std::string GCBreachChargeProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBreachChargeProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseGrenade GCBreachChargeProjectile::GetParent() const {
    GCBaseGrenade value(m_ptr);
    return value;
}
void GCBreachChargeProjectile::SetParent(GCBaseGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBreachChargeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBreachChargeProjectile>("CBreachChargeProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBreachChargeProjectile::GetParent, &GCBreachChargeProjectile::SetParent)
        .addFunction("ToPtr", &GCBreachChargeProjectile::ToPtr)
        .addFunction("IsValid", &GCBreachChargeProjectile::IsValid)
        .endClass();
}