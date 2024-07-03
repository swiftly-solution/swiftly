#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysicsWire::GCPhysicsWire(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysicsWire::GCPhysicsWire(void *ptr) {
    m_ptr = ptr;
}
int32_t GCPhysicsWire::GetDensity() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPhysicsWire", "m_nDensity");
}
void GCPhysicsWire::SetDensity(int32_t value) {
    SetSchemaValue(m_ptr, "CPhysicsWire", "m_nDensity", false, value);
}
std::string GCPhysicsWire::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysicsWire::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPhysicsWire::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPhysicsWire::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysicsWire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsWire>("CPhysicsWire")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Density", &GCPhysicsWire::GetDensity, &GCPhysicsWire::SetDensity)
        .addProperty("Parent", &GCPhysicsWire::GetParent, &GCPhysicsWire::SetParent)
        .addFunction("ToPtr", &GCPhysicsWire::ToPtr)
        .addFunction("IsValid", &GCPhysicsWire::IsValid)
        .endClass();
}