#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBumpMineProjectile::GCBumpMineProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBumpMineProjectile::GCBumpMineProjectile(void *ptr) {
    m_ptr = ptr;
}
std::string GCBumpMineProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBumpMineProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseGrenade GCBumpMineProjectile::GetParent() const {
    GCBaseGrenade value(m_ptr);
    return value;
}
void GCBumpMineProjectile::SetParent(GCBaseGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBumpMineProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBumpMineProjectile>("CBumpMineProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBumpMineProjectile::GetParent, &GCBumpMineProjectile::SetParent)
        .addFunction("ToPtr", &GCBumpMineProjectile::ToPtr)
        .addFunction("IsValid", &GCBumpMineProjectile::IsValid)
        .endClass();
}