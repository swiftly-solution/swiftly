#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysTorque::GCPhysTorque(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysTorque::GCPhysTorque(void *ptr) {
    m_ptr = ptr;
}
Vector GCPhysTorque::GetAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CPhysTorque", "m_axis");
}
void GCPhysTorque::SetAxis(Vector value) {
    SetSchemaValue(m_ptr, "CPhysTorque", "m_axis", false, value);
}
std::string GCPhysTorque::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysTorque::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysForce GCPhysTorque::GetParent() const {
    GCPhysForce value(m_ptr);
    return value;
}
void GCPhysTorque::SetParent(GCPhysForce value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysTorque(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysTorque>("CPhysTorque")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Axis", &GCPhysTorque::GetAxis, &GCPhysTorque::SetAxis)
        .addProperty("Parent", &GCPhysTorque::GetParent, &GCPhysTorque::SetParent)
        .addFunction("ToPtr", &GCPhysTorque::ToPtr)
        .addFunction("IsValid", &GCPhysTorque::IsValid)
        .endClass();
}