#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTripWireFireProjectile::GCTripWireFireProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTripWireFireProjectile::GCTripWireFireProjectile(void *ptr) {
    m_ptr = ptr;
}
std::string GCTripWireFireProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTripWireFireProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseGrenade GCTripWireFireProjectile::GetParent() const {
    GCBaseGrenade value(m_ptr);
    return value;
}
void GCTripWireFireProjectile::SetParent(GCBaseGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTripWireFireProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTripWireFireProjectile>("CTripWireFireProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTripWireFireProjectile::GetParent, &GCTripWireFireProjectile::SetParent)
        .addFunction("ToPtr", &GCTripWireFireProjectile::ToPtr)
        .addFunction("IsValid", &GCTripWireFireProjectile::IsValid)
        .endClass();
}