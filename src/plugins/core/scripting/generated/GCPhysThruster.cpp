#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysThruster::GCPhysThruster(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysThruster::GCPhysThruster(void *ptr) {
    m_ptr = ptr;
}
Vector GCPhysThruster::GetLocalOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysThruster", "m_localOrigin");
}
void GCPhysThruster::SetLocalOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CPhysThruster", "m_localOrigin", false, value);
}
std::string GCPhysThruster::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysThruster::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysForce GCPhysThruster::GetParent() const {
    GCPhysForce value(m_ptr);
    return value;
}
void GCPhysThruster::SetParent(GCPhysForce value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysThruster(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysThruster>("CPhysThruster")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LocalOrigin", &GCPhysThruster::GetLocalOrigin, &GCPhysThruster::SetLocalOrigin)
        .addProperty("Parent", &GCPhysThruster::GetParent, &GCPhysThruster::SetParent)
        .addFunction("ToPtr", &GCPhysThruster::ToPtr)
        .addFunction("IsValid", &GCPhysThruster::IsValid)
        .endClass();
}