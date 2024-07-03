#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTripWireFire::GCTripWireFire(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTripWireFire::GCTripWireFire(void *ptr) {
    m_ptr = ptr;
}
std::string GCTripWireFire::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTripWireFire::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenade GCTripWireFire::GetParent() const {
    GCBaseCSGrenade value(m_ptr);
    return value;
}
void GCTripWireFire::SetParent(GCBaseCSGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTripWireFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTripWireFire>("CTripWireFire")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTripWireFire::GetParent, &GCTripWireFire::SetParent)
        .addFunction("ToPtr", &GCTripWireFire::ToPtr)
        .addFunction("IsValid", &GCTripWireFire::IsValid)
        .endClass();
}