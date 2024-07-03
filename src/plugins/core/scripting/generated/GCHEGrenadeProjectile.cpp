#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHEGrenadeProjectile::GCHEGrenadeProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHEGrenadeProjectile::GCHEGrenadeProjectile(void *ptr) {
    m_ptr = ptr;
}
std::string GCHEGrenadeProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHEGrenadeProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenadeProjectile GCHEGrenadeProjectile::GetParent() const {
    GCBaseCSGrenadeProjectile value(m_ptr);
    return value;
}
void GCHEGrenadeProjectile::SetParent(GCBaseCSGrenadeProjectile value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHEGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHEGrenadeProjectile>("CHEGrenadeProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCHEGrenadeProjectile::GetParent, &GCHEGrenadeProjectile::SetParent)
        .addFunction("ToPtr", &GCHEGrenadeProjectile::ToPtr)
        .addFunction("IsValid", &GCHEGrenadeProjectile::IsValid)
        .endClass();
}